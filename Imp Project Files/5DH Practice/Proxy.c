/**********************************************************************************************************************
 *  FILE REQUIRES USER MODIFICATIONS
 *  Template Scope: sections marked with Start and End comments
 *  -------------------------------------------------------------------------------------------------------------------
 *  This file includes template code that must be completed and/or adapted during BSW integration.
 *  The template code is incomplete and only intended for providing a signature and an empty implementation.
 *  It is neither intended nor qualified for use in series production without applying suitable quality measures.
 *  The template code must be completed as described in the instructions given within this file and/or in the.
 *  Technical Reference.
 *  The completed implementation must be tested with diligent care and must comply with all quality requirements which.
 *  are necessary according to the state of the art before its use.
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Proxy.c
 *           Config:  DCDC_5DH.dpa
 *        SW-C Type:  Proxy
 *
 *        Generator:  MICROSAR RTE Generator Version 4.28.0
 *                    RTE Core Version 1.28.0
 *          License:  CBD2200292
 *
 *      Description:  C-Code implementation template for SW-C <Proxy>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Data Types:
 * ===========
 * DtLlcState
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * DtPwmFreq
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * Dt_ErrClass
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 *********************************************************************************************************************/

#include "Rte_Proxy.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "StandardMacros.h"

static CONST(uint8,CRC_CONST)Crc8Table[256] =
{
	0x00u, 0x1du, 0x3au, 0x27u,
	0x74u, 0x69u, 0x4eu, 0x53u,
	0xe8u, 0xf5u, 0xd2u, 0xcfu,
	0x9cu, 0x81u, 0xa6u, 0xbbu,
	0xcdu, 0xd0u, 0xf7u, 0xeau,
	0xb9u, 0xa4u, 0x83u, 0x9eu,
	0x25u, 0x38u, 0x1fu, 0x02u,
	0x51u, 0x4cu, 0x6bu, 0x76u,
	0x87u, 0x9au, 0xbdu, 0xa0u,
	0xf3u, 0xeeu, 0xc9u, 0xd4u,
	0x6fu, 0x72u, 0x55u, 0x48u,
	0x1bu, 0x06u, 0x21u, 0x3cu,
	0x4au, 0x57u, 0x70u, 0x6du,
	0x3eu, 0x23u, 0x04u, 0x19u,
	0xa2u, 0xbfu, 0x98u, 0x85u,
	0xd6u, 0xcbu, 0xecu, 0xf1u,
	0x13u, 0x0eu, 0x29u, 0x34u,
	0x67u, 0x7au, 0x5du, 0x40u,
	0xfbu, 0xe6u, 0xc1u, 0xdcu,
	0x8fu, 0x92u, 0xb5u, 0xa8u,
	0xdeu, 0xc3u, 0xe4u, 0xf9u,
	0xaau, 0xb7u, 0x90u, 0x8du,
	0x36u, 0x2bu, 0x0cu, 0x11u,
	0x42u, 0x5fu, 0x78u, 0x65u,
	0x94u, 0x89u, 0xaeu, 0xb3u,
	0xe0u, 0xfdu, 0xdau, 0xc7u,
	0x7cu, 0x61u, 0x46u, 0x5bu,
	0x08u, 0x15u, 0x32u, 0x2fu,
	0x59u, 0x44u, 0x63u, 0x7eu,
	0x2du, 0x30u, 0x17u, 0x0au,
	0xb1u, 0xacu, 0x8bu, 0x96u,
	0xc5u, 0xd8u, 0xffu, 0xe2u,
	0x26u, 0x3bu, 0x1cu, 0x01u,
	0x52u, 0x4fu, 0x68u, 0x75u,
	0xceu, 0xd3u, 0xf4u, 0xe9u,
	0xbau, 0xa7u, 0x80u, 0x9du,
	0xebu, 0xf6u, 0xd1u, 0xccu,
	0x9fu, 0x82u, 0xa5u, 0xb8u,
	0x03u, 0x1eu, 0x39u, 0x24u,
	0x77u, 0x6au, 0x4du, 0x50u,
	0xa1u, 0xbcu, 0x9bu, 0x86u,
	0xd5u, 0xc8u, 0xefu, 0xf2u,
	0x49u, 0x54u, 0x73u, 0x6eu,
	0x3du, 0x20u, 0x07u, 0x1au,
	0x6cu, 0x71u, 0x56u, 0x4bu,
	0x18u, 0x05u, 0x22u, 0x3fu,
	0x84u, 0x99u, 0xbeu, 0xa3u,
	0xf0u, 0xedu, 0xcau, 0xd7u,
	0x35u, 0x28u, 0x0fu, 0x12u,
	0x41u, 0x5cu, 0x7bu, 0x66u,
	0xddu, 0xc0u, 0xe7u, 0xfau,
	0xa9u, 0xb4u, 0x93u, 0x8eu,
	0xf8u, 0xe5u, 0xc2u, 0xdfu,
	0x8cu, 0x91u, 0xb6u, 0xabu,
	0x10u, 0x0du, 0x2au, 0x37u,
	0x64u, 0x79u, 0x5eu, 0x43u,
	0xb2u, 0xafu, 0x88u, 0x95u,
	0xc6u, 0xdbu, 0xfcu, 0xe1u,
	0x5au, 0x47u, 0x60u, 0x7du,
	0x2eu, 0x33u, 0x14u, 0x09u,
	0x7fu, 0x62u, 0x45u, 0x58u,
	0x0bu, 0x16u, 0x31u, 0x2cu,
	0x97u, 0x8au, 0xadu, 0xb0u,
	0xe3u, 0xfeu, 0xd9u, 0xc4u
};

static uint8 u8CrcDataIn[9];
static uint8 u8CrcVal;
  
static FUNC(void, Proxy_CODE) Compute_CRC08(uint8 Data[]);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * BoostCmd_VbulkRef: Integer in interval [0...255]
 *   Unit: [V], Factor: 1, Offset: 300
 * DcDc_LlcFreq: Integer in interval [0...255]
 *   Unit: [Hz], Factor: 2048, Offset: 0
 * DtDCDCHVNetworkVoltag_V2: Integer in interval [0...8191]
 *   Unit: [V], Factor: 0.1, Offset: 0
 * Dt_Clock_DCDC_RN104: Integer in interval [0...15]
 * Dt_DCDCCurrentOutput: Integer in interval [0...255]
 * Dt_DCDCInputPower: Integer in interval [0...63]
 *   Unit: [kW], Factor: 0.1, Offset: 0
 * Dt_DCDC_ElecSysFailureDisplay: Boolean
 * Dt_DCDC_MajorElecFailureDisplay: Boolean
 * Dt_DCDC_u13IoutMeas: Integer in interval [0...255]
 * Dt_DiagStatus_u2FailureCount: Integer in interval [0...3]
 * Dt_Ireso_10mA: Integer in interval [0...4095]
 *   Unit: [A], Factor: 0.01, Offset: 0
 * Dt_MaxCurrentAvailableBySystem: Integer in interval [0...254]
 * Dt_Ubulk_100mV: Integer in interval [0...8191]
 *   Factor: 0.1, Offset: 0
 * Dt_Uout2_10mV: Integer in interval [0...16383]
 *   Factor: 0.01, Offset: 0
 * Dt_Uout_10mV: Integer in interval [0...8191]
 *   Unit: [V], Factor: 0.01, Offset: 0
 * Llc_State: Integer in interval [0...7]
 * boolean: Boolean (standard type)
 * sint16: Integer in interval [-32768...32767] (standard type)
 * u11ErrIntC: Integer in interval [0...2047]
 * u11ErrIntC_Last: Integer in interval [0...2047]
 * u15WantInt: Integer in interval [0...32767]
 * u3ErrInput: Integer in interval [0...7]
 * u3ErrInput_Last: Integer in interval [0...7]
 * u5ErrIntD: Integer in interval [0...31]
 * u5ErrIntD_Last: Integer in interval [0...31]
 * u6ErrOutput: Integer in interval [0...63]
 * u6ErrOutput_Last: Integer in interval [0...63]
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * DCDC_MILLamp: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_MIL_lamp_off_request (0U)
 *   Cx1_MIL_Lamp_on_request (1U)
 *   Cx2_MIL_lamp_flash_request (2U)
 *   Cx3_MIL_lamp_auto_test (3U)
 * DtLlcState: Enumeration of integer in interval [0...15] with enumerators
 *   LLC_STATE_INIT (0U)
 *   LLC_STATE_IDLE (1U)
 *   LLC_STATE_RAMPUP (2U)
 *   LLC_STATE_RUN (3U)
 *   LLC_STATE_RAMDOWN (4U)
 * DtPwmFreq: Enumeration of integer in interval [0...4294967295] with enumerators
 *   LLC_PWM_FREQ_OFF (500000U)
 *   LLC_PWM_FREQ_STOP (400001U)
 *   LLC_PWM_FREQ_START (400000U)
 *   LLC_PWM_FREQ_MAX (250000U)
 *   LLC_PWM_FREQ_RESO (115000U)
 *   LLC_PWM_FREQ_MIN (84500U)
 * Dt_AD_MajorFlt: Enumeration of integer in interval [0...15] with enumerators
 *   PmuEccEdcTst (1U)
 *   SriTest (2U)
 *   PflashMonTst (4U)
 *   SramEccTst (8U)
 *   SpbTstPeriphera (16U)
 *   PhlSramTst (32U)
 *   SpbTstTimeout (64U)
 *   SmuTst_NmiTst (128U)
 *   CpuWdgTst (256U)
 *   LockStepTst (512U)
 * Dt_AD_MinorFlt: Enumeration of integer in interval [0...15] with enumerators
 *   CpuMpuTst (1U)
 *   SmuTst_IrqTst (2U)
 *   SmuTst_RtTst (4U)
 *   VltmTst (8U)
 *   TrapTst (16U)
 *   ClkmTst (32U)
 *   RegAccProTst (64U)
 *   IRTst (128U)
 *   SffTst (256U)
 *   SfrCmpTst (512U)
 *   SfrCrcTst (1024U)
 *   AD_OVPC_Tst (2048U)
 * Dt_DCDCInterlockState: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Unvailable_Value (0U)
 *   Cx1_Interlock_Open (1U)
 *   Cx2_Interlock_Close (2U)
 *   Cx3_Not_Used (3U)
 * Dt_DCDCState: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Starting_mode (0U)
 *   Cx1_Standby (1U)
 *   Cx2_DirectMode (2U)
 *   Cx3_Unavailable (3U)
 * Dt_DCDC_Fault_Type: Enumeration of integer in interval [0...7] with enumerators
 *   Cx0_NO_FAULT (0U)
 *   Cx1_FAULT_CLASS_C (1U)
 *   Cx2_FAULT_CLASS_D (2U)
 *   Cx3_FAULT_UNBALLAST (3U)
 *   Cx4_FAULT_SAFETY_BARRIER_LOST (4U)
 *   Cx5_FAULT_TYPE_5 (5U)
 *   Cx6_FAULT_RESERVED6 (6U)
 *   Cx7_FAULT_RESERVED7 (7U)
 * Dt_DCDC_RefusetoSleep: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_reserved (0U)
 *   Cx1_DCDC_refuse_to_sleep (1U)
 *   Cx2_DCDC_ready_to_sleep (2U)
 *   Cx3_reserved (3U)
 * Dt_ErrClass: Enumeration of integer in interval [0...255] with enumerators
 *   ERR_NONE (0U)
 *   ERR_CLASS_A3 (1U)
 *   ERR_CLASS_A2 (2U)
 *   ERR_CLASS_A1 (3U)
 *   ERR_CLASS_A (4U)
 *   ERR_CLASS_B (5U)
 *   ERR_CLASS_C (6U)
 *   ERR_CLASS_D (7U)
 * Dt_FailCode: Enumeration of integer in interval [0...4294967295] with enumerators
 *   INT_ERR0_COMM (1U)
 *   INT_ERR1_BULK_OV (2U)
 *   INT_ERR2_OPVOLT_DIFF (4U)
 *   INT_ERR3_IPVOLT_BULKVOLT_DIFF (8U)
 *   INT_ERR4_OPCURR_CALC_DIFF (16U)
 *   INT_ERR5_INPUT_OC_SW (32U)
 *   INT_ERR6_VOUT_SENSOR1 (64U)
 *   INT_ERR7_VOUT_SENSOR2 (128U)
 *   INT_ERR8_ADC_REF_VOLT (256U)
 *   INT_ERR9_WATERTEMP_TH (512U)
 *   INT_ERR10_WATERTEMP_DERATE (1024U)
 *   INT_ERR11_5VREF_OUTOFRANGE (2048U)
 *   INT_ERR12_3V3REF_OUTOFRANGE (4096U)
 *   INT_ERR13_AUTODIAG_MINORFAULT (8192U)
 *   INT_ERR14 (16384U)
 *   INT_ERR15 (32768U)
 *   INT_ERR16_OUTP_24V_OV (65536U)
 *   INT_ERR17_OUTP_18V_OV (131072U)
 *   INT_ERR18_OUTP_HW_18V_OV (262144U)
 *   INT_ERR19_OUTP_16V_OV (524288U)
 *   INT_ERR20_WATCHDOG (1048576U)
 *   INT_ERR21_PRECHARG (2097152U)
 *   INT_ERR22_LLC_OC (4194304U)
 *   INT_ERR23_SMU (8388608U)
 *   INT_ERR24_BULK_NOK (16777216U)
 *   INT_ERR25_INTERN_TEMP_HIGH (33554432U)
 *   INT_ERR26 (67108864U)
 *   INT_ERR27_HV_UIN_UV (134217728U)
 *   INT_ERR28_INPUT_CURRENT_STANDBY (268435456U)
 *   INT_ERR29_RESO_CURRENT_STANDBY (536870912U)
 *   INT_ERR30_VOUTSENSE_STANDBY (1073741824U)
 *   INT_ERR31_AUTODIAG_MAJORFAULT (2147483648U)
 * Dt_NetErrCode: Enumeration of integer in interval [0...4294967295] with enumerators
 *   NETWORK_BUSOFF (1U)
 *   NETWORK_LOST_HEVC_RN107 (2U)
 *   NETWORK_WAKESLEEP_INVALID_HEVC_RN107 (4U)
 *   NETWORK_ACTIVATION_INVALID_HEVC_RN107 (8U)
 *   NETWORK_GADE_INVALID_HEVC_RN107 (16U)
 *   NETWORK_LOST_HEVC_RN123 (32U)
 *   NETWORK_REFVOLT_INVALID (64U)
 *   NETWORK_LOST_BMS_RN108 (128U)
 *   NETWORK_INTERLOCK_INVALID_BMS_RN108 (256U)
 *   FAILURE_CODE10 (512U)
 *   FAILURE_CODE11 (1024U)
 *   FAILURE_CODE12 (2048U)
 *   FAILURE_CODE13 (4096U)
 *   FAILURE_CODE14 (8192U)
 *   NETWORK_LOST_HEVC_RN104 (16384U)
 *   NETWORK_LOST_HEVC_RN108 (32768U)
 *   NETWORK_LOST_HEVC_RN111 (65536U)
 *   NETWORK_VehicleSpeed_HV_INVALID (131072U)
 *   NETWORK_DistanceTotalizer_HV_INVALID (262144U)
 *   NETWORK_AbsoluteTimeSince1rstIgn_HV_INVALID (524288U)
 *   NETWORK_VehicleStates_HV_INVALID (1048576U)
 *   NETWORK_LOST_RN4 (2097152U)
 *   NETWORK_WAKESLEEP_INVALID (4194304U)
 *   NETWORK_ACTIVATION_INVALID (8388608U)
 *   NETWORK_GADE_INVALID (16777216U)
 *   NETWORK_LOST_RN1 (33554432U)
 *   NETWORK_INTERLOCK_INVALID (67108864U)
 *   NETWORK_LOST_RN2RN18 (134217728U)
 *   NETWORK_LOST_RN123 (268435456U)
 *
 * Record Types:
 * =============
 * Dt_SG_DCDC_RN104: Record with elements
 *   Clock_DCDC_RN104 of type Dt_Clock_DCDC_RN104
 *   CRC_DCDC_RN104 of type uint8
 *   DCDC_Fault_Type of type Dt_DCDC_Fault_Type
 *   DCDC_RefusetoSleep of type Dt_DCDC_RefusetoSleep
 *   DCDCCurrentOutput of type Dt_DCDCCurrentOutput
 *   DCDCState of type Dt_DCDCState
 *   MaxCurrentAvailableBySystem of type Dt_MaxCurrentAvailableBySystem
 *   DCDC_12VCurrent of type uint16
 *   DCDC_Max12VcurrentAvailable_HV of type uint16
 *
 *********************************************************************************************************************/


#define Proxy_START_SEC_CODE
#include "Proxy_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Proxy_vInit
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Proxy_vInit_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Proxy_CODE) Proxy_vInit(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Proxy_vInit
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Proxy_vMain
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_R_AP_DERATE_bDerateActiv(boolean *data)
 *   Std_ReturnType Rte_Read_R_AP_DERATE_u16IoutDerate(uint16 *data)
 *   Std_ReturnType Rte_Read_R_AP_DIAG_bDrvEnable(boolean *data)
 *   Std_ReturnType Rte_Read_R_AP_DIAG_bFailureReset(boolean *data)
 *   Std_ReturnType Rte_Read_R_AP_DIAG_bHwLatchReset(boolean *data)
 *   Std_ReturnType Rte_Read_R_AP_DIAG_tErrClass(Dt_ErrClass *data)
 *   Std_ReturnType Rte_Read_R_AP_DiagToCan_ErrInput(uint8 *data)
 *   Std_ReturnType Rte_Read_R_AP_DiagToCan_ErrInput_Last(uint8 *data)
 *   Std_ReturnType Rte_Read_R_AP_DiagToCan_ErrOutput(uint8 *data)
 *   Std_ReturnType Rte_Read_R_AP_DiagToCan_ErrOutput_Last(uint8 *data)
 *   Std_ReturnType Rte_Read_R_AP_DiagToCan_FailureCount(uint8 *data)
 *   Std_ReturnType Rte_Read_R_AP_DiagToCan_IntFailure(Dt_FailCode *data)
 *   Std_ReturnType Rte_Read_R_AP_DiagToCan_IntFailure_Last(uint32 *data)
 *   Std_ReturnType Rte_Read_R_AP_LLC_bPwmEnable(boolean *data)
 *   Std_ReturnType Rte_Read_R_AP_LLC_u16UoutRef_10mV(uint16 *data)
 *   Std_ReturnType Rte_Read_R_AP_LLC_u32PwmFreq(DtPwmFreq *data)
 *   Std_ReturnType Rte_Read_R_AP_LLC_u8BulkRef(uint8 *data)
 *   Std_ReturnType Rte_Read_R_AP_LlcToCan_InputPower100W(Dt_DCDCInputPower *data)
 *   Std_ReturnType Rte_Read_R_AP_LlcToCan_LlcState(DtLlcState *data)
 *   Std_ReturnType Rte_Read_R_AP_LlcToCan_u8IoutMeas(Dt_DCDC_u13IoutMeas *data)
 *   Std_ReturnType Rte_Read_R_AP_NetworkDiag_u16Failure(Dt_NetErrCode *data)
 *   Std_ReturnType Rte_Read_R_ASR_AverageLlcFreq_u32Val(uint32 *data)
 *   Std_ReturnType Rte_Read_R_DCDCState_Dp_DCDCState(Dt_DCDCState *data)
 *   Std_ReturnType Rte_Read_R_DCDC_RefusetoSleep_Dp_DCDC_RefusetoSleep(Dt_DCDC_RefusetoSleep *data)
 *   Std_ReturnType Rte_Read_R_GADE_Signal(uint8 *data)
 *   Std_ReturnType Rte_Read_R_Pi_AutoDiag_MajorFlt_Dp_AD_Fault(Dt_AD_MajorFlt *data)
 *   Std_ReturnType Rte_Read_R_Pi_AutoDiag_MinorFlt_Dp_AD_Fault(Dt_AD_MinorFlt *data)
 *   Std_ReturnType Rte_Read_R_Pi_MaxCurrentAvailableBySystem_Dp_MaxCurrentAvailableBySystem(Dt_MaxCurrentAvailableBySystem *data)
 *   Std_ReturnType Rte_Read_R_SP_CDDADC_s16IresoAverage_10mA(sint16 *data)
 *   Std_ReturnType Rte_Read_R_SP_CDDADC_u16Ireso1_10mA(uint16 *data)
 *   Std_ReturnType Rte_Read_R_SP_CDDADC_u16Uout1_10mV(uint16 *data)
 *   Std_ReturnType Rte_Read_R_SP_CDDADC_u16Uout2_10mV(uint16 *data)
 *   Std_ReturnType Rte_Read_R_SP_CDDADC_u16Uout_10mV(uint16 *data)
 *   Std_ReturnType Rte_Read_R_SP_UART_bBulkOK(boolean *data)
 *   Std_ReturnType Rte_Read_R_SP_UART_bBulkOv(boolean *data)
 *   Std_ReturnType Rte_Read_R_SP_UART_bIntComErr(boolean *data)
 *   Std_ReturnType Rte_Read_R_SP_UART_u16InCurr_10mA(uint16 *data)
 *   Std_ReturnType Rte_Read_R_SP_UART_u16UBulk_100mV(uint16 *data)
 *   Std_ReturnType Rte_Read_R_SP_UART_u16Uin_100mV(uint16 *data)
 *   Std_ReturnType Rte_Read_R_SP_UART_u8BulkRef(uint8 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_P_CRC_DCDC_RN104_DT_CRC_DCDC_RN104(uint8 data)
 *   Std_ReturnType Rte_Write_P_Clock_DCDC_RN104_DT_Clock_DCDC_RN104(Dt_Clock_DCDC_RN104 data)
 *   Std_ReturnType Rte_Write_P_DCDCCurrentOutput_Dp_DCDCCurrentOutput(Dt_DCDCCurrentOutput data)
 *   Std_ReturnType Rte_Write_P_DCDCHVNetworkVoltag_V2_Dp_DCDCHVNetworkVoltag_V2(DtDCDCHVNetworkVoltag_V2 data)
 *   Std_ReturnType Rte_Write_P_DCDCInputPower_Dp_DCDCInputPower(Dt_DCDCInputPower data)
 *   Std_ReturnType Rte_Write_P_DCDCInterlockState_Dp_DCDCInterlockState(Dt_DCDCInterlockState data)
 *   Std_ReturnType Rte_Write_P_DCDC_ElecSysFailureDisplay_Dp_DCDC_ElecSysFailureDisplay(Dt_DCDC_ElecSysFailureDisplay data)
 *   Std_ReturnType Rte_Write_P_DCDC_Fault_Type_Dp_DCDC_Fault_Type(Dt_DCDC_Fault_Type data)
 *   Std_ReturnType Rte_Write_P_DCDC_MajorElecFailureDisplay_Dp_DCDC_MajorElecFailureDisplay(Dt_DCDC_MajorElecFailureDisplay data)
 *   Std_ReturnType Rte_Write_P_DCDC_u13IoutMeas_Dp_DCDC_u13IoutMeas(Dt_DCDC_u13IoutMeas data)
 *   Std_ReturnType Rte_Write_P_DiagStatus_u2FailureCount_Dp_DiagStatus_u2FailureCount(Dt_DiagStatus_u2FailureCount data)
 *   Std_ReturnType Rte_Write_P_Ireso_10mA_Dp_Ireso_10mA(Dt_Ireso_10mA data)
 *   Std_ReturnType Rte_Write_P_SG_DCDC_RN104_Pi_SG_DCDC_RN104(const Dt_SG_DCDC_RN104 *data)
 *   Std_ReturnType Rte_Write_P_TxSigBoostCmd_VbulkRef_Dp_TxSigBoostCmd_VbulkRef(BoostCmd_VbulkRef data)
 *   Std_ReturnType Rte_Write_P_TxSig_DCDC_MILLamp_Dp_TxSigDCDC_MILLamp(DCDC_MILLamp data)
 *   Std_ReturnType Rte_Write_P_TxSig_DcDc_LlcFreq_Dp_TxSigDcDc_LlcFreq(DcDc_LlcFreq data)
 *   Std_ReturnType Rte_Write_P_TxSig_Llc_State_Dp_TxSig_Llc_State(Llc_State data)
 *   Std_ReturnType Rte_Write_P_TxSig_u11ErrIntC_Dp_TxSigu11ErrIntC(u11ErrIntC data)
 *   Std_ReturnType Rte_Write_P_TxSig_u11ErrIntC_Last_Dp_TxSigu11ErrIntC_Last(u11ErrIntC_Last data)
 *   Std_ReturnType Rte_Write_P_TxSig_u15WantInt_Dp_TxSigu15WantInt(u15WantInt data)
 *   Std_ReturnType Rte_Write_P_TxSig_u3ErrInput_Dp_TxSigu3ErrInput(u3ErrInput data)
 *   Std_ReturnType Rte_Write_P_TxSig_u3ErrInput_Last_Dp_TxSigu3ErrInput_Last(u3ErrInput_Last data)
 *   Std_ReturnType Rte_Write_P_TxSig_u5ErrIntD_Dp_TxSigu5ErrIntD(u5ErrIntD data)
 *   Std_ReturnType Rte_Write_P_TxSig_u5ErrIntD_Last_Dp_TxSigu5ErrIntD_Last(u5ErrIntD_Last data)
 *   Std_ReturnType Rte_Write_P_TxSig_u6ErrOutput_Dp_TxSigu6ErrOutput(u6ErrOutput data)
 *   Std_ReturnType Rte_Write_P_TxSig_u6ErrOutput_Last_Dp_TxSigu6ErrOutput_Last(u6ErrOutput_Last data)
 *   Std_ReturnType Rte_Write_P_Ubulk_100mV_Dp_Ubulk_100mV(Dt_Ubulk_100mV data)
 *   Std_ReturnType Rte_Write_P_Uout2_10mV_Dp_Uout2_10mV(Dt_Uout2_10mV data)
 *   Std_ReturnType Rte_Write_P_Uout_10mV_Dp_Uout_10mV(Dt_Uout_10mV data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Proxy_vMain_doc
 *********************************************************************************************************************/
#define PROXY_MG_INT_LOSTBARIER (INT_ERR2_OPVOLT_DIFF  | INT_ERR6_VOUT_SENSOR1 | INT_ERR7_VOUT_SENSOR2 | \
                                 INT_ERR8_ADC_REF_VOLT | INT_ERR9_WATERTEMP_TH | INT_ERR10_WATERTEMP_DERATE)
#define PROXY_MG_INT_ALLERT     (0X00003FFD)
#define PROXY_MG_LOSTFRAME      (NETWORK_LOST_RN4 | NETWORK_LOST_RN2RN18 | NETWORK_LOST_RN1 \
								| NETWORK_LOST_HEVC_RN107 | NETWORK_LOST_HEVC_RN123 | NETWORK_LOST_BMS_RN108 \
								| NETWORK_LOST_HEVC_RN108 | NETWORK_LOST_HEVC_RN111 | NETWORK_LOST_HEVC_RN104)


#define MG_INTERNDIAG_WARN        0X0000FFFF
#define MG_INTERNDIAG_ERR_CLASSC  0X0FFF0000
#define MG_INTERNDIAG_ERR_CLASSD  0XF0000000

#define CRC_CLK_CNT_MASK                          (0x0F)
#define MSGID_DCDC_RN104                          (0x45E)
#define CRC_INITIAL_VALUE                         (0xFF)
#define CRC_FINAL_VALUE                           (0xFF)
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Proxy_CODE) Proxy_vMain(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Proxy_vMain
 *********************************************************************************************************************/
  uint8   loc_u8HelpVar;
  sint16  loc_s16HelpVar;
  uint16  loc_u16HelpVar;
  uint32  loc_u32HelpVar;
  uint16  loc_u16Uin_100mV;
  uint16  loc_u16Pin100w;
  sint16  loc_s16DCDCCurrentOutput;
  uint16  loc_u16MaxAvailableCurrent;
  uint16  loc_u16IoutCal;
  uint32  loc_u32InternFailure;
  Dt_DCDCState loc_tDCDCState;
  boolean loc_bDerateActiv;
  Dt_ErrClass   loc_tErrClass;
  Dt_DCDC_Fault_Type loc_tFaultType;
  Dt_NetErrCode      loc_tNetWorkErr;
  Dt_DCDC_MajorElecFailureDisplay loc_bMajorElecFailureDisplay;
  Dt_DCDC_ElecSysFailureDisplay   loc_bElecSysFailureDisplay;
  Dt_DCDCInterlockState loc_tDCDCInterlockState;
  
  Dt_SG_DCDC_RN104 t_SG_DCDC_RN104;
  Dt_DCDC_RefusetoSleep loc_tRefusetoSleep;
  static Dt_Clock_DCDC_RN104 loc_u8DCDC_RN104_CLK_CNT;
  static uint8 loc_u8CycleRaster_Cntr;
	
  (void)Rte_Read_R_SP_UART_u8BulkRef(&loc_u8HelpVar);
  (void)Rte_Write_P_TxSigBoostCmd_VbulkRef_Dp_TxSigBoostCmd_VbulkRef(loc_u8HelpVar);

  (void)Rte_Read_R_AP_LlcToCan_LlcState(&loc_u8HelpVar);
  (void)Rte_Write_P_TxSig_Llc_State_Dp_TxSig_Llc_State(loc_u8HelpVar);

  (void)Rte_Read_R_SP_CDDADC_s16IresoAverage_10mA(&loc_s16HelpVar);
  (void)Rte_Write_P_Ireso_10mA_Dp_Ireso_10mA(loc_s16HelpVar);

  (void)Rte_Read_R_SP_UART_u16UBulk_100mV(&loc_u16HelpVar);
  (void)Rte_Write_P_Ubulk_100mV_Dp_Ubulk_100mV(loc_u16HelpVar);

  (void)Rte_Read_R_ASR_AverageLlcFreq_u32Val(&loc_u32HelpVar);
  (void)Rte_Write_P_TxSig_DcDc_LlcFreq_Dp_TxSigDcDc_LlcFreq((loc_u32HelpVar>> 11));

  (void)Rte_Read_R_SP_CDDADC_u16Uout1_10mV(&loc_u16HelpVar);
  (void)Rte_Write_P_Uout_10mV_Dp_Uout_10mV(loc_u16HelpVar);

  (void)Rte_Read_R_SP_CDDADC_u16Uout2_10mV(&loc_u16HelpVar);
  (void)Rte_Write_P_Uout2_10mV_Dp_Uout2_10mV(loc_u16HelpVar);

  (void)Rte_Read_R_AP_DiagToCan_FailureCount(&loc_u16HelpVar);
  (void)Rte_Write_P_DiagStatus_u2FailureCount_Dp_DiagStatus_u2FailureCount(loc_u16HelpVar);

  (void)Rte_Read_R_AP_DiagToCan_ErrInput(&loc_u8HelpVar);
  (void)Rte_Write_P_TxSig_u3ErrInput_Dp_TxSigu3ErrInput(loc_u8HelpVar);

  (void)Rte_Read_R_AP_DiagToCan_ErrInput_Last(&loc_u8HelpVar);
  (void)Rte_Write_P_TxSig_u3ErrInput_Last_Dp_TxSigu3ErrInput_Last(loc_u8HelpVar);

  (void)Rte_Read_R_AP_DiagToCan_ErrOutput(&loc_u8HelpVar);
  (void)Rte_Write_P_TxSig_u6ErrOutput_Dp_TxSigu6ErrOutput(loc_u8HelpVar);

  (void)Rte_Read_R_AP_DiagToCan_ErrOutput_Last(&loc_u8HelpVar);
  (void)Rte_Write_P_TxSig_u6ErrOutput_Last_Dp_TxSigu6ErrOutput_Last(loc_u8HelpVar);

  (void)Rte_Read_R_AP_DiagToCan_IntFailure(&loc_u32InternFailure);
  (void)Rte_Write_P_TxSig_u15WantInt_Dp_TxSigu15WantInt((loc_u32InternFailure & MG_INTERNDIAG_WARN));
  (void)Rte_Write_P_TxSig_u11ErrIntC_Dp_TxSigu11ErrIntC((loc_u32InternFailure & MG_INTERNDIAG_ERR_CLASSC) >> 16);
  (void)Rte_Write_P_TxSig_u5ErrIntD_Dp_TxSigu5ErrIntD((loc_u32InternFailure & MG_INTERNDIAG_ERR_CLASSD) >> 28);

  (void)Rte_Read_R_AP_DiagToCan_IntFailure_Last(&loc_u32HelpVar);
  (void)Rte_Write_P_TxSig_u11ErrIntC_Last_Dp_TxSigu11ErrIntC_Last((loc_u32HelpVar & MG_INTERNDIAG_ERR_CLASSC) >> 16);
  (void)Rte_Write_P_TxSig_u5ErrIntD_Last_Dp_TxSigu5ErrIntD_Last((loc_u32HelpVar & MG_INTERNDIAG_ERR_CLASSD) >> 28);

  (void)Rte_Read_R_DCDCState_Dp_DCDCState(&loc_tDCDCState);
  (void)Rte_Read_R_Pi_MaxCurrentAvailableBySystem_Dp_MaxCurrentAvailableBySystem(&loc_u16MaxAvailableCurrent);
  (void)Rte_Read_R_SP_UART_u16Uin_100mV(&loc_u16Uin_100mV);
  (void)Rte_Read_R_AP_LlcToCan_InputPower100W(&loc_u16Pin100w);
  (void)Rte_Read_R_AP_LlcToCan_u8IoutMeas(&loc_u16IoutCal);
  (void)Rte_Write_P_DCDC_u13IoutMeas_Dp_DCDC_u13IoutMeas(loc_u16IoutCal);
  loc_s16DCDCCurrentOutput = MIN(loc_u16IoutCal, (sint16)loc_u16MaxAvailableCurrent);

uint8 dummy=0x48;
  Rte_Write_P_DCDCInputPower_Dp_DCDCInputPower(dummy);

  if(Cx0_Starting_mode != loc_tDCDCState){
   // (void)Rte_Write_P_DCDCInputPower_Dp_DCDCInputPower(loc_u16Pin100w);
    (void)Rte_Write_P_DCDCCurrentOutput_Dp_DCDCCurrentOutput(loc_s16DCDCCurrentOutput);
    (void)Rte_Write_P_DCDCHVNetworkVoltag_V2_Dp_DCDCHVNetworkVoltag_V2(loc_u16Uin_100mV);
  }else{
   // (void)Rte_Write_P_DCDCInputPower_Dp_DCDCInputPower(0x3Fu);
    (void)Rte_Write_P_DCDCCurrentOutput_Dp_DCDCCurrentOutput(0xFFu);
    (void)Rte_Write_P_DCDCHVNetworkVoltag_V2_Dp_DCDCHVNetworkVoltag_V2(0x1FFFu);
  }

     /********************** Failure Type ************************************/
	(void)Rte_Read_R_AP_DERATE_bDerateActiv(&loc_bDerateActiv);
	(void)Rte_Read_R_AP_DIAG_tErrClass(&loc_tErrClass);
	(void)Rte_Read_R_AP_NetworkDiag_u16Failure(&loc_tNetWorkErr);
	if(ERR_CLASS_D == loc_tErrClass){

      loc_tFaultType = Cx2_FAULT_CLASS_D;
	  loc_bMajorElecFailureDisplay   = TRUE;
	}else if((uint32)0 != (loc_u32InternFailure & PROXY_MG_INT_LOSTBARIER) ){

	  loc_tFaultType = Cx4_FAULT_SAFETY_BARRIER_LOST;
	  loc_bMajorElecFailureDisplay   = FALSE;
	}else if(ERR_CLASS_C == loc_tErrClass){

	  loc_tFaultType = Cx1_FAULT_CLASS_C;
	  loc_bMajorElecFailureDisplay   = FALSE;
	}else if (TRUE == loc_bDerateActiv){

	  loc_tFaultType = Cx3_FAULT_UNBALLAST;
	  loc_bMajorElecFailureDisplay   = FALSE;
	}else{

	  loc_tFaultType = Cx0_NO_FAULT;
	  loc_bMajorElecFailureDisplay   = FALSE;
	}

	if(  ((uint32)0 != (loc_u32InternFailure & PROXY_MG_INT_ALLERT)) ||
	    (((uint32)0 != (loc_tNetWorkErr & PROXY_MG_LOSTFRAME)) && (Cx2_DirectMode == loc_tDCDCState)) ){

	   loc_bElecSysFailureDisplay     = TRUE;
	}else{
	   loc_bElecSysFailureDisplay     = FALSE;
	}
	
	loc_tDCDCInterlockState = Cx2_Interlock_Close;
	Rte_Write_P_DCDCInterlockState_Dp_DCDCInterlockState(loc_tDCDCInterlockState);
/************************************** Start of Message : DCDC_RN104 ***********************************************/ 
Rte_Read_R_DCDC_RefusetoSleep_Dp_DCDC_RefusetoSleep(&loc_tRefusetoSleep);

loc_u8CycleRaster_Cntr++;
	
	if(loc_u8CycleRaster_Cntr == 10u)
	{
		
	loc_u8DCDC_RN104_CLK_CNT = loc_u8DCDC_RN104_CLK_CNT + 1u;
	loc_u8DCDC_RN104_CLK_CNT = (CRC_CLK_CNT_MASK & loc_u8DCDC_RN104_CLK_CNT);
    t_SG_DCDC_RN104.Clock_DCDC_RN104 = loc_u8DCDC_RN104_CLK_CNT;
	
	t_SG_DCDC_RN104.DCDC_Fault_Type             = loc_tFaultType;
	t_SG_DCDC_RN104.DCDC_RefusetoSleep          = loc_tRefusetoSleep;
	t_SG_DCDC_RN104.DCDCCurrentOutput           = loc_s16DCDCCurrentOutput;
	t_SG_DCDC_RN104.DCDCState                   = loc_tDCDCState;
	t_SG_DCDC_RN104.MaxCurrentAvailableBySystem = loc_u16MaxAvailableCurrent;
	t_SG_DCDC_RN104.DCDC_Max12VcurrentAvailable_HV = 0U;
	t_SG_DCDC_RN104.DCDC_12VCurrent = 0U;
	
	u8CrcDataIn[0] = (uint8)((MSGID_DCDC_RN104 & HIGH_BYTE) >> 8);
	u8CrcDataIn[1] = (uint8)(MSGID_DCDC_RN104 & LOW_BYTE);
	u8CrcDataIn[2] = (uint8)(t_SG_DCDC_RN104.MaxCurrentAvailableBySystem & LOW_BYTE);
	u8CrcDataIn[3] = (uint8)(t_SG_DCDC_RN104.DCDCCurrentOutput & LOW_BYTE);
	u8CrcDataIn[4] = (uint8)(((t_SG_DCDC_RN104.DCDC_Fault_Type << 5) & 0XE0 ) | ((t_SG_DCDC_RN104.DCDC_RefusetoSleep << 3) & 0X18 ) | ((t_SG_DCDC_RN104.DCDCState << 1) & 0X6));
	u8CrcDataIn[5] = (uint8)((t_SG_DCDC_RN104.Clock_DCDC_RN104 << 4)& 0XF0);
	u8CrcDataIn[6] = 0u;
	u8CrcDataIn[7] = 0u;
	u8CrcDataIn[8] = 0u;
	
	Compute_CRC08(u8CrcDataIn);
	
	/* Alive Counter Calculation */
	t_SG_DCDC_RN104.CRC_DCDC_RN104 = u8CrcVal;
	
	loc_u8CycleRaster_Cntr = 0u;
	
    (void)Rte_Write_P_SG_DCDC_RN104_Pi_SG_DCDC_RN104((const Dt_SG_DCDC_RN104 *) &t_SG_DCDC_RN104);
    (void)Rte_Write_P_Clock_DCDC_RN104_DT_Clock_DCDC_RN104(t_SG_DCDC_RN104.Clock_DCDC_RN104);
    (void)Rte_Write_P_CRC_DCDC_RN104_DT_CRC_DCDC_RN104(t_SG_DCDC_RN104.CRC_DCDC_RN104);
	
	}
	
/************************************** End of Message : DCDC_RN104 ***********************************************/

    (void)Rte_Write_P_DCDC_Fault_Type_Dp_DCDC_Fault_Type(loc_tFaultType);
    (void)Rte_Write_P_DCDC_MajorElecFailureDisplay_Dp_DCDC_MajorElecFailureDisplay(loc_bMajorElecFailureDisplay);
    (void)Rte_Write_P_DCDC_ElecSysFailureDisplay_Dp_DCDC_ElecSysFailureDisplay(loc_bElecSysFailureDisplay);
    /*(void)Rte_Write_P_CRC_DCDC_RN104_DT_CRC_DCDC_RN104(t_SG_DCDC_RN104.CRC_DCDC_RN104);*/
    /*(void)Rte_Write_P_Clock_DCDC_RN104_DT_Clock_DCDC_RN104(t_SG_DCDC_RN104.Clock_DCDC_RN104);*/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define Proxy_STOP_SEC_CODE
#include "Proxy_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
FUNC(void, Proxy_CODE) Compute_CRC08(uint8 Data[]) 
{	
	uint8 u8i, u8TempVal, u8TempCRC;
	
	u8TempVal = Data[0] ^ CRC_INITIAL_VALUE;
	u8TempCRC = Crc8Table[u8TempVal];
	
	for(u8i=1; u8i<9; u8i++)
	{
		u8TempVal = Data[u8i] ^ u8TempCRC;
		u8TempCRC = Crc8Table[u8TempVal];	
	}
	
	u8CrcVal = (u8TempCRC ^ CRC_FINAL_VALUE);	
}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/



#if 0
/***  Start of saved code (symbol: runnable implementation:AM_vInit)  ***************************************/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:AM_vMain)  ***************************************/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:AM_vMain_doc)  ****************************************/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:AM_vInit_doc)  ****************************************/


/***  End of saved code  ************************************************************************************/
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_3206:  MISRA rule: Rule2.7
     Reason:     The parameter are not used by the code in all possible code variants.
     Risk:       No functional risk.
     Prevention: Not required.

*/
