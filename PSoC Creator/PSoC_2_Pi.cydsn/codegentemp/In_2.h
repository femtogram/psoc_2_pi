/*******************************************************************************
* File Name: In_2.h  
* Version 2.0
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_In_2_H) /* Pins In_2_H */
#define CY_PINS_In_2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "In_2_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_0 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 In_2__PORT == 15 && ((In_2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    In_2_Write(uint8 value) ;
void    In_2_SetDriveMode(uint8 mode) ;
uint8   In_2_ReadDataReg(void) ;
uint8   In_2_Read(void) ;
uint8   In_2_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define In_2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define In_2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define In_2_DM_RES_UP          PIN_DM_RES_UP
#define In_2_DM_RES_DWN         PIN_DM_RES_DWN
#define In_2_DM_OD_LO           PIN_DM_OD_LO
#define In_2_DM_OD_HI           PIN_DM_OD_HI
#define In_2_DM_STRONG          PIN_DM_STRONG
#define In_2_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define In_2_MASK               In_2__MASK
#define In_2_SHIFT              In_2__SHIFT
#define In_2_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define In_2_PS                     (* (reg8 *) In_2__PS)
/* Data Register */
#define In_2_DR                     (* (reg8 *) In_2__DR)
/* Port Number */
#define In_2_PRT_NUM                (* (reg8 *) In_2__PRT) 
/* Connect to Analog Globals */                                                  
#define In_2_AG                     (* (reg8 *) In_2__AG)                       
/* Analog MUX bux enable */
#define In_2_AMUX                   (* (reg8 *) In_2__AMUX) 
/* Bidirectional Enable */                                                        
#define In_2_BIE                    (* (reg8 *) In_2__BIE)
/* Bit-mask for Aliased Register Access */
#define In_2_BIT_MASK               (* (reg8 *) In_2__BIT_MASK)
/* Bypass Enable */
#define In_2_BYP                    (* (reg8 *) In_2__BYP)
/* Port wide control signals */                                                   
#define In_2_CTL                    (* (reg8 *) In_2__CTL)
/* Drive Modes */
#define In_2_DM0                    (* (reg8 *) In_2__DM0) 
#define In_2_DM1                    (* (reg8 *) In_2__DM1)
#define In_2_DM2                    (* (reg8 *) In_2__DM2) 
/* Input Buffer Disable Override */
#define In_2_INP_DIS                (* (reg8 *) In_2__INP_DIS)
/* LCD Common or Segment Drive */
#define In_2_LCD_COM_SEG            (* (reg8 *) In_2__LCD_COM_SEG)
/* Enable Segment LCD */
#define In_2_LCD_EN                 (* (reg8 *) In_2__LCD_EN)
/* Slew Rate Control */
#define In_2_SLW                    (* (reg8 *) In_2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define In_2_PRTDSI__CAPS_SEL       (* (reg8 *) In_2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define In_2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) In_2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define In_2_PRTDSI__OE_SEL0        (* (reg8 *) In_2__PRTDSI__OE_SEL0) 
#define In_2_PRTDSI__OE_SEL1        (* (reg8 *) In_2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define In_2_PRTDSI__OUT_SEL0       (* (reg8 *) In_2__PRTDSI__OUT_SEL0) 
#define In_2_PRTDSI__OUT_SEL1       (* (reg8 *) In_2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define In_2_PRTDSI__SYNC_OUT       (* (reg8 *) In_2__PRTDSI__SYNC_OUT) 


#if defined(In_2__INTSTAT)  /* Interrupt Registers */

    #define In_2_INTSTAT                (* (reg8 *) In_2__INTSTAT)
    #define In_2_SNAP                   (* (reg8 *) In_2__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_In_2_H */


/* [] END OF FILE */
