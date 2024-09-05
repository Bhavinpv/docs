from flask import Flask, render_template, request, jsonify
from werkzeug.utils import secure_filename
from flask_cors import CORS, cross_origin
from datetime import datetime
from intcan_qm import *
from deltae2e import *
import os
import zipfile
import shutil
from flask import send_file

# APP SETUP
app = Flask(__name__)
# enable resource sharing between frontend and server
CORS(app)
cors = CORS(app, resources={r"*": {"origins": "*"}})

# ROUTES
@app.route('/api/hello', methods=['GET'])
def getHello():
	return 'This is a GET request!'
@app.route('/api/hello', methods=['POST'])
def postHello():
	return 'This is a POST request!'
@app.route('/api/hello', methods=['PUT'])
def putHello():
	return 'This is a PUT request!'
@app.route('/api/hello', methods=['DELETE'])
def deleteHello():
	return 'This is a DELETE request!'

def allowed_file(filename,input):
    return '.' in filename and filename.rsplit('.', 1)[1].lower() == input

@app.route('/api/upload/<userId>', methods=['GET', 'POST'])
@cross_origin()
def upload_file_arxml(userId):
    if request.method == 'POST':
        f = request.files['file']
        folder_path = 'Temp_Delta/' + userId + '/Input/'
        if os.path.exists(folder_path):
            shutil.rmtree(folder_path)
        
        folder_path_input = 'Temp_Delta/' + userId + '/Input/'
         
        if f and allowed_file(f.filename,'arxml'):
            #print("file", f)
            file_name = f.filename.lower()  # Convert filename to lowercase for case-insensitive comparison

            if 'asil' in file_name:
                filetype = 'asil'
                os.makedirs(folder_path_input, exist_ok=True)
                f.save(folder_path_input + secure_filename(f.filename))
                #ProcessMessages(folder_path_input + secure_filename(f.filename), userId)
            elif 'qm' in file_name:
                filetype = 'qm'
                os.makedirs(folder_path_input, exist_ok=True)
                f.save(folder_path_input + secure_filename(f.filename))
                #GetMessages(folder_path_input + secure_filename(f.filename), userId)
            else:
                return jsonify({"status": "error", "message": "Invalid file name. The filename should contain 'ASIL' or 'QM'."}), 400

            return jsonify({"status": "success", "filename": f.filename, "fileType": filetype})
        else:
            return jsonify({"status": "error", "message": "Invalid file type. Only .arxml files are allowed."}), 400


@app.route('/api/uploaddbc/<userId>', methods=['GET', 'POST'])
@cross_origin()
def upload_file_dbc(userId):
    if request.method == 'POST':
        f = request.files['file']
        folder_path = 'Temp_Delta/' + userId + '/dbc/'
        if os.path.exists(folder_path):
            shutil.rmtree(folder_path)
        
        folder_path_input = 'Temp_Delta/' + userId + '/dbc/'
         
        if f and allowed_file(f.filename,'dbc'):
            os.makedirs(folder_path_input, exist_ok=True)
            f.save(folder_path_input + secure_filename(f.filename))
            return jsonify({"status": "success", "filename": f.filename})
        else:
            return jsonify({"status": "error", "message": "Invalid file type. Only .dbc files are allowed."}), 400

def find_file_in_folder(folder_path, filesearchstring):
    # Get the list of files in the folder
    if not os.path.exists(folder_path):
        raise Exception(f"Upload the files First, Input files not found")
    
    files_in_folder = os.listdir(folder_path)

    # Check if the target file name is present in the list
    for file_name in files_in_folder:
        if filesearchstring in file_name.lower():
            return os.path.join(folder_path, file_name)

    # Return None if the target file name is not found
    return None


@app.route('/api/downloadfile/<userId>', methods=['GET'])
def download_folder(userId):
    fileType = request.args.get('filetype')
    # req_data = request.get_json(force=True)
    # fileType = req_data['fileType']
    print("fileType", fileType)

    folder_path_input_dbc = 'Temp_Delta/' + userId + '/dbc/'
    folder_path_output = 'Temp_Delta/' + userId + '/Output/'
    folder_path_input = 'Temp_Delta/' + userId + '/Input/'

    try:
        # Find the 'dbc' file in the Input folder
        dbc_path = find_file_in_folder(folder_path_input_dbc, 'dbc')
        # print('dbc_path', dbc_path)
        if dbc_path is None:
            return jsonify({"status": "error", "message": "No 'dbc' file found in the Input folder."}), 400


        if fileType == 'asil':
            files_in_folder = os.listdir(folder_path_input)
            for file_name in files_in_folder:
                if 'asil' in file_name.lower():
                    ProcessMessages(os.path.join(folder_path_input, file_name), dbc_path, userId)
                    break  # Assuming there is only one 'asil' file in the Input folder
            else:
                return jsonify({"status": "error", "message": "No 'asil' file found in the Input folder."}), 400

        elif fileType == 'qm':
            files_in_folder = os.listdir(folder_path_input)
            for file_name in files_in_folder:
                if 'qm' in file_name.lower():
                    GetMessages(os.path.join(folder_path_input, file_name),dbc_path, userId)
                    break  # Assuming there is only one 'qm' file in the Input folder
            else:
                return jsonify({"status": "error", "message": "No 'qm' file found in the Input folder."}), 400

        else:
            return jsonify({"status": "error", "message": "Invalid fileType. Use 'asil' or 'qm' as fileType parameter."}), 400

        # Rest of the code inside the try block

        # Check if the folder exists
        if not os.path.exists(folder_path_output):
            raise Exception(f"Upload the arxml or dbc file first, Download for {userId} does not exist.")

        # Create a temporary zip file with a unique filename
        timestamp = datetime.now().strftime('%Y%m%d%H%M%S')
        temp_file_name = f'{timestamp}.zip'
        temp_zip_path = 'Temp_Delta/' + userId + '/' + temp_file_name

        with zipfile.ZipFile(temp_zip_path, 'w') as zip_file:
            for root, dirs, files in os.walk(folder_path_output):
                for file in files:
                    file_path = os.path.join(root, file)
                    zip_file.write(file_path, os.path.relpath(file_path, folder_path_output))
        zip_file.close()
        return send_file(temp_zip_path, as_attachment=True)

    except Exception as e:
        return jsonify({"status": "error", "message": str(e)}), 404

@app.route('/api/delete/<userId>', methods=['DELETE'])
@cross_origin()
def delete_user_folder(userId):
    folder_to_delete = f"Temp_Delta/{userId}/"

    try:
        # Perform folder deletion using the 'os' module
        if os.path.exists(folder_to_delete):
            shutil.rmtree(folder_to_delete)
            return jsonify({"status": "success", "message": f"Folder for {userId} deleted."})
        else:
            return jsonify({"status": "error", "message": f"Folder for {userId} not found."}), 404
    except Exception as e:
        return jsonify({"status": "error", "message": str(e)}), 500


@app.route('/generate', methods = ['GET', 'POST'])
def generate_files():
	if request.method == 'GET':
		# data = request.form["data"]
		# json1_data = json.loads(request.form["data"])
		# my_list = list(json1_data.values())
		# print("data",my_list)
		# Generate()
		return jsonify({"status":"success"})

@app.route('/download/<path:filename>')
def downloadFile (filename):
    # For windows you need to use drive name [ex: F:/Example.pdf]
    path = "build/"+ filename
    return send_file(path, as_attachment=True)

if __name__ == "__main__":
    app.run(debug=True)