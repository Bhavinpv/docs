from xml.etree import ElementTree as ET
import os
import cantools
from pprint import pprint
import sys

TS_list_factor={'1':['CM_TEMPERATURE_1DEG_INIT','CM_TEMPERATURE_1DEG_INVALID']}
CS_list_factor={'0.1':['CM_CURRENT_100MA_INIT','CM_CURRENT_100MA_INVALID'],'0.01':['CM_CURRENT_10MA_INIT','CM_CURRENT_10MA_INVALID'],'0.001':['CM_CURRENT_1MA_INIT','CM_CURRENT_1MA_INVALID']}
VS_list_factor={'0.1':['CM_VOLTAGE_100MV_INIT','CM_VOLTAGE_100MV_INVALID'],'0.01':['CM_VOLTAGE_10MV_INIT','CM_VOLTAGE_10MV_INVALID'],'0.001':['CM_VOLTAGE_1MV_INIT','CM_VOLTAGE_1MV_INVALID']}
TS_Dict,CS_Dict,VS_Dict,AT_CS_Dict,AT_TS_Dict,AT_VS_Dict,AT_cm_Dict,DBC_dict={},{},{},{},{},{},{},{}
TS,CS,VS,struct_list,AT_list,DBC_list,CM_list=[],[],[],[],[],[],[]
struct_dict=dict()
Rx_list,Tx_list,runnable=[],[],[]
Rx_list_RTE=[]
signal_dict = {} # Dictionary to store all msgs and signals
asil_dict = {}   # Dictionary to store ASIL msgs and signals
qm_dict = {}     # Dictionary to store QM msgs and signals
asil_list = []   # list to store ASIL msgs
qm_list = []     # list to store QM msgs
asil_tx_list = []# list to store ASIL TX msgs
qm_tx_list = []  # list to store QM TX msgs

def ProcessMessages(fpath,dbc_path, userId):
    TS_Dict.clear()      # Clear the TS_Dict before calling ProcessMessages
    CS_Dict.clear()      # Clear the CS_Dict before calling ProcessMessages
    VS_Dict.clear()      # Clear the VS_Dict before calling ProcessMessages
    AT_CS_Dict.clear()   # Clear the AT_CS_Dict before calling ProcessMessages
    AT_TS_Dict.clear()   # Clear the AT_TS_Dict before calling ProcessMessages
    AT_VS_Dict.clear()   # Clear the AT_VS_Dict before calling ProcessMessages
    AT_cm_Dict.clear()   # Clear the AT_cm_Dict before calling ProcessMessages
    DBC_dict.clear()
    TS.clear()
    CS.clear()
    VS.clear()
    struct_list.clear()
    AT_list.clear()
    DBC_list.clear()
    CM_list.clear()
    Rx_list.clear()
    Tx_list.clear()
    runnable.clear()
    Rx_list_RTE.clear()
    signal_dict.clear()
    asil_dict.clear()
    qm_dict.clear()
    asil_list.clear()
    qm_list.clear()
    asil_tx_list.clear()
    qm_tx_list.clear()

    folder_path_output = 'Temp_Delta/'+userId+'/Output/'
    os.makedirs(folder_path_output, exist_ok=True)
    file_list = os.listdir(folder_path_output)

    for file_name in file_list:
        file_path = os.path.join(folder_path_output, file_name)
        try:
            os.remove(file_path)
            #print(f"Deleted file: {file_name}")
        except Exception as e:
            print(f"Error while deleting {file_name}: {e}")

    #db_Data= cantools.database.load_file('data-mahesh-input/PAG_IPB_Int_CAN_Matrix_V1_9_1.dbc')
    db_Data= cantools.database.load_file(dbc_path)

    with open(dbc_path, 'r', encoding='ISO-8859-1') as dbc_file:
        dbc_contents_txt = dbc_file.read()
        for message in db_Data.messages:
            message_name = message.name
            signal_names = [signal.name for signal in message.signals]
            signal_dict[message_name] = signal_names
    for message_name, signal_names in signal_dict.items():
        has_asil_signal = any(signal_name.endswith("CRC") or signal_name.endswith("BZ") for signal_name in signal_names)
        if has_asil_signal:
            asil_dict[message_name] = signal_names
        else:
            qm_dict[message_name] = signal_names
    
    asil_list.extend(asil_dict.keys()) 
    qm_list.extend(qm_dict.keys())

    for element in asil_list:
        asil_tx_element = element + ":"
        lines = dbc_contents_txt.split('\n')
        for line in lines:
            if asil_tx_element in line and line.strip().endswith("IPB"):
                asil_tx_list.append(element)
    
    asil_rx_list = [element for element in asil_list if element not in asil_tx_list]

    for element in qm_list:
        qm_tx_element = element + ":"
        lines = dbc_contents_txt.split('\n')
        for line in lines:
            if qm_tx_element in line and line.strip().endswith("IPB"):
                qm_tx_list.append(element)
    
    qm_rx_list = [element for element in qm_list if element not in qm_tx_list]
    
    original_stdout = sys.stdout

    for msg in db_Data.messages:
        for sig in msg.signals:
            if sig.maximum==None:#can apply filter for msgs which have non-1 factor or non-zero offset
                DBC_dict[sig.name]=[sig.scale,0,sig.initial,sig.offset]
            else:
                DBC_dict[sig.name]=[sig.scale,round(sig.maximum/sig.scale),sig.initial,sig.offset]
            DBC_list.append(sig.name)

            if str(sig.name).startswith('TS_'):
                if sig.maximum==None:
                    TS_Dict[sig.name]=[sig.scale,0,sig.initial,sig.offset]
                else:
                    TS_Dict[sig.name]=[sig.scale,round(sig.maximum/sig.scale),sig.initial,sig.offset]
                TS.append(sig.name)
                
            elif str(sig.name).startswith('CS_'):
                if sig.maximum==None:
                    CS_Dict[sig.name]=[sig.scale,0,sig.initial,sig.offset]
                else:
                    CS_Dict[sig.name]=[sig.scale,round(sig.maximum/sig.scale),sig.initial,sig.offset]
                CS.append(sig.name)

            elif str(sig.name).startswith('VS_'):
                if sig.maximum==None:
                    VS_Dict[sig.name]=[sig.scale,0,sig.initial,sig.offset]
                else:
                    VS_Dict[sig.name]=[sig.scale,round(sig.maximum/sig.scale),sig.initial,sig.offset]
                VS.append(sig.name)

    tree = ET.parse(fpath)
    root = tree.getroot()
    ns = {'ns':'http://autosar.org/schema/r4.0'}
    val,var,count,buffer_var,struct_var=0,0,0,0,0
    data_typ,array_typ,structr_list=[],[],[]
    data_typ.clear()
    array_typ.clear()
    structr_list.clear()
    my_list_de= []
    my_list_de.clear()
    data_type=['sint16','uint16','uint8']
    at_cnt,buf_at,cm_var_num,compu,cm_var=0,0,0,0,0

    for arpackage in tree.iter():
        if 'SHORT-NAME' in arpackage.tag:

            if arpackage.text.startswith('CM_'):
                if arpackage.text.split('CM_')[1] in DBC_list: #will it miss the messages which start with CM_?if thats msg has a Compu method, then it wont be missed.
                    CM_list.append(arpackage.text) #will take all the compu methods(with signal name) if the signal name is in dbc.
                    cm_var=1
                    cm_name=arpackage.text
        if cm_var_num==1:
            AT_cm_Dict[cm_name]=[arpackage.text] #only those computation methods which have outputfactor/offset 
            cm_var_num=2
        elif cm_var_num==2:
            AT_cm_Dict[cm_name].append(arpackage.text)
            cm_var_num=0
        if cm_var==1 and 'COMPU-NUMERATOR' in arpackage.tag : # there shouldnt be a short name before compu numerator
            cm_var_num=1
    cm_var=0
    cm_var_num=0
    for arpackage in tree.iter():
        if count==1:
            if 'SHORT-NAME' in arpackage.tag and struct_var!=1:
                if arpackage.text not in data_type :
                    if buffer_var==0:
                        buffer_var=1
                    else:
                        data_typ.append(buffer)#stores the signals which are not part of any structure, these will have it_, rte_read and rte_write based on rec_r and send_p
                    buffer=arpackage.text #storing the text of previous iteration helps to identify if structure or array in present iteration.
            elif 'SHORT-NAME' in arpackage.tag and struct_var==1:
                structr_list.append(arpackage.text)

            elif arpackage.text =="STRUCTURE" and buffer_var==1:
                struct_dict[buffer]=structr_list
                struct_var=1
            elif arpackage.text =="ARRAY" and buffer_var==1:
                array_typ.append(buffer)
                buffer_var=0
            elif 'IMPLEMENTATION-DATA-TYPE' in arpackage.tag and ('IMPLEMENTATION-DATA-TYPE-' not in arpackage.tag) and  struct_var==1:#start looking for new str(msg)
                struct_var=0
                buffer_var=0
                structr_list=[]
            elif 'AR-PACKAGE' in arpackage.tag:
                count=0
        if buf_at==1:
            if 'TYPE-TREF' in arpackage.tag:
                if sig_name.startswith("CS_"):
                    AT_CS_Dict[sig_name]=(arpackage.text).split('DataTypes/')[1] #contains volt str signals whose AT is mentioned in typeref under str's AT
                elif sig_name.startswith("VS_"):
                    AT_VS_Dict[sig_name]=(arpackage.text).split('DataTypes/')[1]#their compu_methods are not same as sig name
                elif sig_name.startswith("TS_"):
                    AT_TS_Dict[sig_name]=(arpackage.text).split('DataTypes/')[1]
                    
                AT_list.append((arpackage.text).split('DataTypes/')[1])
                
                buf_at=0
            elif 'SHORT-NAME' in arpackage.tag:#there was a structure element of AT_structure but the element does not have type-ref or short name comes before typeref 
                buf_at=0
        if compu==1:
            if 'SHORT-NAME' in arpackage.tag :
                if arpackage.text.startswith('CM_'):#len(arpackage.text.split('CM_'))>1 ///  collects CM which do not have signal names. is there a possibility some signals' AT is different and its CM is mentioned before ApplicationDataTypes
                    if 'AT_'+arpackage.text.split('CM_')[1] in AT_list and (('Voltage' in arpackage.text) or('Current' in arpackage.text) or('Temp' in arpackage.text)) :
                        cm_var=1#do i need to make this 0(or compu 0) when applicationdatatypes start again?
                        cm_name=arpackage.text
        
        if cm_var_num==1:
            AT_cm_Dict[cm_name]=[arpackage.text]
            cm_var_num=2
        elif cm_var_num==2:
            AT_cm_Dict[cm_name].append(arpackage.text)
            cm_var_num=0
        if cm_var==1 and 'COMPU-NUMERATOR' in arpackage.tag :
            cm_var_num=1 
        
        if 'SHORT-NAME' in arpackage.tag and at_cnt==1 and buf_at==0:#if any AT starts with CS...then buf_at=1, and if type-ref is not found, and another short name comes(buf_at =0), this if condition will run again
            if (arpackage.text)=='CompuMethods':
                compu=1
                at_cnt=0
            if (arpackage.text).startswith("CS_"):#if conditions for ATs which do not start with AT_(basically for structure elements, their ATs are different)
                buf_at=1
            elif (arpackage.text).startswith("TS_"):
                buf_at=1
            elif (arpackage.text).startswith("VS_")  :
                buf_at=1
            elif (arpackage.text).startswith("AT_"):#takes the AT mentioned in the beginning as well as later(earlier script took only AT_TS )
                AT_list.append(arpackage.text)
            else:
                buf_at=0
            sig_name=arpackage.text
            
        if arpackage.text=='ImplementationDataTypes': #all messages' and signals' names are extracted from ImpDatatypes
            count=1
            at_cnt=0
        if arpackage.text=='ApplicationDataTypes':
            at_cnt=1
            count=0
        if var==1:
            var=0
            runnable.append(arpackage.text)
        if 'RUNNABLE-ENTITY' in arpackage.tag:
            var=1
    #print(data_typ,'\n'+str(len(data_typ)))
    imp_dt=[]
    map_dict=dict()
    
    for i in struct_dict:
        struct_list.append(i)
        imp_dt+=struct_dict[i]
        for j in struct_dict[i]:
            map_dict[j]=i
    for i in data_typ:
        imp_dt+=i
    
    del var    
    for i in runnable:
        if 'Init' in i:
            Init_run=i
        elif 'Tx' in i:
            Tx_run=i
        elif 'Rx' in i:
            Rx_run=i
               
    for arpackage in tree.iter():
        if str(arpackage.text)==Rx_run:
            val=1
        elif str(arpackage.text)==Tx_run:
            val=2
        if val==1:
            if str(arpackage.text).startswith("SEND_P"):
                Rx_list.append(arpackage.text)
            elif str(arpackage.text).startswith("REC_R"):
                Rx_list.append(arpackage.text)               
        elif val==2:
            if str(arpackage.text).startswith("SEND_P"):
                Tx_list.append(arpackage.text)
            elif str(arpackage.text).startswith("REC_R"):
                Tx_list.append(arpackage.text)
    
    def cfileVariablePrint():
        for element in asil_rx_list:
             fc.write('static VAR(boolean, intcanhl_asil_VAR_NOINIT) INTCANHL_mg_bErrStatus_TO_'+element+';\n')
             fc.write('static VAR(boolean, intcanhl_asil_VAR_NOINIT) INTCANHL_mg_bErrStatus_BZ_'+element+';\n')
             fc.write('static VAR(boolean, intcanhl_asil_VAR_NOINIT) INTCANHL_mg_bErrStatus_CRC_'+element+';\n')
             fc.write('static VAR(boolean, intcanhl_asil_VAR_NOINIT) INTCANHL_mg_bRte_isUpdated_'+element+';\n')
             fc.write('static VAR(uint8, intcanhl_asil_VAR_NOINIT) '+element+'_BZ_INTCANHLASIL_mg_u8OldBZ;\n')
             fc.write('static VAR(uint8, intcanhl_asil_VAR_NOINIT) INTCANHL_mg_u8'+element+'_BZ_Cntr;\n')
             fc.write('static VAR(uint8, intcanhl_asil_VAR_NOINIT) INTCANHL_mg_u8'+element+'_TO_Cntr;\n')
             fc.write('static VAR(uint8, intcanhl_asil_VAR_NOINIT) INTCANHL_mg_u8E2E_Qualifier_'+element+';\n')
             fc.write('static VAR(uint8, intcanhl_asil_VAR_NOINIT) INTCANHL_mg_u8'+element+'_CRC_Cntr;\n\n')
        
        for element in asil_tx_list:
             fc.write('static VAR(uint8, intcanhl_asil_VAR_NOINIT) '+element+'_old_BZ;\n')
             fc.write('static VAR(uint8, intcanhl_asil_VAR_NOINIT) '+element+'_current_BZ;\n')
             fc.write('static VAR(uint8, intcanhl_asil_VAR_NOINIT) '+element+'_Cal_CRC_Value;\n\n')

    def cfile(list_iter,elemen):
        fc.write('\tfloat In_factor;\n\tfloat Out_factor;\n\tfloat In_offset;\n\tfloat Out_offset;\n\tfloat Converted_data;\n\tboolean CRC_Value_check;\n\n')

        for element in asil_rx_list:
             fc.write('\tIT_'+element+'  DE_IntCan_'+element+';\n')
             fc.write('\tIT_SG_'+element+'  DE_SG_'+element+';\n')
        for element in asil_rx_list:
             fc.write(f'\tStd_ReturnType retValue_{element};\n')
        
        if elemen==1:
            pass
        elif elemen==2:
            fc.write('\tfloat In_factor = 0.0f;\n\tfloat Out_factor = 0.0f;\n\tfloat In_offset = 0.0f;\n\tfloat Out_offset = 0.0f;\n\tfloat Converted_data = 0.0f;\n\tfloat Out_data = 0.0f;\n\n')

        fc.write('\n\tboolean Enable_value;\n\tmg_u8CycleCnt_100ms++;\n')

        for element in list_iter:
            if element.startswith("REC_R"):
                if "Status_status" in element:
                    buffer_list = element.split('Status_')
                    if len(buffer_list) >= 2:
                        fc.write(f'\n\tRte_Read_R_IntCanReq_{buffer_list[1]}(&tIntCanReq_Status);\n')
        if elemen==1:
            for element in asil_rx_list:
                buffer_var='IT_'+element
                new_list1 = asil_dict.get(element, [])
                for i in range(len(new_list1)):
                    if new_list1[i].endswith('BZ'):
                        bz_variable = new_list1[i]
                    elif new_list1[i].endswith('CRC'):
                        crc_variable = new_list1[i]

                if element in ['HV_Measure_01', 'DCDC_Measure', 'HTB_Measure_01', 'HTB_Measure_02', 'HV_Measure_00']:
                
                    fc.write('\n\t/*==================================== '+element+' ========================================*/\n')
                    fc.write('\n\tif (Enable_value)\n\t{\n\t\tif (CYCLE_TIME_100MS < mg_u8CycleCnt_100ms)\n\t\t{\n\t\t\tINTCANHL_mg_bRte_isUpdated_'+element+' = Rte_IsUpdated_R_SG_' +element+'_DE_SG_'+element+'();\n\n')
                    fc.write('\t\t\t/*checking RTE update using Enable update */\n')
                    fc.write('\t\t\tif (FALSE != INTCANHL_mg_bRte_isUpdated_'+element+')\n\t\t\t{\n\t\t\t\tretValue_'+element+' = Rte_Read_R_SG_'+element+'_DE_SG_'+element+'(&DE_SG_'+element+');\n')
                    fc.write('\n\t\t\t\tif (RTE_E_OK == retValue_'+element+')\n\t\t\t\t{\n')
                    fc.write('\t\t\t\t\tuint8 '+element+'_Value_CRC;\n\t\t\t\t\tStd_ReturnType '+element+'_CRC_RetVal;\n\t\t\t\t\t'+element+'_CRC_RetVal = INTCANHL_ASIL_CALCCRC_'+element+'(&DE_SG_'+element+',&'+element+'_Value_CRC);\n\n\t\t\t\t\t/*checking Recieved CRC and Calculated CRC*/\n\n\t\t\t\t\tCRC_Value_check = (DE_SG_'+element+'.'+crc_variable+' != '+element+'_Value_CRC);')
                    fc.write('\n\t\t\t\t\tINTCANHLASIL_mg_u8OldBZ = '+element+'_BZ_INTCANHLASIL_mg_u8OldBZ;\n')
                    fc.write('\n\t\t\t\t\t/*Timeout checking with the help message counter(BZ)*/\n')
                    fc.write('\n\t\t\t\t\tif (!(CRC_Value_check))\n\t\t\t\t\t{\n\t\t\t\t\t\tif (DE_SG_'+element+'.'+bz_variable+' == INTCANHLASIL_mg_u8OldBZ)\n\t\t\t\t\t\t{\n\t\t\t\t\t\t\tif (INTCANHL_mg_u8'+element+'_TO_Cntr < Debounce_Time_C)\n\t\t\t\t\t\t\t{\n\t\t\t\t\t\t\t\tINTCANHL_mg_u8'+element+'_TO_Cntr++;\n\t\t\t\t\t\t\t\tINTCANHL_mg_bErrStatus_TO_'+element+' = FALSE;\n\t\t\t\t\t\t\t}\n\t\t\t\t\t\t\telse\n\t\t\t\t\t\t\t{\n\t\t\t\t\t\t\t\tINTCANHL_mg_bErrStatus_TO_'+element+' = TRUE;\n\t\t\t\t\t\t\t}\n\t\t\t\t\t\t}\n')
                    fc.write('\t\t\t\t\t\telse\n\t\t\t\t\t\t{\n\t\t\t\t\t\t\tINTCANHL_mg_u8'+element+'_TO_Cntr = 0;\n\t\t\t\t\t\t\tINTCANHL_mg_bErrStatus_TO_'+element+' = FALSE;\n\t\t\t\t\t\t}\n')
                    fc.write('\n\t\t\t\t\t\t/*Message Counter Verification*/\n')
                    fc.write('\n\t\t\t\t\t\tif (DE_SG_'+element+'.'+bz_variable+' > INTCANHLASIL_mg_u8OldBZ)\n\t\t\t\t\t\t{\n\t\t\t\t\t\t\tINTCANHL_mg_u8DiffBZ = (DE_SG_'+element+'.'+bz_variable+' - INTCANHLASIL_mg_u8OldBZ);\n\t\t\t\t\t\t}')
                    fc.write('\n\t\t\t\t\t\telse\n\t\t\t\t\t\t{\n\t\t\t\t\t\t\tINTCANHL_mg_u8sum_value = DE_SG_'+element+'.'+bz_variable+';\n\t\t\t\t\t\t\tINTCANHL_mg_u8sum_value = INTCANHL_mg_u8sum_value + BZ_ERR_CHECK;\n\t\t\t\t\t\t\tINTCANHL_mg_u8DiffBZ = INTCANHL_mg_u8sum_value - INTCANHLASIL_mg_u8OldBZ;\n\t\t\t\t\t\t}\t\t\t\t\t\t\n')
                    fc.write('\t\t\t\t\t\tif (INTCANHL_mg_u8DiffBZ != Max_Skip_Allowed_C)\n\t\t\t\t\t\t{\n\t\t\t\t\t\t\tif (INTCANHL_mg_u8'+element+'_BZ_Cntr < Debounce_Time_C)\n\t\t\t\t\t\t\t{\n\t\t\t\t\t\t\t\tINTCANHL_mg_u8'+element+'_BZ_Cntr++;\n\t\t\t\t\t\t\t\tINTCANHL_mg_bErrStatus_BZ_'+element+' = FALSE;\n\t\t\t\t\t\t\t}\n\t\t\t\t\t\t\telse\n\t\t\t\t\t\t\t{\n\t\t\t\t\t\t\t\tINTCANHL_mg_bErrStatus_BZ_'+element+' = TRUE;\n\t\t\t\t\t\t\t}\n\t\t\t\t\t\t}\n')
                    fc.write('\t\t\t\t\t\telse\n\t\t\t\t\t\t{\n\t\t\t\t\t\t\tINTCANHL_mg_u8'+element+'_BZ_Cntr = 0;\n\t\t\t\t\t\t}\n\t\t\t\t\t}\n')
                    fc.write('\t\t\t\t\tif (CRC_Value_check)\n\t\t\t\t\t{\n\t\t\t\t\t\tif (INTCANHL_mg_u8'+element+'_CRC_Cntr < Debounce_Time_C)\n\t\t\t\t\t\t{\n\t\t\t\t\t\t\tINTCANHL_mg_u8'+element+'_CRC_Cntr++;\n\t\t\t\t\t\t\tINTCANHL_mg_bErrStatus_CRC_'+element+' = FALSE;\n\t\t\t\t\t\t}\n')
                    fc.write('\t\t\t\t\t\telse\n\t\t\t\t\t\t{\n\t\t\t\t\t\t\tINTCANHL_mg_bErrStatus_CRC_'+element+' = TRUE;\n\t\t\t\t\t\t}\n\t\t\t\t\t}')
                    fc.write('\n\t\t\t\t\telse\n\t\t\t\t\t{\n\t\t\t\t\t\tINTCANHL_mg_u8'+element+'_CRC_Cntr = 0;\n\t\t\t\t\t\tINTCANHL_mg_bErrStatus_CRC_'+element+' = FALSE;\n\t\t\t\t\t}\n')
                    fc.write('\n\t\t\t\t\t/*Storing BZ value for Next Cycle */\n')
                    fc.write('\n\t\t\t\t\t'+element+'_BZ_INTCANHLASIL_mg_u8OldBZ = DE_SG_'+element+'.'+bz_variable+';\n')
                    fc.write('\n\t\t\t\t\tif ((FALSE != INTCANHL_mg_bErrStatus_CRC_'+element+') || (FALSE != INTCANHL_mg_bErrStatus_BZ_'+element+') || (FALSE != INTCANHL_mg_bErrStatus_TO_'+element+'))\n\t\t\t\t\t{\n\t\t\t\t\t\tINTCANHL_mg_u8E2E_Qualifier_'+element+' = CM_INTCAN_QUALIFIER_ERROR;\n\t\t\t\t\t}\n')
                    fc.write('\t\t\t\t\telse\n\t\t\t\t\t{\n\t\t\t\t\t\tif ((0u != INTCANHL_mg_u8'+element+'_TO_Cntr) || (0u != INTCANHL_mg_u8'+element+'_BZ_Cntr) || (0u != INTCANHL_mg_u8'+element+'_CRC_Cntr))\n\t\t\t\t\t\t{\n\t\t\t\t\t\t\tINTCANHL_mg_u8E2E_Qualifier_'+element+' = CM_INTCAN_QUALIFIER_DEB;\n\t\t\t\t\t\t}\n')
                    fc.write('\t\t\t\t\t\telse\n\t\t\t\t\t\t{\n\t\t\t\t\t\t\tINTCANHL_mg_u8E2E_Qualifier_'+element+' = CM_INTCAN_QUALIFIER_OK;\n\t\t\t\t\t\t}\n\t\t\t\t\t}\n\t\t\t\t}\n')
                    fc.write('\n\t\t\t}\n\t\t\telse\n\t\t\t{\n\t\t\t\tINTCANHL_mg_u8E2E_Qualifier_'+element+' = CM_INTCAN_QUALIFIER_INIT;\n\t\t\t}\n\t\t\tmg_u8CycleCnt_100ms = 0;\n\t\t}\n')
                    fc.write('\t\telse\n\t\t{\n\t\t\tINTCANHL_mg_u8E2E_Qualifier_'+element+' = CM_INTCAN_QUALIFIER_DEB;\n\t\t}\n\n')                   
                    fc.write('\t\t/* Assigning data to the output data element */\n')   
                    # fc.write('\n\t\tDE_IntCan_'+element+'.Qualifier = INTCANHL_mg_u8E2E_Qualifier_'+element+';\n\n')

                elif element.startswith('LVDC_SafetyMeasure'):
                    fc.write('\n\tif (CM_ENABLE_ENABLE == tIntCanReq_Status)\n\t{\n\t\tEnable_value = 1;\n\t}\n\telse \n\t{\n\t\tEnable_value = 0;\n\t}\n')
                    fc.write('\n\t/*==================================== '+element+' ========================================*/\n')
                    fc.write('\n\tif (Enable_value)\n\t{\n\t\t/*checking RTE update using Enable update */\n\t\tINTCANHL_mg_bRte_isUpdated_'+element+' = Rte_IsUpdated_R_SG_' +element+'_DE_IntCan_SG_'+element+'();\n\n')
                    fc.write('\t\tif (FALSE != INTCANHL_mg_bRte_isUpdated_'+element+')\n\t\t{\n\t\t\tretValue_'+element+' = Rte_Read_R_SG_'+element+'_DE_IntCan_SG_'+element+'(&DE_SG_'+element+');\n')
                    process_element(element, crc_variable, bz_variable)

                else:
                    fc.write('\n\t/*==================================== '+element+' ========================================*/\n')
                    fc.write('\n\tif (Enable_value)\n\t{\n\t\t/*checking RTE update using Enable update */\n\t\tINTCANHL_mg_bRte_isUpdated_'+element+' = Rte_IsUpdated_R_SG_' +element+'_DE_SG_'+element+'();\n\n')
                    fc.write('\t\tif (FALSE != INTCANHL_mg_bRte_isUpdated_'+element+')\n\t\t{\n\t\t\tretValue_'+element+' = Rte_Read_R_SG_'+element+'_DE_SG_'+element+'(&DE_SG_'+element+');\n')
                    process_element(element, crc_variable, bz_variable)

                for x in asil_dict[element]:
                    if x in CS:
                        if CS_Dict[x][0]!=1 : 
                            try:
                                # fc.write('\t\thiii01')
                                fc.write('\t\tIn_factor = '+str(float(CS_Dict[x][0]))+'f;\n\t\tOut_factor = '+str(float(AT_cm_Dict['CM_'+x][1]))+'f;\n\t\tIn_offset = '+str(float(CS_Dict[x][3]))+'f;\n\t\tOut_offset = '+str(float(AT_cm_Dict['CM_'+x][0]))+'f;\n\n')
                            except:#signals which have CM_some other name than signal
                                fc.write('\t\tIn_factor = '+str(float(CS_Dict[x][0]))+'f;\n\t\tOut_factor = '+str(float(AT_cm_Dict['CM_'+AT_CS_Dict[x].split('AT_')[1]][1]))+'f;\n\t\tIn_offset = '+str(float(CS_Dict[x][3]))+'f;\n\t\tOut_offset = '+str(float(AT_cm_Dict['CM_'+AT_CS_Dict[x].split('AT_')[1]][0]))+'f;\n\n')
                                # fc.write('\t\thiii02')
                            fc.write('\t\tif (DE_SG_'+element+'.'+x+' < INTCANHL_MAX_VALUE_'+x.upper()+') \n\t\t{\n\t\t\tif (DE_SG_'+element+'.'+x+' == INTCANHL_INIT_VALUE_'+x.upper()+') \n\t\t\t{\n\t\t\t\tDE_IntCan_'+element+'.'+x+' = '+str(CS_list_factor[str(CS_Dict[x][0])][0])+';\n\t\t\t}\n\t\t\telse\n\t\t\t{\n\t\t\t\tConverted_data = ((DE_SG_'+element+'.'+x+' * In_factor) + In_offset);\n\n\t\t\t\tDE_IntCan_'+element+'.'+x+' = ((Converted_data - Out_offset) / Out_factor);\n\t\t\t}\n\t\t}\n\t\telse\n\t\t{\n\t\t\tDE_IntCan_'+element+'.'+x+' = '+str(CS_list_factor[str(CS_Dict[x][0])][1])+';\n\t\t}\n\n')
                            # fc.write('\t\thiii03')
                        else:
                            if x.endswith('BZ'):
                                pass
                            elif x.endswith('CRC') :
                                fc.write('\t\tDE_IntCan_'+element+'.Qualifier = INTCANHL_mg_u8E2E_Qualifier_'+element+';\n\n')
                                # fc.write('\t\thiii04')
                            else:
                                fc.write('\t\tDE_IntCan_'+element+'.'+x+' = DE_SG_'+element+'.'+x+';\n\n') 
                                # fc.write('\t\thiii05')                                     
                            
                    elif x in VS:
                        if VS_Dict[x][0]!=1:
                            try:
                                fc.write('\t\tIn_factor = '+str(float(VS_Dict[x][0]))+'f;\n\t\tOut_factor = '+str(float(AT_cm_Dict['CM_'+x][1]))+'f;\n\t\tIn_offset = '+str(float(VS_Dict[x][3]))+'f;\n\t\tOut_offset = '+str(float(AT_cm_Dict['CM_'+x][0]))+'f;\n\n')
                                # fc.write('\t\thiii06')
                            except:
                                fc.write('\t\tIn_factor = '+-str(float(VS_Dict[x][0]))+'f;\n\t\tOut_factor = '+str(float(AT_cm_Dict['CM_'+AT_VS_Dict[x].split('AT_')[1]][1]))+'f;\n\t\tIn_offset = '+str(float(VS_Dict[x][3]))+'f;\n\t\tOut_offset = '+str(float(AT_cm_Dict['CM_'+AT_VS_Dict[x].split('AT_')[1]][0]))+'f;\n\n')
                                # fc.write('\t\thiii07')
                            fc.write('\t\tif (DE_SG_'+element+'.'+x+' < INTCANHL_MAX_VALUE_'+x.upper()+') \n\t\t{\n\t\t\tif (DE_SG_'+element+'.'+x+' == INTCANHL_INIT_VALUE_'+x.upper()+') \n\t\t\t{\n\t\t\t\tDE_IntCan_'+element+'.'+x+' = '+str(VS_list_factor[str(VS_Dict[x][0])][0])+';\n\t\t\t}\n\t\t\telse\n\t\t\t{\n\t\t\t\tConverted_data = ((DE_SG_'+element+'.'+x+' * In_factor) + In_offset);\n\n\t\t\t\tDE_IntCan_'+element+'.'+x+' = ((Converted_data - Out_offset) / Out_factor);\n\t\t\t}\n\t\t}\n\t\telse\n\t\t{\n\t\t\tDE_IntCan_'+element+'.'+x+' = '+str(VS_list_factor[str(VS_Dict[x][0])][1])+';\n\t\t}\n\n')
                            # fc.write('\t\thiii08')
                            
                        else:
                            if x.endswith('BZ'):
                                pass
                            elif x.endswith('CRC') :
                                fc.write('\t\tDE_IntCan_'+element+'.Qualifier = INTCANHL_mg_u8E2E_Qualifier_'+element+';\n\n')
                                # fc.write('\t\thiii09')
                            else:
                                fc.write('\t\tDE_IntCan_'+element+'.'+x+' = DE_SG_'+x+';\n\n')
                                # fc.write('\t\thiii10')
                            
                    elif x in TS:
                        if TS_Dict[x][0]==1:
                            # fc.write('\t\thiii11')
                            fc.write('\t\tIn_factor = '+str(float(TS_Dict[x][0]))+'f;\n\t\tOut_factor = '+str(float(AT_cm_Dict['CM_'+x][1]))+'f;\n\t\tIn_offset = '+str(float(TS_Dict[x][3]))+'f;\n\t\tOut_offset = '+str(float(AT_cm_Dict['CM_'+x][0]))+'f;\n\n')
                            fc.write('\t\tif (DE_SG_'+element+'.'+x+' < INTCANHL_MAX_VALUE_'+x.upper()+') \n\t\t{\n\t\t\tif (DE_SG_'+element+'.'+x+' == INTCANHL_INIT_VALUE_'+x.upper()+') \n\t\t\t{\n\t\t\t\tDE_IntCan_'+element+'.'+x+' = '+str(TS_list_factor[str(TS_Dict[x][0])][0])+';\n\t\t\t}\n\t\t\telse\n\t\t\t{\n\t\t\t\tConverted_data = ((DE_SG_'+element+'.'+x+' * In_factor) + In_offset);\n\n\t\t\t\tDE_IntCan_'+element+'.'+x+' = ((Converted_data - Out_offset) / Out_factor);\n\t\t\t}\n\t\t}\n\t\telse\n\t\t{\n\t\t\tDE_IntCan_'+element+'.'+x+' = '+str(TS_list_factor[str(TS_Dict[x][0])][1])+';\n\t\t}\n\n')
                        else:
                            if x.endswith('BZ'):
                                pass
                            elif x.endswith('CRC') :
                                fc.write('\t\tDE_IntCan_'+element+'.Qualifier = INTCANHL_mg_u8E2E_Qualifier_'+element+';\n\n')
                                # fc.write('\t\thiii2')
                            else:
                                fc.write('\t\tDE_IntCan_'+element+'.'+x+' = DE_SG_'+x+';\n\n')
                                # fc.write('\t\thiii13')
                            
                    elif x in DBC_list:
                        if (DBC_dict[x][0]==1 and DBC_dict[x][3]==0):
                            
                            if element.startswith('DCDC') or element.startswith('HTB'):
                                if x.endswith('BZ'):
                                    pass
                                elif x.endswith('CRC') :
                                    # fc.write('\t\thiii14')
                                    fc.write('\t\tDE_IntCan_'+element+'.Qualifier = INTCANHL_mg_u8E2E_Qualifier_'+element+';\n\n')
                                else:                                      
                                    fc.write('\t\tDE_IntCan_'+element+'.'+x+' = DE_SG_'+element+'.'+x+';\n\n')
                                    # fc.write('\t\thiii15')
                            else:
                                if x.endswith('BZ'):
                                    pass
                                elif x.endswith('CRC') :
                                    fc.write('\t\tDE_IntCan_'+element+'.Qualifier = INTCANHL_mg_u8E2E_Qualifier_'+element+';\n\n')
                                    # fc.write('\t\thiii16')
                                else:
                                    fc.write('\t\tDE_IntCan_'+element+'.'+x+' = DE_SG_'+element+'.'+x+';\n\n')
                                    # fc.write('\t\thiii17')
                            
                        else:
                            fc.write('\n\t\tIn_factor = '+str(float(DBC_dict[x][0]))+'f;\n\t\tOut_factor = '+str(float(AT_cm_Dict['CM_'+x][1]))+'f;\n\t\tIn_offset = '+str(float(DBC_dict[x][3]))+'f;\n\t\tOut_offset = '+str(float(AT_cm_Dict['CM_'+x][0]))+'f;\n\n')
                            fc.write('\t\tConverted_data = ((DE_IntCan_'+x+' * In_factor) + In_offset);\n\t\tDE_IntCan_'+element+'.'+x+' = ((Converted_data - Out_offset) / Out_factor);\n\n')
                fc.write('\t}\n\n\t/* Assigning Init values to the Port if the Intcanhl status not active*/\n\n\telse\n\t{\n')
                        
                for x in asil_dict[element]:
                    if x in CS:
                        if CS_Dict[x][0]!=1 and CS_Dict[x][0]!=0.5:
                            # fc.write('\t\thiii18')
                            fc.write('\t\tDE_IntCan_'+element+'.'+x+' = '+str(CS_list_factor[str(CS_Dict[x][0])][0])+';\n\n')
                        else:
                            if x.endswith('BZ') :
                                    pass
                            elif x.endswith('CRC')  or x.endswith('Qualifier') :
                                    # fc.write('\t\thiii19')
                                    fc.write('\t\tDE_IntCan_'+element+'.Qualifier = CM_INTCAN_QUALIFIER_INIT;\n\n')
                            else:
                                # fc.write('\t\thiii20')  
                                fc.write('\t\tDE_IntCan_'+element+'.'+x+' = 0;\n\n')
                    elif x in VS:
                        if VS_Dict[x][0]!=1 and VS_Dict[x][0]!=0.5:
                            # fc.write('\t\thiii20')
                            fc.write('\t\tDE_IntCan_'+element+'.'+x+' = '+str(VS_list_factor[str(VS_Dict[x][0])][0])+';\n\n')
                        else:
                            if x.endswith('BZ')  :
                                    pass
                            elif x.endswith('CRC')  or x.endswith('Qualifier'):
                                    # fc.write('\t\thiii21')
                                    fc.write('\t\tDE_IntCan_'+element+'.Qualifier = CM_INTCAN_QUALIFIER_INIT;\n\n')
                            else:  
                                fc.write('\t\tDE_IntCan_'+element+'.'+x+' = 0;\n\n')
                    elif x in TS:
                        if TS_Dict[x][0]==1:
                            # fc.write('\t\thiii22')
                            fc.write('\t\tDE_IntCan_'+element+'.'+x+' = '+str(TS_list_factor[str(TS_Dict[x][0])][0])+';\n\n')
                        else:
                            if x.endswith('BZ') :
                                    pass
                            elif x.endswith('CRC') or x.endswith('Qualifier'):
                                    fc.write('\t\thiii23')
                                    fc.write('\t\tDE_IntCan_'+element+'.Qualifier = CM_INTCAN_QUALIFIER_INIT;\n\n')
                            else:
                                # fc.write('\t\thiii24')  
                                fc.write('\t\tDE_IntCan_'+element+'.'+x+' = 0;\n\n')
                    else:
                        if element.startswith('LVDC_SafetyMeasure'):
                            if x.endswith('BZ') :
                                    pass
                            elif x.endswith('CRC')  or x.endswith('Qualifier'):
                                    # fc.write('\t\thiii25')
                                    fc.write('\t\tDE_IntCan_'+element+'.Qualifier = CM_INTCAN_QUALIFIER_INIT;\n\n')
                            else: 
                                # fc.write('\t\thiii26') 
                                fc.write('\t\tDE_IntCan_'+element+'.'+x+' = 0;\n\n')                                        
                        else:
                            if x.endswith('BZ') :
                                    pass
                            elif x.endswith('CRC') or x.endswith('Qualifier'):
                                    # fc.write('\t\thiii27')
                                    fc.write('\t\tDE_IntCan_'+element+'.Qualifier = CM_INTCAN_QUALIFIER_INIT;\n\n')
                            else:  
                                # fc.write('\t\thiii28')
                                fc.write('\t\tDE_IntCan_'+element+'.'+x+' = 0;\n\n')
                        
                fc.write('\t}\n')   

            for element in asil_rx_list:
                if element.startswith('LVDC') or element.startswith('HVDC'):
                    fc.write('\tRte_Write_P_'+element+'_IntCan_'+element+'((const IT_'+element+' *) &DE_IntCan_'+element+');\n')
                else:
                    fc.write('\tRte_Write_P_'+element+'_IntCan_DE_IntCan_'+element+'((const IT_'+element+' *) &DE_IntCan_'+element+');\n')
                                       
            fc.write('\tRte_Write_P_IntCAN_SrvState_active(Status_var);\n')
            fc.write('\n\tif (')
            if len(asil_rx_list) > 0:
                conditions = ' || \n\t\t'.join('(INTCANHL_mg_u8E2E_Qualifier_'+Rx+' == CM_INTCAN_QUALIFIER_ERROR)' for Rx in asil_rx_list)
                fc.write(conditions)
            fc.write(')\n')
            fc.write('\t{\n\t\tDemwrap_Appl_Write_error_intcanhl_asil_IntCan_E2E_Error(DT_ERRORSTATUS_FAILED);\n\t}')
            fc.write('\n\telse\n\t{\n\t\tDemwrap_Appl_Write_error_intcanhl_asil_IntCan_E2E_Error(DT_ERRORSTATUS_PASSED);\n\t}\n')
            fc.write('}\n\n')

    def crcfile(list_iter,elemen):
        if elemen==1:            
            for i in range(len(asil_tx_list)):
                fa.write(''+asil_tx_list[i]+' INTCANHL_ASIL_mg_au8'+asil_tx_list[i]+'[MG_DLC_'+asil_tx_list[i]+'];\n')

            for i in range(len(asil_rx_list)):
                if(asil_rx_list[i].endswith('OruStatus')):
                    pass
                else:
                    fa.write(''+asil_rx_list[i]+' INTCANHL_ASIL_mg_au8'+asil_rx_list[i]+'[MG_DLC_'+asil_rx_list[i]+'];\n')

            fa.write('\n#define intcanhl_asil_STOP_SEC_VAR_NOINIT_UNSPECIFIED\n#include "intcanhl_asil_MemMap.h"\n#define intcanhl_asil_START_SEC_CODE\n#include "intcanhl_asil_MemMap.h"\n\n')
            for rx_element in asil_rx_list:
                if(rx_element.endswith('OruStatus')):
                    pass
                else:
                    fa.write('Std_ReturnType INTCANHL_ASIL_CALCCRC_' + rx_element + '(IT_SG_' + rx_element + ' * DE_SG_' + rx_element + ', uint8 * ' + rx_element + '_Check_CRC)\n{\n')
                    fa.write('\tStd_ReturnType ret = E_NOT_OK;\n\tif ((NULL_PTR != ' + rx_element + '_Check_CRC) && (NULL_PTR != DE_SG_' + rx_element + '))\n\t{\n')
                    my_list = struct_dict.get('IT_SG_'+rx_element, [])
                    for item in my_list:
                        if(item.endswith('CRC')) :
                            pass
                        elif 'x' in item and any(c.isdigit() for c in item.split('x', 1)[1]):
                            continue  # Skip items containing 'x' followed by numeric characters
                        else:
                            fa.write('\t\tSet_' + item + '(DE_SG_' + rx_element + '->' + item + ');\n')

                    fa.write('\n\t\tret = INTCANHL_ASIL_u8CalculateCRC8(&INTCANHL_ASIL_mg_au8' + rx_element + '[1], MG_DLC, *' + rx_element + '_Check_CRC);\n\t}\n')
                    fa.write('\treturn (ret);\n}\n')

            for tx_element in asil_tx_list:
                fa.write('Std_ReturnType INTCANHL_ASIL_CALCCRC_' + tx_element + '(IT_' + tx_element + ' * DE_IntCan_' + tx_element + ', uint8 * ' + tx_element + '_Check_CRC)\n{\n')
                fa.write('\tStd_ReturnType ret = 0;\n\tif ((NULL_PTR != ' + tx_element + '_Check_CRC) && (NULL_PTR != DE_IntCan_' + tx_element + '))\n\t{\n')
                my_list = struct_dict.get('IT_SG_'+tx_element, [])
                for item in my_list:
                    if(item.endswith('CRC')) :
                        pass
                    elif 'x' in item and any(c.isdigit() for c in item.split('x', 1)[1]):
                        continue  # Skip items containing 'x' followed by numeric characters
                    else:
                        fa.write('\t\tSet_' + item + '(DE_IntCan_' + tx_element + '->' + item + ');\n')

                fa.write('\n\t\tret = INTCANHL_ASIL_u8CalculateCRC8(&INTCANHL_ASIL_mg_au8' + tx_element + '[1], MG_DLC, *' + tx_element + '_Check_CRC);\n\t}\n')
                fa.write('\treturn (ret);\n}\n')

    def cfilenew(list_iter,elemen):

        for element in asil_tx_list:
             fc.write('\tIT_'+element+'  DE_IntCan_'+element+';\n')
             fc.write('\tIT_SG_'+element+'  DE_SG_'+element+';\n')
        
        fc.write('\tIT_Enable status;\n')
        fc.write('\tIT_Active tIntCan_status;\n')
        fc.write('\n')

        for element in asil_tx_list:
             if element == 'HTB_CMD_02':
                 fc.write(f'\t(void)Rte_Read_R_{element}_IntCan_DE_{element}(&DE_IntCan_{element});\n')
             else:
                fc.write(f'\t(void)Rte_Read_R_{element}_IntCan_DE_IntCan_{element}(&DE_IntCan_{element});\n')
        
        for element in list_iter:
            if element.startswith("REC_R"):
                if "_OruStatus_DE_" in element:
                    buffer_list = element.split('_OruStatus_DE_')
                    if len(buffer_list) >= 2:
                        fc.write(f'\t(void)Rte_Read_R_{element[6:]}(&DE_{buffer_list[1]});\n') 
                        my_list_de.append(('DE_'+buffer_list[1]))
                elif "Status_" in element:
                    buffer_list = element.split('Status_')
                    if len(buffer_list) >= 2:
                        fc.write(f'\t(void)Rte_Read_R_{element[6:]}(&tIntCan_status);\n') 
                elif "HV_CMD_Vcc_18V_DRV_EN_" in element:
                    buffer_list = element.split('HV_CMD_Vcc_18V_DRV_EN_')
                    if len(buffer_list) >= 2:
                        fc.write(f'\t(void)Rte_Read_R_{element[6:]}(&{buffer_list[1]});\n')
                        
        fc.write('\n')

        if elemen==2:
            
            fc.write('\tif (tIntCan_status == CM_ACTIVE_ACTIVE)\n\t{\n')
            for element in asil_tx_list:
                fc.write('\t\tStd_ReturnType '+element+'_RetVal;\n')
            for element in asil_tx_list:
                fc.write('\t\tIT_'+element+' MG_Buff_'+element+';\n')
            
            for element in asil_tx_list:
                fc.write('\n\t\t/*==================================== '+element+' ========================================*/\n')
                fc.write('\n\t\t/*Message counter calculation*/\n')
                fc.write('\n\t\tif (('+element+'_old_BZ) >= MAX_VALUE_15)\n\t\t{\n\t\t\t'+element+'_current_BZ = 0;\n\t\t}\n\t\telse\n\t\t{\n\t\t\t'+element+'_current_BZ = (('+element+'_old_BZ)+ 1);\n\t\t}\n')
                fc.write('\n\t\t'+element+'_old_BZ = '+element+'_current_BZ;\n')
                new_list = struct_dict.get('IT_'+element, [])
                new_list2 = struct_dict.get('IT_SG_'+element, [])
                for i in range(len(new_list)):
                    
                    if new_list[i].endswith('BZ'):
                        fc.write('\t\tMG_Buff_'+element+'.'+new_list[i]+' = '+element+'_current_BZ;\n')
                    else:
                        fc.write('\t\tMG_Buff_'+element+'.'+new_list[i]+' = DE_IntCan_'+element+'.'+new_list[i]+';\n')
                
                fc.write('\n\t\t'+element+'_RetVal = INTCANHL_ASIL_CALCCRC_'+element+'(&MG_Buff_'+element+', &'+element+'_Cal_CRC_Value);\n\n')
                for i in range(len(new_list2)):
                    if new_list2[i].endswith('CRC'):
                        fc.write('\t\tDE_SG_'+element+'.'+new_list2[i]+' = '+element+'_Cal_CRC_Value;\n')
                    elif new_list2[i].endswith('BZ'):
                        fc.write('\t\tDE_SG_'+element+'.'+new_list2[i]+' = '+element+'_current_BZ;\n')
                    else:
                        fc.write('\t\tDE_SG_'+element+'.'+new_list2[i]+' = DE_IntCan_'+element+'.'+new_list2[i]+';\n')
                
                fc.write('\n\t\tRte_Write_P_SG_'+element+'_DE_SG_'+element+'((const IT_SG_'+element+' *)&DE_SG_'+element+');\n\n')

            fc.write('\t}\n') 
              
            fc.write('}\n\n')
     
    def cinit(list_init):
        for element in list_init:
            if element.startswith("SEND_P"):
                fc.write('DE_IntCan'+element[6:]+' = 0;\n')
            elif element.startswith("REC_R"): 
                 fc.write('DE_IntCan'+element[5:]+' = 0;\n')
    
    def process_element(element, crc_variable, bz_variable):
        fc.write('\n\t\t\tif (RTE_E_OK == retValue_'+element+')\n\t\t\t{')
        fc.write('\n\t\t\t\tuint8 '+element+'_Value_CRC;\n\t\t\t\tStd_ReturnType '+element+'_CRC_RetVal;\n\t\t\t\t'+element+'_CRC_RetVal = INTCANHL_ASIL_CALCCRC_'+element+'(&DE_SG_'+element+',&'+element+'_Value_CRC);\n\n\t\t\t\t/*checking Recieved CRC and Calculated CRC*/\n\n\t\t\t\tCRC_Value_check = (DE_SG_'+element+'.'+crc_variable+' != '+element+'_Value_CRC);')
        fc.write('\n\t\t\t\tINTCANHLASIL_mg_u8OldBZ = '+element+'_BZ_INTCANHLASIL_mg_u8OldBZ;\n')
        fc.write('\n\t\t\t\t/*Timeout checking with the help message counter(BZ)*/\n')
        fc.write('\n\t\t\t\tif (!(CRC_Value_check))\n\t\t\t\t{\n\t\t\t\t\tif (DE_SG_'+element+'.'+bz_variable+' == INTCANHLASIL_mg_u8OldBZ)\n\t\t\t\t\t{\n\t\t\t\t\t\tif (INTCANHL_mg_u8'+element+'_TO_Cntr < Debounce_Time_C)\n\t\t\t\t\t\t{\n\t\t\t\t\t\t\tINTCANHL_mg_u8'+element+'_TO_Cntr++;\n\t\t\t\t\t\t\tINTCANHL_mg_bErrStatus_TO_'+element+' = FALSE;\n\t\t\t\t\t\t}\n\t\t\t\t\t\telse\n\t\t\t\t\t\t{\n\t\t\t\t\t\t\tINTCANHL_mg_bErrStatus_TO_'+element+' = TRUE;\n\t\t\t\t\t\t}\n\t\t\t\t\t}\n')
        fc.write('\t\t\t\t\telse\n\t\t\t\t\t{\n\t\t\t\t\t\tINTCANHL_mg_u8'+element+'_TO_Cntr = 0;\n\t\t\t\t\t\tINTCANHL_mg_bErrStatus_TO_'+element+' = FALSE;\n\t\t\t\t\t}\n')
        fc.write('\n\t\t\t\t\t/*Message Counter Verification*/\n')
        fc.write('\n\t\t\t\t\tif (DE_SG_'+element+'.'+bz_variable+' > INTCANHLASIL_mg_u8OldBZ)\n\t\t\t\t\t{\n\t\t\t\t\t\tINTCANHL_mg_u8DiffBZ = (DE_SG_'+element+'.'+bz_variable+' - INTCANHLASIL_mg_u8OldBZ);\n\t\t\t\t\t}\n')
        fc.write('\t\t\t\t\telse\n\t\t\t\t\t{\n\t\t\t\t\t\tINTCANHL_mg_u8sum_value = DE_SG_'+element+'.'+bz_variable+';\n\t\t\t\t\t\tINTCANHL_mg_u8sum_value = INTCANHL_mg_u8sum_value + BZ_ERR_CHECK;\n\t\t\t\t\t\tINTCANHL_mg_u8DiffBZ = INTCANHL_mg_u8sum_value - INTCANHLASIL_mg_u8OldBZ;\n\t\t\t\t\t}\t\t\t\t\t\n')
        fc.write('\t\t\t\t\tif (INTCANHL_mg_u8DiffBZ != Max_Skip_Allowed_C)\n\t\t\t\t\t{\n\t\t\t\t\t\tif (INTCANHL_mg_u8'+element+'_BZ_Cntr < Debounce_Time_C)\n\t\t\t\t\t\t{\n\t\t\t\t\t\t\tINTCANHL_mg_u8'+element+'_BZ_Cntr++;\n\t\t\t\t\t\t\tINTCANHL_mg_bErrStatus_BZ_'+element+' = FALSE;\n\t\t\t\t\t\t}\n\t\t\t\t\t\telse\n\t\t\t\t\t\t{\n\t\t\t\t\t\t\tINTCANHL_mg_bErrStatus_BZ_'+element+' = TRUE;\n\t\t\t\t\t\t}\n\t\t\t\t\t}\n')
        fc.write('\t\t\t\t\telse\n\t\t\t\t\t{\n\t\t\t\t\t\tINTCANHL_mg_u8'+element+'_BZ_Cntr = 0;\n\t\t\t\t\t}\n\t\t\t\t}\n')
        fc.write('\t\t\t\tif (CRC_Value_check)\n\t\t\t\t{\n\t\t\t\t\tif (INTCANHL_mg_u8'+element+'_CRC_Cntr < Debounce_Time_C)\n\t\t\t\t\t{\n\t\t\t\t\t\tINTCANHL_mg_u8'+element+'_CRC_Cntr++;\n\t\t\t\t\t\tINTCANHL_mg_bErrStatus_CRC_'+element+' = FALSE;\n\t\t\t\t\t}\n')
        fc.write('\t\t\t\t\telse\n\t\t\t\t\t{\n\t\t\t\t\t\tINTCANHL_mg_bErrStatus_CRC_'+element+' = TRUE;\n\t\t\t\t\t}\n\t\t\t\t}')
        fc.write('\n\t\t\t\telse\n\t\t\t\t{\n\t\t\t\t\tINTCANHL_mg_u8'+element+'_CRC_Cntr = 0;\n\t\t\t\t\tINTCANHL_mg_bErrStatus_CRC_'+element+' = FALSE;\n\t\t\t\t}\n')
        fc.write('\n\t\t\t\t/*Storing BZ value for Next Cycle */\n')
        fc.write('\n\t\t\t\t'+element+'_BZ_INTCANHLASIL_mg_u8OldBZ = DE_SG_'+element+'.'+bz_variable+';\n')
        fc.write('\n\t\t\t\tif ((FALSE != INTCANHL_mg_bErrStatus_CRC_'+element+') || (FALSE != INTCANHL_mg_bErrStatus_BZ_'+element+') || (FALSE != INTCANHL_mg_bErrStatus_TO_'+element+'))\n\t\t\t\t{\n\t\t\t\t\tINTCANHL_mg_u8E2E_Qualifier_'+element+' = CM_INTCAN_QUALIFIER_ERROR;\n\t\t\t\t}')
        fc.write('\n\t\t\t\telse\n\t\t\t\t{\n\t\t\t\t\tif ((0u != INTCANHL_mg_u8'+element+'_TO_Cntr) || (0u != INTCANHL_mg_u8'+element+'_BZ_Cntr) || (0u != INTCANHL_mg_u8'+element+'_CRC_Cntr))\n\t\t\t\t\t{\n\t\t\t\t\t\tINTCANHL_mg_u8E2E_Qualifier_'+element+' = CM_INTCAN_QUALIFIER_DEB;\n\t\t\t\t\t}')
        fc.write('\n\t\t\t\t\telse\n\t\t\t\t\t{\n\t\t\t\t\t\tINTCANHL_mg_u8E2E_Qualifier_'+element+' = CM_INTCAN_QUALIFIER_OK;\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n')
        fc.write('\t\t\telse\n\t\t\t{\n\t\t\t\tINTCANHL_mg_u8E2E_Qualifier_'+element+' = CM_INTCAN_QUALIFIER_DEB;\n\t\t\t}\n\t\t}\n')
        fc.write('\n\t\t/* Assinging Init value for Qualifier if RTE not updated */\n')
        fc.write('\n\t\telse\n\t\t{\n\t\t\tINTCANHL_mg_u8E2E_Qualifier_'+element+' = CM_INTCAN_QUALIFIER_INIT;\n\t\t}\n\n')
        fc.write('\t\t/* Assigning data to the output data element */\n\n')

    fc=open(''+folder_path_output+'intcanhl_asil.c','w')
    fc.write('#ifndef INTCANHL_ASIL_C\n#define INTCANHL_ASIL_C\n\n')
    fc.write('#include "Rte_intcanhl_asil.h"\n#include "IntCanHL_ASIL_Measure.h"\n#include "IntCanHL_ASIL_Defines.h"\n#include "intcanhl_asil_calccrc.h"\n#include "demwrap_intcanhl_asil.h"\n#include "Rte_Type.h"\n\n')
    fc.write('#ifdef __cplusplus\nextern "C" {\n#endif\n\n')
    fc.write('#define intcanhl_asil_START_SEC_VAR_NOINIT_UNSPECIFIED\n#include "intcanhl_asil_MemMap.h"\n\n#define CYCLE_TIME_100MS 10u\n\n')
    
    fc.write('static VAR(uint8, intcanhl_asil_VAR_NOINIT) INTCANHLASIL_mg_u8OldBZ;\nstatic VAR(uint8, intcanhl_asil_VAR_NOINIT) INTCANHL_mg_u8DiffBZ;\nstatic VAR(uint8, intcanhl_asil_VAR_NOINIT) INTCANHL_mg_u8sum_value;\n\n')
    cfileVariablePrint()
    fc.write('static IT_Enable tIntCanReq_Status;\nstatic VAR(uint8, intcanhl_asil_VAR_NOINIT) mg_u8CycleCnt_100ms;\n')
    fc.write('\n#define intcanhl_asil_STOP_SEC_VAR_NOINIT_UNSPECIFIED\n#include "intcanhl_asil_MemMap.h"\n\n#define intcanhl_asil_START_SEC_CODE\n#include "intcanhl_asil_MemMap.h"\n')
    
    fc.write('\nFUNC(void, intcanhl_asil_CODE) '+Rx_run+'(void)\n{\n')
    cfile(Rx_list,1)

    fc.write('FUNC(void, intcanhl_asil_CODE) '+Tx_run+'(void)\n{\n')
    cfilenew(Tx_list,2)

    fc.write('FUNC(void, intcanhl_asil_CODE) '+Init_run+'(void)\n{\n')
    fc.write('\tINTCANHLASIL_mg_u8OldBZ = 0u;\n\tINTCANHL_mg_u8DiffBZ = 0u;\n\tINTCANHL_mg_u8sum_value = 0u;\n\n')
    for element in asil_rx_list:
             fc.write('\tINTCANHL_mg_bErrStatus_TO_'+element+' = 0u;\n')
             fc.write('\tINTCANHL_mg_bErrStatus_BZ_'+element+' = 0u;\n')
             fc.write('\tINTCANHL_mg_bErrStatus_CRC_'+element+' = 0u;\n')
             fc.write('\tINTCANHL_mg_u8'+element+'_BZ_Cntr = 0u;\n')
             fc.write('\tINTCANHL_mg_u8'+element+'_TO_Cntr = 0u;\n')
             fc.write('\tINTCANHL_mg_u8E2E_Qualifier_'+element+' = 0u;\n')
             fc.write('\tINTCANHL_mg_u8'+element+'_CRC_Cntr = 0u;\n\n')
    
    for element in asil_tx_list:
             fc.write('\t'+element+'_old_BZ = 0u;\n')
             fc.write('\t'+element+'_Cal_CRC_Value = 0u;\n\n')
        
    fc.write('}\n\n')
    fc.write('#ifdef __cplusplus\n}\n#endif\n\n#endif')
    fc.close()

    fa=open(''+folder_path_output+'intcanhl_asil_calccrc.c','w')
    fa.write('#ifndef INTCANHL_ASIL_CALCCRC_C\n#define INTCANHL_ASIL_CALCCRC_C\n\n#include "intcanhl_asil_calccrc.h"\n#include "intcanhl_asil_calccrc_cfg_dcdc.h"\n#include "intcanhl_asil_calccrc_cfg_hv.h"\n\n#ifdef __cplusplus\n')    
    fa.write('extern "C" {\n#endif\n')
    fa.write('#define MG_DLC 7u\n#define MG_DLC_1 6u\n\n#define intcanhl_asil_START_SEC_VAR_NOINIT_UNSPECIFIED\n#include "intcanhl_asil_MemMap.h"\n\n')    
    crcfile(Rx_list,1)
    fa.write('#ifdef __cplusplus\n}\n#endif\n\n#endif\n')
    fa.write('#define intcanhl_asil_STOP_SEC_CODE\n#include "intcanhl_asil_MemMap.h"\n')
    fa.close()

    fb=open(''+folder_path_output+'IntCanHL_ASIL_Measure.c','w')
    fb.write('#ifndef INTCANHL_ASIL_MEASURE_C\n#define INTCANHL_ASIL_MEASURE_C\n\n#include "IntCanHL_ASIL_Measure.h"\n\n') 
    fb.write('#ifdef __cplusplus\n')   
    fb.write('extern "C" {\n#endif\n\n')
    fb.write('CAL uint16 Debounce_Time_C = 3;\n\nCAL uint8 Max_Skip_Allowed_C = 1;\n\n')
    fb.write('#define intcanhl_asil_START_SEC_VAR_NOINIT_UNSPECIFIED\n#include "intcanhl_asil_MemMap.h"\n\n') 
    fb.write('#define intcanhl_asil_STOP_SEC_VAR_NOINIT_UNSPECIFIED\n#include "intcanhl_asil_MemMap.h"\n\n')
    fb.write('#ifdef __cplusplus\n}\n#endif\n\n#endif\n') 
    fb.close()
    
    fd=open(''+folder_path_output+'IntCanHL_ASIL_Measure.h','w')
    fd.write('#ifndef INTCANHL_ASIL_MEASURE_H\n#define INTCANHL_ASIL_MEASURE_H\n\n#include "Rte_Type.h"\n#include "tl_defines_IntCanHL_ASIL.h"\n\n') 
    fd.write('#ifdef __cplusplus\n')   
    fd.write('extern "C" {\n#endif\n\n')
    fd.write('extern CAL uint16 Debounce_Time_C;\nextern CAL uint8 Max_Skip_Allowed_C;\n\n')
    fd.write('#ifdef __cplusplus\n}\n#endif\n\n#endif\n')
    fd.close()

    fe=open(''+folder_path_output+'intcanhl_asil_calccrc.h','w')
    fe.write('#ifndef INTCANHL_ASIL_CALCCRC_H\n#define INTCANHL_ASIL_CALCCRC_H\n\n#include "Rte_Type.h"\n\n') 
    fe.write('#ifdef __cplusplus\n')   
    fe.write('extern "C" {\n#endif\n\n')

    for rx_element in asil_rx_list:
            if(rx_element.endswith('OruStatus')):
                pass
            else:
                fe.write('extern Std_ReturnType INTCANHL_ASIL_CALCCRC_'+ rx_element + '(IT_SG_' + rx_element + ' * DE_SG_' + rx_element + ', uint8 * ' + rx_element + '_Check_CRC);\n')

    for tx_element in asil_tx_list:
                fe.write('extern Std_ReturnType INTCANHL_ASIL_CALCCRC_' + tx_element + '(IT_' + tx_element + ' * IntCanHL_MG_Buff_' + tx_element + ', uint8 * ' + tx_element + '_Check_CRC);\n')

    fe.write('\n#ifdef __cplusplus\n}\n#endif\n\n#endif\n')
    fe.close()

    fg=open(''+folder_path_output+'IntCanHL_ASIL_Defines.h','w')
    fg.write('#ifndef INTCANHL_ASIL_DEFINES_H\n#define INTCANHL_ASIL_DEFINES_H\n\n#include "Rte_Type.h"\n\n') 
    fg.write('#ifdef __cplusplus\n')   
    fg.write('extern "C" {\n#endif\n\n')
    keys = []
    for key in DBC_dict:
        if key.startswith('CS') or key.startswith('VS') or key.startswith('TS'):
            keys.append(key)
    
    filtered_keys = [key for key in keys if key in DBC_dict]
    # Creating a new dictionary with filtered keys and values
    filtered_dict = {key: DBC_dict[key] for key in filtered_keys}
    for key, value in filtered_dict.items():
        if(key.startswith('TS')):
             fg.write('#define INTCANHL_INIT_VALUE_'+key.upper()+' ((IT_TS_DCDC_Temp_WaterIn) '+str(value[2])+')\n')
             fg.write('#define INTCANHL_MAX_VALUE_'+key.upper()+' ((IT_TS_DCDC_Temp_WaterIn) '+str(value[2] + 1)+')\n')
        else:
             fg.write('#define INTCANHL_INIT_VALUE_'+key.upper()+' ((IT_'+key+') '+str(value[2])+')\n')
             fg.write('#define INTCANHL_MAX_VALUE_'+key.upper()+' ((IT_'+key+') '+str(value[2] + 1)+')\n')
                   
    fg.write('#define BZ_ERR_CHECK ((IT_uint8) 16)\n#define MAX_VALUE_15 ((IT_uint8) 15)\n')
    fg.write('#ifdef __cplusplus\n}\n#endif\n\n#endif\n\n') 
    fg.close()

    return(struct_list,imp_dt,map_dict)

# ProcessMessages('Temp_Delta/delta1/Input/','Temp_Delta/delta1/dbc/','delta1',)