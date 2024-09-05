
from xml.etree import ElementTree as ET
import os
import cantools
from pprint import pprint
import sys

TS_list_factor={'1':['CM_TEMPERATURE_1DEG_INIT','CM_TEMPERATURE_1DEG_INVALID']}
CS_list_factor={'0.1':['CM_CURRENT_100MA_INIT','CM_CURRENT_100MA_INVALID'],'0.01':['CM_CURRENT_10MA_INIT','CM_CURRENT_10MA_INVALID'],'0.001':['CM_CURRENT_1MA_INIT','CM_CURRENT_1MA_INVALID']}
VS_list_factor={'0.1':['CM_VOLTAGE_100MV_INIT','CM_VOLTAGE_100MV_INVALID'],'0.01':['CM_VOLTAGE_10MV_INIT','CM_VOLTAGE_10MV_INVALID'],'0.001':['CM_VOLTAGE_1MV_INIT','CM_VOLTAGE_1MV_INVALID']}
TS_List,CS_List,VS_List,AT_CS_list,AT_TS_list,AT_VS_list,AT_cmlist,DBC_dict={},{},{},{},{},{},{},{}
TS,CS,VS,struct_list,AT_list,DBC_list,CM_list=[],[],[],[],[],[],[]
struct_dict=dict()
Rx_list,Tx_list,runnable=[],[],[]
signal_dict = {} # Dictionary to store all msgs and signals
asil_dict = {}   # Dictionary to store ASIL msgs and signals
qm_dict = {}     # Dictionary to store QM msgs and signals
asil_list = []   # list to store ASIL msgs
qm_list = []     # list to store QM msgs
asil_tx_list = []# list to store ASIL TX msgs
qm_tx_list = []  # list to store QM TX msgs
qm_list_all_signal = [] # list to store QM signals
VS_CS_TS_DIC={}
CDD_PARAMS = ["AC", "DC", "DCDC"]
RESET_PARAMS = ["HV", "DCDC"]

def GetMessages(fpath,dbc_path, userId):
    TS_List.clear()
    CS_List.clear()
    VS_List.clear()
    AT_CS_list.clear()
    AT_TS_list.clear()
    AT_VS_list.clear()
    AT_cmlist.clear()
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
    signal_dict.clear()
    asil_dict.clear()
    qm_dict.clear()
    asil_list.clear()
    qm_list.clear()
    asil_tx_list.clear()
    qm_tx_list.clear()
    qm_list_all_signal.clear()
    VS_CS_TS_DIC.clear()

    
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
    #db= cantools.database.load_file('temp/dbc/PAG_IPB_Int_CAN_Matrix_V1_8.dbc')
    db= cantools.database.load_file(dbc_path)
    with open(dbc_path, 'r', encoding='ISO-8859-1') as dbc_file:
        dbc_contents_txt = dbc_file.read()
        for message in db.messages:
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

    for values in qm_dict.values():
        qm_list_all_signal.extend(values)

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

    # Create a list of values from qm_dict for keys present in qm_rx_list
    result_list_qm_rx_signal = [value for key, value in qm_dict.items() if key in qm_rx_list]

    # Flatten the list of values (since each value is a list)
    qm_rx_all_signal = [item for sublist in result_list_qm_rx_signal for item in sublist]

    # Create a list of values from qm_dict for keys present in qm_rx_list
    result_list_qm_tx_signal = [value for key, value in qm_dict.items() if key in qm_tx_list]

    # Flatten the list of values (since each value is a list)
    qm_tx_all_signal = [item for sublist in result_list_qm_tx_signal for item in sublist]


    for msg in db.messages:
        for sig in msg.signals:

            if sig.maximum==None:#can apply filter for msgs which have non-1 factor or non-zero offset
                DBC_dict[sig.name]=[sig.scale,0,sig.initial,sig.offset]
            else:
                DBC_dict[sig.name]=[sig.scale,round(sig.maximum/sig.scale),sig.initial,sig.offset]
            DBC_list.append(sig.name)

            if str(sig.name).startswith('TS_'):
                if sig.maximum==None:
                    TS_List[sig.name]=[sig.scale,0,sig.initial,sig.offset]
                else:
                    TS_List[sig.name]=[sig.scale,round(sig.maximum/sig.scale),sig.initial,sig.offset]
                TS.append(sig.name)
            elif str(sig.name).startswith('CS_'):
                if sig.maximum==None:
                    CS_List[sig.name]=[sig.scale,0,sig.initial,sig.offset]
                else:
                    CS_List[sig.name]=[sig.scale,round(sig.maximum/sig.scale),sig.initial,sig.offset]
                CS.append(sig.name)
            elif str(sig.name).startswith('VS_'):
                if sig.maximum==None:
                    VS_List[sig.name]=[sig.scale,0,sig.initial,sig.offset]
                else:
                    VS_List[sig.name]=[sig.scale,round(sig.maximum/sig.scale),sig.initial,sig.offset]
                VS.append(sig.name)
    
    for msg in db.messages:
        for sig in msg.signals:
            if str(sig.name).startswith('TS_') or str(sig.name).startswith('CS_') or str(sig.name).startswith('VS_'):
                VS_CS_TS_DIC[sig.name]=sig.initial

    tree = ET.parse(fpath)
    root = tree.getroot()
    ns = {'ns':'http://autosar.org/schema/r4.0'}
    val,var,count,buffer_var,struct_var=0,0,0,0,0
    data_typ,array_typ,structr_list=[],[],[]
    data_typ.clear()
    array_typ.clear()
    structr_list.clear()
    data_type=['sint16','uint16','uint8']
    at_cnt,buf_at,cm_var_num,compu,cm_var=0,0,0,0,0
    for arpackage in tree.iter():
        if 'SHORT-NAME' in arpackage.tag:
#             if arpackage.text.startswith('CM_TS') or arpackage.text.startswith('CM_VS') or arpackage.text.startswith('CM_CS'):
            if arpackage.text.startswith('CM_'):
                if arpackage.text.split('CM_')[1] in DBC_list:#will it miss the messages which start with CM_?if thats msg has a Compu method, then it wont be missed.
                    CM_list.append(arpackage.text)#will take all the compu methods(with signal name) if the signal name is in dbc.
                    cm_var=1
                    cm_name=arpackage.text
        if cm_var_num==1:
            AT_cmlist[cm_name]=[arpackage.text] #only those computation methods which have outputfactor/offset 
            cm_var_num=2
        elif cm_var_num==2:
            AT_cmlist[cm_name].append(arpackage.text)
            cm_var_num=0
        if cm_var==1 and 'COMPU-NUMERATOR' in arpackage.tag :# there shouldnt be a short name before compu numerator
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
                    AT_CS_list[sig_name]=(arpackage.text).split('DataTypes/')[1]#contains volt str signals whose AT is mentioned in typeref under str's AT
                elif sig_name.startswith("VS_"):
                    #print(arpackage.text)
                    AT_VS_list[sig_name]=(arpackage.text).split('DataTypes/')[1]#their compu_methods are not same as sig name
                elif sig_name.startswith("TS_"):
                    AT_TS_list[sig_name]=(arpackage.text).split('DataTypes/')[1]
#                 elif not sig_name.startswith("AT_"):   
                    
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
            AT_cmlist[cm_name]=[arpackage.text]
            cm_var_num=2
        elif cm_var_num==2:
            AT_cmlist[cm_name].append(arpackage.text)
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
#         imp_dt.append(i)
        struct_list.append(i)
        imp_dt+=struct_dict[i]
        for j in struct_dict[i]:
            map_dict[j]=i
    for i in data_typ:
        imp_dt+=i
#     print('All implementation data types\' number=', len(imp_dt))
    
    del var    
    for i in runnable:
        if 'Init' in i:
            Init_run=i
        elif 'Tx' in i:
            Tx_run=i
        elif 'Rx' in i:
            Rx_run=i
               
    for arpackage in tree.iter():
    #     for arpck in arpackage.findall('.//ns:SHORT-NAME', namespaces=ns)[0].text)
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
    
    buff_list=[]#contains all the signals and msgs which have ports--> is 2nd element of buffer_list always a signals?

    def cfile(list_iter,elemen):
    
        if elemen==1:
            for element in qm_rx_list:
                fc.write('\tIT_'+element+'  DE_IntCan_'+element+';\n')
            for element in qm_rx_all_signal:
                fc.write('\tIT_'+element+'  DE_IntCan_'+element+';\n')
            for element in list_iter:
                buffer_list=element.split('DE_IntCan_')
                if len(buffer_list)==2:
                    buffer_var='IT_'+buffer_list[1]
                    if buffer_var in struct_list:#port element +IT_ -->is searched in list of all messages. 
                        if buffer_var.startswith("IT_AC"):
                            fc.write('\tIT_'+buffer_list[1]+'  DE_IntCan_'+buffer_list[1]+';\n')
            
            fc.write('\tIT_DCDC_BBC_Diag_Resp_Byte_0  DE_IntCan_DCDC_BBC_Diag_Resp_Byte_0;\n\tIT_DCDC_BBC_Diag_Resp_Byte_1  DE_IntCan_DCDC_BBC_Diag_Resp_Byte_1;\n\tIT_DCDC_BBC_Diag_Resp_Byte_2  DE_IntCan_DCDC_BBC_Diag_Resp_Byte_2;\n\tIT_DCDC_BBC_Diag_Resp_Byte_3  DE_IntCan_DCDC_BBC_Diag_Resp_Byte_3;\n\tIT_DCDC_BBC_Diag_Resp_Byte_4  DE_IntCan_DCDC_BBC_Diag_Resp_Byte_4;\n\tIT_DCDC_BBC_Diag_Resp_Byte_5  DE_IntCan_DCDC_BBC_Diag_Resp_Byte_5;\n\tIT_DCDC_BBC_Diag_Resp_Byte_6  DE_IntCan_DCDC_BBC_Diag_Resp_Byte_6;\n\tIT_DCDC_BBC_Diag_Resp_Byte_7  DE_IntCan_DCDC_BBC_Diag_Resp_Byte_7;\n\tIT_VS_BBC_Bulk_R1_PkPk  DE_IntCan_VS_BBC_Bulk_R1_PkPk;\n\tIT_VS_BBC_Bulk_R2_PkPk  DE_IntCan_VS_BBC_Bulk_R2_PkPk;\n\tIT_Com_WakeUpSleepCmd  DE_IntCan_Com_WakeUpSleepCmd;\n\tIT_DCDC_BBC_XCP_Data_Resp  DE_IntCan_DCDC_BBC_XCP_Data_Resp;\n')
            fc.write('\tIT_Enable status;\n\tStd_ReturnType Ret_Val_HVDC_Cntrl;\n\tStd_ReturnType Ret_Val_DCDC_Cntrl;\n\tuint8 diff_value;\n')
            for element in CDD_PARAMS:
                fc.write('\tIT_SendResp '+element+'_calibSendResp;\n\tIT_SendResp '+element+'_paramSendResp;\n')
            fc.write('\tIT_Active Intcan_Timeout_Active;\n\tboolean Statemachines_Error_check;\n\tIT_Active check_Intcan_Active;\n\tuint8 IntCanQmResp_status;')
            fc.write('\n\tIT_Proxy_Rx buffer_a;\n\tIT_Enable tIntCanReq_Status;\n')
            fc.write('\tuint8 Aux_U8_Add1;\n\n')
            fc.write('\tfloat In_factor = 0.0f;\n\tfloat Out_factor = 0.0f;\n\tfloat In_offset = 0.0f;\n\tfloat Out_offset = 0.0f;\n\tfloat Converted_data = 0.0f;\n\n')
        elif elemen==2:
            for element in qm_tx_list:
                fc.write('\tIT_'+element+'  DE_IntCan_'+element+';\n')
            for element in qm_tx_all_signal:
                fc.write('\tIT_'+element+'  DE_IntCan_'+element+';\n')
            fc.write('\tIT_HV_Measure_01  DE_IntCan_HV_Measure_01;\n\tIT_Reset DspResetReq_value;\n\tDT_IntCan_DCDC_LLC_Diag_Req_Byte_0 HV_DspResetReq_Byte0;\n\tDT_IntCan_DCDC_LLC_Diag_Req_Byte_1 HV_DspResetReq_Byte1;\n\tDT_IntCan_DCDC_LLC_Diag_Req_Byte_2 HV_DspResetReq_Byte2;\n\tDT_IntCan_DCDC_LLC_Diag_Req_Byte_0 DCDC_DspResetReq_Byte0;\n\tDT_IntCan_DCDC_LLC_Diag_Req_Byte_1 DCDC_DspResetReq_Byte1;\n\tDT_IntCan_DCDC_LLC_Diag_Req_Byte_2 DCDC_DspResetReq_Byte2;\n\tIT_Enable tIntCanReq_Status;\n\tIT_Proxy_Tx buffer;\n')
            fc.write('\tIT_AC_Diag_Req DE_IntCan_AC_Diag_Req;\n\tIT_AC_FblCpu2_Diag_Req DE_IntCan_AC_FblCpu2_Diag_Req;\n\n')
            fc.write('\tfloat In_factor = 0.0f;\n\tfloat Out_factor = 0.0f;\n\tfloat In_offset = 0.0f;\n\tfloat Out_offset = 0.0f;\n\tfloat Converted_data = 0.0f;\n\tfloat Out_data = 0.0f;\n\n')       
            
        for element in list_iter:#Rx list only has ports for individual messages.
            buffer_list=element.split('DE_IntCan_')
            if len(buffer_list)==2:
                if element.startswith("REC_R"):
                    if buffer_list[1] == 'HV_OutPwr' :
                        fc.write('\n\tRet_Val_HVDC_Cntrl = Rte_Read_R_'+element[6:]+'(&DE_IntCan_'+buffer_list[1]+');\n\n')
                    elif buffer_list[1] =='VS_DCDC_VoutDiag':
                        fc.write('\n\tRet_Val_DCDC_Cntrl = Rte_Read_R_'+element[6:]+'(&DE_IntCan_'+buffer_list[1]+');\n\n')
                    elif element[6:].startswith("AC"):
                        test_list= element[6:].split('_IntCan_DE_IntCan_')
                        fc.write('\tRte_Read_R_'+element[6:]+'(&(buffer.'+test_list[0]+'.'+buffer_list[1]+'));\n') 
                    else:
                        # fc.write('\thiii\n')
                        fc.write('\tRte_Read_R_'+element[6:]+'(&DE_IntCan_'+buffer_list[1]+');\n') 
        fc.write('\n')
        if elemen==1:
            # fc.write('\tif ((RTE_E_MAX_AGE_EXCEEDED == ((uint8)(Ret_Val_HVDC_Cntrl & RTE_E_MAX_AGE_EXCEEDED))) || (RTE_E_MAX_AGE_EXCEEDED == ((uint8)(Ret_Val_DCDC_Cntrl & RTE_E_MAX_AGE_EXCEEDED))))\n\t{\n ')
            # fc.write('\t\tStatus_var = CM_ACTIVE_NOT_ACTIVE;\n\t\tAux_U8_Add1 = DT_ERRORSTATUS_FAILED;\n\t}\n\telse\n\t{\n\t\tStatus_var = CM_ACTIVE_ACTIVE;\n\t\tAux_U8_Add1 = DT_ERRORSTATUS_PASSED;\n\t}\n')
            fc.write('\n\tRte_Read_R_Proxy_Rx_buffer(&buffer_a);\n\tRte_Read_R_IntCanReq_status(&tIntCanReq_Status);\n\n\t{')
            fc.write('\n\t\tif(!((boolean) 1))\n\t\t{\n\t\t\tINTCANHL_Output_value = 0;\n\t\t\tINTCANHL_state_value = 0;\n\t\t}\n\t\telse\n\t\t{\n\t\t\tif(INTCANHL_state_value < Waiting_Time_C)\n\t\t\t{\n\t\t\t\t++INTCANHL_state_value;\n\t\t\t\tINTCANHL_Output_value = 0;\n\t\t\t}\n\t\t\telse\n\t\t\t\tINTCANHL_Output_value = 1;\n\t\t}\n\t}')
            fc.write('\n\tif(INTCANHL_Output_value)\n\t{\n\t\tINTCANHL_Qualifier_value = CM_INTCAN_QUALIFIER_OK;\n\t}\n\telse\n\t{\n\t\tINTCANHL_Qualifier_value = CM_INTCAN_QUALIFIER_INIT;\n\t}')    
            fc.write('\n\n\t/*delay block implementation for DSPs(which will take some time to wakeup) */\n')
            fc.write('\n\tif(Delay_state_block.u8Delay_Statemachine_default)\n\t{\n\t\tif(tIntCanReq_Status == 1)\n\t\t{\n\t\t\tDelay_state_block.u8Delay_Statemachine_default = 0;\n\t\t\tDelay_state_block.u8Delay_Statemachine_Wait = 1;\n\t\t\tINTCANHL_mg_u8Delay_block_flag = 0.;\n\t\t}\n\t\telse\n\t\t{\n\t\t\tINTCANHL_mg_u8Delay_block_Output = 2.;\n\t\t}\n\t}')
            fc.write('\n\telse\n\t{\n\t\tif(Delay_state_block.u8Delay_Statemachine_Wait)\n\t\t{\n\t\t\tif(tIntCanReq_Status == 2)\n\t\t\t{\n\t\t\t\tDelay_state_block.u8Delay_Statemachine_Wait = 0;\n\t\t\t\tDelay_state_block.u8Delay_Statemachine_default = 1;\n\t\t\t\tINTCANHL_mg_u8Delay_block_flag = 0.;\n\t\t\t\tINTCANHL_mg_u8Delay_block_Output = 2.;\n\t\t\t}\n\t\t\telse\n\t\t\t{\n\t\t\t\tif(INTCANHL_mg_u8Delay_block_flag > 30.)\n\t\t\t\t{\n\t\t\t\t\tDelay_state_block.u8Delay_Statemachine_Wait = 0;\n\t\t\t\t\tDelay_state_block.u8Delay_Statemachine_Pass = 1;\n\t\t\t\t\tINTCANHL_mg_u8Delay_block_flag = 0.;\n\t\t\t\t}\n\t\t\t\telse\n\t\t\t\t{\n\t\t\t\t\tINTCANHL_mg_u8Delay_block_flag = INTCANHL_mg_u8Delay_block_flag + 1.;\n\t\t\t\t}\n\t\t\t}\n\t\t}')
            fc.write('\n\t\telse\n\t\t{\n\t\t\tif(Delay_state_block.u8Delay_Statemachine_Pass)\n\t\t\t{\n\t\t\t\tif(tIntCanReq_Status == 2)\n\t\t\t\t{\n\t\t\t\t\tDelay_state_block.u8Delay_Statemachine_Pass = 0;\n\t\t\t\t\tDelay_state_block.u8Delay_Statemachine_default = 1;\n\t\t\t\t\tINTCANHL_mg_u8Delay_block_flag = 0.;\n\t\t\t\t\tINTCANHL_mg_u8Delay_block_Output = 2.;\n\t\t\t\t}\n\t\t\t\telse\n\t\t\t\t{\n\t\t\t\t\tINTCANHL_mg_u8Delay_block_Output = 1.;\n\t\t\t\t}\n\t\t\t}\n\t\t\telse\n\t\t\t{\n\t\t\t\tDelay_state_block.u8Delay_Statemachine_default = 1;\n\t\t\t\tINTCANHL_mg_u8Delay_block_flag = 0.;\n\t\t\t\tINTCANHL_mg_u8Delay_block_Output = 2.;\n\t\t\t}\n\t\t}\n\t}')
            fc.write('\n\n\t/*end of delay block implementation*/\n')
            for element in CDD_PARAMS:
                fc.write('\n\t/*Start of '+element+' statemachine implementation */\n') 
                fc.write('\n\tRte_Read_R_'+element+'_ParamSend_Resp_SendResp(&'+element+'_paramSendResp);\n\tRte_Read_R_'+element+'_CalibSend_Resp_SendResp(&'+element+'_calibSendResp);')    
                fc.write('\n\tif(INTCANHL_mg_'+element+'_Statemachine.u8'+element+'_Statemachine_Qualifier_INIT_state)\n\t{\n\t\tif(INTCANHL_Qualifier_value == 0)\n\t\t{\n\t\t\tINTCANHL_mg_'+element+'_Statemachine.u8'+element+'_Statemachine_Qualifier_INIT_state = 0;\n\t\t\tINTCANHL_mg_'+element+'_Statemachine.u8'+element+'_Statemachine_Qualifier_NOT_INIT_state = 1;\n\t\t\tINTCANHL_mg_'+element+'_Statemachine.u8'+element+'_Statemachine_IntCan_active_state = 1;\n\t\t\tINTCANHL_mg_'+element+'_Statemachine.u8'+element+'_Statemachine_IntCan_active_ns_state = U8_'+element+'_Init_id;\n\t\t\tINTCANHL_mg_u8'+element+'_StateMachine_param_Req = CM_STOP_SENDING;\n\t\t\tINTCANHL_mg_u8'+element+'_StateMachine_Calib_Req = CM_STOP_SENDING;\n\t\t}\n\t}')
                fc.write('\n\telse\n\t{\n\t\tif(INTCANHL_mg_'+element+'_Statemachine.u8'+element+'_Statemachine_Qualifier_NOT_INIT_state)\n\t\t{\n\t\t\tif(INTCANHL_Qualifier_value == 3)\n\t\t\t{\n\t\t\t\tif(INTCANHL_mg_'+element+'_Statemachine.u8'+element+'_Statemachine_IntCan_active_state)\n\t\t\t\t{\n\t\t\t\t\tmg_'+element+'_state_IntCan_active_ex();\n\t\t\t\t}\n\t\t\t\telse\n\t\t\t\t{\n\t\t\t\t\tINTCANHL_mg_'+element+'_Statemachine.u8'+element+'_Statemachine_IntCan_NotActive1_state = 0;\n\t\t\t\t}\n\t\t\t\tINTCANHL_mg_'+element+'_Statemachine.u8'+element+'_Statemachine_Qualifier_NOT_INIT_state = 0;\n\t\t\t\tINTCANHL_mg_'+element+'_Statemachine.u8'+element+'_Statemachine_Qualifier_INIT_state = 1;\n\t\t\t}')
                fc.write('\n\t\t\telse\n\t\t\t{\n\t\t\t\tif(INTCANHL_mg_'+element+'_Statemachine.u8'+element+'_Statemachine_IntCan_active_state)\n\t\t\t\t{\n\t\t\t\t\tif(INTCANHL_mg_u8Delay_block_Output == CM_ENABLE_DISABLE)\n\t\t\t\t\t{\n\t\t\t\t\t\tmg_'+element+'_state_IntCan_active_ex();\n\t\t\t\t\t\tINTCANHL_mg_'+element+'_Statemachine.u8'+element+'_Statemachine_IntCan_NotActive1_state = 1;\n\t\t\t\t\t\tINTCANHL_b'+element+'_Error = 0;\n\t\t\t\t\t\tINTCANHL_mg_u8'+element+'_StateMachine_param_Req = CM_STOP_SENDING;\n\t\t\t\t\t\tINTCANHL_mg_u8'+element+'_StateMachine_Calib_Req = CM_STOP_SENDING;\n\t\t\t\t\t}')
                fc.write('\n\t\t\t\t\telse\n\t\t\t\t\t{\n\t\t\t\t\t\tif(INTCANHL_bparamSendResp2'+element+'_C)\n\t\t\t\t\t\t{\n\t\t\t\t\t\t\tintcanhl_paramSendResp'+element+' = INTCANHL_bparamSendResp'+element+'_C;\n\t\t\t\t\t\t}\n\t\t\t\t\t\telse\n\t\t\t\t\t\t{\n\t\t\t\t\t\t\tintcanhl_paramSendResp'+element+' = '+element+'_paramSendResp;\n\t\t\t\t\t\t}\n\t\t\t\t\t\tif(INTCANHL_bcalibSendResp2'+element+'_C)\n\t\t\t\t\t\t{\n\t\t\t\t\t\t\tintcanhl_calibSendResp'+element+' = INTCANHL_bcalibSendResp'+element+'_C;\n\t\t\t\t\t\t}\n\t\t\t\t\t\telse\n\t\t\t\t\t\t{\n\t\t\t\t\t\t\tintcanhl_calibSendResp'+element+' = '+element+'_calibSendResp;\n\t\t\t\t\t\t}')
                fc.write('\n\t\t\t\t\t\tswitch (INTCANHL_mg_'+element+'_Statemachine.u8'+element+'_Statemachine_IntCan_active_ns_state)\n\t\t\t\t\t\t{')
                fc.write('\n\t\t\t\t\t\t\tcase U8_'+element+'_Init_id:\n\t\t\t\t\t\t\t{\n\t\t\t\t\t\t\t\tif((intcanhl_paramSendResp'+element+' == CM_PARAM_LOADING_OK) && (intcanhl_calibSendResp'+element+' == CM_PARAM_LOADING_OK))\n\t\t\t\t\t\t\t\t{\n\t\t\t\t\t\t\t\t\tINTCANHL_mg_'+element+'_Statemachine.u8'+element+'_Statemachine_IntCan_active_ns_state = U8_'+element+'_Parameter_id;\n\t\t\t\t\t\t\t\t\tINTCANHL_mg_u8'+element+'_StateMachine_param_Req = CM_START_SENDING;\n\t\t\t\t\t\t\t\t}\n\t\t\t\t\t\t\t\tbreak;\n\t\t\t\t\t\t\t}')
                fc.write('\n\t\t\t\t\t\t\tcase U8_'+element+'_Error_id:\n\t\t\t\t\t\t\t{\n\t\t\t\t\t\t\t\tif(INTCANHL_mg_'+element+'_Statemachine.u8'+element+'_Statemachine_Idle_state)\n\t\t\t\t\t\t\t\t{\n\t\t\t\t\t\t\t\t\tif((intcanhl_paramSendResp'+element+' == CM_SENDRETRYCOUNTER_REACHED) || (intcanhl_calibSendResp'+element+' == CM_SENDRETRYCOUNTER_REACHED))\n\t\t\t\t\t\t\t\t\t{\n\t\t\t\t\t\t\t\t\t\tINTCANHL_mg_'+element+'_Statemachine.u8'+element+'_Statemachine_Idle_state = 0;\n\t\t\t\t\t\t\t\t\t\tINTCANHL_b'+element+'_Error = 1;\n\t\t\t\t\t\t\t\t\t\tINTCANHL_mg_u8'+element+'_StateMachine_param_Req = CM_STOP_SENDING;\n\t\t\t\t\t\t\t\t\t\tINTCANHL_mg_u8'+element+'_StateMachine_Calib_Req = CM_STOP_SENDING;\n\t\t\t\t\t\t\t\t\t}\n\t\t\t\t\t\t\t\t}\n\t\t\t\t\t\t\t\tbreak;\n\t\t\t\t\t\t\t}')
                fc.write('\n\t\t\t\t\t\t\tcase U8_'+element+'_Parameter_id:\n\t\t\t\t\t\t\t{\n\t\t\t\t\t\t\t\tswitch (intcanhl_paramSendResp'+element+')\n\t\t\t\t\t\t\t\t{\n\t\t\t\t\t\t\t\t\tcase CM_PARAM_TRANSMISSION_OK:\n\t\t\t\t\t\t\t\t\t{\n\t\t\t\t\t\t\t\t\t\tINTCANHL_mg_'+element+'_Statemachine.u8'+element+'_Statemachine_IntCan_active_ns_state = U8_'+element+'_Calibration_id;\n\t\t\t\t\t\t\t\t\t\tINTCANHL_mg_u8'+element+'_StateMachine_Calib_Req = CM_START_SENDING;\n\t\t\t\t\t\t\t\t\t\tbreak;\n\t\t\t\t\t\t\t\t\t}\n\t\t\t\t\t\t\t\t\tcase CM_SENDRETRYCOUNTER_REACHED:\n\t\t\t\t\t\t\t\t\t{\n\t\t\t\t\t\t\t\t\t\tINTCANHL_mg_'+element+'_Statemachine.u8'+element+'_Statemachine_IntCan_active_ns_state = U8_'+element+'_Error_id;\n\t\t\t\t\t\t\t\t\t\tINTCANHL_mg_'+element+'_Statemachine.u8'+element+'_Statemachine_Idle_state = 1;\n\t\t\t\t\t\t\t\t\t\tbreak;\n\t\t\t\t\t\t\t\t\t}\n\t\t\t\t\t\t\t\t\tdefault:\n\t\t\t\t\t\t\t\t\t{\n\t\t\t\t\t\t\t\t\t\tbreak;\n\t\t\t\t\t\t\t\t\t}\n\t\t\t\t\t\t\t\t}\n\t\t\t\t\t\t\t\tbreak;\n\t\t\t\t\t\t\t}')
                fc.write('\n\t\t\t\t\t\t\tcase U8_'+element+'_Calibration_id:\n\t\t\t\t\t\t\t{\n\t\t\t\t\t\t\t\tswitch (intcanhl_calibSendResp'+element+')\n\t\t\t\t\t\t\t\t{\n\t\t\t\t\t\t\t\t\tcase CM_SENDRETRYCOUNTER_REACHED:\n\t\t\t\t\t\t\t\t\t{\n\t\t\t\t\t\t\t\t\t\tINTCANHL_mg_'+element+'_Statemachine.u8'+element+'_Statemachine_IntCan_active_ns_state = U8_'+element+'_Error_id;\n\t\t\t\t\t\t\t\t\t\tINTCANHL_mg_'+element+'_Statemachine.u8'+element+'_Statemachine_Idle_state = 1;\n\t\t\t\t\t\t\t\t\t\tbreak;\n\t\t\t\t\t\t\t\t\t}\n\t\t\t\t\t\t\t\t\tcase CM_PARAM_TRANSMISSION_OK:\n\t\t\t\t\t\t\t\t\t{\n\t\t\t\t\t\t\t\t\t\tINTCANHL_mg_'+element+'_Statemachine.u8'+element+'_Statemachine_IntCan_active_ns_state = U8_'+element+'_Running_id;\n\t\t\t\t\t\t\t\t\t\tbreak;\n\t\t\t\t\t\t\t\t\t}\n\t\t\t\t\t\t\t\t\tdefault:\n\t\t\t\t\t\t\t\t\t{\n\t\t\t\t\t\t\t\t\t\tbreak;\n\t\t\t\t\t\t\t\t\t}\n\t\t\t\t\t\t\t\t}\n\t\t\t\t\t\t\t\tbreak;\n\t\t\t\t\t\t\t}')
                fc.write('\n\t\t\t\t\t\t\tdefault:\n\t\t\t\t\t\t\t{\n\t\t\t\t\t\t\t\tbreak;\n\t\t\t\t\t\t\t}\n\t\t\t\t\t\t}\n\t\t\t\t\t}\n\t\t\t\t}')
                fc.write('\n\t\t\t\telse\n\t\t\t\t{\n\t\t\t\t\tif(INTCANHL_mg_'+element+'_Statemachine.u8'+element+'_Statemachine_IntCan_NotActive1_state)\n\t\t\t\t\t{\n\t\t\t\t\t\tif(INTCANHL_mg_u8Delay_block_Output == CM_ENABLE_ENABLE)\n\t\t\t\t\t\t{\n\t\t\t\t\t\t\tINTCANHL_mg_'+element+'_Statemachine.u8'+element+'_Statemachine_IntCan_NotActive1_state = 0;\n\t\t\t\t\t\t\tINTCANHL_mg_'+element+'_Statemachine.u8'+element+'_Statemachine_IntCan_active_state = 1;\n\t\t\t\t\t\t\tINTCANHL_mg_'+element+'_Statemachine.u8'+element+'_Statemachine_IntCan_active_ns_state = U8_'+element+'_Init_id;\n\t\t\t\t\t\t\tINTCANHL_mg_u8'+element+'_StateMachine_param_Req = CM_STOP_SENDING;\n\t\t\t\t\t\t\tINTCANHL_mg_u8'+element+'_StateMachine_Calib_Req = CM_STOP_SENDING;\n\t\t\t\t\t\t}\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\telse\n\t\t{\n\t\t\tINTCANHL_mg_'+element+'_Statemachine.u8'+element+'_Statemachine_Qualifier_INIT_state = 1;\n\t\t}\n\t}')
                fc.write('\n\n\t/*End of '+element+' statemachine implementation */\n')
            
            fc.write('\n\tStatemachines_Error_check = INTCANHL_bAC_Error || INTCANHL_bDC_Error || INTCANHL_bDCDC_Error;\n\tbRxInitActive = (RTE_E_MAX_AGE_EXCEEDED == ((uint8) (Ret_Val_HVDC_Cntrl & RTE_E_MAX_AGE_EXCEEDED))) || (RTE_E_MAX_AGE_EXCEEDED == ((uint8) (Ret_Val_DCDC_Cntrl & RTE_E_MAX_AGE_EXCEEDED))) || (tIntCanReq_Status != CM_ENABLE_ENABLE) || Statemachines_Error_check;')
            fc.write('\n\tif(bRxInitActive)\n\t{\n\t\tcheck_Intcan_Active = CM_ACTIVE_NOT_ACTIVE;\n\t}\n\telse\n\t{\n\t\tcheck_Intcan_Active = CM_ACTIVE_ACTIVE;\n\t}')
            fc.write('\n\n\t/*start of the internal can response block */\n')
            fc.write('\n\tif(INTCANHL_mg_IntCanResp.u8Resp_Statemachine_Shutdown)\n\t{\n\t\tif(tIntCanReq_Status == 1)\n\t\t{\n\t\t\tINTCANHL_mg_IntCanResp.u8Resp_Statemachine_Shutdown = 0;\n\t\t\tINTCANHL_mg_IntCanResp.u8Resp_Statemachine_Startup = 1;\n\t\t\tINTCANHL_mg_u8Resp_block_flag = 0.;\n\t\t\tINTCANHL_mg_u8Resp_block_Output = check_Intcan_Active;\n\t\t}\n\t\telse\n\t\t{\n\t\t\tif(INTCANHL_mg_u8Resp_block_flag > 30.)\n\t\t\t{\n\t\t\t\tINTCANHL_mg_IntCanResp.u8Resp_Statemachine_Shutdown = 0;\n\t\t\t\tINTCANHL_mg_IntCanResp.u8Resp_Statemachine_Shutdown1 = 1;\n\t\t\t\tINTCANHL_mg_u8Resp_block_flag = 0.;\n\t\t\t}\n\t\t\telse\n\t\t\t{\n\t\t\t\tINTCANHL_mg_u8Resp_block_flag = INTCANHL_mg_u8Resp_block_flag + 1.;\n\t\t\t}\n\t\t}\n\t}')            
            fc.write('\n\telse\n\t{\n\t\tif(INTCANHL_mg_IntCanResp.u8Resp_Statemachine_Startup)\n\t\t{\n\t\t\tif(tIntCanReq_Status == 2)\n\t\t\t{\n\t\t\t\tINTCANHL_mg_IntCanResp.u8Resp_Statemachine_Startup = 0;\n\t\t\t\tINTCANHL_mg_IntCanResp.u8Resp_Statemachine_Shutdown = 1;\n\t\t\t\tINTCANHL_mg_u8Resp_block_flag = 0.;\n\t\t\t}\n\t\t\telse\n\t\t\t{\n\t\t\t\tINTCANHL_mg_u8Resp_block_Output = check_Intcan_Active;\n\t\t\t}\n\t\t}') 
            fc.write('\n\t\telse\n\t\t{\n\t\t\tif(INTCANHL_mg_IntCanResp.u8Resp_Statemachine_default)\n\t\t\t{\n\t\t\t\tif(tIntCanReq_Status == 1)\n\t\t\t\t{\n\t\t\t\t\tINTCANHL_mg_IntCanResp.u8Resp_Statemachine_default = 0;\n\t\t\t\t\tINTCANHL_mg_IntCanResp.u8Resp_Statemachine_Startup = 1;\n\t\t\t\t\tINTCANHL_mg_u8Resp_block_flag = 0.;\n\t\t\t\t\tINTCANHL_mg_u8Resp_block_Output = check_Intcan_Active;\n\t\t\t\t}\n\t\t\t\telse\n\t\t\t\t{\n\t\t\t\t\tINTCANHL_mg_u8Resp_block_Output = check_Intcan_Active;\n\t\t\t\t}\n\t\t\t}')
            fc.write('\n\t\t\telse\n\t\t\t{\n\t\t\t\tif(INTCANHL_mg_IntCanResp.u8Resp_Statemachine_Shutdown1)\n\t\t\t\t{\n\t\t\t\t\tif(tIntCanReq_Status == 1)\n\t\t\t\t\t{\n\t\t\t\t\t\tINTCANHL_mg_IntCanResp.u8Resp_Statemachine_Shutdown1 = 0;\n\t\t\t\t\t\tINTCANHL_mg_IntCanResp.u8Resp_Statemachine_Startup = 1;\n\t\t\t\t\t\tINTCANHL_mg_u8Resp_block_flag = 0.;\n\t\t\t\t\t\tINTCANHL_mg_u8Resp_block_Output = check_Intcan_Active;\n\t\t\t\t\t}\n\t\t\t\t\telse\n\t\t\t\t\t{\n\t\t\t\t\t\tINTCANHL_mg_u8Resp_block_Output = check_Intcan_Active;\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t\telse\n\t\t\t\t{\n\t\t\t\t\tINTCANHL_mg_IntCanResp.u8Resp_Statemachine_default = 1;\n\t\t\t\t\tINTCANHL_mg_u8Resp_block_flag = 0.;\n\t\t\t\t\tINTCANHL_mg_u8Resp_block_Output = check_Intcan_Active;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}')
            fc.write('\n\tif (INTCANHL_mg_u8Resp_block_Output >= 2.)\n\t{\n\t\tIntCanQmResp_status = CM_ENABLE_ENABLE;\n\t}\n\telse\n\t{\n\t\tIntCanQmResp_status = CM_ENABLE_DISABLE;\n\t}\n\tRte_Write_P_IntCanQmResp_status(IntCanQmResp_status);')
            fc.write('\n\n\t/*end of the internal can response block*/\n\n\t/*start of message counter implementation for the AC_status message */\n')
            fc.write('\n\t{\n\t\tif(!(buffer_a.AC_Status_00.AC_Cpu1_Alive_Counter == INTCANHL_mg_old_delay_value))\n\t\t{\n\t\t\tINTCANHL_mg_To_out_value = 0;\n\t\t\tINTCANHL_mg_Alive_Counter_value = 0;\n\t\t}\n\t\telse\n\t\t{\n\t\t\tif(INTCANHL_mg_Alive_Counter_value < Debounce_Time_C)\n\t\t\t{\n\t\t\t\t++INTCANHL_mg_Alive_Counter_value;\n\t\t\t\tINTCANHL_mg_To_out_value = 0;\n\t\t\t}\n\t\t\telse\n\t\t\t\tINTCANHL_mg_To_out_value = 1;\n\t\t}\n\t}')
            fc.write('\n\tif(buffer_a.AC_Status_00.AC_Cpu1_Alive_Counter > INTCANHL_mg_old_delay_value)\n\t{\n\t\tdiff_value = (uint8) (buffer_a.AC_Status_00.AC_Cpu1_Alive_Counter - INTCANHL_mg_old_delay_value);\n\t}\n\telse\n\t{\n\t\tAux_U8_Add1 = buffer_a.AC_Status_00.AC_Cpu1_Alive_Counter;\n\t\tAux_U8_Add1 += BZ_Err_Check;\n\t\tdiff_value = (uint8) (Aux_U8_Add1 - INTCANHL_mg_old_delay_value);\n\t}')
            fc.write('\n\tINTCANHL_mg_old_delay_value = buffer_a.AC_Status_00.AC_Cpu1_Alive_Counter;\n\t{\n\t\tif(!(diff_value != Max_Skip_Allowed_C))\n\t\t{\n\t\t\tINTCANHL_mg_BZ_out_value = 0;\n\t\t\tINTCANHL_mg_message_Counter_value = 0;\n\t\t}\n\t\telse\n\t\t{\n\t\t\tif(INTCANHL_mg_message_Counter_value < Debounce_Time_C)\n\t\t\t{\n\t\t\t\t++INTCANHL_mg_message_Counter_value;\n\t\t\t\tINTCANHL_mg_BZ_out_value = 0;\n\t\t\t}\n\t\t\telse\n\t\t\t\tINTCANHL_mg_BZ_out_value = 1;\n\t\t}\n\t}')
            fc.write('\n\t{\n\t\tif(!((uint8) (INTCANHL_mg_To_out_value || INTCANHL_mg_BZ_out_value)))\n\t\t{\n\t\t\tINTCANHL_mg_out_value = 0;\n\t\t\tINTCANHL_mg_cntr_value = 0;\n\t\t}\n\t\telse\n\t\t{\n\t\t\tif(INTCANHL_mg_cntr_value < ((uint8) 100))\n\t\t\t{\n\t\t\t\t++INTCANHL_mg_cntr_value;\n\t\t\t\tINTCANHL_mg_out_value = 0;\n\t\t\t}\n\t\t\telse\n\t\t\t\tINTCANHL_mg_out_value = 1;\n\t\t}\n\t}')
            fc.write('\n\tif(Statemachines_Error_check || (INTCANHL_mg_out_value != 0))\n\t{\n\t\tIntcan_Timeout_Active = CM_ACTIVE_ACTIVE;\n\t}\n\telse\n\t{\n\t\tIntcan_Timeout_Active = CM_ACTIVE_NOT_ACTIVE;\n\t}')
            fc.write('\n\n\t/*end of message counter implementation for the AC_status message */\n')
            fc.write('\n\tRte_Write_P_IntCAN_Timeout_Active_status(Intcan_Timeout_Active);\n\tRte_Write_P_IntCAN_SrvState_active(check_Intcan_Active);')
            
            for element in CDD_PARAMS:
                fc.write('\n\tRte_Write_P_'+element+'_ParamSend_Req_SendReq((uint8) INTCANHL_mg_u8'+element+'_StateMachine_param_Req);\n\tRte_Write_P_'+element+'_CalibSend_Req_SendReq((uint8) INTCANHL_mg_u8'+element+'_StateMachine_Calib_Req);')
            for element in list_iter:
                buffer_list=element.split('DE_IntCan_')
                if len(buffer_list)==2:
                    buffer_var='IT_'+buffer_list[1]
                    if buffer_var in struct_list:#port element +IT_ -->is searched in list of all messages. 
                        if buffer_var.startswith("IT_AC"):
                            if buffer_var in ['IT_AC_Measure_01', 'IT_AC_Measure_02', 'IT_AC_Measure_03', 'IT_AC_Measure_04', 'IT_AC_Measure_05','IT_AC_Measure_06','IT_AC_Status_00']:
                                for y in struct_dict[buffer_var]:
                                    if y == 'Qualifier':
                                        fc.write('\n\tDE_IntCan_'+buffer_list[1]+'.'+y+' = 0;')
                                    else:
                                       fc.write('\n\tDE_IntCan_'+buffer_list[1]+'.'+y+' = buffer_a.'+buffer_list[1]+'.'+y+';')
                            else:
                                pass                       
                            
                        else:
                            fc.write('\n\n\tif (CM_ENABLE_ENABLE == tIntCanReq_Status)\n\t{\n')
                            for x in struct_dict[buffer_var]:
                                if x in CS:
                                    if CS_List[x][0]!=1 : 
                                        try:
                                            fc.write('\t\tIn_factor = '+str(CS_List[x][0])+';\n\t\tOut_factor = '+str(AT_cmlist['CM_'+x][1])+';\n\t\tIn_offset = '+str(CS_List[x][3])+';\n\t\tOut_offset = '+str(AT_cmlist['CM_'+x][0])+';\n\n')
                                        except:#signals which have CM_some other name than signal
                                            fc.write('\t\tIn_factor = '+str(CS_List[x][0])+';\n\t\tOut_factor = '+str(AT_cmlist['CM_'+AT_CS_list[x].split('AT_')[1]][1])+';\n\t\tIn_offset = '+str(CS_List[x][3])+';\n\t\tOut_offset = '+str(AT_cmlist['CM_'+AT_CS_list[x].split('AT_')[1]][0])+';\n\n')
                                        fc.write('\t\tif (DE_IntCan_'+x+' < INTCANHL_MAX_VALUE_'+x+') \n\t\t{\n\t\t\tif (DE_IntCan_'+x+' == INTCANHL_INIT_VALUE_'+x+') \n\t\t\t{\n\t\t\t\tDE_IntCan_'+buffer_list[1]+'.'+x+' = '+str(CS_list_factor[str(CS_List[x][0])][0])+';\n\t\t\t}\n\t\t\telse\n\t\t\t{\n\t\t\t\tConverted_data = ((DE_IntCan_'+x+' * In_factor) + In_offset);\n\n\t\t\t\tDE_IntCan_'+buffer_list[1]+'.'+x+' = ((Converted_data - Out_offset) / Out_factor);\n\t\t\t}\n\t\t}\n\t\telse\n\t\t{\n\t\t\tDE_IntCan_'+buffer_list[1]+'.'+x+' = '+str(CS_list_factor[str(CS_List[x][0])][1])+';\n\t\t}\n\n')
                                    else:
                                        fc.write('\t\tDE_IntCan_'+buffer_list[1]+'.'+x+' = DE_IntCan_'+x+';\n\n')
                                elif x in VS:
                                    if VS_List[x][0]!=1:
                                        try:
                                            fc.write('\t\tIn_factor = '+str(VS_List[x][0])+';\n\t\tOut_factor = '+str(AT_cmlist['CM_'+x][1])+';\n\t\tIn_offset = '+str(VS_List[x][3])+';\n\t\tOut_offset = '+str(AT_cmlist['CM_'+x][0])+';\n\n')
                                        except:
                                            fc.write('\t\tIn_factor = '+str(VS_List[x][0])+';\n\t\tOut_factor = '+str(AT_cmlist['CM_'+AT_VS_list[x].split('AT_')[1]][1])+';\n\t\tIn_offset = '+str(VS_List[x][3])+';\n\t\tOut_offset = '+str(AT_cmlist['CM_'+AT_VS_list[x].split('AT_')[1]][0])+';\n\n')
                                        fc.write('\t\tif (DE_IntCan_'+x+' < INTCANHL_MAX_VALUE_'+x+') \n\t\t{\n\t\t\tif (DE_IntCan_'+x+' == INTCANHL_INIT_VALUE_'+x+') \n\t\t\t{\n\t\t\t\tDE_IntCan_'+buffer_list[1]+'.'+x+' = '+str(VS_list_factor[str(VS_List[x][0])][0])+';\n\t\t\t}\n\t\t\telse\n\t\t\t{\n\t\t\t\tConverted_data = ((DE_IntCan_'+x+' * In_factor) + In_offset);\n\n\t\t\t\tDE_IntCan_'+buffer_list[1]+'.'+x+' = ((Converted_data - Out_offset) / Out_factor);\n\t\t\t}\n\t\t}\n\t\telse\n\t\t{\n\t\t\tDE_IntCan_'+buffer_list[1]+'.'+x+' = '+str(VS_list_factor[str(VS_List[x][0])][1])+';\n\t\t}\n\n')
                                    else:
                                        fc.write('\t\tDE_IntCan_'+buffer_list[1]+'.'+x+' = DE_IntCan_'+x+';\n\n')
                                        
                                elif x in TS:
                                    if TS_List[x][0]==1:
                                        fc.write('\t\tIn_factor = '+str(TS_List[x][0])+';\n\t\tOut_factor = '+str(AT_cmlist['CM_'+x][1])+';\n\t\tIn_offset = '+str(TS_List[x][3])+';\n\t\tOut_offset = '+str(AT_cmlist['CM_'+x][0])+';\n\n')
                                        fc.write('\t\tif (DE_IntCan_'+x+' < INTCANHL_MAX_VALUE_'+x+') \n\t\t{\n\t\t\tif (DE_IntCan_'+x+' == INTCANHL_INIT_VALUE_'+x+') \n\t\t\t{\n\t\t\t\tDE_IntCan_'+buffer_list[1]+'.'+x+' = '+str(TS_list_factor[str(TS_List[x][0])][0])+';\n\t\t\t}\n\t\t\telse\n\t\t\t{\n\t\t\t\tConverted_data = ((DE_IntCan_'+x+' * In_factor) + In_offset);\n\n\t\t\t\tDE_IntCan_'+buffer_list[1]+'.'+x+' = ((Converted_data - Out_offset) / Out_factor);\n\t\t\t}\n\t\t}\n\t\telse\n\t\t{\n\t\t\tDE_IntCan_'+buffer_list[1]+'.'+x+' = '+str(TS_list_factor[str(TS_List[x][0])][1])+';\n\t\t}\n\n')
                                    else:
                                        fc.write('\t\tDE_IntCan_'+buffer_list[1]+'.'+x+' = DE_IntCan_'+x+';\n\n')
                                elif x in DBC_list:
                                    #print(x)
                                    if (DBC_dict[x][0]==1 and DBC_dict[x][3]==0):
                                        fc.write('\t\tDE_IntCan_'+buffer_list[1]+'.'+x+' = DE_IntCan_'+x+';\n\n')
                                    else:
                                        fc.write('\n\t\tIn_factor = '+str(DBC_dict[x][0])+';\n\t\tOut_factor = '+str(AT_cmlist['CM_'+x][1])+';\n\t\tIn_offset = '+str(DBC_dict[x][3])+';\n\t\tOut_offset = '+str(AT_cmlist['CM_'+x][0])+';\n\n')
                                        fc.write('\t\tConverted_data = ((DE_IntCan_'+x+' * In_factor) + In_offset);\n\t\tDE_IntCan_'+buffer_list[1]+'.'+x+' = ((Converted_data - Out_offset) / Out_factor);\n\n')
                            fc.write('\t}\n\telse\n\t{\n')
                            for x in struct_dict[buffer_var]:
                                if x in CS:
                                    if CS_List[x][0]!=1 and CS_List[x][0]!=0.5:
                                        fc.write('\t\tDE_IntCan_'+buffer_list[1]+'.'+x+' = '+str(CS_list_factor[str(CS_List[x][0])][0])+';\n\n')
                                    else:
                                        fc.write('\t\tDE_IntCan_'+buffer_list[1]+'.'+x+' = 0;\n\n')
                                elif x in VS:
                                    if VS_List[x][0]!=1 and VS_List[x][0]!=0.5:
                                        fc.write('\t\tDE_IntCan_'+buffer_list[1]+'.'+x+' = '+str(VS_list_factor[str(VS_List[x][0])][0])+';\n\n')
                                    else:
                                        fc.write('\t\tDE_IntCan_'+buffer_list[1]+'.'+x+' = 0;\n\n')
                                elif x in TS:
                                    if TS_List[x][0]==1:
                                        fc.write('\t\tDE_IntCan_'+buffer_list[1]+'.'+x+' = '+str(TS_list_factor[str(TS_List[x][0])][0])+';\n\n')
                                    else:
                                        fc.write('\t\tDE_IntCan_'+buffer_list[1]+'.'+x+' = 0;\n\n')
                                else:
                                    fc.write('\t\tDE_IntCan_'+buffer_list[1]+'.'+x+' = 0;\n\n')
                            fc.write('\t}\n')   
                            
            for element in list_iter:
                if element.startswith("SEND_P"):
                    buffer_list=element.split('DE_IntCan_')
                    if len(buffer_list)==2:
                        buffer_var='IT_'+buffer_list[1]
                        if buffer_var in struct_list:
                            # fc.write('\thiii\n')
                            if buffer_list[1].startswith("AC"):
                                if buffer_list[1] in ['AC_Measure_01', 'AC_Measure_02', 'AC_Measure_03', 'AC_Measure_04', 'AC_Measure_05','AC_Measure_06']:
                                    fc.write('\tRte_Write_P_'+element[7:]+'((const IT_'+buffer_list[1]+' *) &DE_IntCan_'+buffer_list[1]+');\n')
                                else:
                                    fc.write('\tRte_Write_P_'+element[7:]+'((const IT_'+buffer_list[1]+' *) &buffer_a.'+buffer_list[1]+');\n')
                            else:
                                fc.write('\tRte_Write_P_'+element[7:]+'((const IT_'+buffer_list[1]+' *) &DE_IntCan_'+buffer_list[1]+');\n')# using buffer_list to avoid redundant use of de_intcan
                        else:
                            # fc.write('\thiii222222222\n')
                            fc.write('\tRte_Write_P_'+element[7:]+'(DE_IntCan_'+buffer_list[1]+');\n')# using buffer_list to avoid redundant use of de_intcan
                        
            # fc.write('\tRte_Write_P_IntCAN_SrvState_active(Status_var);\n')
            fc.write('\n\tif ((Ret_Val_HVDC_Cntrl != 0) || (Ret_Val_DCDC_Cntrl != 0))\n\t{\n\t\tAux_U8_Add1 = DT_ERRORSTATUS_FAILED;\n\t}\n\telse\n\t{\n\t\tAux_U8_Add1 = DT_ERRORSTATUS_PASSED;\n\t}\n')
            fc.write('\tDemwrap_Appl_Write_error_intcanhl_qm_IntCan_Timeout_Error(Aux_U8_Add1);\n')
            fc.write('}\n\n')
        elif elemen==2:
            fc.write('\tRte_Read_R_DspResetReq_value(&DspResetReq_value);')
            for element in RESET_PARAMS:
                fc.write('\n\n\t/*'+element+' Controller Reset request implementation*/\n\n')
                fc.write('\tif (INTCANHL_mg_'+element+'_DspResetReq_state.'+element+'_DspResetReq_state_Init)\n\t{\n\t\tif (DspResetReq_value == 2)\n\t\t{\n\t\t\tINTCANHL_mg_'+element+'_DspResetReq_state.'+element+'_DspResetReq_state_Init = 0;\n\t\t\tINTCANHL_mg_'+element+'_DspResetReq_state.'+element+'_DspResetReq_state_Reset_Seq = 1;\n\t\t\t'+element+'_DspResetReq_Byte0 = 0;\n\t\t\t'+element+'_DspResetReq_Byte1 = 0;\n\t\t\t'+element+'_DspResetReq_Byte2 = 0;\n\t\t}\n\t\telse\n\t\t{\n\t\t\t'+element+'_DspResetReq_Byte0 = 2;\n\t\t\t'+element+'_DspResetReq_Byte1 = 16;\n\t\t\t'+element+'_DspResetReq_Byte2 = 129;\n\t\t}\n\t}\n')
                fc.write('\telse\n\t{\n\t\tif (INTCANHL_mg_'+element+'_DspResetReq_state.'+element+'_DspResetReq_state_Reset_Seq)\n\t\t{\n\t\t\tif (DspResetReq_value == 1)\n\t\t\t{\n\t\t\t\tINTCANHL_mg_'+element+'_DspResetReq_state.'+element+'_DspResetReq_state_Reset_Seq = 0;\n\t\t\t\tINTCANHL_mg_'+element+'_DspResetReq_state.'+element+'_DspResetReq_state_Init = 1;\n\t\t\t\t'+element+'_DspResetReq_Byte0 = 2;\n\t\t\t\t'+element+'_DspResetReq_Byte1 = 16;\n\t\t\t\t'+element+'_DspResetReq_Byte2 = 129;\n\t\t\t}\n\t\t\telse\n\t\t\t{\n\t\t\t\t'+element+'_DspResetReq_Byte0 = 0;\n\t\t\t\t'+element+'_DspResetReq_Byte1 = 0;\n\t\t\t\t'+element+'_DspResetReq_Byte2 = 0;\n\t\t\t}\n\t\t}\n')
                fc.write('\t\telse\n\t\t{\n\t\t\tINTCANHL_mg_'+element+'_DspResetReq_state.'+element+'_DspResetReq_state_Init = 1;\n\t\t\t'+element+'_DspResetReq_Byte0 = 2;\n\t\t\t'+element+'_DspResetReq_Byte1 = 16;\n\t\t\t'+element+'_DspResetReq_Byte2 = 129;\n\t\t}\n\t}')
                
            for element in list_iter:
                    buffer_list=element.split('DE_IntCan_')
                    if len(buffer_list)==2:
                        buffer_var='IT_'+buffer_list[1]
                        if buffer_var in struct_list:#port element +IT_ -->is searched in list of all messages. 
                            if buffer_var.startswith("IT_AC"):
                                if buffer_var in ['IT_AC_FblCpu2_Diag_Req', 'IT_AC_Diag_Req']:
                                    for y in struct_dict[buffer_var]:
                                        if y.endswith(("0", "1", "2")):
                                            fc.write('\n\tbuffer.'+buffer_list[1]+'.'+y+' = INTCANHL_mg_'+buffer_list[1]+'_Byte_'+y[-1]+';')
                                        else:
                                            fc.write('\n\tbuffer.'+buffer_list[1]+'.'+y+' = DE_IntCan_'+buffer_list[1]+'.'+y+';')
                                else:
                                    pass

            fc.write('\n\n\tif (CM_ENABLE_ENABLE == tIntCanReq_Status)\n\t{\n')
            for element in list_iter:
                if element.startswith("SEND_P"):
                    buffer_list=element.split('_DE_IntCan_')
                    if len(buffer_list)==2:
                        buffer_var='IT_'+buffer_list[1]

                        if buffer_list[1] in DBC_list:
                            if (DBC_dict[buffer_list[1]][0]==1 and DBC_dict[buffer_list[1]][3]==0):
                                if buffer_list[0][7:] in ['DCDC_HSFB_Diag_Req','HV_Diag_Req']:
                                    if buffer_list[1].endswith(("0", "1", "2")):
                                        if buffer_list[0][7:].startswith("DCDC"):
                                            testVar = "DCDC"
                                        else: 
                                            testVar = "HV"
                                        suffix = buffer_list[1][-1]
                                        fc.write('\t\tRte_Write_P_'+element[7:]+'('+testVar+'_DspResetReq_Byte'+ suffix+');\n')
                                    else:
                                        fc.write('\t\tRte_Write_P_'+element[7:]+'(INTCANHL_mg_'+buffer_list[1]+');\n')
                                else:
                                    # fc.write('\tmahesh\n')
                                    fc.write('\t\tRte_Write_P_'+element[7:]+'(DE_IntCan_'+buffer_list[0][7:]+'.'+buffer_list[1]+');\n')
                            else:
                                fc.write('\n\t\tIn_factor = '+str(DBC_dict[buffer_list[1]][0])+';\n\t\tOut_factor = '+str(AT_cmlist['CM_'+buffer_list[1]][1])+';\n\t\tIn_offset = '+str(DBC_dict[buffer_list[1]][3])+';\n\t\tOut_offset = '+str(AT_cmlist['CM_'+buffer_list[1]][0])+';\n')
                                fc.write('\t\tConverted_data = ((DE_IntCan_'+buffer_list[0][7:]+'.'+buffer_list[1]+' * In_factor) + In_offset);\n')
                                fc.write('\t\tOut_data = ((Converted_data - Out_offset) / Out_factor);\n')
                                fc.write('\t\tRte_Write_P_'+element[7:]+'(Out_data);\n')
#                             print('hi')
                        else:
                            fc.write('\t\tRte_Write_P_'+element[7:]+'(DE_IntCan_'+buffer_list[0][7:]+'.'+buffer_list[1]+');\n')           
            fc.write('\t\tRte_Write_P_Proxy_Tx_buffer((const IT_Proxy_Tx *) &buffer);\n')
            fc.write('\t}\n\telse\n\t{\n')
            for element in list_iter:
                if element.startswith("SEND_P"):
                    buffer_list=element.split('DE_IntCan_')
                    if len(buffer_list)==2:
                        buffer_var='IT_'+buffer_list[1]
                        fc.write('\t\tRte_Write_P_'+element[7:]+'(0);\n')
                                    
            fc.write('\t}\n')          
              
            fc.write('}\n\n')
    def cinit(list_init):
        for element in list_init:
            if element.startswith("SEND_P"):
                fc.write('DE_IntCan'+element[6:]+' = 0;\n')
            elif element.startswith("REC_R"): 
                 fc.write('DE_IntCan'+element[5:]+' = 0;\n')
        
    Init_val='RESTART_intcanhl_QM_intcanhl_QM_Main_Rx_10ms'
    fc=open(''+folder_path_output+'internal_QM_swc.c','w')
    fc.write('#ifndef INTCANHL_QM_C\n#define INTCANHL_QM_C\n\n')
    fc.write('#include "Rte_intcanhl_QM.h"\n#include "Rte.h"\n#include "intcanhl_qm.h"\n#include "demwrap_intcanhl_qm.h"\n#include "Subsystem_Defines.h"\n#include "Subsystem_Measure.h"\n\n')
    fc.write('#ifdef __cplusplus\nextern "C" {\n#endif\n\n')
    fc.write('#define intcanhl_qm_START_SEC_VAR_NOINIT_UNSPECIFIED\n#include "intcanhl_QM_MemMap.h"\n\n')
    fc.write('static VAR(uint8, intcanhl_qm_VAR_NOINIT) INTCANHL_mg_HV_Diag_Req_Byte_3;\nstatic VAR(uint8, intcanhl_qm_VAR_NOINIT) INTCANHL_mg_HV_Diag_Req_Byte_4;\nstatic VAR(uint8, intcanhl_qm_VAR_NOINIT) INTCANHL_mg_HV_Diag_Req_Byte_5;\nstatic VAR(uint8, intcanhl_qm_VAR_NOINIT) INTCANHL_mg_HV_Diag_Req_Byte_6;\nstatic VAR(uint8, intcanhl_qm_VAR_NOINIT) INTCANHL_mg_HV_Diag_Req_Byte_7;\nstatic VAR(uint8, intcanhl_qm_VAR_NOINIT) INTCANHL_mg_DCDC_LLC_Diag_Req_Byte_3;\nstatic VAR(uint8, intcanhl_qm_VAR_NOINIT) INTCANHL_mg_DCDC_LLC_Diag_Req_Byte_4;\nstatic VAR(uint8, intcanhl_qm_VAR_NOINIT) INTCANHL_mg_DCDC_LLC_Diag_Req_Byte_5;\nstatic VAR(uint8, intcanhl_qm_VAR_NOINIT) INTCANHL_mg_DCDC_LLC_Diag_Req_Byte_6;\nstatic VAR(uint8, intcanhl_qm_VAR_NOINIT) INTCANHL_mg_DCDC_LLC_Diag_Req_Byte_7;\nstatic VAR(uint8, intcanhl_qm_VAR_NOINIT) INTCANHL_mg_AC_Diag_Req_Byte_0;\nstatic VAR(uint8, intcanhl_qm_VAR_NOINIT) INTCANHL_mg_AC_Diag_Req_Byte_1;\nstatic VAR(uint8, intcanhl_qm_VAR_NOINIT) INTCANHL_mg_AC_Diag_Req_Byte_2;\nstatic VAR(uint8, intcanhl_qm_VAR_NOINIT) INTCANHL_mg_AC_FblCpu2_Diag_Req_Byte_0;\nstatic VAR(uint8, intcanhl_qm_VAR_NOINIT) INTCANHL_mg_AC_FblCpu2_Diag_Req_Byte_1;\n')
    fc.write('static VAR(uint8, intcanhl_qm_VAR_NOINIT) INTCANHL_mg_AC_FblCpu2_Diag_Req_Byte_2;\nstatic VAR(uint8, intcanhl_qm_VAR_NOINIT) INTCANHL_mg_DCDC_BBC_Diag_Req_Byte_0;\nstatic VAR(uint8, intcanhl_qm_VAR_NOINIT) INTCANHL_mg_DCDC_BBC_Diag_Req_Byte_1;\nstatic VAR(uint8, intcanhl_qm_VAR_NOINIT) INTCANHL_mg_DCDC_BBC_Diag_Req_Byte_2;\n')
    # fc.write('STATIC_GLOBAL boolean Sa23_BZ_TurnOnDelay_out;\nSTATIC_GLOBAL boolean Sa23_To_TurnOnDelay_out;\nSTATIC_GLOBAL uint8 Sa3_TurnOnDelay_final_out;\nSTATIC_GLOBAL boolean Sa3_TurnOnDelay_out;\nSTATIC_GLOBAL uint8 Sa101_DSPSTARTUP_HIGHBYTE_DCDC_BBC1;\nSTATIC_GLOBAL uint8 Sa101_DSPSTARTUP_HIGHBYTE_DCDC_BBC2;\n')
    # fc.write('STATIC_GLOBAL uint8 Sa101_DSPSTARTUP_HIGHBYTE_DCDC_BBC3;\nSTATIC_GLOBAL uint8 Sa101_DSPSTARTUP_HIGHBYTE_DCDC_BBC4;\nSTATIC_GLOBAL uint8 Sa101_DSPSTARTUP_HIGHBYTE_DCDC_BBC5;\nSTATIC_GLOBAL uint8 Sa93_DSPSTARTUP_HIGHBYTE_DCDC_BBC1;\nSTATIC_GLOBAL uint8 Sa93_DSPSTARTUP_HIGHBYTE_DCDC_BBC2;\nSTATIC_GLOBAL uint8 Sa93_DSPSTARTUP_HIGHBYTE_DCDC_BBC3;\n')
    # fc.write('STATIC_GLOBAL uint8 Sa93_DSPSTARTUP_HIGHBYTE_DCDC_BBC4;\nSTATIC_GLOBAL uint8 Sa93_DSPSTARTUP_HIGHBYTE_DCDC_BBC5;\nSTATIC_GLOBAL uint8 Sa94_DSPSTARTUP_HIGHBYTE_AC;\nSTATIC_GLOBAL uint8 Sa94_DSPSTARTUP_LOWBYTE_AC;\nSTATIC_GLOBAL uint8 Sa94_DSPSTARTUP_MIDDLEBYTE_AC;\nSTATIC_GLOBAL uint8 Sa95_DSPSTARTUP_HIGHBYTE_AC_FblCpu2;\nSTATIC_GLOBAL uint8 Sa95_DSPSTARTUP_LOWBYTE_AC_FblCpu2;\n')
    # fc.write('STATIC_GLOBAL uint8 Sa95_DSPSTARTUP_MIDDLEBYTE_AC_FblCpu2;\nSTATIC_GLOBAL uint8 Sa96_DSPSTARTUP_HIGHBYTE_DCDC_BBC;\nSTATIC_GLOBAL uint8 Sa96_DSPSTARTUP_LOWBYTE_DCDC_BBC;\nSTATIC_GLOBAL uint8 Sa96_DSPSTARTUP_MIDDLEBYTE_DCDC_BBC;\nSTATIC_GLOBAL uint8 Sa3_TurnOnDelay_final_ti;\n\n')
    for element in CDD_PARAMS:
        fc.write('static VAR(IT_SendResp, intcanhl_qm_VAR_NOINIT) intcanhl_calibSendResp'+element+';\nstatic VAR(IT_SendResp, intcanhl_qm_VAR_NOINIT) intcanhl_paramSendResp'+element+';\n')
    fc.write('static VAR(boolean, intcanhl_qm_VAR_NOINIT) bRxInitActive;\n')
    fc.write('static VAR(boolean, intcanhl_qm_VAR_NOINIT) INTCANHL_Output_value;\nstatic VAR(boolean, intcanhl_qm_VAR_NOINIT) INTCANHL_state_value;\nstatic VAR(uint8, intcanhl_qm_VAR_NOINIT) INTCANHL_Qualifier_value;\n')
    fc.write('\nCAL VAR(uint16, intcanhl_qm_VAR_INIT) Debounce_Time_C = 3;\nCAL VAR(uint16, intcanhl_qm_VAR_INIT) Waiting_Time_C = 30;\n\n')
 
    for element in CDD_PARAMS:
        fc.write('#define U8_'+element+'_Init_id 1\n')
        fc.write('#define U8_'+element+'_Error_id 2\n')
        fc.write('#define U8_'+element+'_Parameter_id 3\n')
        fc.write('#define U8_'+element+'_Calibration_id 4\n')
        fc.write('#define U8_'+element+'_Running_id 5\n')
    fc.write('\n')
    for element in CDD_PARAMS:
        fc.write('static struct INTCANHL_'+element+'_Statemachine_state INTCANHL_mg_'+element+'_Statemachine;\n')

    fc.write('static struct DCDC_DspResetReq_state INTCANHL_mg_DCDC_DspResetReq_state;\nstatic struct HV_DspResetReq_state INTCANHL_mg_HV_DspResetReq_state;\nstatic struct INTCANHL_Delay_Statemachine Delay_state_block;\nstatic struct IntCanResp_statemachine INTCANHL_mg_IntCanResp;\n\n')
    fc.write('static VAR(uint8, intcanhl_qm_VAR_NOINIT) INTCANHL_mg_cntr_value;\nstatic VAR(uint8, intcanhl_qm_VAR_NOINIT) INTCANHL_mg_out_value;\nstatic VAR(boolean, intcanhl_qm_VAR_NOINIT) INTCANHL_mg_To_out_value;\nstatic VAR(boolean, intcanhl_qm_VAR_NOINIT) INTCANHL_mg_BZ_out_value;\nstatic VAR(uint16, intcanhl_qm_VAR_NOINIT) INTCANHL_mg_Alive_Counter_value;\nstatic VAR(uint16, intcanhl_qm_VAR_NOINIT) INTCANHL_mg_message_Counter_value;\nstatic VAR(uint8, intcanhl_qm_VAR_NOINIT) INTCANHL_mg_old_delay_value;\n\n')
    fc.write('CAL VAR(uint8, intcanhl_qm_VAR_INIT) Max_Skip_Allowed_C = 1;\n')
    for element in CDD_PARAMS:
        fc.write('CAL VAR(boolean, intcanhl_qm_VAR_INIT) INTCANHL_bcalibSendResp2'+element+'_C = 0;\n')
        fc.write('CAL VAR(boolean, intcanhl_qm_VAR_INIT) INTCANHL_bparamSendResp2'+element+'_C = 0;\n')
        fc.write('CAL VAR(IT_SendResp, intcanhl_qm_VAR_INIT) INTCANHL_bcalibSendResp'+element+'_C = 1;\n')
        fc.write('CAL VAR(IT_SendResp, intcanhl_qm_VAR_INIT) INTCANHL_bparamSendResp'+element+'_C = 1;\n\n')

    fc.write('static uint16 Sa2_Data_Store_Memory;\n\n')
    fc.write('static VAR(boolean, intcanhl_qm_VAR_NOINIT) INTCANHL_bAC_Error;\nstatic VAR(boolean, intcanhl_qm_VAR_NOINIT) INTCANHL_bDC_Error;\nstatic VAR(boolean, intcanhl_qm_VAR_NOINIT) INTCANHL_bDCDC_Error;\n\n')
    for element in CDD_PARAMS:
        fc.write('static VAR(uint8, intcanhl_qm_VAR_NOINIT) INTCANHL_mg_u8'+element+'_StateMachine_Calib_Req;\nstatic VAR(uint8, intcanhl_qm_VAR_NOINIT) INTCANHL_mg_u8'+element+'_StateMachine_param_Req;\n')
    fc.write('static VAR(uint8, intcanhl_qm_VAR_NOINIT) INTCANHL_mg_u8Delay_block_flag;\nstatic VAR(uint8, intcanhl_qm_VAR_NOINIT) INTCANHL_mg_u8Delay_block_Output;\nstatic VAR(uint8, intcanhl_qm_VAR_NOINIT) INTCANHL_mg_u8Resp_block_flag;\nstatic VAR(uint8, intcanhl_qm_VAR_NOINIT) INTCANHL_mg_u8Resp_block_Output;\n\n')
    for element in CDD_PARAMS:
        fc.write('static void mg_'+element+'_state_IntCan_active_ex(void);\n')
    fc.write('\n')
    fc.write('#define intcanhl_qm_STOP_SEC_VAR_NOINIT_UNSPECIFIED\n#include "intcanhl_QM_MemMap.h"\n\n')
    fc.write('void RESTART_intcanhl_QM_intcanhl_QM_Main_Rx_10ms(void)\n{\n')
    for element in CDD_PARAMS:
        fc.write('\tINTCANHL_mg_u8'+element+'_StateMachine_Calib_Req = 0.;\n\tINTCANHL_mg_u8'+element+'_StateMachine_param_Req = 0.;\n\tINTCANHL_b'+element+'_Error = 0;\n')
    fc.write('\tINTCANHL_mg_u8Resp_block_flag = 0.;\n\tINTCANHL_mg_u8Resp_block_Output = 0.;\n\n')
    
    for element in CDD_PARAMS:
        fc.write('\tINTCANHL_mg_'+element+'_Statemachine.u8'+element+'_Statemachine_Qualifier_INIT_state = 0;\n\tINTCANHL_mg_'+element+'_Statemachine.u8'+element+'_Statemachine_Qualifier_NOT_INIT_state = 0;\n\tINTCANHL_mg_'+element+'_Statemachine.u8'+element+'_Statemachine_IntCan_active_state = 0;\n\tINTCANHL_mg_'+element+'_Statemachine.u8'+element+'_Statemachine_IntCan_active_ns_state = 0;\n\tINTCANHL_mg_'+element+'_Statemachine.u8'+element+'_Statemachine_Idle_state = 0;\n\tINTCANHL_mg_'+element+'_Statemachine.u8'+element+'_Statemachine_IntCan_NotActive1_state = 0;\n')
    for element in RESET_PARAMS:
        fc.write('\tINTCANHL_mg_'+element+'_DspResetReq_state.'+element+'_DspResetReq_state_Init = 0;\n\tINTCANHL_mg_'+element+'_DspResetReq_state.'+element+'_DspResetReq_state_Reset_Seq = 0;\n')
    fc.write('\tDelay_state_block.u8Delay_Statemachine_default = 0;\n\tDelay_state_block.u8Delay_Statemachine_Wait = 0;\n\tDelay_state_block.u8Delay_Statemachine_Pass = 0;\n\tINTCANHL_mg_IntCanResp.u8Resp_Statemachine_Shutdown = 0;\n\tINTCANHL_mg_IntCanResp.u8Resp_Statemachine_Startup = 0;\n\tINTCANHL_mg_IntCanResp.u8Resp_Statemachine_default = 0;\n\tINTCANHL_mg_IntCanResp.u8Resp_Statemachine_Shutdown1 = 0;\n\tINTCANHL_mg_HV_Diag_Req_Byte_3 = 0;\n\tINTCANHL_mg_HV_Diag_Req_Byte_4 = 0;\n\tINTCANHL_mg_HV_Diag_Req_Byte_5 = 0;\n\tINTCANHL_mg_HV_Diag_Req_Byte_6 = 0;\n\tINTCANHL_mg_HV_Diag_Req_Byte_7 = 0;\n\tSa2_Data_Store_Memory = 0;\n')
    fc.write('\tINTCANHL_mg_DCDC_LLC_Diag_Req_Byte_3 = 0;\n\tINTCANHL_mg_DCDC_LLC_Diag_Req_Byte_4 = 0;\n\tINTCANHL_mg_DCDC_LLC_Diag_Req_Byte_5 = 0;\n\tINTCANHL_mg_DCDC_LLC_Diag_Req_Byte_6 = 0;\n\tINTCANHL_mg_DCDC_LLC_Diag_Req_Byte_7 = 0;\n\tINTCANHL_mg_AC_Diag_Req_Byte_2 = 129;\n\tINTCANHL_mg_AC_Diag_Req_Byte_0 = 2;\n\tINTCANHL_mg_AC_Diag_Req_Byte_1 = 16;\n\tINTCANHL_mg_AC_FblCpu2_Diag_Req_Byte_2 = 129;\n\tINTCANHL_mg_AC_FblCpu2_Diag_Req_Byte_0 = 2;\n\tINTCANHL_mg_AC_FblCpu2_Diag_Req_Byte_1 = 16;\n\tINTCANHL_mg_DCDC_BBC_Diag_Req_Byte_2 = 129;\n\tINTCANHL_mg_DCDC_BBC_Diag_Req_Byte_0 = 2;\n\tINTCANHL_mg_DCDC_BBC_Diag_Req_Byte_1 = 16;\n')
    for element in CDD_PARAMS:
        fc.write('\tintcanhl_calibSendResp'+element+' = 0;\n')
        fc.write('\tintcanhl_paramSendResp'+element+' = 0;\n')
    fc.write('\tINTCANHL_mg_message_Counter_value = 0;\n\tINTCANHL_mg_Alive_Counter_value = 0;\n\tINTCANHL_mg_cntr_value = 0;\n\tINTCANHL_mg_old_delay_value = 0;\n\tbRxInitActive = 0;\n}\n\n')    

    fc.write('FUNC(void, intcanhl_qm_CODE) '+Rx_run+'(void)\n{\n')
    cfile(Rx_list,1)
    fc.write('FUNC(void, intcanhl_qm_CODE) '+Tx_run+'(void)\n{\n')
    cfile(Tx_list,2)
    fc.write('FUNC(void, intcanhl_qm_CODE) '+Init_run+'(void)\n{\n\tRESTART_intcanhl_QM_intcanhl_QM_Main_Rx_10ms();\n}\n\n')
    # fc.write('(void) '+Init_val+'(void)\n{\n')
    # fc.write('}\n\n')
    for element in CDD_PARAMS:
        fc.write('static void mg_'+element+'_state_IntCan_active_ex(void)\n{\n\tswitch (INTCANHL_mg_'+element+'_Statemachine.u8'+element+'_Statemachine_IntCan_active_ns_state)\n\t{')
        fc.write('\n\t\tcase U8_'+element+'_Init_id:\n\t\t{\n\t\t\tINTCANHL_mg_'+element+'_Statemachine.u8'+element+'_Statemachine_IntCan_active_ns_state = 0;\n\t\t\tbreak;\n\t\t}')
        fc.write('\n\t\tcase U8_'+element+'_Error_id:\n\t\t{\n\t\t\tif (INTCANHL_mg_'+element+'_Statemachine.u8'+element+'_Statemachine_Idle_state)\n\t\t\t{\n\t\t\t\tINTCANHL_mg_'+element+'_Statemachine.u8'+element+'_Statemachine_Idle_state = 0;\n\t\t\t}\n\t\t\tINTCANHL_mg_'+element+'_Statemachine.u8'+element+'_Statemachine_IntCan_active_ns_state = 0;\n\t\t\tbreak;\n\t\t}')
        fc.write('\n\t\tcase U8_'+element+'_Parameter_id:\n\t\t{\n\t\t\tINTCANHL_mg_'+element+'_Statemachine.u8'+element+'_Statemachine_IntCan_active_ns_state = 0;\n\t\t\tbreak;\n\t\t}')
        fc.write('\n\t\tcase U8_'+element+'_Calibration_id:\n\t\t{\n\t\t\tINTCANHL_mg_'+element+'_Statemachine.u8'+element+'_Statemachine_IntCan_active_ns_state = 0;\n\t\t\tbreak;\n\t\t}')
        fc.write('\n\t\tdefault:\n\t\t{\n\t\t\tINTCANHL_mg_'+element+'_Statemachine.u8'+element+'_Statemachine_IntCan_active_ns_state = 0;\n\t\t\tbreak;\n\t\t}')
        fc.write('\n\t}\n\tINTCANHL_mg_'+element+'_Statemachine.u8'+element+'_Statemachine_IntCan_active_state = 0;\n}\n\n')

    fc.write('#ifdef __cplusplus\n}\n#endif\n\n#endif')
    fc.close()
    
    fh=open(''+folder_path_output+'internal_QM_swc.h','w')
    fh.write('#include "Rte_Type.h"\n#include "tl_defines_a.h"\n\n')
    for element in qm_list_all_signal:
        if element.startswith('TS') or element.startswith('VS') or element.startswith('CS'):
            value = VS_CS_TS_DIC.get(element)
            fh.write('#define INTCANHL_MAX_VALUE_'+element+' ((IT_'+element+') '+str(value+1)+')\n')
            fh.write('#define INTCANHL_INIT_VALUE_'+element+' ((IT_'+element+') '+str(value)+')\n')
    for element in CDD_PARAMS:
        fh.write('\nstruct INTCANHL_'+element+'_Statemachine_state\n{\n\tuint8 u8'+element+'_Statemachine_IntCan_active_ns_state : 3;\n\tuint8 u8'+element+'_Statemachine_Qualifier_INIT_state : 1;\n\tuint8 u8'+element+'_Statemachine_Qualifier_NOT_INIT_state : 1;\n\tuint8 u8'+element+'_Statemachine_IntCan_active_state : 1;\n\tuint8 u8'+element+'_Statemachine_Idle_state : 1;\n\tuint8 u8'+element+'_Statemachine_IntCan_NotActive1_state : 1;\n};\n')
    fh.write('\nstruct DCDC_DspResetReq_state\n{\n\tuint8 DCDC_DspResetReq_state_Init : 1;\n\tuint8 DCDC_DspResetReq_state_Reset_Seq : 1;\n};\n')
    fh.write('\nstruct HV_DspResetReq_state\n{\n\tuint8 HV_DspResetReq_state_Init : 1;\n\tuint8 HV_DspResetReq_state_Reset_Seq : 1;\n};\n')
    fh.write('\nstruct INTCANHL_Delay_Statemachine\n{\n\tuint8 u8Delay_Statemachine_default : 1;\n\tuint8 u8Delay_Statemachine_Wait : 1;\n\tuint8 u8Delay_Statemachine_Pass : 1;\n};\n')
    fh.write('\nstruct IntCanResp_statemachine\n{\n\tuint8 u8Resp_Statemachine_Shutdown : 1;\n\tuint8 u8Resp_Statemachine_Startup : 1;\n\tuint8 u8Resp_Statemachine_default : 1;\n\tuint8 u8Resp_Statemachine_Shutdown1 : 1;\n};\n')
    
    fh.write('\nFUNC(void, intcanhl_qm_CODE) '+Rx_run+'(void);\n\n')
    fh.write('FUNC(void, intcanhl_qm_CODE) '+Tx_run+'(void);\n\n')
    fh.write('FUNC(void, intcanhl_qm_CODE) '+Init_run+'(void);\n\n')
    fh.write('extern void '+Init_val+'(void);')
    fh.close()
    return(struct_list,imp_dt,map_dict)
