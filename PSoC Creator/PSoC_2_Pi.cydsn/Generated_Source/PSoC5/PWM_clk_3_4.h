/*******************************************************************************
* File Name: PWM_clk_3_4.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_PWM_clk_3_4_H)
#define CY_CLOCK_PWM_clk_3_4_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_20 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void PWM_clk_3_4_Start(void) ;
void PWM_clk_3_4_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void PWM_clk_3_4_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void PWM_clk_3_4_StandbyPower(uint8 state) ;
void PWM_clk_3_4_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 PWM_clk_3_4_GetDividerRegister(void) ;
void PWM_clk_3_4_SetModeRegister(uint8 modeBitMask) ;
void PWM_clk_3_4_ClearModeRegister(uint8 modeBitMask) ;
uint8 PWM_clk_3_4_GetModeRegister(void) ;
void PWM_clk_3_4_SetSourceRegister(uint8 clkSource) ;
uint8 PWM_clk_3_4_GetSourceRegister(void) ;
#if defined(PWM_clk_3_4__CFG3)
void PWM_clk_3_4_SetPhaseRegister(uint8 clkPhase) ;
uint8 PWM_clk_3_4_GetPhaseRegister(void) ;
#endif /* defined(PWM_clk_3_4__CFG3) */

#define PWM_clk_3_4_Enable()                       PWM_clk_3_4_Start()
#define PWM_clk_3_4_Disable()                      PWM_clk_3_4_Stop()
#define PWM_clk_3_4_SetDivider(clkDivider)         PWM_clk_3_4_SetDividerRegister(clkDivider, 1u)
#define PWM_clk_3_4_SetDividerValue(clkDivider)    PWM_clk_3_4_SetDividerRegister((clkDivider) - 1u, 1u)
#define PWM_clk_3_4_SetMode(clkMode)               PWM_clk_3_4_SetModeRegister(clkMode)
#define PWM_clk_3_4_SetSource(clkSource)           PWM_clk_3_4_SetSourceRegister(clkSource)
#if defined(PWM_clk_3_4__CFG3)
#define PWM_clk_3_4_SetPhase(clkPhase)             PWM_clk_3_4_SetPhaseRegister(clkPhase)
#define PWM_clk_3_4_SetPhaseValue(clkPhase)        PWM_clk_3_4_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(PWM_clk_3_4__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define PWM_clk_3_4_CLKEN              (* (reg8 *) PWM_clk_3_4__PM_ACT_CFG)
#define PWM_clk_3_4_CLKEN_PTR          ((reg8 *) PWM_clk_3_4__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define PWM_clk_3_4_CLKSTBY            (* (reg8 *) PWM_clk_3_4__PM_STBY_CFG)
#define PWM_clk_3_4_CLKSTBY_PTR        ((reg8 *) PWM_clk_3_4__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define PWM_clk_3_4_DIV_LSB            (* (reg8 *) PWM_clk_3_4__CFG0)
#define PWM_clk_3_4_DIV_LSB_PTR        ((reg8 *) PWM_clk_3_4__CFG0)
#define PWM_clk_3_4_DIV_PTR            ((reg16 *) PWM_clk_3_4__CFG0)

/* Clock MSB divider configuration register. */
#define PWM_clk_3_4_DIV_MSB            (* (reg8 *) PWM_clk_3_4__CFG1)
#define PWM_clk_3_4_DIV_MSB_PTR        ((reg8 *) PWM_clk_3_4__CFG1)

/* Mode and source configuration register */
#define PWM_clk_3_4_MOD_SRC            (* (reg8 *) PWM_clk_3_4__CFG2)
#define PWM_clk_3_4_MOD_SRC_PTR        ((reg8 *) PWM_clk_3_4__CFG2)

#if defined(PWM_clk_3_4__CFG3)
/* Analog clock phase configuration register */
#define PWM_clk_3_4_PHASE              (* (reg8 *) PWM_clk_3_4__CFG3)
#define PWM_clk_3_4_PHASE_PTR          ((reg8 *) PWM_clk_3_4__CFG3)
#endif /* defined(PWM_clk_3_4__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define PWM_clk_3_4_CLKEN_MASK         PWM_clk_3_4__PM_ACT_MSK
#define PWM_clk_3_4_CLKSTBY_MASK       PWM_clk_3_4__PM_STBY_MSK

/* CFG2 field masks */
#define PWM_clk_3_4_SRC_SEL_MSK        PWM_clk_3_4__CFG2_SRC_SEL_MASK
#define PWM_clk_3_4_MODE_MASK          (~(PWM_clk_3_4_SRC_SEL_MSK))

#if defined(PWM_clk_3_4__CFG3)
/* CFG3 phase mask */
#define PWM_clk_3_4_PHASE_MASK         PWM_clk_3_4__CFG3_PHASE_DLY_MASK
#endif /* defined(PWM_clk_3_4__CFG3) */

#endif /* CY_CLOCK_PWM_clk_3_4_H */


/* [] END OF FILE */
