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
 *             File:  ApplDiag.c
 *           Config:  DCDC_5DH.dpa
 *        SW-C Type:  ApplDiag
 *
 *        Generator:  MICROSAR RTE Generator Version 4.28.0
 *                    RTE Core Version 1.28.0
 *          License:  CBD2200292
 *
 *      Description:  C-Code implementation template for SW-C <ApplDiag>
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
 * Dcm_NegativeResponseCodeType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_OpStatusType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_SecLevelType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_SesCtrlType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * DtLlcState
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * DtSystemMode
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * IT_Active
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * IT_Array_Element
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * IT_CP_State
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * IT_Charge_Display
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * IT_CouplerType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * IT_Current_100mA
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * IT_Current_10mA
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * IT_Current_1mA
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * IT_Dsp_DiagRequest
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * IT_EVSE_State
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * IT_Enable
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * IT_Frequency_100mHz
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * IT_Frequency_1Hz
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * IT_HVILstate
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * IT_HighLow
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * IT_Lock_Actuation
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * IT_Locked_Unlocked
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * IT_MagneticTemperature
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * IT_Motor
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * IT_NumberOfPhases
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * IT_OBC_Mode
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * IT_OBC_State
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * IT_OnOff
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * IT_OpenClose
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * IT_Percentage_0p0
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * IT_Percentage_0p01
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * IT_Plug_State
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * IT_PowerStage
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * IT_Power_100mW
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * IT_Power_1W
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * IT_Power_500mW
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * IT_Prox_State
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * IT_Resistance_1Ohm
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * IT_Status
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * IT_Temperature_0degC1
 *   SInt16 represents integers with a minimum value of -32768 and a maximum value 
 *      of 32767. The order-relation on sint16 is: x < y if y - x is positive.
 *      sint16 has a lexical representation consisting of an optional sign followed
 *      by a finite-length sequence of decimal digits (#x30-#x39). If the sign is
 *      omitted, "+" is assumed. 
 *      
 *      For example: -1, 0, -12678, +10000, 2500
 *
 * IT_Time_100ns
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * IT_Time_1us
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * IT_Voltage_100mV
 *   SInt16 represents integers with a minimum value of -32768 and a maximum value 
 *      of 32767. The order-relation on sint16 is: x < y if y - x is positive.
 *      sint16 has a lexical representation consisting of an optional sign followed
 *      by a finite-length sequence of decimal digits (#x30-#x39). If the sign is
 *      omitted, "+" is assumed. 
 *      
 *      For example: -1, 0, -12678, +10000, 2500
 *
 * IT_Voltage_10mV
 *   SInt16 represents integers with a minimum value of -32768 and a maximum value 
 *      of 32767. The order-relation on sint16 is: x < y if y - x is positive.
 *      sint16 has a lexical representation consisting of an optional sign followed
 *      by a finite-length sequence of decimal digits (#x30-#x39). If the sign is
 *      omitted, "+" is assumed. 
 *      
 *      For example: -1, 0, -12678, +10000, 2500
 *
 * IT_Voltage_1mV
 *   SInt16 represents integers with a minimum value of -32768 and a maximum value 
 *      of 32767. The order-relation on sint16 is: x < y if y - x is positive.
 *      sint16 has a lexical representation consisting of an optional sign followed
 *      by a finite-length sequence of decimal digits (#x30-#x39). If the sign is
 *      omitted, "+" is assumed. 
 *      
 *      For example: -1, 0, -12678, +10000, 2500
 *
 * IT_XCP_DSP
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * SaSrv_FVirginFlagType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * SaSrv_FailedAttemptCounterType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * SaSrv_MileageForNormalModeType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * SaSrv_StatusFlagType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * SaSrv_VirginFlagType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 *********************************************************************************************************************/

#include "Rte_ApplDiag.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include <string.h>
#include "varcfg.h"
#include "ecuext_dcm.h"
#include "Dcm.h"
#include "coding_nvmcfg.h"
#include "ecuext_os.h"
#include "coding_appldiag.h"
#include "Com_Lcfg.h"
#include "ApplDiag_cfg.h"
#include "coding_diagmap.h"
#include "coding_diagmap.c"
#include "ApplDiag_nvblock.h"
#include "coding_type.h"


#define RTE_CORE
#include "SaSrv.h"
#undef RTE_CORE

/******************************************************************************
 * Local defines
******************************************************************************/
#define SASRV_MODE    FNORMAL   /* FVIRGIN = 0x00, dummy security acccess,  
                                 FNORMAL = 0xFF, security access is needed */

/* Delta Internal Access Defines */
#define APPLDIAG_KEYLENGTH                          (6u)
#define APPLDIAG_KEYMATCH                           (0u)
#define SET						                    					(1u)
#define CLEAR                                       (0u)

 #define   Cx0_Starting_mode                        (0U)
 #define   Cx1_Standby                              (1U)
 #define   Cx2_DirectMode                           (2U)
 #define   Cx3_Unavailable                          (3U)
 #define   Allowed                                  (1U)
 #define   NotAllowed                               (1U)
#define kEepSizeDID_F190                           (0x11u)
/* ECU ResetType */
#define PowerOnReset                               (0x07u)
#define WDGReset                                   (0x01u)
#define CLKReset                                   (0x02u)
#define SWReset                                    (0x03u)
#define URTout_RESET                               (0x04u)

/************************* Negative response code ***************************/
#define APPLDIAG_ACK                                (Dcm_NegativeResponseCodeType) 0x40U    /* Positive answer */
/** \brief NRC_11  **/
#define APPLDIAG_NRC_11                             (Dcm_NegativeResponseCodeType) 0x11U    /* Non-supported service */
/** \brief NRC_12 **/
#define APPLDIAG_NRC_12                             (Dcm_NegativeResponseCodeType) 0x12U    /* Non-supported sub-service */
/** \brief NRC_22 **/
#define APPLDIAG_NRC_22                             (Dcm_NegativeResponseCodeType) 0x22U    /* Unsatisfied conditions */
/** \brief NRC_31 **/
#define APPLDIAG_NRC_31                             (Dcm_NegativeResponseCodeType) 0x31U    /* Request out of range */
/** \brief NRC_33 **/
#define APPLDIAG_NRC_33                             (Dcm_NegativeResponseCodeType) 0x33U    /* ECU is locked */
/** \brief NRC_35 **/
#define APPLDIAG_NRC_35                             (Dcm_NegativeResponseCodeType) 0x35U    /* Invalid key */
/** \brief NRC_72 **/
#define APPLDIAG_NRC_72                             (Dcm_NegativeResponseCodeType) 0x72U    /* Erasing or writing error volatil memory */
/** \brief NRC_78 **/
#define APPLDIAG_NRC_78                             (Dcm_NegativeResponseCodeType) 0x78U    /* Request well received / Answer constitution in progress */
/** \brief NRC_7E **/
#define APPLDIAG_NRC_7E                             (Dcm_NegativeResponseCodeType) 0x7EU    /* Sub-service supported by the ECU but not in the active session */
/** \brief NRC_7F **/
#define APPLDIAG_NRC_7F                             (Dcm_NegativeResponseCodeType) 0x7FU    /* Service supported by the ECU but not in the active session */
/** \brief ERR_COHE **/
#define APPLDIAG_ERR_COHE                           (Dcm_NegativeResponseCodeType) 0xFFU    /* SDF UDS error */

/** \brief NRC_21 **/
#define APPLDIAG_NRC_21                             (Dcm_NegativeResponseCodeType) 0x21U    /* Busy-Repeat Request */
/** \brief NRC_23 **/
#define APPLDIAG_NRC_23                             (Dcm_NegativeResponseCodeType) 0x23U    /* Routine Not Complete */
/** \brief NRC_INVALID_DID **/
#define APPLDIAG_NRC_INVALID_DID                    (Dcm_NegativeResponseCodeType) 0x12U   /* DID implemented in other session and session supported by the service */

/* Shift and Mask */
#define APPLDIAG_SHIFT_1BYTE                        (8u)
#define APPLDIAG_SHIFT_2BYTE                        (16u)
#define APPLDIAG_SHIFT_3BYTE                        (24u)
#define APPLDIAG_MASK_BYTE_0                        (0x00FFu)
#define APPLDIAG_MASK_BYTE_1                        (0xFF00u)
#define RTE_E_AI_CodingDiag_E_NOK (1U)
#define RTE_E_AI_CodingDiag_E_PENDING (10U)
/******************************************************************************
 * Local data types
******************************************************************************/
#define VIRGIN_FLAG_WRITING_DELAY_TIME 50U

/*--------------------------------------------------------------------------------------------------*/
/*-------------------------------- SECURITY ACCESS defines/typedefs --------------------------------*/
/*--------------------------------------------------------------------------------------------------*/
#if (0) /* Security Access will be delegated to DiagHardening SaSrv Module */

//#define ESL_SIZEOF_SHA1_BLOCK            ( 64u )
//#define ESL_SIZEOF_SHA1_DIGEST           ( 20u )

#define SECM_OK                          ( 0x00u )
#define SECM_BUFFER_TO_SMALL             ( 0x01u )
#define SECM_INVALID_PARAM               ( 0x02u )

#define SECM_CRYPT_DIR_ENCRYPTION        ( 0x55u )
#define SECM_CRYPT_DIR_DECRYPTION        ( 0xAAu )

//#define ESL_BM_CBC                       ( 0x01u )
//#define ESL_PM_PKCS5                     ( 0x01u )

#define kFblSecNewSeedIssued             ( 3u )      /* seed */
#define kFblSecGranted                   ( 4u )      /* seed - key - status */
#define kFblSecDeniedLocked              ( 5u )      /* status */
#define kFblSecDeniedIncorrectLevel      ( 6u )      /* seed */
#define kFblSecDeniedInvalidKey          ( 7u )

#define kFblOk                           ( 0u )
#define kFblFailed                       ( 1u )

/*#define kEepSizeDID_F18C                  0x14u */
#define SEED_SIZE                        ( 30u )
#define FBL_MTAB_NO_OF_BLOCKS            ( 1u )

#define FblReadRam                       FblReadBlock
#define FBL_MTAB_MAGIC_FLAG              0xB5A4C3D2u

#define FBL_NO_TRIGGER                   ( 0x00u )    /* No action performed (just watching the timer) */
#define FBL_WD_TRIGGERED                 ( 0x03u )    /* Watchdog has been triggered */
#define FBL_TM_TRIGGERED                 ( 0x02u )    /* Timer has expired and was re-triggered */

typedef uint32 SecM_WordType;
typedef uint16 SecM_LengthType;
typedef uint32 SecM_AddrType;
typedef uint32 SecM_SizeType;
typedef uint8  SecM_StatusType;

typedef uint8                                   tFblResult;
typedef uint32                                  FBL_ADDR_TYPE;
typedef uint32                                  FBL_MEMSIZE_TYPE;

typedef FBL_ADDR_TYPE                           tFblAddress;
typedef FBL_MEMSIZE_TYPE                        tFblLength;

/* Pointer types for function calls from external application */
typedef void (* FL_WDTriggerFctType)(void);
typedef tFblLength (* tReadMemoryFct)(tFblAddress address, uint8 * buffer, tFblLength length);

typedef uint16                                 tTpDataType;
typedef tTpDataType                             tCwDataLengthType;

/* Parameter structure for hash computation */
typedef struct tagSecM_CalcHashParamType
{
   SecM_AddrType         startAddr; /* start address of data area */
   SecM_SizeType         length; /* length of data area           */
   uint8 *               hashBuffer; /* buffer for the result     */
   SecM_LengthType       bufferSize; /* in: size of hashBuffer
                                        out: size of hash         */
   tReadMemoryFct        memReadFct; /* Memory read function      */
   FL_WDTriggerFctType   wdTriggerFct; /* WD trigger function     */
} SecM_CalcHashParamType;

/* Parameter structure for de/encryption */
typedef struct tagSecM_CryptAESParamType
{
   uint8           * inBuf;
   SecM_LengthType   inSize;
   uint8           * outBuf;
   SecM_LengthType * outSize;
   const uint8 * key;
   FL_WDTriggerFctType  wdTriggerFct;  /* Pointer to watchdog trigger function */
   uint8               cryptDir;      /* crypt direction (de-/encryption)     */
} SecM_CryptAESParamType;

typedef struct tBlockDescriptorTag
{
  uint8 blockNr; /* Number of logical block */
  uint32 blockIndex;
  tFblAddress blockStartAddress; /* Start address of current block */
  tFblLength blockLength; /* Block length in bytes */
  uint16 maxProgAttempts; /* Maximum number of reprogramming attempts */
} tBlockDescriptor;

typedef struct tLogicalBlockTableTag
{
  uint32 magicFlag; /* Value of FBL_MTAB_MAGIC_FLAG - Indicates the existence of the table */
  uint8 noOfBlocks; /* Number of configured logical blocks */
  tBlockDescriptor logicalBlock[FBL_MTAB_NO_OF_BLOCKS];
} tLogicalBlockTable;

/*--------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------*/
static tCwDataLengthType                       DiagDataLength;            /**< Stores number of received data */

/*--------------------------------------------------------------------------------------------------*/
/*-------------------------------- SECURITY ACCESS local functions ---------------------------------*/
/*--------------------------------------------------------------------------------------------------*/

static tFblLength FblReadBlock(tFblAddress address, uint8* buffer, tFblLength length);
static SecM_StatusType SecM_CalculateHash( SecM_CalcHashParamType *hashParam );
static SecM_StatusType SecM_CryptAES( SecM_CryptAESParamType *cryptParam );
static tFblResult ApplFblDecryptSecurityKey(uint8 * keyBuffer, uint16 keySize, const uint8 * secretKeyBuf,
                                            uint16 * secKeyBufSize, const uint8 * sKey  );
static tFblResult ApplFblEncryptSecuritySeed(uint8 * secretSeed, uint16 secretSeedSize,uint8 * securitySeed,
                                             uint16 * securitySeedSize, const uint8 * aesKey );
static tFblResult ApplFblCalculateHash( FBL_ADDR_TYPE addr, FBL_MEMSIZE_TYPE len,
   uint8 * hashBuffer, uint16 bufferSize, tReadMemoryFct memReadFct);
static void FblRealTimeSupport( void );

/***********************************************************************************************************************
 *  FblReadBlock
 **********************************************************************************************************************/
/*! \brief          This function reads a given amount of bytes from an address.
 *  \param[in]      address Memory address to read out
 *  \param[out]     buffer Target buffer
 *  \param[in]      length Number of bytes to read
 *  \return         Number of actually copied bytes
 **********************************************************************************************************************/
static tFblLength FblReadBlock(tFblAddress address, uint8* buffer, tFblLength length)
{
   tFblLength actualReadCount;

   actualReadCount = length;
   memcpy((void *)buffer, (const void *)address, length);   /* PRQA S 0306 */ /* MD_FblHw_0306 */  /* MODIFIED BY ROTRIFA !!!!! */
   return actualReadCount;
}

/***********************************************************************************************************************
 *  FblRealTimeSupport - 14229 specific
 **********************************************************************************************************************/
/*! \brief       Transmit busy messages and triggers the watchdog according to system timer
 *  \pre         P2Timer must be initialized
 *  \return      Return code of FblLookForWatchdog
 **********************************************************************************************************************/
static void FblRealTimeSupport( void )
{
  /* Dummy function */
}


/***********************************************************************************************************************
 *  SecM_CalculateHash
 **********************************************************************************************************************/
/*! \brief       This function calculate hash over a provided area of continious data
 *  \param[   ]  hashParam  [in/out] - structure with exchanged data
 *  \return      SECM_OK if hash calculation was successful,
 *               SECM_NOT_OK otherwise
 *               SECM_BUFFER_TO_SMALL if buffer was choosen to small
 **********************************************************************************************************************/
static SecM_StatusType SecM_CalculateHash( SecM_CalcHashParamType *hashParam )
{
   eslt_Byte          buffer[ESL_SIZEOF_SHA1_BLOCK]; /* temp buffer for hash calculation */
   SecM_StatusType    result;
   eslt_WorkSpaceSHA1 workSpaceSHA1;
   SecM_LengthType    tmpByteCount;

   SecM_AddrType      addr;
   SecM_SizeType      len;
   SecM_SizeType      readLen;

   addr = hashParam->startAddr;
   len = hashParam->length;

   /* Check buffer size first */
   if (hashParam->bufferSize < ESL_SIZEOF_SHA1_DIGEST )
   {
      return SECM_BUFFER_TO_SMALL;
   }

   /* Init hash calculation - SECM_HASH_INIT */
   result = esl_initWorkSpaceHeader(&workSpaceSHA1.header, sizeof(workSpaceSHA1)-sizeof(eslt_WorkSpaceHeader), (void (*)(void))(hashParam->wdTriggerFct));
   if (result == SECM_OK )
   {
      result = esl_initSHA1(&workSpaceSHA1);
   }

   /* Compute hash */
   while ((len > 0) && (result == SECM_OK))
   {
      if (len > sizeof(buffer))
      {
         tmpByteCount = sizeof(buffer);
      }
      else
      {
         tmpByteCount = (SecM_LengthType)len;
      }

      /* Read values into RAM buffer */
      readLen = (hashParam->memReadFct)(addr, buffer, tmpByteCount);

      /* calculate only over readable areas - exclude gaps */
      if (readLen > 0)
      {
         /* SECM_HASH_COMPUTE */
         result = esl_updateSHA1(&workSpaceSHA1, (eslt_Length)readLen, buffer);
      }

      addr += tmpByteCount;
      len  -= tmpByteCount;
   }

   /* Finalize computation - SECM_HASH_FINALIZE */
   if (result == SECM_OK )
   {
      result = esl_finalizeSHA1(&workSpaceSHA1, hashParam->hashBuffer);
   }

   return result;
}

/***********************************************************************************************************************
 *  SecM_CryptAES
 **********************************************************************************************************************/
/*! \brief       This function de/encrypt RAM buffers
 *  \param[   ]  cryptParam  [in/out] - structure with exchanged data
 *  \return      SECM_OK if hash calculation was successful,
 *               SECM_NOT_OK otherwise
 *               SECM_INVALID_PARAM if direction parameter is illegal
 **********************************************************************************************************************/
static SecM_StatusType SecM_CryptAES( SecM_CryptAESParamType *cryptParam )
{
   SecM_StatusType       result;
   eslt_WorkSpaceAES128  workSpaceAES128;
   uint8   initVector[16];
   uint8 * pBuffer;
   uint16  tmpSize;
   uint16  outSize;
   uint8 i;

   pBuffer = cryptParam->outBuf;
   tmpSize = *(cryptParam->outSize);

   /* Initialize initVector */
   for ( i = 0; i < 16; i++)
   {
      initVector[i] = 0x00u;
   }

   if (((cryptParam->cryptDir) != SECM_CRYPT_DIR_ENCRYPTION) &&
       ((cryptParam->cryptDir) != SECM_CRYPT_DIR_DECRYPTION)    )
   {
      return SECM_INVALID_PARAM;
   }

   /* Init step */
   result = esl_initWorkSpaceHeader(&workSpaceAES128.header, sizeof(workSpaceAES128)-sizeof(eslt_WorkSpaceHeader), (void (*)(void))(cryptParam->wdTriggerFct));
   if (result == SECM_OK )
   {
      if ((cryptParam->cryptDir) == SECM_CRYPT_DIR_ENCRYPTION )
      {
         result = esl_initEncryptAES128(&workSpaceAES128, cryptParam->key, ESL_BM_CBC, ESL_PM_PKCS5, initVector );
      }
      else
      {
         result = esl_initDecryptAES128(&workSpaceAES128, cryptParam->key, ESL_BM_CBC, ESL_PM_PKCS5, initVector );
      }
   }

   /* compute step */
   if (result == SECM_OK )
   {
      if ((cryptParam->cryptDir) == SECM_CRYPT_DIR_ENCRYPTION )
      {
         result = esl_encryptAES128(&workSpaceAES128, cryptParam->inSize, cryptParam->inBuf, &tmpSize, pBuffer);
      }
      else
      {
         result = esl_decryptAES128(&workSpaceAES128, cryptParam->inSize, cryptParam->inBuf, &tmpSize, pBuffer);
      }
   }

   /* finalize step */
   if (result == SECM_OK )
   {
      pBuffer    += tmpSize;
      outSize     = tmpSize;
      tmpSize     = *(cryptParam->outSize) - tmpSize;

      if ((cryptParam->cryptDir) == SECM_CRYPT_DIR_ENCRYPTION )
      {
         result = esl_finalizeEncryptAES128(&workSpaceAES128, &tmpSize, pBuffer);
      }
      else
      {
         result = esl_finalizeDecryptAES128(&workSpaceAES128, &tmpSize, pBuffer);
      }

      *(cryptParam->outSize) = outSize + tmpSize;
   }

   return result;
}

/***********************************************************************************************************************
 *  ApplFblDecryptSecurityKey
 **********************************************************************************************************************/
/*! \brief         Calculate hash for a given area.
 *  \param[in]     keyBuffer        buffer with the securityKey
 *  \param[in]     keySize          size of securityKey
 *  \param[out]    secretKeyBuf     buffer for the result
 *  \param[in,out] secKeyBufSize    in: size of secretKeyBuf/out: size of secretKey
 *  \param[in]     sKey             Key for decryption (sessionKey)
 *  \return        If all conditions are correct, the function returns kFblOk, otherwise kFblFailed.
 **********************************************************************************************************************/
static tFblResult ApplFblDecryptSecurityKey(uint8 * keyBuffer, uint16 keySize,
   const uint8 * secretKeyBuf, uint16 * secKeyBufSize, const uint8 * sKey  )
{
   SecM_CryptAESParamType decryptKey;

   decryptKey.inBuf        = keyBuffer;
   decryptKey.inSize       = keySize;
   decryptKey.outBuf       = secretKeyBuf;
   decryptKey.outSize      = secKeyBufSize;
   decryptKey.key          = sKey;
   decryptKey.wdTriggerFct = (FL_WDTriggerFctType)FblRealTimeSupport;
   decryptKey.cryptDir     = SECM_CRYPT_DIR_DECRYPTION;

   if (SecM_CryptAES( &decryptKey ) == SECM_OK )
   {
      return kFblOk;
   }
   else
   {
      return kFblFailed;
   }
}

/***********************************************************************************************************************
 *  ApplFblEncryptSecuritySeed
 **********************************************************************************************************************/
/*! \brief         Calculate hash for a given area.
 *  \param[in]     secretSeed          buffer with the secretSeed
 *  \param[in]     secretSeedSize      size of secretSeed
 *  \param[out]    securitySeed        buffer for the result
 *  \param[in,out] securitySeedSize    in: size of securitySeed buffer/out: size of securitySeed
 *  \param[in]     aesKey              Key for encryption (aesKey)
 *  \return        If all conditions are correct, the function returns kFblOk, otherwise kFblFailed.
 **********************************************************************************************************************/
static tFblResult ApplFblEncryptSecuritySeed(uint8 * secretSeed, uint16 secretSeedSize,
   uint8 * securitySeed, uint16 * securitySeedSize, const uint8 * aesKey )
{
   SecM_CryptAESParamType encryptSeed;

   encryptSeed.inBuf        = secretSeed;
   encryptSeed.inSize       = secretSeedSize;
   encryptSeed.outBuf       = securitySeed;
   encryptSeed.outSize      = securitySeedSize;
   encryptSeed.key          = aesKey;
   encryptSeed.wdTriggerFct = (FL_WDTriggerFctType)FblRealTimeSupport;
   encryptSeed.cryptDir     = SECM_CRYPT_DIR_ENCRYPTION;

   if (SecM_CryptAES( &encryptSeed ) == SECM_OK )
   {
      return kFblOk;
   }
   else
   {
      return kFblFailed;
   }
}

/***********************************************************************************************************************
 *  ApplFblCalculateHash
 **********************************************************************************************************************/
/*! \brief         Calculate hash for a given area.
 *  \param[in]     addr          start address of data area, which shall be hashed
 *  \param[in]     len           length of data area
 *  \param[out]    hashBuffer    buffer for the result
 *  \param[in,out] bufferSize    in: size of hashBuffer/out: size of hash
 *  \param[in]     memReadFct    Memory read function for the whole data area
 *  \return        If all conditions are correct, the function returns kFblOk, otherwise kFblFailed.
 **********************************************************************************************************************/
static tFblResult ApplFblCalculateHash( FBL_ADDR_TYPE addr, FBL_MEMSIZE_TYPE len, uint8 * hashBuffer,
   uint16 bufferSize, tReadMemoryFct memReadFct)
{
  SecM_CalcHashParamType hashParam;
 // uint8 status = kFblOk;

  hashParam.startAddr    = (SecM_AddrType) addr;
  hashParam.length       = (SecM_SizeType) len;
  hashParam.hashBuffer   = hashBuffer;
  hashParam.bufferSize   = bufferSize;
  hashParam.memReadFct   = memReadFct;
  hashParam.wdTriggerFct = (FL_WDTriggerFctType)FblRealTimeSupport;


  if (SecM_CalculateHash( &hashParam ) == SECM_OK)
  {
    return kFblOk;
  }
  else
  {
    return kFblFailed;
  }

}
#endif /* Security Access will be delegated to DiagHardening SaSrv Module */
/*--------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------*/


#define ApplDiag_START_SEC_VAR_INIT_UNSPECIFIED
#include "ApplDiag_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ 

/******************************************************************************
 * Local constants
******************************************************************************/
_STATIC_ VAR(uint8, ApplDiag_VAR_INIT)  APPLDIAG_au8AccessKeyLevel1[]    = { 'D', 'e', 's', 'Q', 'T', 'S' };
_STATIC_ VAR(uint8, ApplDiag_VAR_INIT)  APPLDIAG_au8AccessKeyLevel2[]     = { 'D', 'e', 's', 'R', '&', 'D' };
_STATIC_ VAR(uint8, ApplDiag_VAR_INIT)  APPLDIAG_au8ReturnAccessLevel2[] = { 'D', 'e', 'l', 't', 'a', '2' };
_STATIC_ VAR(uint8, ApplDiag_VAR_INIT)  APPLDIAG_au8ReturnAccessLevel1[] = { 'D', 'e', 'l', 't', 'a', '1' };
_STATIC_ VAR(uint8, ApplDiag_VAR_INIT)  APPLDIAG_au8ReturnAccessLocked[] = { 'L', 'o', 'c', 'k', 'e', 'd' };

#define ApplDiag_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "ApplDiag_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ 

/******************************************************************************
 * Local data
******************************************************************************/
#define ApplDiag_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "ApplDiag_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ 

_STATIC_ VAR(uint8 ,ApplDiag_VAR_NOINIT)                        APPLDIAG_u8Debug[4];
_STATIC_ VAR(uint8, ApplDiag_VAR_NOINIT)                        APPLDIAG_u8AccessLevel = DELTA_ACCESS_LOCKED;
_STATIC_ VAR(AbsoluteTimeSince1rstIgn_HV ,ApplDiag_VAR_NOINIT)  APPLDIAG_tAbsoluteTimeSince1rstIgn;
_STATIC_ VAR(DistanceTotalizer_HV, ApplDiag_VAR_NOINIT)         APPLDIAG_tDistanceTotalizer;
_STATIC_ VAR(Dcm_SesCtrlType ,ApplDiag_VAR_NOINIT)              APPLDIAG_tActivSession;
_STATIC_ VAR(Dcm_SecLevelType ,ApplDiag_VAR_NOINIT)             APPLDIAG_tSecLevel;
_STATIC_ VAR(Dcm_SecLevelType ,ApplDiag_VAR_NOINIT)             APPLDIAG_tDCDCCurrentOutput;
_STATIC_ VAR(DtSystemMode ,ApplDiag_VAR_NOINIT)    	            APPLDIAG_tLastSystemMode;

#define ApplDiag_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "ApplDiag_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ 
/*
_STATIC_ VAR(boolean ,ApplDiag_VAR_NOINIT)  APPLDIAG_bWriteNvm;
*/
#define ApplDiag_START_SEC_VAR_INIT_UNSPECIFIED
#include "ApplDiag_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ 
/* Security Access local variables */
static uint8 id_F18C[21u] = "20101213000000000000";
static uint8 aesKey[16u] = {0x9Eu, 0x31u, 0xB9u, 0xEFu, 0x13u, 0x3Bu, 0xC5u, 0x5Cu, 0x51u, 0xA1u, 0x23u, 0xCDu, 0x9Cu, 0x95u, 0x8Au, 0xB7u};
static uint8 sessionKey[0x20u] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
uint8 SaSrv_EcuStatus = FALSE;

static boolean VirginFlagWritingDone, VirginFlagWritingFailed = FALSE;
static boolean FvirginFlagWritingDone,FvirginFlagWritingFailed = FALSE;  
static uint16 UDS_WriteVirginflag = 0; /*1s delay for coding writing */
static boolean mg_AsymCounterSynchRequest = FALSE;
static boolean mg_PUNSynchRequest = FALSE;
static boolean mg_FailedAttempCntSynchRequest = FALSE;
static boolean mg_SaSrvSeedSynhDelay_Flag = FALSE;
static boolean UDS_VirginFlagWritingRequest = FALSE;

#define ApplDiag_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "ApplDiag_MemMap.h"

#define ApplDiag_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "ApplDiag_MemMap.h"
/* sysmode */

static uint8 APPLDIAG_RESET;
/*static uint8 *                                 DiagBuffer;*/

#define ApplDiag_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "ApplDiag_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ 
/*******************************************************************************
 * Local functions
 ******************************************************************************/




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
 * AbsoluteTimeSince1rstIgn_HV: Integer in interval [0...16777215]
 * DT_VehicleSpeed_HV: Integer in interval [0...65534]
 * DistanceTotalizer_HV: Integer in interval [0...268435455]
 *   Unit: [km], Factor: 0.01, Offset: 0
 * Dt_Clock_DCDC_RN104: Integer in interval [0...15]
 * Dt_DCDCCurrentOutput: Integer in interval [0...255]
 * Dt_DCDCInputPower: Integer in interval [0...63]
 *   Unit: [kW], Factor: 0.1, Offset: 0
 * IT_Array_Element: Integer in interval [0...255]
 * IT_Current_100mA: Integer in interval [0...65535]
 * IT_Current_10mA: Integer in interval [0...65535]
 * IT_Current_1mA: Integer in interval [0...65535]
 * IT_Dsp_DiagRequest: Integer in interval [0...255]
 * IT_Frequency_100mHz: Integer in interval [0...65535]
 * IT_Frequency_1Hz: Integer in interval [0...65535]
 * IT_MagneticTemperature: Integer in interval [0...255]
 * IT_Percentage_0p0: Integer in interval [0...65535]
 * IT_Percentage_0p01: Integer in interval [0...65535]
 * IT_Power_100mW: Integer in interval [0...65535]
 * IT_Power_1W: Integer in interval [0...65535]
 * IT_Power_500mW: Integer in interval [0...65535]
 * IT_Resistance_1Ohm: Integer in interval [0...65535]
 * IT_Temperature_0degC1: Integer in interval [-32768...32767]
 * IT_Time_100ns: Integer in interval [0...65535]
 * IT_Time_1us: Integer in interval [0...65535]
 * IT_Voltage_100mV: Integer in interval [-32768...32767]
 * IT_Voltage_10mV: Integer in interval [-32768...32767]
 * IT_Voltage_1mV: Integer in interval [-32768...32767]
 * IT_XCP_DSP: Integer in interval [0...255]
 * SaSrv_FailedAttemptCounterType: Integer in interval [0...255]
 * SaSrv_MileageForNormalModeType: Integer in interval [0...255]
 * SaSrv_StatusFlagType: Integer in interval [0...255]
 * boolean: Boolean (standard type)
 * sint16: Integer in interval [-32768...32767] (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * DT_Active: Enumeration of integer in interval [0...2] with enumerators
 *   DT_ACTIVE_NOT_ACTIVE (0U)
 *   DT_ACTIVE_ACTIVE (1U)
 *   DT_ACTIVE_INIT (2U)
 * DT_HVFOTAConditionCheckStatus_HV: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_No_Request (0U)
 *   Cx1_Pending_Conditions (1U)
 *   Cx2_Achieved_Conditions (2U)
 *   Cx3_Error_Detected (3U)
 * DT_OnOff: Enumeration of integer in interval [0...2] with enumerators
 *   DT_ONOFF_OFF (0U)
 *   DT_ONOFF_ON (1U)
 *   DT_ONOFF_INIT (2U)
 * DT_vehicleStates_HV: Enumeration of integer in interval [0...15] with enumerators
 *   Cx0_Sleeping (0U)
 *   Cx1_Not_used (1U)
 *   Cx2_CutoffPending (2U)
 *   Cx3_AutoACC_BatTempoLevel (3U)
 *   Cx4_Not_used (4U)
 *   Cx5_IgnitionLevel (5U)
 *   Cx6_StartingInProgress (6U)
 *   Cx7_PowertrainRunning (7U)
 *   Cx8_AutoStart (8U)
 *   Cx9_EngineSystemStop (9U)
 *   CxA_Not_used (10U)
 *   CxB_Not_used (11U)
 *   CxC_Not_used (12U)
 *   CxD_Not_used (13U)
 *   CxE_Not_used (14U)
 *   CxF_Description_for_the_value_0xF_ (15U)
 * Dcm_NegativeResponseCodeType: Enumeration of integer in interval [0...255] with enumerators
 *   DCM_E_POSITIVERESPONSE (0U)
 *   DCM_E_GENERALREJECT (16U)
 *   DCM_E_SERVICENOTSUPPORTED (17U)
 *   DCM_E_SUBFUNCTIONNOTSUPPORTED (18U)
 *   DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT (19U)
 *   DCM_E_RESPONSETOOLONG (20U)
 *   DCM_E_BUSYREPEATREQUEST (33U)
 *   DCM_E_CONDITIONSNOTCORRECT (34U)
 *   DCM_E_REQUESTSEQUENCEERROR (36U)
 *   DCM_E_NORESPONSEFROMSUBNETCOMPONENT (37U)
 *   DCM_E_FAILUREPREVENTSEXECUTIONOFREQUESTEDACTION (38U)
 *   DCM_E_REQUESTOUTOFRANGE (49U)
 *   DCM_E_SECURITYACCESSDENIED (51U)
 *   DCM_E_AUTHENTICATIONREQUIRED (52U)
 *   DCM_E_INVALIDKEY (53U)
 *   DCM_E_EXCEEDNUMBEROFATTEMPTS (54U)
 *   DCM_E_REQUIREDTIMEDELAYNOTEXPIRED (55U)
 *   DCM_E_CVF_INVALIDTIMEPERIOD (80U)
 *   DCM_E_CVF_INVALIDSIGNATURE (81U)
 *   DCM_E_CVF_INVALIDCHAINOFTRUST (82U)
 *   DCM_E_CVF_INVALIDTYPE (83U)
 *   DCM_E_CVF_INVALIDFORMAT (84U)
 *   DCM_E_CVF_INVALIDCONTENT (85U)
 *   DCM_E_CVF_INVALIDSCOPE (86U)
 *   DCM_E_CVF_INVALIDCERTIFICATEREVOKED (87U)
 *   DCM_E_OWNERSHIPVERIFICATIONFAILED (88U)
 *   DCM_E_CHALLENGECALCULATIONFAILED (89U)
 *   DCM_E_UPLOADDOWNLOADNOTACCEPTED (112U)
 *   DCM_E_TRANSFERDATASUSPENDED (113U)
 *   DCM_E_GENERALPROGRAMMINGFAILURE (114U)
 *   DCM_E_WRONGBLOCKSEQUENCECOUNTER (115U)
 *   DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING (120U)
 *   DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION (126U)
 *   DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION (127U)
 *   DCM_E_RPMTOOHIGH (129U)
 *   DCM_E_RPMTOOLOW (130U)
 *   DCM_E_ENGINEISRUNNING (131U)
 *   DCM_E_ENGINEISNOTRUNNING (132U)
 *   DCM_E_ENGINERUNTIMETOOLOW (133U)
 *   DCM_E_TEMPERATURETOOHIGH (134U)
 *   DCM_E_TEMPERATURETOOLOW (135U)
 *   DCM_E_VEHICLESPEEDTOOHIGH (136U)
 *   DCM_E_VEHICLESPEEDTOOLOW (137U)
 *   DCM_E_THROTTLE_PEDALTOOHIGH (138U)
 *   DCM_E_THROTTLE_PEDALTOOLOW (139U)
 *   DCM_E_TRANSMISSIONRANGENOTINNEUTRAL (140U)
 *   DCM_E_TRANSMISSIONRANGENOTINGEAR (141U)
 *   DCM_E_BRAKESWITCH_NOTCLOSED (143U)
 *   DCM_E_SHIFTERLEVERNOTINPARK (144U)
 *   DCM_E_TORQUECONVERTERCLUTCHLOCKED (145U)
 *   DCM_E_VOLTAGETOOHIGH (146U)
 *   DCM_E_VOLTAGETOOLOW (147U)
 *   DCM_E_VMSCNC_0 (240U)
 *   DCM_E_VMSCNC_1 (241U)
 *   DCM_E_VMSCNC_2 (242U)
 *   DCM_E_VMSCNC_3 (243U)
 *   DCM_E_VMSCNC_4 (244U)
 *   DCM_E_VMSCNC_5 (245U)
 *   DCM_E_VMSCNC_6 (246U)
 *   DCM_E_VMSCNC_7 (247U)
 *   DCM_E_VMSCNC_8 (248U)
 *   DCM_E_VMSCNC_9 (249U)
 *   DCM_E_VMSCNC_A (250U)
 *   DCM_E_VMSCNC_B (251U)
 *   DCM_E_VMSCNC_C (252U)
 *   DCM_E_VMSCNC_D (253U)
 *   DCM_E_VMSCNC_E (254U)
 * Dcm_OpStatusType: Enumeration of integer in interval [0...64] with enumerators
 *   DCM_INITIAL (0U)
 *   DCM_PENDING (1U)
 *   DCM_CANCEL (2U)
 *   DCM_FORCE_RCRRP_OK (3U)
 *   DCM_FORCE_RCRRP_NOT_OK (64U)
 * Dcm_SecLevelType: Enumeration of integer in interval [0...1] with enumerators
 *   DCM_SEC_LEV_LOCKED (0U)
 *   DCM_SEC_LEV_L1 (1U)
 * Dcm_SesCtrlType: Enumeration of integer in interval [0...97] with enumerators
 *   DCM_DEFAULT_SESSION (1U)
 *   DCM_PROGRAMMING_SESSION (2U)
 *   DCM_EXTENDED_DIAGNOSTIC_SESSION (3U)
 *   DCM_DeltaSession (97U)
 * DtLlcState: Enumeration of integer in interval [0...15] with enumerators
 *   LLC_STATE_INIT (0U)
 *   LLC_STATE_IDLE (1U)
 *   LLC_STATE_RAMPUP (2U)
 *   LLC_STATE_RUN (3U)
 *   LLC_STATE_RAMDOWN (4U)
 * DtSystemMode: Enumeration of integer in interval [0...15] with enumerators
 *   SYSMODE_INIT (0U)
 *   SYSMODE_STARTDIAG (1U)
 *   SYSMODE_STANDBY (2U)
 *   SYSMODE_STOPCURRENT (3U)
 *   SYSMODE_FAILURE (4U)
 *   SYSMODE_LOCKEDFAILURE (5U)
 *   SYSMODE_PRECHARGE (6U)
 *   SYSMODE_CONVERTING (7U)
 *   SYSMODE_PWRLATCH (8U)
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
 * Dt_DCDCState: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Starting_mode (0U)
 *   Cx1_Standby (1U)
 *   Cx2_DirectMode (2U)
 *   Cx3_Unavailable (3U)
 * Dt_DeltaAccessLevel: Enumeration of integer in interval [0...255] with enumerators
 *   DELTA_ACCESS_LOCKED (0U)
 *   DELTA_ACCESS_LEVEL1 (1U)
 *   DELTA_ACCESS_LEVEL2 (2U)
 * IT_Active: Enumeration of integer in interval [0...255] with enumerators
 *   CM_ACTIVE_INIT (0U)
 *   CM_ACTIVE_NOT_ACTIVE (1U)
 *   CM_ACTIVE_ACTIVE (2U)
 * IT_CP_State: Enumeration of integer in interval [0...255] with enumerators
 *   CM_CP_STATE_INIT (0U)
 *   CM_CP_STATE_VALID_PRESENT (1U)
 *   CM_CP_STATE_INVALID_PRESENT (2U)
 *   CM_CP_STATE_NOT_PRESENT (165U)
 * IT_Charge_Display: Enumeration of integer in interval [0...255] with enumerators
 *   CM_CHARGE_DISPLAY_INIT (0U)
 *   CM_CHARGE_DISPLAY_OFF (1U)
 *   CM_CHARGE_DISPLAY_COM (2U)
 *   CM_CHARGE_DISPLAY_READY (3U)
 *   CM_CHARGE_DISPLAY_CHARGING (4U)
 *   CM_CHARGE_DISPLAY_FULL (5U)
 *   CM_CHARGE_DISPLAY_ERROR (6U)
 * IT_CodingInit: Enumeration of integer in interval [0...255] with enumerators
 *   CM_CODINGINIT_ALLTODEFAULT (0U)
 *   CM_CODINGINIT_DEFAULTAFTERFLASH (1U)
 *   CM_CODINGINIT_ALLTODEFAULT_KEEPPRODUCTIONDATA (2U)
 * IT_CodingUpdate: Enumeration of integer in interval [0...255] with enumerators
 *   CM_CODINGUPDATE_ALL_PARAM (0U)
 *   CM_CODINGUPDATE_ALL_NVNORMAL (1U)
 *   CM_CODINGUPDATE_ALL_NVCYCLIC (2U)
 *   CM_CODINGUPDATE_ALL_NVIMMEDIATE (3U)
 *   CM_CODINGUPDATE_ALL_NVTRACE (4U)
 * IT_CouplerType: Enumeration of integer in interval [0...255] with enumerators
 *   CM_COUPLERTYPE_INIT (0U)
 *   CM_COUPLERTYPE_TYPE1 (1U)
 *   CM_COUPLERTYPE_TYPE2 (2U)
 *   CM_COUPLERTYPE_CHINA (3U)
 * IT_EVSE_State: Enumeration of integer in interval [0...255] with enumerators
 *   CM_EVSE_STATE_SNA (0U)
 *   CM_EVSE_STATE_READY (1U)
 *   CM_EVSE_STATE_NOPOWER (2U)
 *   CM_EVSE_STATE_OFF (3U)
 * IT_Enable: Enumeration of integer in interval [0...255] with enumerators
 *   CM_ENABLE_INIT (0U)
 *   CM_ENABLE_ENABLE (1U)
 *   CM_ENABLE_DISABLE (2U)
 * IT_HVILstate: Enumeration of integer in interval [0...255] with enumerators
 *   CM_HVILSTATE_INIT (0U)
 *   CM_HVILSTATE_CLOSED (1U)
 *   CM_HVILSTATE_HIGH (2U)
 *   CM_HVILSTATE_LOW (3U)
 *   CM_HVILSTATE_FAILURE (4U)
 *   CM_HVILSTATE_OPEN (5U)
 * IT_HighLow: Enumeration of integer in interval [0...255] with enumerators
 *   CM_HIGHLOW_INIT (0U)
 *   CM_HIGHLOW_LOW (1U)
 *   CM_HIGHLOW_HIGH (2U)
 *   CM_HIGHLOW_OFF (3U)
 * IT_Lock_Actuation: Enumeration of integer in interval [0...255] with enumerators
 *   CM_LOCK_ACTUATION_INIT (0U)
 *   CM_LOCK_ACTUATION_UNLOCK (1U)
 *   CM_LOCK_ACTUATION_LOCK (2U)
 *   CM_LOCK_ACTUATION_RETR_UNLOCK (3U)
 *   CM_LOCK_ACTUATION_LOCK_ERROR (4U)
 *   CM_LOCK_ACTUATION_PLAY_PROTECT (5U)
 *   CM_LOCK_ACTUATION_STOP_ACT (6U)
 *   CM_LOCK_ACTUATION_NO_ACT (7U)
 * IT_Locked_Unlocked: Enumeration of integer in interval [0...255] with enumerators
 *   CM_LOCKED_UNLOCKED_INIT (0U)
 *   CM_LOCKED_UNLOCKED_UNLOCKED (1U)
 *   CM_LOCKED_UNLOCKED_LOCKED (2U)
 *   CM_LOCKED_UNLOCKED_ERROR (3U)
 *   CM_LOCKED_UNLOCKED_SNA (4U)
 * IT_Motor: Enumeration of integer in interval [0...255] with enumerators
 *   CM_MOTORSTATUS_INIT (0U)
 *   CM_MOTORSTATUS_IDLE (1U)
 *   CM_MOTORSTATUS_BRAKE (2U)
 *   CM_MOTORSTATUS_MOVING (3U)
 *   CM_MOTORSTATUS_ERROR (4U)
 *   CM_MOTORSTATUS_OFF (5U)
 * IT_NumberOfPhases: Enumeration of integer in interval [0...255] with enumerators
 *   CM_NUMBEROFPHASES_INIT (0U)
 *   CM_NUMBEROFPHASES_ONE (1U)
 *   CM_NUMBEROFPHASES_TWO (2U)
 *   CM_NUMBEROFPHASES_THREE (3U)
 *   CM_NUMBEROFPHASES_NONE (4U)
 * IT_OBC_Mode: Enumeration of integer in interval [0...255] with enumerators
 *   CM_OBC_MODE_INIT (0U)
 *   CM_OBC_MODE_LOWPOWER (1U)
 *   CM_OBC_MODE_STANDBY (2U)
 *   CM_OBC_MODE_READYTOCHARGE (3U)
 *   CM_OBC_MODE_CHARGE (4U)
 * IT_OBC_State: Enumeration of integer in interval [0...255] with enumerators
 *   CM_OBC_STATE_INIT (0U)
 *   CM_OBC_STATE_NOT_READY (1U)
 *   CM_OBC_STATE_READY (2U)
 *   CM_OBC_STATE_ACTIVE (3U)
 *   CM_OBC_STATE_FAULT_C (4U)
 *   CM_OBC_STATE_FAULT_D (5U)
 *   CM_OBC_STATE_FAULT_E (6U)
 * IT_OnOff: Enumeration of integer in interval [0...255] with enumerators
 *   CM_ONOFF_INIT (0U)
 *   CM_ONOFF_OFF (1U)
 *   CM_ONOFF_ON (2U)
 * IT_OpenClose: Enumeration of integer in interval [0...255] with enumerators
 *   CM_OPENCLOSE_INIT (0U)
 *   CM_OPENCLOSE_CLOSE (1U)
 *   CM_OPENCLOSE_OPEN (2U)
 *   CM_OPENCLOSE_INVALID (3U)
 * IT_Plug_State: Enumeration of integer in interval [0...255] with enumerators
 *   CM_PLUG_STATE_INIT (0U)
 *   CM_PLUG_STATE_PLUGGED (3U)
 *   CM_PLUG_STATE_VEH_PLUGGED (5U)
 *   CM_PLUG_STATE_VEH_NOT_PLUGGED (6U)
 *   CM_PLUG_STATE_DEFECT (9U)
 * IT_PowerStage: Enumeration of integer in interval [0...255] with enumerators
 *   CM_POWERSTAGE_INIT (0U)
 *   CM_POWERSTAGE_DISABLED (1U)
 *   CM_POWERSTAGE_PARAM (2U)
 *   CM_POWERSTAGE_READY (3U)
 *   CM_POWERSTAGE_INRUSH (4U)
 *   CM_POWERSTAGE_BOOST (5U)
 *   CM_POWERSTAGE_DCDC (6U)
 *   CM_POWERSTAGE_ACTIVE (7U)
 *   CM_POWERSTAGE_PFC_SHUTDOWN (8U)
 *   CM_POWERSTAGE_LLC_SHUTDOWN (9U)
 *   CM_POWERSTAGE_CLEAR_FAULTS (10U)
 * IT_Prox_State: Enumeration of integer in interval [0...255] with enumerators
 *   CM_PROX_STATE_INIT (0U)
 *   CM_PROX_STATE_SNA (1U)
 *   CM_PROX_STATE_CONNECTED (2U)
 *   CM_PROX_STATE_NOT_CONNECTED (90U)
 * IT_Status: Enumeration of integer in interval [0...255] with enumerators
 *   CM_STATUS_INIT (0U)
 *   CM_STATUS_VALID (1U)
 *   CM_STATUS_INVALID (2U)
 * SaSrv_FVirginFlagType: Enumeration of integer in interval [0...255] with enumerators
 *   FVIRGIN (0U)
 *   FNORMAL (255U)
 * SaSrv_VirginFlagType: Enumeration of integer in interval [0...255] with enumerators
 *   VIRGIN (0U)
 *   NORMAL (255U)
 *
 * Array Types:
 * ============
 * DataArrayType_uint8_3: Array with 3 element(s) of type uint8
 * Dcm_Data10ByteType: Array with 10 element(s) of type uint8
 * Dcm_Data16ByteType: Array with 16 element(s) of type uint8
 * Dcm_Data17ByteType: Array with 17 element(s) of type uint8
 * Dcm_Data1ByteType: Array with 1 element(s) of type uint8
 * Dcm_Data20ByteType: Array with 20 element(s) of type uint8
 * Dcm_Data2ByteType: Array with 2 element(s) of type uint8
 * Dcm_Data31ByteType: Array with 31 element(s) of type uint8
 * Dcm_Data3ByteType: Array with 3 element(s) of type uint8
 * Dcm_Data4095ByteType: Array with 4095 element(s) of type uint8
 * Dcm_Data4ByteType: Array with 4 element(s) of type uint8
 * Dcm_Data5ByteType: Array with 5 element(s) of type uint8
 * Dcm_Data6ByteType: Array with 6 element(s) of type uint8
 * Dcm_Data8ByteType: Array with 8 element(s) of type uint8
 * IT_Array_08: Array with 8 element(s) of type IT_Array_Element
 * IT_Array_XCP_DSP: Array with 8 element(s) of type IT_XCP_DSP
 * SaSrv_AsymCounterType: Array with 32 element(s) of type uint8
 * SaSrv_ECUSerialNumberType: Array with 20 element(s) of type uint8
 * SaSrv_KilometerArrayType: Array with 4 element(s) of type uint8
 * SaSrv_PUNType: Array with 32 element(s) of type uint8
 *
 * Record Types:
 * =============
 * IT_CurrentMeasurement_100mA: Record with elements
 *   data of type IT_Current_100mA
 *   status of type IT_Status
 * IT_CurrentMeasurement_10mA: Record with elements
 *   data of type IT_Current_10mA
 *   status of type IT_Status
 * IT_CurrentMeasurement_1mA: Record with elements
 *   data of type IT_Current_1mA
 *   status of type IT_Status
 * IT_FrequencyMeasurement_100mHz: Record with elements
 *   frequency of type IT_Frequency_100mHz
 *   status of type IT_Status
 * IT_FrequencyMeasurement_1Hz: Record with elements
 *   frequency of type IT_Frequency_1Hz
 *   status of type IT_Status
 * IT_MagneticTemperatureMeasurement: Record with elements
 *   data of type IT_MagneticTemperature
 *   status of type IT_Status
 * IT_PowerMeasurement_100mW: Record with elements
 *   data of type IT_Power_100mW
 *   status of type IT_Status
 * IT_PowerMeasurement_1W: Record with elements
 *   data of type IT_Power_1W
 *   status of type IT_Status
 * IT_PowerMeasurement_500mW: Record with elements
 *   data of type IT_Power_500mW
 *   status of type IT_Status
 * IT_PwmMeasurement_100us: Record with elements
 *   status of type IT_Status
 *   periode of type IT_Time_100ns
 *   hightime of type IT_Time_100ns
 * IT_PwmMeasurement_1us: Record with elements
 *   status of type IT_Status
 *   periode of type IT_Time_1us
 *   hightime of type IT_Time_1us
 * IT_TemperatureMeasurement_0degC1: Record with elements
 *   data of type IT_Temperature_0degC1
 *   status of type IT_Status
 * IT_VoltageMeasurement_100mV: Record with elements
 *   data of type IT_Voltage_100mV
 *   status of type IT_Status
 * IT_VoltageMeasurement_10mV: Record with elements
 *   data of type IT_Voltage_10mV
 *   status of type IT_Status
 * IT_VoltageMeasurement_1mV: Record with elements
 *   data of type IT_Voltage_1mV
 *   status of type IT_Status
 *
 *********************************************************************************************************************/


#define ApplDiag_START_SEC_CODE
#include "ApplDiag_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAGP_SaSrv_KilometerInterface_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <P_SaSrv_KilometerInterface>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAGP_SaSrv_KilometerInterface_ReadData(uint8 *Data)
 *     Argument Data: uint8* is of type SaSrv_KilometerArrayType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_KilometerInterface_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAGP_SaSrv_KilometerInterface_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAGP_SaSrv_KilometerInterface_ReadData(P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAGP_SaSrv_KilometerInterface_ReadData (returns application error)
 *********************************************************************************************************************/
  #define BIG_ENDIAN      0xAA
  #define LITTLE_ENDIAN   0xCC
  #define SASRV_DISTANCE_ENDIANITY    BIG_ENDIAN

  DistanceTotalizer_HV DistanceTotalizer_copy = 0U;
  Rte_Read_R_DistanceTotalizer_HV_Dp_DistanceTotalizer_HV(&DistanceTotalizer_copy);

  DistanceTotalizer_copy = (DistanceTotalizer_copy / 100);  /* To convert to Km */
  
  #if(0)  /* TODO: DEWILSS */
  /* Handle the case of no Distance reading available */
  if(C_SACHA_DistanceTotalizer_copy_unavailable == DistanceTotalizer_copy || C_SACHA_DistanceTotalizer_copy_default == DistanceTotalizer_copy)
  {
    DistanceTotalizer_copy = 0;
  }
  #endif

  #if(SASRV_DISTANCE_ENDIANITY == BIG_ENDIAN)
  Data[0u] = (uint8) (APPLDIAG_MASK_BYTE_0 & DistanceTotalizer_copy);
  Data[1u] = (uint8) (DistanceTotalizer_copy >> APPLDIAG_SHIFT_1BYTE);
  Data[2u] = (uint8) (DistanceTotalizer_copy >> APPLDIAG_SHIFT_2BYTE);
  Data[3u] = (uint8) (DistanceTotalizer_copy >> APPLDIAG_SHIFT_3BYTE);
  #elif(SASRV_DISTANCE_ENDIANITY == LITTLE_ENDIAN)
  Data[0u] = (uint8) (DistanceTotalizer_copy >> APPLDIAG_SHIFT_3BYTE);
  Data[1u] = (uint8) (DistanceTotalizer_copy >> APPLDIAG_SHIFT_2BYTE);
  Data[2u] = (uint8) (DistanceTotalizer_copy >> APPLDIAG_SHIFT_1BYTE);
  Data[3u] = (uint8) (APPLDIAG_MASK_BYTE_0 & DistanceTotalizer_copy);
  #endif
  
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAGP_SaSrv_MemoryFailure_GetMemoryFailure
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetMemoryFailure> of PortPrototype <P_SaSrv_MemoryFailure>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAGP_SaSrv_MemoryFailure_GetMemoryFailure(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_MemoryFailureInterface_E_NOT_OK_NORMAL_SA
 *   RTE_E_MemoryFailureInterface_E_NOT_OK_NRC22
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAGP_SaSrv_MemoryFailure_GetMemoryFailure_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAGP_SaSrv_MemoryFailure_GetMemoryFailure(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAGP_SaSrv_MemoryFailure_GetMemoryFailure (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAGS_Dcm_BootVersion_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <S_Dcm_BootVersion_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAGS_Dcm_BootVersion_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data31ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_BootVersion_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_BootVersion_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAGS_Dcm_BootVersion_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAGS_Dcm_BootVersion_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAGS_Dcm_BootVersion_Read_ReadData (returns application error)
 *********************************************************************************************************************/
	 uint8 i;
	 uint8 u8Index;
   uint8 u8year;
   uint8 u8yearMSB;
   uint8 u8yearLSB;
   uint8 u8week;
   uint8 u8weekMSB;
   uint8 u8weekLSB;
   uint8 u8patch;
   // uint8 checkarr[31];
   u8Index = 0;
   u8year = Coding_Appl_Read_parameter_DID_F180(0);
   u8yearMSB = u8year / 10;
   u8yearLSB = u8year % 10;
   u8week =  Coding_Appl_Read_parameter_DID_F180(1);
   u8weekMSB = u8week / 10;
   u8weekLSB = u8week % 10;
   u8patch = Coding_Appl_Read_parameter_DID_F180(2);
   /* 36-02-014/--F /25953NDS28_3 RuleReference_BootVersion_010_b/RuleReference_BootVersion_015_b
  In default and programming session of bootloader software, the ECU shall answer positively to
  READ the BootVersion, using the dataRecord parameter as defined in [9.1.4] */

   Data[u8Index] = 0x01u;     /* RuleReference_BootVersion_140_a: The first data byte is always equals to 1 */
   u8Index++;
         /* year */
   Data[u8Index] = 0x30 + u8yearMSB; /* bootVersion[0]; */
	 u8Index++;
	 Data[u8Index] = 0x30 + u8yearLSB; /* bootVersion[0]; */
	 u8Index++;
	          /* week */
	 Data[u8Index] = 0x30 + u8weekMSB ; /* bootVersion[1]; */
	 u8Index++;
	 Data[u8Index] = 0x30 + u8weekLSB ; /* bootVersion[1]; */
	 u8Index++;
	 if (u8patch > 99) {
		  Data[u8Index] = 0x30 + u8patch / 100;  /* bootVersion[2]; */
		  u8Index++;
		  Data[u8Index] = 0x30 + (u8patch % 100) / 10; /* bootVersion[2]; */
		  u8Index++;
		  Data[u8Index] = 0x30 + u8patch % 10;  /* bootVersion[2]; */
		  u8Index++;
		  } /* end if */
	 else {
		    Data[u8Index] = 0x30 + u8patch / 10;  /* bootVersion[2]; */
		    u8Index++;
		    Data[u8Index] = 0x30 + u8patch % 10; /* bootVersion[2]; */
		    u8Index++;
		    } /* end else */
	 for (i = u8Index; i < 31u; i++)
		   {
	   /* RuleReference_BootVersion_130_a
   If the ECU answers to a BootVersion read request,using the max length (31),it shall use ONLY padding bytes with $20.*/
		            Data[i] = 0x20u;
		    }


  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAGS_Dcm_BootVersion_Read_ReadDataLength
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadDataLength> of PortPrototype <S_Dcm_BootVersion_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAGS_Dcm_BootVersion_Read_ReadDataLength(Dcm_OpStatusType OpStatus, uint16 *DataLength)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_BootVersion_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_BootVersion_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAGS_Dcm_BootVersion_Read_ReadDataLength_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAGS_Dcm_BootVersion_Read_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) DataLength) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAGS_Dcm_BootVersion_Read_ReadDataLength (returns application error)
 *********************************************************************************************************************/
  *DataLength += 31u;
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_DataServices_Data_In_Power1_Calib_Read_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Data_In_Power1_Calib_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_DataServices_Data_In_Power1_Calib_Read_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_In_Power1_Calib_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_In_Power1_Calib_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_DataServices_Data_In_Power1_Calib_Read_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_DataServices_Data_In_Power1_Calib_Read_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_DataServices_Data_In_Power1_Calib_Read_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
*ErrorCode = APPLDIAG_NRC_72;

  return RTE_E_DataServices_Data_In_Power1_Calib_Read_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_DataServices_Data_In_Power1_Calib_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_In_Power1_Calib_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_DataServices_Data_In_Power1_Calib_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_In_Power1_Calib_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_In_Power1_Calib_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_DataServices_Data_In_Power1_Calib_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_DataServices_Data_In_Power1_Calib_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_DataServices_Data_In_Power1_Calib_Read_ReadData (returns application error)
 *********************************************************************************************************************/

  Data[0] = (uint8)(Coding_Diag_Read_parameter_InputPowerGain1()    >> 8);
  Data[1] = (uint8)(Coding_Diag_Read_parameter_InputPowerGain1()        );
  Data[2] = (uint8)(Coding_Diag_Read_parameter_InputPowerOffset1()  >> 8);
  Data[3] = (uint8)(Coding_Diag_Read_parameter_InputPowerOffset1()      );

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_DataServices_Data_In_Power1_Calib_Read_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_Data_In_Power1_Calib_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_DataServices_Data_In_Power1_Calib_Read_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_In_Power1_Calib_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_In_Power1_Calib_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_DataServices_Data_In_Power1_Calib_Read_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_DataServices_Data_In_Power1_Calib_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_DataServices_Data_In_Power1_Calib_Read_WriteData (returns application error)
 *********************************************************************************************************************/
  uint16 loc_u16Gain   = (((uint16)Data[0] << 8) | (uint16)Data[1]);
  sint16 loc_s16Offset = (sint16)(((uint16)Data[2] << 8) | (uint16)Data[3]);
  uint8  loc_u8HwVersion;

  /* BDV4 Default Gain 2031, Offset -64 -> BDV4 Default Gain 2031*1,2, Offset -64**1,2 */

  Rte_Read_R_HwInfos_u8HwVersion(&loc_u8HwVersion);
  Coding_Diag_Write_parameter_InputPowerGain1( loc_u16Gain );
  Coding_Diag_Write_parameter_InputPowerOffset1(loc_s16Offset);

  return RTE_E_OK;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_DataServices_Data_In_Power2_Calib_Read_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Data_In_Power2_Calib_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_DataServices_Data_In_Power2_Calib_Read_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_In_Power2_Calib_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_In_Power2_Calib_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_DataServices_Data_In_Power2_Calib_Read_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_DataServices_Data_In_Power2_Calib_Read_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_DataServices_Data_In_Power2_Calib_Read_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_DataServices_Data_In_Power2_Calib_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_In_Power2_Calib_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_DataServices_Data_In_Power2_Calib_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_In_Power2_Calib_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_In_Power2_Calib_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_DataServices_Data_In_Power2_Calib_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_DataServices_Data_In_Power2_Calib_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_DataServices_Data_In_Power2_Calib_Read_ReadData (returns application error)
 *********************************************************************************************************************/

  Data[0] = (uint8)(Coding_Diag_Read_parameter_InputPowerGain2()    >> 8);
  Data[1] = (uint8)(Coding_Diag_Read_parameter_InputPowerGain2()        );
  Data[2] = (uint8)(Coding_Diag_Read_parameter_InputPowerOffset2()  >> 8);
  Data[3] = (uint8)(Coding_Diag_Read_parameter_InputPowerOffset2()      );

  return RTE_E_OK;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_DataServices_Data_In_Power2_Calib_Read_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_Data_In_Power2_Calib_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_DataServices_Data_In_Power2_Calib_Read_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_In_Power2_Calib_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_In_Power2_Calib_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_DataServices_Data_In_Power2_Calib_Read_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_DataServices_Data_In_Power2_Calib_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_DataServices_Data_In_Power2_Calib_Read_WriteData (returns application error)
 *********************************************************************************************************************/

  uint16 loc_u16Gain   = (((uint16)Data[0] << 8) | (uint16)Data[1]);
  sint16 loc_s16Offset = (sint16)(((uint16)Data[2] << 8) | (uint16)Data[3]);
  uint8  loc_u8HwVersion;

  /* BDV4 Default Gain 2031, Offset -64 -> BDV4 Default Gain 2031*1,2, Offset -64**1,2 */

  Rte_Read_R_HwInfos_u8HwVersion(&loc_u8HwVersion);
  Coding_Diag_Write_parameter_InputPowerGain2( loc_u16Gain );
  Coding_Diag_Write_parameter_InputPowerOffset2(loc_s16Offset);

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_DataServices_Data_In_Power3_Calib_Read_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Data_In_Power3_Calib_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_DataServices_Data_In_Power3_Calib_Read_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_In_Power3_Calib_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_In_Power3_Calib_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_DataServices_Data_In_Power3_Calib_Read_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_DataServices_Data_In_Power3_Calib_Read_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_DataServices_Data_In_Power3_Calib_Read_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_DataServices_Data_In_Power3_Calib_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_In_Power3_Calib_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_DataServices_Data_In_Power3_Calib_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_In_Power3_Calib_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_In_Power3_Calib_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_DataServices_Data_In_Power3_Calib_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_DataServices_Data_In_Power3_Calib_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_DataServices_Data_In_Power3_Calib_Read_ReadData (returns application error)
 *********************************************************************************************************************/

  Data[0] = (uint8)(Coding_Diag_Read_parameter_InputPowerGain3()    >> 8);
  Data[1] = (uint8)(Coding_Diag_Read_parameter_InputPowerGain3()        );
  Data[2] = (uint8)(Coding_Diag_Read_parameter_InputPowerOffset3()  >> 8);
  Data[3] = (uint8)(Coding_Diag_Read_parameter_InputPowerOffset3()      );
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_DataServices_Data_In_Power3_Calib_Read_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_Data_In_Power3_Calib_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_DataServices_Data_In_Power3_Calib_Read_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_In_Power3_Calib_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_In_Power3_Calib_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_DataServices_Data_In_Power3_Calib_Read_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_DataServices_Data_In_Power3_Calib_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_DataServices_Data_In_Power3_Calib_Read_WriteData (returns application error)
 *********************************************************************************************************************/

  uint16 loc_u16Gain   = (((uint16)Data[0] << 8) | (uint16)Data[1]);
  sint16 loc_s16Offset = (sint16)(((uint16)Data[2] << 8) | (uint16)Data[3]);
  uint8  loc_u8HwVersion;

  /* BDV4 Default Gain 2031, Offset -64 -> BDV4 Default Gain 2031*1,2, Offset -64**1,2 */

  Rte_Read_R_HwInfos_u8HwVersion(&loc_u8HwVersion);
  Coding_Diag_Write_parameter_InputPowerGain3( loc_u16Gain );
  Coding_Diag_Write_parameter_InputPowerOffset3(loc_s16Offset);
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_DCMDelta_Internal_DeltaSoftwareVersion_Read_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Data_Delta_Internal_DeltaSoftwareVersion_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_DCMDelta_Internal_DeltaSoftwareVersion_Read_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_Delta_Internal_DeltaSoftwareVersion_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_Delta_Internal_DeltaSoftwareVersion_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_DCMDelta_Internal_DeltaSoftwareVersion_Read_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_DCMDelta_Internal_DeltaSoftwareVersion_Read_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_DCMDelta_Internal_DeltaSoftwareVersion_Read_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_DCM_Data_VdefaultCONVERSIONstate_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <S_DCM_Data_VdefaultCONVERSIONstate_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_DCM_Data_VdefaultCONVERSIONstate_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_VdefaultCONVERSIONstate_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_VdefaultCONVERSIONstate_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_DCM_Data_VdefaultCONVERSIONstate_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_DCM_Data_VdefaultCONVERSIONstate_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_DCM_Data_VdefaultCONVERSIONstate_Read_ReadData (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_DataServices_Data_OutCurrent1_Calib_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_OutCurrent1_Calib_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_DataServices_Data_OutCurrent1_Calib_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_OutCurrent1_Calib_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_OutCurrent1_Calib_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_DataServices_Data_OutCurrent1_Calib_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_DataServices_Data_OutCurrent1_Calib_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_DataServices_Data_OutCurrent1_Calib_Read_ReadData (returns application error)
 *********************************************************************************************************************/
  Data[0] = (uint8)(Coding_Diag_Read_parameter_ADC_u16OutCurrent1Gain()    >> 8);
  Data[1] = (uint8)(Coding_Diag_Read_parameter_ADC_u16OutCurrent1Gain()        );
  Data[2] = (uint8)(Coding_Diag_Read_parameter_ADC_s16OutCurrent1Offset()  >> 8);
  Data[3] = (uint8)(Coding_Diag_Read_parameter_ADC_s16OutCurrent1Offset()      );
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_DataServices_Data_OutCurrent1_Calib_Read_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_Data_OutCurrent1_Calib_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_DataServices_Data_OutCurrent1_Calib_Read_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_OutCurrent1_Calib_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_OutCurrent1_Calib_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_DataServices_Data_OutCurrent1_Calib_Read_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_DataServices_Data_OutCurrent1_Calib_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_DataServices_Data_OutCurrent1_Calib_Read_WriteData (returns application error)
 *********************************************************************************************************************/
  uint16 loc_u16Gain   = (((uint16)Data[0] << 8) | (uint16)Data[1]);
  sint16 loc_s16Offset = (sint16)(((uint16)Data[2] << 8) | (uint16)Data[3]);

  Coding_Diag_Write_parameter_ADC_u16OutCurrent1Gain( loc_u16Gain );
  Coding_Diag_Write_parameter_ADC_s16OutCurrent1Offset(loc_s16Offset);
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_DataServices_Data_OutCurrent2_Calib_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_OutCurrent2_Calib_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_DataServices_Data_OutCurrent2_Calib_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_OutCurrent2_Calib_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_OutCurrent2_Calib_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_DataServices_Data_OutCurrent2_Calib_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_DataServices_Data_OutCurrent2_Calib_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_DataServices_Data_OutCurrent2_Calib_Read_ReadData (returns application error)
 *********************************************************************************************************************/
	  Data[0] = (uint8)(Coding_Diag_Read_parameter_ADC_u16OutCurrent2Gain()    >> 8);
	  Data[1] = (uint8)(Coding_Diag_Read_parameter_ADC_u16OutCurrent2Gain()        );
	  Data[2] = (uint8)(Coding_Diag_Read_parameter_ADC_s16OutCurrent2Offset()  >> 8);
	  Data[3] = (uint8)(Coding_Diag_Read_parameter_ADC_s16OutCurrent2Offset()      );
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_DataServices_Data_OutCurrent2_Calib_Read_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_Data_OutCurrent2_Calib_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_DataServices_Data_OutCurrent2_Calib_Read_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_OutCurrent2_Calib_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_OutCurrent2_Calib_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_DataServices_Data_OutCurrent2_Calib_Read_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_DataServices_Data_OutCurrent2_Calib_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_DataServices_Data_OutCurrent2_Calib_Read_WriteData (returns application error)
 *********************************************************************************************************************/
  uint16 loc_u16Gain   = (((uint16)Data[0] << 8) | (uint16)Data[1]);
  sint16 loc_s16Offset = (sint16)(((uint16)Data[2] << 8) | (uint16)Data[3]);

  Coding_Diag_Write_parameter_ADC_u16OutCurrent2Gain( loc_u16Gain );
  Coding_Diag_Write_parameter_ADC_s16OutCurrent2Offset(loc_s16Offset);
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_DataServices_Data_OutCurrent3_Calib_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_OutCurrent3_Calib_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_DataServices_Data_OutCurrent3_Calib_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_OutCurrent3_Calib_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_OutCurrent3_Calib_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_DataServices_Data_OutCurrent3_Calib_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_DataServices_Data_OutCurrent3_Calib_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_DataServices_Data_OutCurrent3_Calib_Read_ReadData (returns application error)
 *********************************************************************************************************************/
  Data[0] = (uint8)(Coding_Diag_Read_parameter_ADC_u16OutCurrent3Gain()    >> 8);
  Data[1] = (uint8)(Coding_Diag_Read_parameter_ADC_u16OutCurrent3Gain()        );
  Data[2] = (uint8)(Coding_Diag_Read_parameter_ADC_s16OutCurrent3Offset()  >> 8);
  Data[3] = (uint8)(Coding_Diag_Read_parameter_ADC_s16OutCurrent3Offset()      );
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_DataServices_Data_OutCurrent3_Calib_Read_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_Data_OutCurrent3_Calib_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_DataServices_Data_OutCurrent3_Calib_Read_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_OutCurrent3_Calib_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_OutCurrent3_Calib_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_DataServices_Data_OutCurrent3_Calib_Read_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_DataServices_Data_OutCurrent3_Calib_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_DataServices_Data_OutCurrent3_Calib_Read_WriteData (returns application error)
 *********************************************************************************************************************/
  uint16 loc_u16Gain   = (((uint16)Data[0] << 8) | (uint16)Data[1]);
  sint16 loc_s16Offset = (sint16)(((uint16)Data[2] << 8) | (uint16)Data[3]);

  Coding_Diag_Write_parameter_ADC_u16OutCurrent3Gain( loc_u16Gain );
  Coding_Diag_Write_parameter_ADC_s16OutCurrent3Offset(loc_s16Offset);
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_DataServices_Data_OutCurrent4_Calib_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_OutCurrent4_Calib_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_DataServices_Data_OutCurrent4_Calib_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_OutCurrent4_Calib_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_OutCurrent4_Calib_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_DataServices_Data_OutCurrent4_Calib_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_DataServices_Data_OutCurrent4_Calib_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_DataServices_Data_OutCurrent4_Calib_Read_ReadData (returns application error)
 *********************************************************************************************************************/
  Data[0] = (uint8)(Coding_Diag_Read_parameter_ADC_u16OutCurrent4Gain()    >> 8);
  Data[1] = (uint8)(Coding_Diag_Read_parameter_ADC_u16OutCurrent4Gain()        );
  Data[2] = (uint8)(Coding_Diag_Read_parameter_ADC_s16OutCurrent4Offset()  >> 8);
  Data[3] = (uint8)(Coding_Diag_Read_parameter_ADC_s16OutCurrent4Offset()      );
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_DataServices_Data_OutCurrent4_Calib_Read_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_Data_OutCurrent4_Calib_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_DataServices_Data_OutCurrent4_Calib_Read_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_OutCurrent4_Calib_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_OutCurrent4_Calib_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_DataServices_Data_OutCurrent4_Calib_Read_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_DataServices_Data_OutCurrent4_Calib_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_DataServices_Data_OutCurrent4_Calib_Read_WriteData (returns application error)
 *********************************************************************************************************************/
  uint16 loc_u16Gain   = (((uint16)Data[0] << 8) | (uint16)Data[1]);
  sint16 loc_s16Offset = (sint16)(((uint16)Data[2] << 8) | (uint16)Data[3]);

  Coding_Diag_Write_parameter_ADC_u16OutCurrent4Gain( loc_u16Gain );
  Coding_Diag_Write_parameter_ADC_s16OutCurrent4Offset(loc_s16Offset);
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_CAN_Received_HVFOTAConditionCheckStatus_HV_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <S_Dcm_CAN_Received_HVFOTAConditionCheckStatus_HV_Read>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_R_HVFOTAConditionCheckStatus_HV_HVFOTAConditionCheckStatus_HV(DT_HVFOTAConditionCheckStatus_HV *data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_CAN_Received_HVFOTAConditionCheckStatus_HV_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_CAN_Received_HVFOTAConditionCheckStatus_HV_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_CAN_Received_HVFOTAConditionCheckStatus_HV_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_CAN_Received_HVFOTAConditionCheckStatus_HV_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_CAN_Received_HVFOTAConditionCheckStatus_HV_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_CAN_Received_HVFOTAConditionCheckStatus_HV_Read_ReadData (returns application error)
 *********************************************************************************************************************/
//Data[0] = 0U;
  Rte_Read_R_HVFOTAConditionCheckStatus_HV_HVFOTAConditionCheckStatus_HV(Data);
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_CAN_Received_VehicleSpeed_HV_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <S_Dcm_CAN_Received_VehicleSpeed_HV_Read>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_R_VehicleSpeed_HV_VehicleSpeed_HV(DT_VehicleSpeed_HV *data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_CAN_Received_VehicleSpeed_HV_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data2ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_CAN_Received_VehicleSpeed_HV_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_CAN_Received_VehicleSpeed_HV_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_CAN_Received_VehicleSpeed_HV_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_CAN_Received_VehicleSpeed_HV_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_CAN_Received_VehicleSpeed_HV_Read_ReadData (returns application error)
 *********************************************************************************************************************/

  uint16 vspeed;
  Rte_Read_R_VehicleSpeed_HV_VehicleSpeed_HV(&vspeed);
  //VehicleSpeed_HV_ComRead(&vspeed);
  Data[0]= vspeed>>8;
  Data[1]= vspeed;
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_CAN_Received_vehicleStates_HV_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <S_Dcm_CAN_Received_vehicleStates_HV_Read>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_R_VehicleState_HV_vehicleStates_HV(DT_vehicleStates_HV *data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_CAN_Received_vehicleStates_HV_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_CAN_Received_vehicleStates_HV_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_CAN_Received_vehicleStates_HV_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_CAN_Received_vehicleStates_HV_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_CAN_Received_vehicleStates_HV_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_CAN_Received_vehicleStates_HV_Read_ReadData (returns application error)
 *********************************************************************************************************************/
	Rte_Read_R_VehicleState_HV_vehicleStates_HV(Data);
  //Com_ReceiveSignal(ComConf_ComSignal_VehicleStates_HV_oHEVC_RN111_oEXTCAN_7e4a5f57_Rx, (Data));
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_CAN_Transmitted_CRC_DCDC_RN104_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <S_Dcm_CAN_Transmitted_CRC_DCDC_RN104>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_R_CRC_DCDC_RN104_DT_CRC_DCDC_RN104(uint8 *data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_CAN_Transmitted_CRC_DCDC_RN104_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_DID_0x0121_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_DID_0x0121_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_CAN_Transmitted_CRC_DCDC_RN104_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_CAN_Transmitted_CRC_DCDC_RN104_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_CAN_Transmitted_CRC_DCDC_RN104_ReadData (returns application error)
 *********************************************************************************************************************/
	Rte_Read_R_CRC_DCDC_RN104_DT_CRC_DCDC_RN104(Data);
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_CAN_Transmitted_Clock_DCDC_RN104_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <S_Dcm_CAN_Transmitted_Clock_DCDC_RN104_Read>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_R_Clock_DCDC_RN104_DT_Clock_DCDC_RN104(Dt_Clock_DCDC_RN104 *data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_CAN_Transmitted_Clock_DCDC_RN104_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_CAN_Transmitted_Clock_DCDC_RN104_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_CAN_Transmitted_Clock_DCDC_RN104_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_CAN_Transmitted_Clock_DCDC_RN104_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_CAN_Transmitted_Clock_DCDC_RN104_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_CAN_Transmitted_Clock_DCDC_RN104_Read_ReadData (returns application error)
 *********************************************************************************************************************/
	Rte_Read_R_Clock_DCDC_RN104_DT_Clock_DCDC_RN104(Data);
	Data[0] &= 0x0f;
	return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_CalibrationNumber_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <S_Dcm_CalibrationNumber_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_CalibrationNumber_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data2ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_CalibrationNumber_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_CalibrationNumber_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_CalibrationNumber_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_CalibrationNumber_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_CalibrationNumber_Read_ReadData (returns application error)
 *********************************************************************************************************************/

  Data[0] = 0x01U;
  Data[1] = 0x00U;

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_CalibrationNumber_Read_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <S_Dcm_CalibrationNumber_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_CalibrationNumber_Read_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data2ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_CalibrationNumber_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_CalibrationNumber_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_CalibrationNumber_Read_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_CalibrationNumber_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_CalibrationNumber_Read_WriteData (returns application error)
 *********************************************************************************************************************/

  *ErrorCode = APPLDIAG_NRC_31;
  return RTE_E_INVALID;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_ConfigurationDataReference_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <S_Dcm_ConfigurationDataReference_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_ConfigurationDataReference_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data10ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_ConfigurationDataReference_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_ConfigurationDataReference_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_ConfigurationDataReference_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_ConfigurationDataReference_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_ConfigurationDataReference_Read_ReadData (returns application error)
 *********************************************************************************************************************/
  Data[0] = 0x30U;
  Data[1] = 0x30U;
  Data[2] = 0x30U;
  Data[3] = 0x30U;
  Data[4] = 0x30U;
  Data[5] = 0x30U;
  Data[6] = 0x30U;
  Data[7] = 0x30U;
  Data[8] = 0x30U;
  Data[9] = 0x30U;

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_ConfigurationDataReference_Read_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <S_Dcm_ConfigurationDataReference_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_ConfigurationDataReference_Read_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data10ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_ConfigurationDataReference_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_ConfigurationDataReference_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_ConfigurationDataReference_Read_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_ConfigurationDataReference_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_ConfigurationDataReference_Read_WriteData (returns application error)
 *********************************************************************************************************************/

  *ErrorCode = APPLDIAG_NRC_31;
  return RTE_E_INVALID;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_ConfigurationFileReferenceLink_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <S_Dcm_ConfigurationFileReferenceLink_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_ConfigurationFileReferenceLink_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data10ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_ConfigurationFileReferenceLink_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_ConfigurationFileReferenceLink_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_ConfigurationFileReferenceLink_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_ConfigurationFileReferenceLink_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_ConfigurationFileReferenceLink_Read_ReadData (returns application error)
 *********************************************************************************************************************/
/*  Data[0] = 'R';
  Data[1] = 'S';
  Data[2] = 'A';
  Data[3] = 'R';
  Data[4] = 'E';
  Data[5] = 'F';
  Data[6] = 'S';
  Data[7] = 'W';
  Data[8] = '3';
  Data[9] = 'R';
  return RTE_E_OK;*/

/* Same value as $F012 */
  if (10u == kEepSizeDID_F188)
  {
    uint8 u8_index = 0;
    for (u8_index = 0; u8_index < kEepSizeDID_F188; ++u8_index)
    {
      Data[u8_index] = Coding_Appl_Read_parameter_DID_F188(u8_index);
    } /* end for */
  }

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_ConfigurationFileReferenceLink_Read_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <S_Dcm_ConfigurationFileReferenceLink_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_ConfigurationFileReferenceLink_Read_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data10ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_ConfigurationFileReferenceLink_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_ConfigurationFileReferenceLink_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_ConfigurationFileReferenceLink_Read_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_ConfigurationFileReferenceLink_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_ConfigurationFileReferenceLink_Read_WriteData (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType tRetVal;
  if (DELTA_ACCESS_LEVEL1 == APPLDIAG_u8AccessLevel)
  {
    uint8 u8_index = 0;
    for (u8_index = 0; u8_index < kEepSizeDID_F188; ++u8_index)
    {
      Coding_Diag_Write_parameter_DID_F188(u8_index,Data[u8_index]);
    } /* end for */
    tRetVal = RTE_E_OK;
  }
  else
  {
    *ErrorCode = APPLDIAG_NRC_33;
     tRetVal =RTE_E_INVALID;
  }
  return tRetVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_DataServices_Data_AAPractice_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <S_Dcm_DataServices_Data_AAPractice>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_DataServices_Data_AAPractice_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_AAPractice_DCM_E_PENDING
 *   RTE_E_DataServices_Data_AAPractice_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_DataServices_Data_AAPractice_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_DataServices_Data_AAPractice_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_DataServices_Data_AAPractice_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_DataServices_Data_AAPractice_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <S_Dcm_DataServices_Data_AAPractice>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_DataServices_Data_AAPractice_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_AAPractice_DCM_E_PENDING
 *   RTE_E_DataServices_Data_AAPractice_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_DataServices_Data_AAPractice_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_DataServices_Data_AAPractice_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_DataServices_Data_AAPractice_ReadData (returns application error)
 *********************************************************************************************************************/
Data[0]=0x67;
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_DataServices_Data_AbsoluteTimeSince1rstIgnition_HV_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <S_Dcm_DataServices_Data_AbsoluteTimeSince1rstIgnition_HV_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_DataServices_Data_AbsoluteTimeSince1rstIgnition_HV_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data3ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_AbsoluteTimeSince1rstIgnition_HV_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_AbsoluteTimeSince1rstIgnition_HV_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_DataServices_Data_AbsoluteTimeSince1rstIgnition_HV_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_DataServices_Data_AbsoluteTimeSince1rstIgnition_HV_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_DataServices_Data_AbsoluteTimeSince1rstIgnition_HV_Read_ReadData (returns application error)
 *********************************************************************************************************************/
  APPLDIAG_S_Dem_SnapShot_Data_AbsoluteTimeSince1rstIgnition_HV_Read_ReadData(Data);
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_DataServices_Data_CAN_Transmitted_DCDCCurrentOutput_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <S_Dcm_DataServices_Data_CAN_Transmitted_DCDCCurrentOutput_Read>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_R_DCDCCurrentOutput_Dp_DCDCCurrentOutput(Dt_DCDCCurrentOutput *data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_DataServices_Data_CAN_Transmitted_DCDCCurrentOutput_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_CAN_Transmitted_DCDCCurrentOutput_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_CAN_Transmitted_DCDCCurrentOutput_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_DataServices_Data_CAN_Transmitted_DCDCCurrentOutput_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_DataServices_Data_CAN_Transmitted_DCDCCurrentOutput_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_DataServices_Data_CAN_Transmitted_DCDCCurrentOutput_Read_ReadData (returns application error)
 *********************************************************************************************************************/
  Data[0]= APPLDIAG_tDCDCCurrentOutput;
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_DataServices_Data_CodingWrite_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <S_Dcm_DataServices_Data_CodingWrite>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_DataServices_Data_CodingWrite_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_CodingWrite_DCM_E_PENDING
 *   RTE_E_DataServices_Data_CodingWrite_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_DataServices_Data_CodingWrite_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_DataServices_Data_CodingWrite_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_DataServices_Data_CodingWrite_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_DataServices_Data_CodingWrite_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <S_Dcm_DataServices_Data_CodingWrite>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_DataServices_Data_CodingWrite_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_CodingWrite_DCM_E_PENDING
 *   RTE_E_DataServices_Data_CodingWrite_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_DataServices_Data_CodingWrite_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_DataServices_Data_CodingWrite_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_DataServices_Data_CodingWrite_ReadData (returns application error)
 *********************************************************************************************************************/
 Data[0]=0x56;
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_DataServices_Data_CodingWrite_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <S_Dcm_DataServices_Data_CodingWrite>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_DataServices_Data_CodingWrite_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_CodingWrite_DCM_E_PENDING
 *   RTE_E_DataServices_Data_CodingWrite_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_DataServices_Data_CodingWrite_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_DataServices_Data_CodingWrite_WriteData(P2CONST(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_DataServices_Data_CodingWrite_WriteData (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_DataServices_Data_DTC_Occurrence_Counter_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <S_Dcm_DataServices_Data_DTC_Occurrence_Counter_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_DataServices_Data_DTC_Occurrence_Counter_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_DTC_Occurrence_Counter_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_DTC_Occurrence_Counter_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_DataServices_Data_DTC_Occurrence_Counter_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_DataServices_Data_DTC_Occurrence_Counter_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_DataServices_Data_DTC_Occurrence_Counter_Read_ReadData (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_Cpu_Load_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <S_Dcm_DataServices_Data_Delta_Internal_Cpu_Load_Read>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_R_Runtime_value(IT_Percentage_0p0 *data)
 *   Std_ReturnType Rte_Read_R_Runtime_Max_value(IT_Percentage_0p0 *data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_Cpu_Load_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_Delta_Internal_Cpu_Load_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_Delta_Internal_Cpu_Load_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_Cpu_Load_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_Cpu_Load_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_Cpu_Load_Read_ReadData (returns application error)
 *********************************************************************************************************************/
  Rte_Read_R_Runtime_Max_value (&Data[0]);
  Rte_Read_R_Runtime_value (&Data[1]);
  Data[2] = 0x00;
  Data[3] = 0x00;
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_Debug_Activation_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <S_Dcm_DataServices_Data_Delta_Internal_Debug_Activation_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_Debug_Activation_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_Delta_Internal_Debug_Activation_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_Delta_Internal_Debug_Activation_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_Debug_Activation_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_Debug_Activation_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_Debug_Activation_Read_ReadData (returns application error)
 *********************************************************************************************************************/

  Data[0] = ECUEXT_u8DebugActivation;
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_Debug_Activation_Read_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <S_Dcm_DataServices_Data_Delta_Internal_Debug_Activation_Read>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_P_Peak_u16Current(uint16 data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_C_Debug_Frame_Debug_Frame_Activation(uint8 *status_type)
 *     Synchronous Service Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_Debug_Activation_Read_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_Delta_Internal_Debug_Activation_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_Delta_Internal_Debug_Activation_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_Debug_Activation_Read_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_Debug_Activation_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_Debug_Activation_Read_WriteData (returns application error)
 *********************************************************************************************************************/

  if (DELTA_ACCESS_LEVEL2 == APPLDIAG_u8AccessLevel){
    ECUEXT_u8DebugActivation = Data[0];

    /* 0xEE = Deactivation ,0xff = Activation of Debug frame */
    if(ECUEXT_u8DebugActivation == ECUEXT_DEBUG_FRAME_ACTIVATION || ECUEXT_u8DebugActivation == ECUEXT_DEBUG_FRAME_DEACTIVATION)
    {
      Rte_Call_C_Debug_Frame_Debug_Frame_Activation( &ECUEXT_u8DebugActivation);
    }

    Rte_Write_P_Peak_u16Current(CFG_IOUT_MAX_PEAK_A);
   
  }else
  {
    *ErrorCode = APPLDIAG_NRC_33;
    return RTE_E_DataServices_Data_Delta_Internal_Debug_Activation_Read_E_NOT_OK;
  }
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_Delta_Access_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <S_Dcm_DataServices_Data_Delta_Internal_Delta_Access_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_Delta_Access_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data6ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_Delta_Internal_Delta_Access_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_Delta_Internal_Delta_Access_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_Delta_Access_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_Delta_Access_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_Delta_Access_Read_ReadData (returns application error)
 *********************************************************************************************************************/

  if (DELTA_ACCESS_LEVEL1 == APPLDIAG_u8AccessLevel)  {

      memcpy( Data, APPLDIAG_au8ReturnAccessLevel1, APPLDIAG_KEYLENGTH ); /*lint !e526 !e628 Memcopy in Standard header available */
    } else if (DELTA_ACCESS_LEVEL2 == APPLDIAG_u8AccessLevel) {

      memcpy( Data, APPLDIAG_au8ReturnAccessLevel2, APPLDIAG_KEYLENGTH ); /*lint !e526 !e628 Memcopy in Standard header available */
    } else {

      memcpy( Data, APPLDIAG_au8ReturnAccessLocked, APPLDIAG_KEYLENGTH ); /*lint !e526 !e628 Memcopy in Standard header available */
    } /* end else */
    return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_Delta_Access_Read_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <S_Dcm_DataServices_Data_Delta_Internal_Delta_Access_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_Delta_Access_Read_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data6ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_Delta_Internal_Delta_Access_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_Delta_Internal_Delta_Access_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_Delta_Access_Read_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_Delta_Access_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_Delta_Access_Read_WriteData (returns application error)
 *********************************************************************************************************************/

  if(APPLDIAG_KEYMATCH == memcmp( Data, APPLDIAG_au8AccessKeyLevel1, APPLDIAG_KEYLENGTH ))
    {
      APPLDIAG_u8AccessLevel = DELTA_ACCESS_LEVEL1;
    } /* end if */
    else
    {
      if (APPLDIAG_KEYMATCH == memcmp( Data, APPLDIAG_au8AccessKeyLevel2, APPLDIAG_KEYLENGTH ))
      {
        APPLDIAG_u8AccessLevel = DELTA_ACCESS_LEVEL2;
      } /* end else if */
      else
      {
        APPLDIAG_u8AccessLevel = DELTA_ACCESS_LOCKED;
        *ErrorCode = APPLDIAG_NRC_35;
      } /* end else */
    }

    Rte_Write_P_DeltaAccess_Level(APPLDIAG_u8AccessLevel);

    return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_Diagnostic_Session_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <S_Dcm_DataServices_Data_Delta_Internal_Diagnostic_Session_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_Diagnostic_Session_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_Delta_Internal_Diagnostic_Session_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_Delta_Internal_Diagnostic_Session_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_Diagnostic_Session_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_Diagnostic_Session_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_Diagnostic_Session_Read_ReadData (returns application error)
 *********************************************************************************************************************/

  Data[0] = APPLDIAG_tActivSession;
   return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_NvRamBlock_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <S_Dcm_DataServices_Data_Delta_Internal_NvRamBlock_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_NvRamBlock_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data4095ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_Delta_Internal_NvRamBlock_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_Delta_Internal_NvRamBlock_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_NvRamBlock_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_NvRamBlock_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_NvRamBlock_Read_ReadData (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_NvRamBlock_Read_ReadDataLength
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadDataLength> of PortPrototype <S_Dcm_DataServices_Data_Delta_Internal_NvRamBlock_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_NvRamBlock_Read_ReadDataLength(Dcm_OpStatusType OpStatus, uint16 *DataLength)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_Delta_Internal_NvRamBlock_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_Delta_Internal_NvRamBlock_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_NvRamBlock_Read_ReadDataLength_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_NvRamBlock_Read_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) DataLength) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_NvRamBlock_Read_ReadDataLength (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_NvRamBlock_Read_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <S_Dcm_DataServices_Data_Delta_Internal_NvRamBlock_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_NvRamBlock_Read_WriteData(const uint8 *Data, uint16 DataLength, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data4095ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_Delta_Internal_NvRamBlock_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_Delta_Internal_NvRamBlock_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_NvRamBlock_Read_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_NvRamBlock_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_DATA) Data, uint16 DataLength, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_NvRamBlock_Read_WriteData (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_Reset_Reason_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <S_Dcm_DataServices_Data_Delta_Internal_Reset_Reason_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_Reset_Reason_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data6ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_Delta_Internal_Reset_Reason_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_Delta_Internal_Reset_Reason_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_Reset_Reason_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_Reset_Reason_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_Reset_Reason_Read_ReadData (returns application error)
 *********************************************************************************************************************/

  Data[0] = Coding_au8ResetInfos_block_st.Coding_appldiag_ECUEXT_au8ResetInfos[1]; /* Reset reason  */
  Data[3] = Coding_au8ResetInfos_block_st.Coding_appldiag_ECUEXT_au8ResetInfos[0]; /* Reset counter */

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_Supply_Voltage_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <S_Dcm_DataServices_Data_Delta_Internal_Supply_Voltage_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_Supply_Voltage_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data2ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_Delta_Internal_Supply_Voltage_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_Delta_Internal_Supply_Voltage_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_Supply_Voltage_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_Supply_Voltage_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_Supply_Voltage_Read_ReadData (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_XCP_Activation_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <S_Dcm_DataServices_Data_Delta_Internal_XCP_Activation_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_XCP_Activation_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_Delta_Internal_XCP_Activation_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_Delta_Internal_XCP_Activation_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_XCP_Activation_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_XCP_Activation_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_XCP_Activation_Read_ReadData (returns application error)
 *********************************************************************************************************************/

  Data[0] = ECUEXT_u8XcpActivation;
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_XCP_Activation_Read_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <S_Dcm_DataServices_Data_Delta_Internal_XCP_Activation_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_XCP_Activation_Read_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_Delta_Internal_XCP_Activation_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_Delta_Internal_XCP_Activation_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_XCP_Activation_Read_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_XCP_Activation_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_DataServices_Data_Delta_Internal_XCP_Activation_Read_WriteData (returns application error)
 *********************************************************************************************************************/

  ECUEXT_u8XcpActivation = Data[0];
   return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_DataServices_Data_Example_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <S_Dcm_DataServices_Data_Example>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_DataServices_Data_Example_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_Example_DCM_E_PENDING
 *   RTE_E_DataServices_Data_Example_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_DataServices_Data_Example_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_DataServices_Data_Example_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_DataServices_Data_Example_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
*ErrorCode = APPLDIAG_NRC_78;
return RTE_E_DataServices_Data_Example_E_NOT_OK;
  //return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_DataServices_Data_Example_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <S_Dcm_DataServices_Data_Example>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_DataServices_Data_Example_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_Example_DCM_E_PENDING
 *   RTE_E_DataServices_Data_Example_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_DataServices_Data_Example_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_DataServices_Data_Example_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_DataServices_Data_Example_ReadData (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_DataServices_Data_Mileage_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <S_Dcm_DataServices_Data_Mileage_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_DataServices_Data_Mileage_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data3ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_Mileage_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_Mileage_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_DataServices_Data_Mileage_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_DataServices_Data_Mileage_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_DataServices_Data_Mileage_Read_ReadData (returns application error)
 *********************************************************************************************************************/
  APPLDIAG_S_Dem_SnapShot_Data_Mileage_Read_ReadData(Data);
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_Delta_Internal_DeltaSoftwareVersion_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_Delta_Internal_DeltaSoftwareVersion_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_Delta_Internal_DeltaSoftwareVersion_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data8ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_Delta_Internal_DeltaSoftwareVersion_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_Delta_Internal_DeltaSoftwareVersion_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_Delta_Internal_DeltaSoftwareVersion_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_Delta_Internal_DeltaSoftwareVersion_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_Delta_Internal_DeltaSoftwareVersion_Read_ReadData (returns application error)
 *********************************************************************************************************************/

  Data[0] = 0x43 + ((DELTA_SAMPLE_VERSION & 0xF0) >> 4) ;       /* Delta Sample MSB */
  Data[1] = 0x30 + (DELTA_SAMPLE_VERSION & 0x0F);               /* Delta Sample LSB */

  Data[2] = 0x52 + ((DELTA_MAJOR_VERSION & 0xF0) >> 4) ;        /* Major Version MSB */
  Data[3] = 0x30 + (DELTA_MAJOR_VERSION & 0x0F);                /* Major Version LSB */

  Data[4] = 0x50 + ((DELTA_MINOR_VERSION & 0xF0) >> 4) ;        /* Minor Version MSB */
  Data[5] = 0x30 + (DELTA_MINOR_VERSION & 0x0F);                /* Minor Version LSB */

  Data[6] = 0x54 + ((DELTA_TEST_VERSION & 0xF0) >> 4) ;         /* Test Version MSB */
  Data[7] = 0x30 + (DELTA_TEST_VERSION & 0x0F);                 /* Test Version LSB */

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_Delta_Internal_DeltaSoftwareVersion_Read_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_Data_Delta_Internal_DeltaSoftwareVersion_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_Delta_Internal_DeltaSoftwareVersion_Read_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data8ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_Delta_Internal_DeltaSoftwareVersion_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_Delta_Internal_DeltaSoftwareVersion_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_Delta_Internal_DeltaSoftwareVersion_Read_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_Delta_Internal_DeltaSoftwareVersion_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_Delta_Internal_DeltaSoftwareVersion_Read_WriteData (returns application error)
 *********************************************************************************************************************/

  *ErrorCode = APPLDIAG_NRC_31;
  return RTE_E_INVALID;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_ECUSerialNumberDataIdentifier_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <S_Dcm_ECUSerialNumberDataIdentifier_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_ECUSerialNumberDataIdentifier_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data20ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_ECUSerialNumberDataIdentifier_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_ECUSerialNumberDataIdentifier_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_ECUSerialNumberDataIdentifier_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_ECUSerialNumberDataIdentifier_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_ECUSerialNumberDataIdentifier_Read_ReadData (returns application error)
 *********************************************************************************************************************/

	if (20u == kEepSizeDID_F18C)
	{
	  uint8 u8_index = 0;
	  for (u8_index = 0; u8_index < kEepSizeDID_F18C; ++u8_index)
	  {
	    Data[u8_index] = Coding_Appl_Read_parameter_DID_F18C(u8_index);
	  } /* end for */
	}

	return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_ECUSerialNumberDataIdentifier_Read_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <S_Dcm_ECUSerialNumberDataIdentifier_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_ECUSerialNumberDataIdentifier_Read_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data20ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_ECUSerialNumberDataIdentifier_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_ECUSerialNumberDataIdentifier_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_ECUSerialNumberDataIdentifier_Read_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_ECUSerialNumberDataIdentifier_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_ECUSerialNumberDataIdentifier_Read_WriteData (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType tRetVal;
  if (DELTA_ACCESS_LEVEL1 == APPLDIAG_u8AccessLevel)
	{
	  uint8 u8_index = 0;
	  for (u8_index = 0; u8_index < kEepSizeDID_F18C; ++u8_index)
	  {
	   Coding_Diag_Write_parameter_DID_F18C(u8_index,Data[u8_index]);
	  } /* end for */
	  tRetVal= RTE_E_OK;
	}
  else
  {
    *ErrorCode = APPLDIAG_NRC_33;
      tRetVal=RTE_E_INVALID;
  }
	return tRetVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_Fingerprint_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <S_Dcm_Fingerprint_Read>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_R_DCDCInputPower_Dp_DCDCInputPower(Dt_DCDCInputPower *data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_Fingerprint_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data16ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_Fingerprint_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_Fingerprint_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_Fingerprint_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_Fingerprint_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_Fingerprint_Read_ReadData (returns application error)
 *********************************************************************************************************************/

  // if (16u == kEepSizeDID_F010)
  // {
  //   uint8 u8_index = 0;
  //   for (u8_index = 0; u8_index < kEepSizeDID_F010; ++u8_index)
  //   {
  //     Data[u8_index] = Coding_Appl_Read_parameter_DID_F010(u8_index);
  //   } /* end for */
  // }

// Data[0]=0xAB;
// Data[1]=0xCD;
// Data[2]=0xEF;
// Data[3]=0x11;
// Data[4]=0x22;
uint8 var;
Rte_Read_R_DCDCInputPower_Dp_DCDCInputPower(&var);
Data[0]=var;
return RTE_E_OK;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_Fingerprint_Read_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <S_Dcm_Fingerprint_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_Fingerprint_Read_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data16ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_Fingerprint_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_Fingerprint_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_Fingerprint_Read_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_Fingerprint_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_Fingerprint_Read_WriteData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType tRetVal;
  if (DELTA_ACCESS_LEVEL1 == APPLDIAG_u8AccessLevel)
  {
    uint8 u8_index = 0;
    for (u8_index = 0; u8_index < kEepSizeDID_F010; ++u8_index)
    {
      Coding_Diag_Write_parameter_DID_F010(u8_index,Data[u8_index]);
    } /* end for */
    tRetVal= RTE_E_OK;
  }
  else
  {
    *ErrorCode = APPLDIAG_NRC_33;
     tRetVal=RTE_E_INVALID;
  }
  return tRetVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_IndexSrvData_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <S_Dcm_IndexSrvData_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_IndexSrvData_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data10ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_IndexSrvData_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_IndexSrvData_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_IndexSrvData_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_IndexSrvData_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_IndexSrvData_Read_ReadData (returns application error)
 *********************************************************************************************************************/

	if (10u == kEepSizeDID_F011)
	{
	  uint8 u8_index = 0;
	  for (u8_index = 0; u8_index < kEepSizeDID_F011; ++u8_index)
	  {
	    Data[u8_index] = Coding_Appl_Read_parameter_DID_F011(u8_index);
	  } /* end for */
	}

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_IndexSrvData_Read_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <S_Dcm_IndexSrvData_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_IndexSrvData_Read_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data10ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_IndexSrvData_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_IndexSrvData_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_IndexSrvData_Read_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_IndexSrvData_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_IndexSrvData_Read_WriteData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType tRetVal;
  if (DELTA_ACCESS_LEVEL1 == APPLDIAG_u8AccessLevel)
  {
    uint8 u8_index = 0;
    for (u8_index = 0; u8_index < kEepSizeDID_F011; ++u8_index)
    {
      Coding_Diag_Write_parameter_DID_F011(u8_index,Data[u8_index]);
    } /* end for */
    tRetVal= RTE_E_OK;
  }
  else
  {
    *ErrorCode = APPLDIAG_NRC_33;
     tRetVal=RTE_E_INVALID;
  }
  return tRetVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_OperationalReference_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <S_Dcm_OperationalReference_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_OperationalReference_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data10ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_OperationalReference_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_OperationalReference_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_OperationalReference_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_OperationalReference_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_OperationalReference_Read_ReadData (returns application error)
 *********************************************************************************************************************/

	if (10u == kEepSizeDID_F012)
	{
	  uint8 u8_index = 0;
	  for (u8_index = 0; u8_index < kEepSizeDID_F012; ++u8_index)
	  {
	    Data[u8_index] = Coding_Appl_Read_parameter_DID_F012(u8_index);
	  } /* end for */
	}

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_OperationalReference_Read_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <S_Dcm_OperationalReference_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_OperationalReference_Read_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data10ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_OperationalReference_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_OperationalReference_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_OperationalReference_Read_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_OperationalReference_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_OperationalReference_Read_WriteData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType tRetVal;
  if (DELTA_ACCESS_LEVEL1 == APPLDIAG_u8AccessLevel)
  {
    uint8 u8_index = 0;
    for (u8_index = 0; u8_index < kEepSizeDID_F012; ++u8_index)
    {
      Coding_Diag_Write_parameter_DID_F012(u8_index,Data[u8_index]);
    } /* end for */
    tRetVal = RTE_E_OK;
  }
  else
  {
    *ErrorCode = APPLDIAG_NRC_33;
     tRetVal =RTE_E_INVALID;
  }
  return tRetVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_ProductionMode_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <S_Dcm_ProductionMode_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_ProductionMode_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_ProductionMode_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_ProductionMode_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_ProductionMode_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_ProductionMode_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_ProductionMode_Read_ReadData (returns application error)
 *********************************************************************************************************************/
  Rte_Read_R_SYSMAN_u8SystemMode(Data);
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_ProductionMode_Read_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <S_Dcm_ProductionMode_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_ProductionMode_Read_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_ProductionMode_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_ProductionMode_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_ProductionMode_Read_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_ProductionMode_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_ProductionMode_Read_WriteData (returns application error)
 *********************************************************************************************************************/
  *ErrorCode = APPLDIAG_NRC_11;
  return RTE_E_INVALID;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_SecondaryOperationalReference_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <S_Dcm_SecondaryOperationalReference_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_SecondaryOperationalReference_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data10ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_SecondaryOperationalReference_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_SecondaryOperationalReference_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_SecondaryOperationalReference_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_SecondaryOperationalReference_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_SecondaryOperationalReference_Read_ReadData (returns application error)
 *********************************************************************************************************************/

   return RTE_E_DataServices_Data_SecondaryOperationalReference_Read_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_SecondaryOperationalReference_Read_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <S_Dcm_SecondaryOperationalReference_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_SecondaryOperationalReference_Read_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data10ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_SecondaryOperationalReference_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_SecondaryOperationalReference_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_SecondaryOperationalReference_Read_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_SecondaryOperationalReference_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_SecondaryOperationalReference_Read_WriteData (returns application error)
 *********************************************************************************************************************/
  *ErrorCode = APPLDIAG_NRC_31;
  return RTE_E_INVALID;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_SystemSupplierIdentifier_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <S_Dcm_SystemSupplierIdentifier_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_SystemSupplierIdentifier_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data5ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_SystemSupplierIdentifier_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_SystemSupplierIdentifier_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_SystemSupplierIdentifier_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_SystemSupplierIdentifier_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_SystemSupplierIdentifier_Read_ReadData (returns application error)
 *********************************************************************************************************************/
  
    uint8 u8_index = 0;
    uint8 Supplier_ID[] = {'D', 'E', 'L', 'T', 'A'};
    for (u8_index = 0; u8_index < kEepSizeDID_F18A; ++u8_index)
    {
      Data[u8_index] = Supplier_ID[u8_index];
    } /* end for */
  
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_VDIAG_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <S_Dcm_VDIAG_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_VDIAG_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_VDIAG_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_VDIAG_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_VDIAG_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_VDIAG_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_VDIAG_Read_ReadData (returns application error)
 *********************************************************************************************************************/
  Data[0] = 0x0CU; /* fix value */
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_VDIAG_Read_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <S_Dcm_VDIAG_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_VDIAG_Read_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_VDIAG_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_VDIAG_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_VDIAG_Read_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_VDIAG_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_VDIAG_Read_WriteData (returns application error)
 *********************************************************************************************************************/
  *ErrorCode = APPLDIAG_NRC_31;
  return RTE_E_INVALID;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_VIN_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <S_Dcm_VIN_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_VIN_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data17ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_VIN_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_VIN_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_VIN_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_VIN_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_VIN_Read_ReadData (returns application error)
 *********************************************************************************************************************/
	if (17u == kEepSizeDID_F190)
	{
	  uint8 index = 0;
	  for (index = 0; index < kEepSizeDID_F190; ++index)
	  {
	    Data[index] = Coding_Diag_Read_parameter_appldiag_VIN(index) ;
	  } /* end for */
	}

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_VIN_Read_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <S_Dcm_VIN_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_VIN_Read_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data17ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_VIN_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_VIN_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_VIN_Read_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_VIN_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_VIN_Read_WriteData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType tRetVal;
    uint8 data_00;
    uint8 data_ff;
    uint8 data_30;
    uint8 u8_index;
    uint8 u8_Flag ;
    u8_Flag = Coding_Diag_Read_parameter_VIN_flag();
    data_00= 0u;
    data_ff= 0u;
    data_30= 0u;
    /* Check data Byte */
    for (u8_index = 0; u8_index < kEepSizeDID_F190; ++u8_index)
    {
      if(Data[u8_index]== 0x0u)          /* check all Data byte is 0x00 */
      {
        data_00++;
      }
      else if(Data[u8_index]== 0xFFu)    /* check all Data byte is 0xff */
      {
        data_ff++;
      }
      else if(Data[u8_index]== 0x30u)    /* check all Data byte  is 0x30 */
      {
        data_30++;
      }
      else
      {
        /* MISRA - Nothing Todo */
      }
    }/* end for */

              /* Check valid data */
    if (kEepSizeDID_F190 == data_00 || kEepSizeDID_F190 == data_ff || kEepSizeDID_F190 == data_30 )
    {                                                            /* DRC 14(UDS): RuleReference_VIN_060_b */
      *ErrorCode = APPLDIAG_NRC_31;
      tRetVal = RTE_E_DataServices_Data_VIN_Read_E_NOT_OK;
    }

        /* Check internal security level */
    else if (!((u8_Flag ) && (APPLDIAG_tSecLevel==DCM_SEC_LEV_LOCKED)))
    {
           /* Write VIN to Nv Memory */
      for (u8_index = 0; u8_index < kEepSizeDID_F190; ++u8_index)
      {
        Coding_Diag_Write_parameter_VIN( u8_index,Data[u8_index]);
      } /* end for */
      Coding_Diag_Write_parameter_VIN_flag( SET );
      tRetVal = RTE_E_OK;
    } /* end if */
    else
    {                                                             /*DRC 14(UDS):  RuleReference_VIN_080_a */
      *ErrorCode = APPLDIAG_NRC_33;
      tRetVal    = RTE_E_DataServices_Data_VIN_Read_E_NOT_OK;
    }

    return tRetVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_VehicleManufacturerECUHardwareNumber_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <S_Dcm_VehicleManufacturerECUHardwareNumber_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_VehicleManufacturerECUHardwareNumber_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data10ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_VehicleManufacturerECUHardwareNumber_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_VehicleManufacturerECUHardwareNumber_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_VehicleManufacturerECUHardwareNumber_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_VehicleManufacturerECUHardwareNumber_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_VehicleManufacturerECUHardwareNumber_Read_ReadData (returns application error)
 *********************************************************************************************************************/
	if (10u == kEepSizeDID_F191)
	{
	  uint8 u8_index = 0;
	  for (u8_index = 0; u8_index < kEepSizeDID_F191; ++u8_index)
	  {
	    Data[u8_index] = Coding_Appl_Read_parameter_DID_F191(u8_index);
	  } /* end for */
	}
	return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_VehicleManufacturerECUHardwareNumber_Read_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <S_Dcm_VehicleManufacturerECUHardwareNumber_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_VehicleManufacturerECUHardwareNumber_Read_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data10ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_VehicleManufacturerECUHardwareNumber_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_VehicleManufacturerECUHardwareNumber_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_VehicleManufacturerECUHardwareNumber_Read_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_VehicleManufacturerECUHardwareNumber_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_VehicleManufacturerECUHardwareNumber_Read_WriteData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType tRetVal;
  if (DELTA_ACCESS_LEVEL1 == APPLDIAG_u8AccessLevel)
  {
    uint8 u8_index = 0;
    for (u8_index = 0; u8_index < kEepSizeDID_F191; ++u8_index)
    {
      Coding_Diag_Write_parameter_DID_F191(u8_index,Data[u8_index]);
    } /* end for */
    tRetVal = RTE_E_OK;
  }
  else
  {
    *ErrorCode = APPLDIAG_NRC_33;
     tRetVal =RTE_E_INVALID;
  }
  return tRetVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_VehicleManufacturerSparePartNumber_N_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <S_Dcm_VehicleManufacturerSparePartNumber_N_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_VehicleManufacturerSparePartNumber_N_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data10ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_VehicleManufacturerSparePartNumber_N_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_VehicleManufacturerSparePartNumber_N_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_VehicleManufacturerSparePartNumber_N_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_VehicleManufacturerSparePartNumber_N_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_VehicleManufacturerSparePartNumber_N_Read_ReadData (returns application error)
 *********************************************************************************************************************/
	if (10u == kEepSizeDID_F1A1)
	{
	  uint8 u8_index = 0;
	  for (u8_index = 0; u8_index < kEepSizeDID_F1A1; ++u8_index)
	  {
	    Data[u8_index] = Coding_Appl_Read_parameter_DID_F1A1(u8_index);
	  } /* end for */
	}
	return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_VehicleManufacturerSparePartNumber_N_Read_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <S_Dcm_VehicleManufacturerSparePartNumber_N_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_VehicleManufacturerSparePartNumber_N_Read_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data10ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_VehicleManufacturerSparePartNumber_N_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_VehicleManufacturerSparePartNumber_N_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_VehicleManufacturerSparePartNumber_N_Read_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_VehicleManufacturerSparePartNumber_N_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_VehicleManufacturerSparePartNumber_N_Read_WriteData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType tRetVal;
  if (DELTA_ACCESS_LEVEL1 == APPLDIAG_u8AccessLevel)
  {
    uint8 u8_index = 0;
    for (u8_index = 0; u8_index < kEepSizeDID_F1A1; ++u8_index)
    {
      Coding_Diag_Write_parameter_DID_F1A1(u8_index,Data[u8_index]);
    } /* end for */
    tRetVal = RTE_E_OK;
  }
  else
  {
    *ErrorCode = APPLDIAG_NRC_33;
     tRetVal =RTE_E_INVALID;
  }
  return tRetVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_VehicleManufacturerSparePartNumber_R_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <S_Dcm_VehicleManufacturerSparePartNumber_R_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_VehicleManufacturerSparePartNumber_R_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data10ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_VehicleManufacturerSparePartNumber_R_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_VehicleManufacturerSparePartNumber_R_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_VehicleManufacturerSparePartNumber_R_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_VehicleManufacturerSparePartNumber_R_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_VehicleManufacturerSparePartNumber_R_Read_ReadData (returns application error)
 *********************************************************************************************************************/
	if (10u == kEepSizeDID_F187)
	{
	  uint8 u8_index = 0;
	  for (u8_index = 0; u8_index < kEepSizeDID_F187; ++u8_index)
	  {
	    Data[u8_index] = Coding_Appl_Read_parameter_DID_F187(u8_index);
	  } /* end for */
	}
	return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dcm_VehicleManufacturerSparePartNumber_R_Read_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <S_Dcm_VehicleManufacturerSparePartNumber_R_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dcm_VehicleManufacturerSparePartNumber_R_Read_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data10ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_VehicleManufacturerSparePartNumber_R_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_VehicleManufacturerSparePartNumber_R_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_VehicleManufacturerSparePartNumber_R_Read_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dcm_VehicleManufacturerSparePartNumber_R_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dcm_VehicleManufacturerSparePartNumber_R_Read_WriteData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType tRetVal;
  if (DELTA_ACCESS_LEVEL1 == APPLDIAG_u8AccessLevel)
  {
    uint8 u8_index = 0;
    for (u8_index = 0; u8_index < kEepSizeDID_F187; ++u8_index)
    {
      Coding_Diag_Write_parameter_DID_F187(u8_index,Data[u8_index]);
    } /* end for */
    tRetVal = RTE_E_OK;
  }
  else
  {
    *ErrorCode = APPLDIAG_NRC_33;
     tRetVal =RTE_E_INVALID;
  }
  return tRetVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dem_SnapShot_Data_AbsoluteTimeSince1rstIgnition_HV_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <S_Dem_SnapShot_Data_AbsoluteTimeSince1rstIgnition_HV_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dem_SnapShot_Data_AbsoluteTimeSince1rstIgnition_HV_Read_ReadData(uint8 *Data)
 *     Argument Data: uint8* is of type DataArrayType_uint8_3
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_Data_DID_0xf0d2_AbsoluteTimeSince1rstIgnition_HV_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dem_SnapShot_Data_AbsoluteTimeSince1rstIgnition_HV_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dem_SnapShot_Data_AbsoluteTimeSince1rstIgnition_HV_Read_ReadData(P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dem_SnapShot_Data_AbsoluteTimeSince1rstIgnition_HV_Read_ReadData (returns application error)
 *********************************************************************************************************************/
  
  Data[0] = (uint8)(APPLDIAG_tAbsoluteTimeSince1rstIgn>>16);
  Data[1] = (uint8)(APPLDIAG_tAbsoluteTimeSince1rstIgn>>8);
  Data[2] = (uint8)(APPLDIAG_tAbsoluteTimeSince1rstIgn);
  
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_S_Dem_SnapShot_Data_Mileage_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <S_Dem_SnapShot_Data_Mileage_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType APPLDIAG_S_Dem_SnapShot_Data_Mileage_Read_ReadData(uint8 *Data)
 *     Argument Data: uint8* is of type DataArrayType_uint8_3
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_Data_DID_0xf0d0_Mileage_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dem_SnapShot_Data_Mileage_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) APPLDIAG_S_Dem_SnapShot_Data_Mileage_Read_ReadData(P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_S_Dem_SnapShot_Data_Mileage_Read_ReadData (returns application error)
 *********************************************************************************************************************/
  uint32 loc_u32Mileage;
  
  loc_u32Mileage = (uint32)(APPLDIAG_tDistanceTotalizer/100u); /* Resolution = 1 as per requirent */
  
  Data[0] = (uint8)(loc_u32Mileage>>16);
  Data[1] = (uint8)(loc_u32Mileage>>8);
  Data[2] = (uint8)(loc_u32Mileage);
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_SaSrv_WriteAsymCounter
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <AsymCounter> of PortPrototype <PR_SaSrv_AsymCounterInterface>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_PR_SaSrv_AsymCounterInterface_AsymCounter(uint8 *data)
 *     Argument data: uint8* is of type SaSrv_AsymCounterType
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_SaSrv_WriteAsymCounter_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, ApplDiag_CODE) APPLDIAG_SaSrv_WriteAsymCounter(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_SaSrv_WriteAsymCounter
 *********************************************************************************************************************/

  uint8 counter[32];
  Rte_Read_ApplDiag_PR_SaSrv_AsymCounterInterface_AsymCounter(counter);
  /* MemCopy */
  memcpy(SaSrv_SecAccess_NvMBlock.AsymCounter, counter, 32);
  mg_AsymCounterSynchRequest = TRUE;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_SaSrv_WriteFailedAttemptCounter
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <FailedAttemptCounter> of PortPrototype <PR_SaSrv_FailedAttemptCounterInterface>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_PR_SaSrv_FailedAttemptCounterInterface_FailedAttemptCounter(SaSrv_FailedAttemptCounterType *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_SaSrv_WriteFailedAttemptCounter_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, ApplDiag_CODE) APPLDIAG_SaSrv_WriteFailedAttemptCounter(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_SaSrv_WriteFailedAttemptCounter
 *********************************************************************************************************************/
  uint8 counter = 0;
  Rte_Read_ApplDiag_PR_SaSrv_FailedAttemptCounterInterface_FailedAttemptCounter(&counter);
  SaSrv_SecAccess_NvMBlock.FailedAttemptCounter = counter;
  mg_FailedAttempCntSynchRequest = TRUE;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_SaSrv_WriteMileageForNormalMode
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <MileageForNormalMode> of PortPrototype <PR_SaSrv_MileageForNormalModeInterface>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_PR_SaSrv_MileageForNormalModeInterface_MileageForNormalMode(SaSrv_MileageForNormalModeType *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_SaSrv_WriteMileageForNormalMode_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, ApplDiag_CODE) APPLDIAG_SaSrv_WriteMileageForNormalMode(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_SaSrv_WriteMileageForNormalMode
 *********************************************************************************************************************/
  uint8 mileage = 0;
  Rte_Read_ApplDiag_PR_SaSrv_MileageForNormalModeInterface_MileageForNormalMode(&mileage);
  SaSrv_VirginMode_NvMBlock.MileageForNormalMode = mileage;

  /* Write coding block for MilegaeForNormalMode */
  Coding_Diag_Write_parameter_MileageForNormalMode(mileage);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_SaSrv_WritePUN
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <PUN> of PortPrototype <PR_SaSrv_PUN>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_PR_SaSrv_PUN_PUN(uint8 *data)
 *     Argument data: uint8* is of type SaSrv_PUNType
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_SaSrv_WritePUN_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, ApplDiag_CODE) APPLDIAG_SaSrv_WritePUN(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_SaSrv_WritePUN
 *********************************************************************************************************************/
  uint8 PUN[32];
  Rte_Read_ApplDiag_PR_SaSrv_PUN_PUN(PUN);
  memcpy(SaSrv_SecAccess_NvMBlock.PUN, PUN, 32);
  mg_PUNSynchRequest = TRUE;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_SaSrv_WriteStatusFlag
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <StatusFlag> of PortPrototype <R_SaSrv_StatusFlag>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_R_SaSrv_StatusFlag_StatusFlag(SaSrv_StatusFlagType *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_SaSrv_WriteStatusFlag_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, ApplDiag_CODE) APPLDIAG_SaSrv_WriteStatusFlag(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_SaSrv_WriteStatusFlag
 *********************************************************************************************************************/
  uint8 statusFlag = 0;
  Rte_Read_R_SaSrv_StatusFlag_StatusFlag(&statusFlag);
  SaSrv_SecAccess_NvMBlock.StatusFlag = statusFlag;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_SaSrv_WriteVirginFlag
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <VirginFlag> of PortPrototype <PR_SaSrv_VirginFlag>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_PR_SaSrv_VirginFlag_VirginFlag(SaSrv_VirginFlagType *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_SaSrv_WriteVirginFlag_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, ApplDiag_CODE) APPLDIAG_SaSrv_WriteVirginFlag(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_SaSrv_WriteVirginFlag
 *********************************************************************************************************************/
// #if(1)  /* DEWILSS: Check impl */
//   uint8 virginFlag = 0;
//   Rte_Read_ApplDiag_PR_SaSrv_VirginFlag_VirginFlag(&virginFlag);
//   SaSrv_VirginMode_NvMBlock.VirginFlag = virginFlag;

//   /* Write coding block (FBL shared block) */
//   Coding_Diag_Write_parameter_FBL_DiagSecH_VirginFlag(virginFlag);
// #else
//   UDS_WriteVirginflag = 50;
// #endif
UDS_WriteVirginflag = VIRGIN_FLAG_WRITING_DELAY_TIME;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_vInit
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_R_HwInfos_u8HwVariant(uint8 *data)
 *   Std_ReturnType Rte_Read_R_HwInfos_u8HwVersion(uint8 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_PR_SaSrv_AsymCounterInterface_AsymCounter(const uint8 *data)
 *     Argument data: uint8* is of type SaSrv_AsymCounterType
 *   Std_ReturnType Rte_Write_PR_SaSrv_FailedAttemptCounterInterface_FailedAttemptCounter(SaSrv_FailedAttemptCounterType data)
 *   Std_ReturnType Rte_Write_PR_SaSrv_MileageForNormalModeInterface_MileageForNormalMode(SaSrv_MileageForNormalModeType data)
 *   Std_ReturnType Rte_Write_PR_SaSrv_PUN_PUN(const uint8 *data)
 *     Argument data: uint8* is of type SaSrv_PUNType
 *   Std_ReturnType Rte_Write_PR_SaSrv_VirginFlag_VirginFlag(SaSrv_VirginFlagType data)
 *   Std_ReturnType Rte_Write_P_DeltaAccess_Level(Dt_DeltaAccessLevel data)
 *   Std_ReturnType Rte_Write_P_SaSrv_FVirgin_FVirginFlag(SaSrv_FVirginFlagType data)
 *   Std_ReturnType Rte_Write_P_SaSrv_SecuredSrvData_ECUSerialNumberDataIdentifier(const uint8 *data)
 *     Argument data: uint8* is of type SaSrv_ECUSerialNumberType
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_vInit_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, ApplDiag_CODE) APPLDIAG_vInit(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_vInit
 *********************************************************************************************************************/
  uint8 virginFlag = 0, FVirginFlag = 0;
   APPLDIAG_u8Debug[0] = 0u;
   APPLDIAG_u8Debug[1] = 0u;
   APPLDIAG_u8Debug[2] = 0u;
   APPLDIAG_u8Debug[3] = 0u;

   APPLDIAG_tAbsoluteTimeSince1rstIgn  = 0u;
   APPLDIAG_tDistanceTotalizer         = 0u;
   APPLDIAG_tDCDCCurrentOutput         = 0u;   
   APPLDIAG_tSecLevel                  = DCM_SEC_LEV_LOCKED;
   APPLDIAG_tActivSession              = DCM_DEFAULT_SESSION;
   APPLDIAG_tLastSystemMode            = SYSMODE_INIT;
   APPLDIAG_RESET = SET;
   if((memcmp(&(Coding_FBL_DataBlock3_block_st.Coding_appldiag_DID_F012),&(Coding_FBL_DataBlock3_def_block_st.Coding_appldiag_DID_F012),kEepSizeDID_F012)))
   {
  //  memcpy(&(Coding_FBL_DataBlock3_block_st.Coding_appldiag_DID_F012),&(Coding_FBL_DataBlock3_def_block_st.Coding_appldiag_DID_F012),kEepSizeDID_F012);
   memcpy(&(Coding_FBL_DataBlock1.Coding_appldiag_DID_F188),&(Coding_FBL_DataBlock1_def.Coding_appldiag_DID_F188),kEepSizeDID_F188);
   }


     
  /* Write stored NvM values to SaSrv */
  /* Rte_Write_PR_SaSrv_AsymCounterInterface_AsymCounter(SaSrv_SecAccess_NvMBlock.AsymCounter); */
  Rte_Write_PR_SaSrv_AsymCounterInterface_AsymCounter(Coding_FBL_DataBlock1.Coding_appldiag_FBL_DiagSecH_Counter);
  /* Rte_Write_PR_SaSrv_FailedAttemptCounterInterface_FailedAttemptCounter(SaSrv_SecAccess_NvMBlock.FailedAttemptCounter); */
  Rte_Write_PR_SaSrv_FailedAttemptCounterInterface_FailedAttemptCounter(Coding_FBL_DataBlock1.Coding_appldiag_FBL_SecAccessInvalidCount);
  /* Rte_Write_PR_SaSrv_PUN_PUN(SaSrv_SecAccess_NvMBlock.PUN); */
  Rte_Write_PR_SaSrv_PUN_PUN(Coding_FBL_DataBlock1.Coding_appldiag_PUN);
  Rte_Write_PR_SaSrv_MileageForNormalModeInterface_MileageForNormalMode(SaSrv_VirginMode_NvMBlock.MileageForNormalMode);
  Rte_Write_P_SaSrv_SecuredSrvData_ECUSerialNumberDataIdentifier(Coding_FBL_DataBlock3_block_st.Coding_appldiag_DID_F18C);

  
  /* Init SaSrv mode */
  #if(SASRV_MODE == FVIRGIN) /* Virgin Mode */
  Rte_Write_P_SaSrv_FVirgin_FVirginFlag(FVIRGIN);  
  #elif(SASRV_MODE == FNORMAL) /* Normal Mode */
  Rte_Write_P_SaSrv_FVirgin_FVirginFlag(FNORMAL);
  #endif
  virginFlag = Coding_Appl_Read_parameter_FBL_DiagSecH_VirginFlag(); /*read coding block*/ 
  Rte_Write_PR_SaSrv_VirginFlag_VirginFlag(virginFlag);

    /* Initiliaze Synch Writing Flags */
  mg_AsymCounterSynchRequest = FALSE;
  mg_FailedAttempCntSynchRequest = FALSE;
  mg_SaSrvSeedSynhDelay_Flag = FALSE;
  UDS_VirginFlagWritingRequest = FALSE;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: APPLDIAG_vMain
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
 *   Std_ReturnType Rte_Read_PR_SaSrv_AsymCounterInterface_AsymCounter(uint8 *data)
 *     Argument data: uint8* is of type SaSrv_AsymCounterType
 *   Std_ReturnType Rte_Read_PR_SaSrv_FailedAttemptCounterInterface_FailedAttemptCounter(SaSrv_FailedAttemptCounterType *data)
 *   Std_ReturnType Rte_Read_PR_SaSrv_PUN_PUN(uint8 *data)
 *     Argument data: uint8* is of type SaSrv_PUNType
 *   Std_ReturnType Rte_Read_R_AbsoluteTimeSince1rstIgn_HV_Dp_AbsoluteTimeSince1rstIgn_HV(AbsoluteTimeSince1rstIgn_HV *data)
 *   Std_ReturnType Rte_Read_R_CDDAD_MajorFaults_Dp_AD_Fault(Dt_AD_MajorFlt *data)
 *   Std_ReturnType Rte_Read_R_CDDAD_MinorFaults_Dp_AD_Fault(Dt_AD_MinorFlt *data)
 *   Std_ReturnType Rte_Read_R_DistanceTotalizer_HV_Dp_DistanceTotalizer_HV(DistanceTotalizer_HV *data)
 *   Std_ReturnType Rte_Read_R_Log_Reset_Event_Reset_Reason(uint8 *data)
 *   Std_ReturnType Rte_Read_R_SYSMAN_u8SystemMode(DtSystemMode *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_P_UART_Reset_Event_Reset_Reason(uint8 data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_DCMServices_GetSecurityLevel(Dcm_SecLevelType *SecLevel)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DCMServices_E_OK
 *   Std_ReturnType Rte_Call_DCMServices_GetSesCtrlType(Dcm_SesCtrlType *SesCtrlType)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DCMServices_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_vMain_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, ApplDiag_CODE) APPLDIAG_vMain(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: APPLDIAG_vMain
 *********************************************************************************************************************/
  uint8        loc_u8HwVersion;
  uint8        loc_u8Reset_Case ;
  uint8        loc_u8Reset_Flag ;
  uint8        loc_u8FBLReset_Flag ;
  uint16       loc_u16Gain;
  DtSystemMode loc_tSystemMode;
  uint8 u8_index = 0;

  Std_ReturnType tRetVal = RTE_E_OK;
  uint8 virginFlag = 0, FvirginFlag = 0,virginFlagRte =0;
  uint8 Data[1]; 
  uint8 AsymCounter[32];  
  uint8 PUN[32];
  uint8 AttempCounter = 0;

  Rte_Read_R_SYSMAN_u8SystemMode(&loc_tSystemMode);
  Rte_Call_DCMServices_GetSecurityLevel(&APPLDIAG_tSecLevel);
  Rte_Call_DCMServices_GetSesCtrlType(&APPLDIAG_tActivSession);
  Rte_Read_R_AbsoluteTimeSince1rstIgn_HV_Dp_AbsoluteTimeSince1rstIgn_HV(&APPLDIAG_tAbsoluteTimeSince1rstIgn);
  Rte_Read_R_DistanceTotalizer_HV_Dp_DistanceTotalizer_HV(&APPLDIAG_tDistanceTotalizer);
  Rte_Read_R_DCDCCurrentOutput_Dp_DCDCCurrentOutput(&APPLDIAG_tDCDCCurrentOutput);
  Rte_Read_R_Log_Reset_Event_Reset_Reason(&loc_u8Reset_Case);
  loc_u8Reset_Flag = Coding_Diag_Read_parameter_ECUEXT_au8ResetInfos_Flag();
  loc_u8FBLReset_Flag = 2;



  if((SYSMODE_STARTDIAG == loc_tSystemMode) && (SYSMODE_STARTDIAG != APPLDIAG_tLastSystemMode)){

    loc_u16Gain = Coding_Diag_Read_parameter_ADC_u16OutCurrentGain();
    if((uint16)10000 > loc_u16Gain)
    {
      Coding_Diag_Write_parameter_ADC_u16OutCurrentGain(16384u);
      Coding_Diag_Write_parameter_ADC_s16OutCurrentOffset(0u);
    }

    loc_u16Gain = Coding_Diag_Read_parameter_ADC_u16OutCurrent1Gain();
    if((uint16)10000 > loc_u16Gain)
    {
      Coding_Diag_Write_parameter_ADC_u16OutCurrent1Gain(16384u);
      Coding_Diag_Write_parameter_ADC_s16OutCurrent1Offset(0u);
    }

    loc_u16Gain = Coding_Diag_Read_parameter_ADC_u16OutCurrent2Gain();
    if((uint16)10000 > loc_u16Gain)
    {
      Coding_Diag_Write_parameter_ADC_u16OutCurrent2Gain(16384u);
      Coding_Diag_Write_parameter_ADC_s16OutCurrent2Offset(0u);
    }

    loc_u16Gain = Coding_Diag_Read_parameter_ADC_u16OutCurrent3Gain();
    if((uint16)10000 > loc_u16Gain)
    {
      Coding_Diag_Write_parameter_ADC_u16OutCurrent3Gain(16384u);
      Coding_Diag_Write_parameter_ADC_s16OutCurrent3Offset(0u);
    }

    loc_u16Gain = Coding_Diag_Read_parameter_ADC_u16OutCurrent4Gain();
    if( (loc_u16Gain < 2021u) || (3754u < loc_u16Gain))
    {
      Coding_Diag_Write_parameter_ADC_u16OutCurrent4Gain(16384u);
      Coding_Diag_Write_parameter_ADC_s16OutCurrent4Offset(0u);
    }

  #if(0)
    /* BDV4 Default Gain 2031, Offset -64 -> BDV4 Default Gain 2031*1,2, Offset -64**1,2 */
    Rte_Read_R_HwInfos_u8HwVersion(&loc_u8HwVersion);
    loc_u16Gain = Coding_Diag_Read_parameter_Hvdc_u16InCurrentGain();

    if( (loc_u8HwVersion < CFG_HW_BDV5) && (2274u < loc_u16Gain)){
		   Coding_Diag_Write_parameter_Hvdc_u16InCurrentGain(2031u);
		   Coding_Diag_Write_parameter_Hvdc_s16InCurrentOffset(-65L);
	  }

	  loc_u16Gain = Coding_Diag_Read_parameter_Hvdc_u16InCurrentGain2();
	  if( (loc_u8HwVersion < CFG_HW_BDV5) && (2274u < loc_u16Gain)){
		   Coding_Diag_Write_parameter_Hvdc_u16InCurrentGain2(2031u);
		   Coding_Diag_Write_parameter_Hvdc_s16InCurrentOffset2(-65L);
	  }

	  loc_u16Gain = Coding_Diag_Read_parameter_Hvdc_u16InCurrentGain3();
	  if( (loc_u8HwVersion < CFG_HW_BDV5) && (2274u < loc_u16Gain)){
		   Coding_Diag_Write_parameter_Hvdc_u16InCurrentGain3(2031u);
		   Coding_Diag_Write_parameter_Hvdc_s16InCurrentOffset3(-65L);
	  }
  #endif
  }
  
  if(loc_u8Reset_Flag == URTout_RESET )
  {
    /* Check UART reset Flag */
    Rte_Write_P_UART_Reset_Event_Reset_Reason (1u);
    loc_u8Reset_Case = URTout_RESET;
     Coding_Diag_Write_parameter_ECUEXT_au8ResetInfos_Flag( URTout_RESET);
  }
  else if(loc_u8FBLReset_Flag == Coding_Diag_Read_parameter_ResetFlag())
  {
    /* Check FBL reset Flag */
    loc_u8Reset_Case = PowerOnReset ;
    Coding_Diag_Write_parameter_ResetFlag(CLEAR);
  }
  else
  {
    /* Nothing to Do */
  }
  if(APPLDIAG_RESET == SET)
  {
  if(loc_u8Reset_Case != PowerOnReset && loc_u8Reset_Flag != SET )
    {
      uint8 u8Index = 0u;
      uint8 u8Reset_Ctr ;
      uint8 u8LtsInfo;
      u8Reset_Ctr =  Coding_au8ResetInfos_block_st.Coding_appldiag_ECUEXT_au8ResetInfos[0];
      u8LtsInfo = (u8Reset_Ctr % 16 ) + 1;

      /*Reset counter is increased by 1 */
      Coding_Diag_Write_parameter_ECUEXT_au8ResetInfos( (uint16) u8Index++ , u8Reset_Ctr+1 );
      Coding_Diag_Write_parameter_ECUEXT_au8ResetInfos( (uint16) u8Index, u8LtsInfo);
      if (u8Reset_Ctr == 0xFF)
      {
        /*if ctr is Greater than 255, 2byte will be set and ctr=00 */
        u8Reset_Ctr = 0u;
        u8Index = 0x2u;
        Coding_Diag_Write_parameter_ECUEXT_au8ResetInfos( (uint16) u8Index,SET );
      }
      /* Fill The latest info in old%16 addr */
      u8Index = u8LtsInfo * 4 ;
      Coding_Diag_Write_parameter_ECUEXT_au8ResetInfos( (uint16) u8Index+3,( uint8 )APPLDIAG_tDistanceTotalizer );
      Coding_Diag_Write_parameter_ECUEXT_au8ResetInfos( (uint16) u8Index+2,( uint8 )(APPLDIAG_tDistanceTotalizer >> 8) );
      Coding_Diag_Write_parameter_ECUEXT_au8ResetInfos( (uint16) u8Index+1,( uint8 )(APPLDIAG_tDistanceTotalizer >> 16));
      /*0x01: Reset by external watchdog*/
      if (loc_u8Reset_Case == 0x0C || loc_u8Reset_Case == 0x0D || loc_u8Reset_Case == 0x0E ||loc_u8Reset_Case == 0x0F)
      {
        loc_u8Reset_Case = WDGReset;
      }
      /*0x02: Reset by clock monitor*/
      else if (loc_u8Reset_Case == 0x08 ||loc_u8Reset_Case == 0x09 ||loc_u8Reset_Case == 0x0A)
      {
        loc_u8Reset_Case = CLKReset;
      }
      /*0x03: Reset by software*/
      else if (loc_u8Reset_Case == 0x03)
      {
        loc_u8Reset_Case = SWReset;
      }
      /*0x04: Reset by UART Time out*/
      else if (loc_u8Reset_Flag == URTout_RESET || loc_u8Reset_Flag == (URTout_RESET+1))
      {
        loc_u8Reset_Case = URTout_RESET;
      }
      /* no reset */
      else
      {
        loc_u8Reset_Case = 0x00;
      }
      Coding_Diag_Write_parameter_ECUEXT_au8ResetInfos( (uint16) u8Index,( uint8 )loc_u8Reset_Case );
      Coding_Diag_Write_parameter_ECUEXT_au8ResetInfos_Flag( CLEAR);
      APPLDIAG_RESET = CLEAR;
    }
    else
    {
      APPLDIAG_RESET = CLEAR;
      Coding_Diag_Write_parameter_ECUEXT_au8ResetInfos_Flag( CLEAR);
    }
  }

  APPLDIAG_tLastSystemMode = loc_tSystemMode;

    /* DEWILSS: TODO: Check Impl. */
  /* ########################## VIRGIN FLAGS ############################## */
  /* synch of coding FBL shared block1 regarding the Virgin and FVirgin flags with FBL*/
  #if(SASRV_MODE == FVIRGIN) /* Virgin Mode */
  #if 0
    FvirginFlag = Coding_Appl_Read_parameter_FBL_DiagSecH_FVirginFlag(); /*read coding block*/  
      /* Update Coding block*/    
    if ((FvirginFlagWritingDone == FALSE)/*&& (VirginFlagWritingDone == TRUE)*/&& (FvirginFlag != FVIRGIN ))
    {
      Data[0] = FVIRGIN;  
      tRetVal = Rte_Call_C_CodingReadWriteData_WriteData(0xF063, (t_Coding_DestPtr*) Data , 1U);      
      if (RTE_E_AI_CodingDiag_E_NOK == tRetVal)
      {
          tRetVal = RTE_E_OK;
      }
      else if (RTE_E_AI_CodingDiag_E_PENDING == tRetVal)
      {
        tRetVal = RTE_E_AI_CodingDiag_E_PENDING;
      }
      else
      {
        tRetVal = RTE_E_OK;      
        FvirginFlagWritingDone = TRUE;
      }
    }
  #endif
    FvirginFlag = Coding_Appl_Read_parameter_FBL_DiagSecH_FVirginFlag(); /*read coding block*/  
      /* Update Coding block*/    
    if ((FvirginFlagWritingDone == FALSE)/*&& (VirginFlagWritingDone == TRUE)*/&& (FvirginFlag != FVIRGIN ))
    {
      Data[0] = FVIRGIN;  
      tRetVal = Coding_DiagWriteData(0xF063, (t_Coding_DestPtr*) Data , 1U);      
      if (RTE_E_AI_CodingDiag_E_NOK == tRetVal)
      {
          tRetVal = RTE_E_OK;
      }
      else if (RTE_E_AI_CodingDiag_E_PENDING == tRetVal)
      {
        tRetVal = RTE_E_AI_CodingDiag_E_PENDING;
      }
      else
      {
        tRetVal = RTE_E_OK;      
        FvirginFlagWritingDone = TRUE;
      }
    }

  #elif(SASRV_MODE == FNORMAL)

  #if 0
  virginFlag = Coding_Appl_Read_parameter_FBL_DiagSecH_VirginFlag(); /*read coding block*/ 
    Rte_Read_PR_SaSrv_VirginFlag_VirginFlag(&virginFlagRte);
    /*Update RTE */
    if (virginFlagRte != FNORMAL )
    {
      Rte_Write_PR_SaSrv_VirginFlag_VirginFlag(FNORMAL);/* update virgin flag second block*/
    }
    /* Update Coding block*/
    if ((VirginFlagWritingDone == FALSE)&& (virginFlag != FNORMAL ))
    {  
      Data[0] = FNORMAL;         
      tRetVal = Rte_Call_C_CodingReadWriteData_WriteData(0xF062, (t_Coding_DestPtr*) Data , 1U);  /* update coding block */

      if (RTE_E_AI_CodingDiag_E_NOK == tRetVal)
      {
          tRetVal = RTE_E_OK;
      }
      else if (RTE_E_AI_CodingDiag_E_PENDING == tRetVal)
      {
        tRetVal = RTE_E_AI_CodingDiag_E_PENDING;
      }
      else
      {
        tRetVal = RTE_E_OK;
        /* writing done */
        VirginFlagWritingDone = TRUE;
      }
    }
    else
    {
        /* writing done */
        VirginFlagWritingDone = TRUE;
    }
  #endif

  FvirginFlag = Coding_Appl_Read_parameter_FBL_DiagSecH_FVirginFlag();  /*read coding block*/ 
    /* Update Coding block*/
    if ((FvirginFlagWritingDone == FALSE)/*&& (VirginFlagWritingDone == TRUE)*/&& (FvirginFlag != FNORMAL ))
    {
      Data[0] = FNORMAL;
      tRetVal = Coding_DiagWriteData(0xF063, (t_Coding_DestPtr*) Data , 1U);      
      if (RTE_E_AI_CodingDiag_E_NOK == tRetVal)
      {
          tRetVal = RTE_E_OK;
      }
      else if (RTE_E_AI_CodingDiag_E_PENDING == tRetVal)
      {
        tRetVal = RTE_E_AI_CodingDiag_E_PENDING;
      }
      else
      {
        tRetVal = RTE_E_OK;      
        FvirginFlagWritingDone = TRUE;
      }
    }
  #endif

  /* Writing of VIRGIN Flag via UDS service $2E F0 62 */
  if (UDS_WriteVirginflag > 0U)
  {
    UDS_WriteVirginflag--;
    if (UDS_WriteVirginflag == 0U){
      UDS_VirginFlagWritingRequest = TRUE;
    }    
  }
  else if (UDS_VirginFlagWritingRequest == TRUE)
  {
    Rte_Read_ApplDiag_PR_SaSrv_VirginFlag_VirginFlag(&virginFlag);
    SaSrv_VirginMode_NvMBlock.VirginFlag = virginFlag;
      
    Data[0] = virginFlag;
    /* TODO */
      /* update coding block */
      Coding_Diag_Write_parameter_FBL_DiagSecH_VirginFlag(virginFlag);
    // if (RTE_E_AI_CodingDiag_E_NOK == tRetVal)
    // {
    //     tRetVal = RTE_E_OK;
    // }
    // else if (RTE_E_AI_CodingDiag_E_PENDING == tRetVal)
    // {
    //   tRetVal = RTE_E_AI_CodingDiag_E_PENDING;
    // }
    // else
    // {
    //   tRetVal = RTE_E_OK;
    //   /* clear write flag */
    //   UDS_VirginFlagWritingRequest = FALSE;
    // }     
    UDS_VirginFlagWritingRequest = FALSE;
  } 
  else
  {
  /* nothing */
  }
  // virginFlag1 = Coding_Appl_Read_parameter_FBL_DiagSecH_VirginFlag(); /*read coding block*/ 
  // Rte_Write_PR_SaSrv_VirginFlag_VirginFlag(virginFlag1);
  /*ABCD*/
  /*######## Synchronization of security access Asymtric counter  ########*/
  if ((mg_AsymCounterSynchRequest == TRUE)||(mg_FailedAttempCntSynchRequest == TRUE))
  {
    Rte_Read_ApplDiag_PR_SaSrv_AsymCounterInterface_AsymCounter(AsymCounter);
    Rte_Read_ApplDiag_PR_SaSrv_PUN_PUN(PUN);
    Rte_Read_ApplDiag_PR_SaSrv_FailedAttemptCounterInterface_FailedAttemptCounter(&AttempCounter);
    uint8 index;
    memcpy(Coding_FBL_DataBlock1.Coding_appldiag_FBL_DiagSecH_Counter, AsymCounter, 32u);
    memcpy(Coding_FBL_DataBlock1.Coding_appldiag_PUN, PUN, 32u);
    if (mg_SaSrvSeedSynhDelay_Flag == TRUE)
    { /* the seed shall not initlized with (SaSrvSecretSeed as 0) at init time 
    only valid seed from security access invocation shall written*/
      memcpy(Coding_FBL_DataBlock1.Coding_appldiag_FBL_DiagSecH_SecretSeed, SaSrvSecretSeed, 85u);
    }
    Coding_FBL_DataBlock1.Coding_appldiag_FBL_SecAccessInvalidCount= AttempCounter;
        /* TODO */
      
      //tRetVal = Coding_DiagWriteData(0x7401, (t_Coding_DestPtr*) AsymCounter , 32u);  /* update coding block */
      for (u8_index = 0; u8_index < 32; ++u8_index) {
    	  Coding_Diag_Write_parameter_FBL_DiagSecH_Counter( u8_index,AsymCounter[u8_index]);
      } 
      // if (RTE_E_AI_CodingDiag_E_NOK == tRetVal)
      // {
      //     tRetVal = RTE_E_OK;
      // }
      // else if (RTE_E_AI_CodingDiag_E_PENDING == tRetVal)
      // {
      //   tRetVal = RTE_E_AI_CodingDiag_E_PENDING;
      // }
      // else
      // {
      //   tRetVal = RTE_E_OK;
      //   /* clear write flag */
      //   mg_AsymCounterSynchRequest = FALSE;
      //   mg_FailedAttempCntSynchRequest = FALSE;
      //   mg_PUNSynchRequest = FALSE;
      //   mg_SaSrvSeedSynhDelay_Flag = TRUE;
      // }     
        mg_AsymCounterSynchRequest = FALSE;
        mg_FailedAttempCntSynchRequest = FALSE;
        mg_PUNSynchRequest = FALSE;
        mg_SaSrvSeedSynhDelay_Flag = TRUE;
  }
  else
  {
  /* nothing */
  }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ApplDiag_S_Dcm_DistanceTotalizer_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <S_Dcm_DistanceTotalizer_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType ApplDiag_S_Dcm_DistanceTotalizer_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_DistanceTotalizer_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_DistanceTotalizer_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ApplDiag_S_Dcm_DistanceTotalizer_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) ApplDiag_S_Dcm_DistanceTotalizer_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ApplDiag_S_Dcm_DistanceTotalizer_Read_ReadData (returns application error)
 *********************************************************************************************************************/

  Data[0] = APPLDIAG_tDistanceTotalizer >> 24;
  Data[1] = APPLDIAG_tDistanceTotalizer >> 16;
  Data[2] = APPLDIAG_tDistanceTotalizer >> 8;
  Data[3] = APPLDIAG_tDistanceTotalizer;

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_Adc_Iout_CalibData_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_Adc_Iout_CalibData_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_Adc_Iout_CalibData_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_Adc_Iout_CalibData_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_Adc_Iout_CalibData_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Adc_Iout_CalibData_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) DataServices_Data_Adc_Iout_CalibData_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Adc_Iout_CalibData_Read_ReadData (returns application error)
 *********************************************************************************************************************/
 Data[0] = (uint8)(Coding_Diag_Read_parameter_ADC_u16OutCurrentGain()    >> 8);
Data[1] = (uint8)(Coding_Diag_Read_parameter_ADC_u16OutCurrentGain()        );
 Data[2] = (uint8)(Coding_Diag_Read_parameter_ADC_s16OutCurrentOffset()  >> 8);
Data[3] = (uint8)(Coding_Diag_Read_parameter_ADC_s16OutCurrentOffset()      );

  //uint8 temp;
  //temp=Coding_Appl_Read_parameter_Practice();
  //Data[0]=temp;
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_Adc_Iout_CalibData_Read_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_Data_Adc_Iout_CalibData_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_Adc_Iout_CalibData_Read_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_Adc_Iout_CalibData_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_Adc_Iout_CalibData_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Adc_Iout_CalibData_Read_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) DataServices_Data_Adc_Iout_CalibData_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Adc_Iout_CalibData_Read_WriteData (returns application error)
 *********************************************************************************************************************/
 uint16 loc_u16Gain   = (((uint16)Data[0] << 8) | (uint16)Data[1]);
  sint16 loc_s16Offset = (sint16)(((uint16)Data[2] << 8) | (uint16)Data[3]);

  Coding_Diag_Write_parameter_ADC_u16OutCurrentGain( loc_u16Gain );
  Coding_Diag_Write_parameter_ADC_s16OutCurrentOffset(loc_s16Offset);


  //uint8 temp;
  //temp=Data[0];
  //Coding_Diag_Write_parameter_Practice( temp );

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_Adc_Ireso_Calib_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_Adc_Ireso_Calib_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_Adc_Ireso_Calib_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_Adc_Ireso_Calib_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_Adc_Ireso_Calib_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Adc_Ireso_Calib_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) DataServices_Data_Adc_Ireso_Calib_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Adc_Ireso_Calib_Read_ReadData (returns application error)
 *********************************************************************************************************************/

  Data[0] = (uint8)(Coding_Diag_Read_parameter_ADC_u16ResoCurrentGain()    >> 8);
  Data[1] = (uint8)(Coding_Diag_Read_parameter_ADC_u16ResoCurrentGain()        );
  Data[2] = (uint8)(Coding_Diag_Read_parameter_ADC_s16ResoCurrentOffset()  >> 8);
  Data[3] = (uint8)(Coding_Diag_Read_parameter_ADC_s16ResoCurrentOffset()      );

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_Adc_Ireso_Calib_Read_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_Data_Adc_Ireso_Calib_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_Adc_Ireso_Calib_Read_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_Adc_Ireso_Calib_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_Adc_Ireso_Calib_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Adc_Ireso_Calib_Read_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) DataServices_Data_Adc_Ireso_Calib_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Adc_Ireso_Calib_Read_WriteData (returns application error)
 *********************************************************************************************************************/
  uint16 loc_u16Gain   = (((uint16)Data[0] << 8) | (uint16)Data[1]);
  sint16 loc_s16Offset = (sint16)(((uint16)Data[2] << 8) | (uint16)Data[3]);

  ECUEXT_GlobalIsrDisable();
  Coding_Diag_Write_parameter_ADC_u16ResoCurrentGain( loc_u16Gain );
  Coding_Diag_Write_parameter_ADC_s16ResoCurrentOffset(loc_s16Offset);
  ECUEXT_GlobalIsrEnable();

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_Adc_Uout2_CalibData_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_Adc_Uout2_CalibData_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_Adc_Uout2_CalibData_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_Adc_Uout2_CalibData_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_Adc_Uout2_CalibData_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Adc_Uout2_CalibData_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) DataServices_Data_Adc_Uout2_CalibData_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Adc_Uout2_CalibData_Read_ReadData (returns application error)
 *********************************************************************************************************************/
  Data[0] = (uint8)(Coding_Diag_Read_parameter_ADC_u16OutVolt2Gain()    >> 8);
  Data[1] = (uint8)(Coding_Diag_Read_parameter_ADC_u16OutVolt2Gain()        );
  Data[2] = (uint8)(Coding_Diag_Read_parameter_ADC_s16OutVolt2Offset()  >> 8);
  Data[3] = (uint8)(Coding_Diag_Read_parameter_ADC_s16OutVolt2Offset()      );
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_Adc_Uout2_CalibData_Read_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_Data_Adc_Uout2_CalibData_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_Adc_Uout2_CalibData_Read_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_Adc_Uout2_CalibData_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_Adc_Uout2_CalibData_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Adc_Uout2_CalibData_Read_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) DataServices_Data_Adc_Uout2_CalibData_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Adc_Uout2_CalibData_Read_WriteData (returns application error)
 *********************************************************************************************************************/
  uint16 loc_u16Gain   = (((uint16)Data[0] << 8) | (uint16)Data[1]);
  sint16 loc_s16Offset = (sint16)(((uint16)Data[2] << 8) | (uint16)Data[3]);

  ECUEXT_GlobalIsrDisable();
  Coding_Diag_Write_parameter_ADC_u16OutVolt2Gain( loc_u16Gain );
  Coding_Diag_Write_parameter_ADC_s16OutVolt2Offset(loc_s16Offset);
  ECUEXT_GlobalIsrEnable();

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_Adc_Uout_Calib_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_Adc_Uout_Calib_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_Adc_Uout_Calib_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_Adc_Uout_Calib_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_Adc_Uout_Calib_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Adc_Uout_Calib_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) DataServices_Data_Adc_Uout_Calib_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Adc_Uout_Calib_Read_ReadData (returns application error)
 *********************************************************************************************************************/

  Data[0] = (uint8)(Coding_Diag_Read_parameter_ADC_u16OutVoltGain()    >> 8);
  Data[1] = (uint8)(Coding_Diag_Read_parameter_ADC_u16OutVoltGain()        );
  Data[2] = (uint8)(Coding_Diag_Read_parameter_ADC_s16OutVoltOffset()  >> 8);
  Data[3] = (uint8)(Coding_Diag_Read_parameter_ADC_s16OutVoltOffset()      );

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_Adc_Uout_Calib_Read_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_Data_Adc_Uout_Calib_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_Adc_Uout_Calib_Read_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_Adc_Uout_Calib_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_Adc_Uout_Calib_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Adc_Uout_Calib_Read_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) DataServices_Data_Adc_Uout_Calib_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Adc_Uout_Calib_Read_WriteData (returns application error)
 *********************************************************************************************************************/
  uint16 loc_u16Gain   = (((uint16)Data[0] << 8) | (uint16)Data[1]);
  sint16 loc_s16Offset = (sint16)(((uint16)Data[2] << 8) | (uint16)Data[3]);

  ECUEXT_GlobalIsrDisable();
  Coding_Diag_Write_parameter_ADC_u16OutVoltGain( loc_u16Gain );
  Coding_Diag_Write_parameter_ADC_s16OutVoltOffset(loc_s16Offset);
  ECUEXT_GlobalIsrEnable();

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_Hvdc_Iin_CalibData2_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_Hvdc_Iin_CalibData2_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_Hvdc_Iin_CalibData2_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_Hvdc_Iin_CalibData2_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_Hvdc_Iin_CalibData2_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Hvdc_Iin_CalibData2_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) DataServices_Data_Hvdc_Iin_CalibData2_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Hvdc_Iin_CalibData2_Read_ReadData (returns application error)
 *********************************************************************************************************************/
  Data[0] = (uint8)(Coding_Diag_Read_parameter_Hvdc_u16InCurrentGain2()    >> 8);
  Data[1] = (uint8)(Coding_Diag_Read_parameter_Hvdc_u16InCurrentGain2()        );
  Data[2] = (uint8)(Coding_Diag_Read_parameter_Hvdc_s16InCurrentOffset2()  >> 8);
  Data[3] = (uint8)(Coding_Diag_Read_parameter_Hvdc_s16InCurrentOffset2()      );

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_Hvdc_Iin_CalibData2_Read_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_Data_Hvdc_Iin_CalibData2_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_Hvdc_Iin_CalibData2_Read_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_Hvdc_Iin_CalibData2_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_Hvdc_Iin_CalibData2_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Hvdc_Iin_CalibData2_Read_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) DataServices_Data_Hvdc_Iin_CalibData2_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Hvdc_Iin_CalibData2_Read_WriteData (returns application error)
 *********************************************************************************************************************/
  uint16 loc_u16Gain   = (((uint16)Data[0] << 8) | (uint16)Data[1]);
  sint16 loc_s16Offset = (sint16)(((uint16)Data[2] << 8) | (uint16)Data[3]);
  uint8  loc_u8HwVersion;

  /* BDV4 Default Gain 2031, Offset -64 -> BDV4 Default Gain 2031*1,2, Offset -64**1,2 */

  Rte_Read_R_HwInfos_u8HwVersion(&loc_u8HwVersion);
  Coding_Diag_Write_parameter_Hvdc_u16InCurrentGain2( loc_u16Gain );
  Coding_Diag_Write_parameter_Hvdc_s16InCurrentOffset2(loc_s16Offset);

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_Hvdc_Iin_CalibData3_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Hvdc_Iin_CalibData3_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, ApplDiag_CODE) DataServices_Data_Hvdc_Iin_CalibData3_Read_ReadData(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Hvdc_Iin_CalibData3_Read_ReadData
 *********************************************************************************************************************/
  Data[0] = (uint8)(Coding_Diag_Read_parameter_Hvdc_u16InCurrentGain3()    >> 8);
  Data[1] = (uint8)(Coding_Diag_Read_parameter_Hvdc_u16InCurrentGain3()        );
  Data[2] = (uint8)(Coding_Diag_Read_parameter_Hvdc_s16InCurrentOffset3()  >> 8);
  Data[3] = (uint8)(Coding_Diag_Read_parameter_Hvdc_s16InCurrentOffset3()      );
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_Hvdc_Iin_CalibData3_Read_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Hvdc_Iin_CalibData3_Read_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, ApplDiag_CODE) DataServices_Data_Hvdc_Iin_CalibData3_Read_WriteData(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Hvdc_Iin_CalibData3_Read_WriteData
 *********************************************************************************************************************/
  uint16 loc_u16Gain   = (((uint16)Data[0] << 8) | (uint16)Data[1]);
  sint16 loc_s16Offset = (sint16)(((uint16)Data[2] << 8) | (uint16)Data[3]);
  uint8  loc_u8HwVersion;

  /* BDV4 Default Gain 2031, Offset -64 -> BDV4 Default Gain 2031*1,2, Offset -64**1,2 */
  Rte_Read_R_HwInfos_u8HwVersion(&loc_u8HwVersion);
  Coding_Diag_Write_parameter_Hvdc_u16InCurrentGain3( loc_u16Gain );
  Coding_Diag_Write_parameter_Hvdc_s16InCurrentOffset3(loc_s16Offset);

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_Hvdc_Iin_CalibData_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_Hvdc_Iin_CalibData_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_Hvdc_Iin_CalibData_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_Hvdc_Iin_CalibData_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_Hvdc_Iin_CalibData_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Hvdc_Iin_CalibData_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) DataServices_Data_Hvdc_Iin_CalibData_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Hvdc_Iin_CalibData_Read_ReadData (returns application error)
 *********************************************************************************************************************/
  Data[0] = (uint8)(Coding_Diag_Read_parameter_Hvdc_u16InCurrentGain()    >> 8);
  Data[1] = (uint8)(Coding_Diag_Read_parameter_Hvdc_u16InCurrentGain()        );
  Data[2] = (uint8)(Coding_Diag_Read_parameter_Hvdc_s16InCurrentOffset()  >> 8);
  Data[3] = (uint8)(Coding_Diag_Read_parameter_Hvdc_s16InCurrentOffset()      );

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_Hvdc_Iin_CalibData_Read_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_Data_Hvdc_Iin_CalibData_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_Hvdc_Iin_CalibData_Read_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_Hvdc_Iin_CalibData_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_Hvdc_Iin_CalibData_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Hvdc_Iin_CalibData_Read_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) DataServices_Data_Hvdc_Iin_CalibData_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Hvdc_Iin_CalibData_Read_WriteData (returns application error)
 *********************************************************************************************************************/
  uint16 loc_u16Gain   = (((uint16)Data[0] << 8) | (uint16)Data[1]);
  sint16 loc_s16Offset = (sint16)(((uint16)Data[2] << 8) | (uint16)Data[3]);
  uint8  loc_u8HwVersion;

  Rte_Read_R_HwInfos_u8HwVersion(&loc_u8HwVersion);

  Coding_Diag_Write_parameter_Hvdc_u16InCurrentGain( loc_u16Gain );
  Coding_Diag_Write_parameter_Hvdc_s16InCurrentOffset(loc_s16Offset);

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_Hvdc_Ubulk_CalibData_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_Hvdc_Ubulk_CalibData_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_Hvdc_Ubulk_CalibData_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_Hvdc_Ubulk_CalibData_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_Hvdc_Ubulk_CalibData_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Hvdc_Ubulk_CalibData_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) DataServices_Data_Hvdc_Ubulk_CalibData_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Hvdc_Ubulk_CalibData_Read_ReadData (returns application error)
 *********************************************************************************************************************/
  Data[0] = (uint8)(Coding_Diag_Read_parameter_Hvdc_u16BulkVoltGain()    >> 8);
  Data[1] = (uint8)(Coding_Diag_Read_parameter_Hvdc_u16BulkVoltGain()        );
  Data[2] = (uint8)(Coding_Diag_Read_parameter_Hvdc_s16BulkVoltOffset()  >> 8);
  Data[3] = (uint8)(Coding_Diag_Read_parameter_Hvdc_s16BulkVoltOffset()      );

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_Hvdc_Ubulk_CalibData_Read_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_Data_Hvdc_Ubulk_CalibData_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_Hvdc_Ubulk_CalibData_Read_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_Hvdc_Ubulk_CalibData_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_Hvdc_Ubulk_CalibData_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Hvdc_Ubulk_CalibData_Read_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) DataServices_Data_Hvdc_Ubulk_CalibData_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Hvdc_Ubulk_CalibData_Read_WriteData (returns application error)
 *********************************************************************************************************************/
  uint16 loc_u16Gain   = (((uint16)Data[0] << 8) | (uint16)Data[1]);
  sint16 loc_s16Offset = (sint16)(((uint16)Data[2] << 8) | (uint16)Data[3]);

  Coding_Diag_Write_parameter_Hvdc_u16BulkVoltGain( loc_u16Gain );
  Coding_Diag_Write_parameter_Hvdc_s16BulkVoltOffset(loc_s16Offset);

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_Hvdc_Uin_CalibData2_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_Hvdc_Uin_CalibData2_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_Hvdc_Uin_CalibData2_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_Hvdc_Uin_CalibData2_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_Hvdc_Uin_CalibData2_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Hvdc_Uin_CalibData2_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) DataServices_Data_Hvdc_Uin_CalibData2_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Hvdc_Uin_CalibData2_Read_ReadData (returns application error)
 *********************************************************************************************************************/
  Data[0] = (uint8)(Coding_Diag_Read_parameter_Hvdc_u16InVoltGain2()    >> 8);
  Data[1] = (uint8)(Coding_Diag_Read_parameter_Hvdc_u16InVoltGain2()        );
  Data[2] = (uint8)(Coding_Diag_Read_parameter_Hvdc_s16InVoltOffset2()  >> 8);
  Data[3] = (uint8)(Coding_Diag_Read_parameter_Hvdc_s16InVoltOffset2()      );
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_Hvdc_Uin_CalibData2_Read_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_Data_Hvdc_Uin_CalibData2_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_Hvdc_Uin_CalibData2_Read_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_Hvdc_Uin_CalibData2_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_Hvdc_Uin_CalibData2_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Hvdc_Uin_CalibData2_Read_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) DataServices_Data_Hvdc_Uin_CalibData2_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Hvdc_Uin_CalibData2_Read_WriteData (returns application error)
 *********************************************************************************************************************/
  uint16 loc_u16Gain   = (((uint16)Data[0] << 8) | (uint16)Data[1]);
  sint16 loc_s16Offset = (sint16)(((uint16)Data[2] << 8) | (uint16)Data[3]);

  Coding_Diag_Write_parameter_Hvdc_u16InVoltGain2( loc_u16Gain );
  Coding_Diag_Write_parameter_Hvdc_s16InVoltOffset2(loc_s16Offset);
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_Hvdc_Uin_CalibData3_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_Hvdc_Uin_CalibData3_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_Hvdc_Uin_CalibData3_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_Hvdc_Uin_CalibData3_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_Hvdc_Uin_CalibData3_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Hvdc_Uin_CalibData3_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) DataServices_Data_Hvdc_Uin_CalibData3_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Hvdc_Uin_CalibData3_Read_ReadData (returns application error)
 *********************************************************************************************************************/
  Data[0] = (uint8)(Coding_Diag_Read_parameter_Hvdc_u16InVoltGain3()    >> 8);
  Data[1] = (uint8)(Coding_Diag_Read_parameter_Hvdc_u16InVoltGain3()        );
  Data[2] = (uint8)(Coding_Diag_Read_parameter_Hvdc_s16InVoltOffset3()  >> 8);
  Data[3] = (uint8)(Coding_Diag_Read_parameter_Hvdc_s16InVoltOffset3()      );
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_Hvdc_Uin_CalibData3_Read_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_Data_Hvdc_Uin_CalibData3_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_Hvdc_Uin_CalibData3_Read_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_Hvdc_Uin_CalibData3_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_Hvdc_Uin_CalibData3_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Hvdc_Uin_CalibData3_Read_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) DataServices_Data_Hvdc_Uin_CalibData3_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Hvdc_Uin_CalibData3_Read_WriteData (returns application error)
 *********************************************************************************************************************/
  uint16 loc_u16Gain   = (((uint16)Data[0] << 8) | (uint16)Data[1]);
  sint16 loc_s16Offset = (sint16)(((uint16)Data[2] << 8) | (uint16)Data[3]);

  Coding_Diag_Write_parameter_Hvdc_u16InVoltGain3( loc_u16Gain );
  Coding_Diag_Write_parameter_Hvdc_s16InVoltOffset3(loc_s16Offset);
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_Hvdc_Uin_CalibData_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_Hvdc_Uin_CalibData_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_Hvdc_Uin_CalibData_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_Hvdc_Uin_CalibData_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_Hvdc_Uin_CalibData_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Hvdc_Uin_CalibData_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) DataServices_Data_Hvdc_Uin_CalibData_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Hvdc_Uin_CalibData_Read_ReadData (returns application error)
 *********************************************************************************************************************/

  Data[0] = (uint8)(Coding_Diag_Read_parameter_Hvdc_u16InVoltGain()    >> 8);
  Data[1] = (uint8)(Coding_Diag_Read_parameter_Hvdc_u16InVoltGain()        );
  Data[2] = (uint8)(Coding_Diag_Read_parameter_Hvdc_s16InVoltOffset()  >> 8);
  Data[3] = (uint8)(Coding_Diag_Read_parameter_Hvdc_s16InVoltOffset()      );

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_Hvdc_Uin_CalibData_Read_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_Data_Hvdc_Uin_CalibData_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_Hvdc_Uin_CalibData_Read_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_Hvdc_Uin_CalibData_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_Hvdc_Uin_CalibData_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Hvdc_Uin_CalibData_Read_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ApplDiag_CODE) DataServices_Data_Hvdc_Uin_CalibData_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_APPLDIAG_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPLDIAG_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_Hvdc_Uin_CalibData_Read_WriteData (returns application error)
 *********************************************************************************************************************/
  uint16 loc_u16Gain   = (((uint16)Data[0] << 8) | (uint16)Data[1]);
  sint16 loc_s16Offset = (sint16)(((uint16)Data[2] << 8) | (uint16)Data[3]);

  Coding_Diag_Write_parameter_Hvdc_u16InVoltGain( loc_u16Gain );
  Coding_Diag_Write_parameter_Hvdc_s16InVoltOffset(loc_s16Offset);

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ResetService_EcuReset
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_R_EcuReq_AwakeRequest(DT_Active *data)
 *   Std_ReturnType Rte_Read_R_HSK_Request_Status_OnOff(DT_OnOff *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_P_EcuReset_EcuResetReq(boolean data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ResetService_EcuReset_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, ApplDiag_CODE) ResetService_EcuReset(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ResetService_EcuReset
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define ApplDiag_STOP_SEC_CODE
#include "ApplDiag_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/




#if 0
/***  Start of saved code (symbol: documentation area:SecurityAccess_Level_1_1_GetSeed_doc)  ****************/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:SecurityAccess_Level_1_1_GetSeed)  ***************/
#if(0)  /* DEWILSS -> Old SecAccess implementation -> Deprecated */
  uint8 i;
  uint8 secretSeed[30];
  uint32 pun[2];
  uint16 tmpSize = 4093;
  uint8 secretAesKey[16];

  /* create secret seed */
  /* 1. get PUN */
  /* PUN Reading */
  memcpy((uint8*)&pun[0],&(Coding_FBL_DataBlock1.Coding_appldiag_PUN),kEepSizePUN);
  pun[0]++;
  if (pun[0] == 0u)
  {
    pun[1]++;
  }
  memcpy(&(Coding_FBL_DataBlock1.Coding_appldiag_PUN),(uint8*)&pun[0],kEepSizePUN);

  secretSeed[0] = (uint8)(pun[0] >> 24u);
  secretSeed[1] = (uint8)(pun[0] >> 16u);
  secretSeed[2] = (uint8)(pun[0] >>  8u);
  secretSeed[3] = (uint8)(pun[0]);
  secretSeed[4] = (uint8)(pun[1] >> 24u);
  secretSeed[5] = (uint8)(pun[1] >> 16u);
  secretSeed[6] = (uint8)(pun[1] >>  8u);
  secretSeed[7] = (uint8)(pun[1]);
  /* 2. Security Level */
  secretSeed[8] = 0x01u;
  /* 3. Session Number */
  secretSeed[9] = 0x02u;
  /* 4. Secured Server Data */
  for (i = 0; i < kEepSizeDID_F18C; i++)
  {
    secretSeed[10 + i] = id_F18C[i];
  }

  /* Copy aeskey into RAM buffer */
  for (i = 0u; i < 0x10u; i++)
  {
    secretAesKey[i] = aesKey[i];
  }

  /* 5. Calculate Security Seed */
  if (ApplFblEncryptSecuritySeed(secretSeed, sizeof(secretSeed), Seed, &tmpSize, (const uint8 *) &secretAesKey) != kFblOk )
  {
    /*  DiagNRCConditionsNotCorrect();*/
    return kFblFailed;
  }
  /* 6. Compute and memorize session key */
  if (ApplFblCalculateHash((SecM_AddrType) &secretSeed[0], sizeof(secretSeed), sessionKey, sizeof(sessionKey), FblReadRam) != SECM_OK )
  {
    /* DiagNRCConditionsNotCorrect();*/
    return kFblFailed;
  }

  /* DID + Subparam + 32 seed bytes */
  DiagDataLength = tmpSize + 1u;

  return RTE_E_OK;

#else
  return RTE_E_OK;
#endif
/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:SecurityAccess_Level_1_1_CompareKey_doc)  *************/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:SecurityAccess_Level_1_1_CompareKey)  ************/
#if(0)  /* DEWILSS -> Old SecAccess implementation -> Deprecated */
 uint8 secretKey[0x20];
  uint32 pun[2], receivedPun[2];
  uint16 length = sizeof(secretKey);

  /* 1. Compute SecretKey */
  if (ApplFblDecryptSecurityKey(Key, (DiagDataLength-1), secretKey, &length, (const uint8 *) sessionKey) != kFblOk)
  {
    return RTE_E_SecurityAccess_Level_1_1_DCM_E_COMPARE_KEY_FAILED;
  }

  memcpy((uint8*)&pun[0],&(Coding_FBL_DataBlock1.Coding_appldiag_PUN),kEepSizePUN);

  receivedPun[0] = (((uint32)secretKey[0]) << 24u) | (((uint32)secretKey[1]) << 16u) | (((uint32)secretKey[2]) << 8u) | ((vuint32)secretKey[3]);
  receivedPun[1] = (((uint32)secretKey[4]) << 24u) | (((uint32)secretKey[5]) << 16u) | (((uint32)secretKey[6]) << 8u) | ((vuint32)secretKey[7]);

  /* 2. Check PUN */
  if ((pun[0] == receivedPun[0]) && (pun[1] == receivedPun[1]))
  {
    /* 3. Store Fingerprint */
    memcpy(&(Coding_FBL_DataBlock1.Coding_appldiag_DID_F010),&secretKey[8],kEepSizeDID_F010);
    return RTE_E_OK;
  }

  return RTE_E_SecurityAccess_Level_1_1_DCM_E_COMPARE_KEY_FAILED;
#else
  return RTE_E_OK;
#endif

/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: runnable implementation:APPLDIAG_S_Dcm_SystemSupplierIdentifier_Read_WriteData)  */
 *ErrorCode = APPLDIAG_NRC_31;
  return RTE_E_INVALID;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:APPLDIAG_S_Dcm_SystemSupplierIdentifier_Read_WriteData_doc)  */


/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: runnable implementation:S_Dcm_DataServices_Data_CodingWrite_ReadData)  ***/
// uint8 temp;
 //temp = Coding_Appl_Read_parameter_Practice();
 //Data[0] = temp;
 Data[0]=0x12;

  return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:S_Dcm_DataServices_Data_CodingWrite_ConditionCheckRead)  */

  return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:S_Dcm_DataServices_Data_CodingWrite_WriteData)  **/
 uint8 temp;
 temp = Data[0];
 Coding_Diag_Write_parameter_Practice(temp);

  return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:S_Dcm_DataServices_Data_CodingWrite_ReadData_doc)  ****/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:S_Dcm_DataServices_Data_CodingWrite_ConditionCheckRead_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:S_Dcm_DataServices_Data_CodingWrite_WriteData_doc)  ***/


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
