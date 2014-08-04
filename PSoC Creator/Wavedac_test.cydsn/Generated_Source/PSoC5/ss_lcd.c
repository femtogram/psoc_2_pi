/*******************************************************************************
* File Name: ss_lcd.c  
* Version 2.0
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "ss_lcd.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 ss_lcd__PORT == 15 && ((ss_lcd__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: ss_lcd_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None
*  
*******************************************************************************/
void ss_lcd_Write(uint8 value) 
{
    uint8 staticBits = (ss_lcd_DR & (uint8)(~ss_lcd_MASK));
    ss_lcd_DR = staticBits | ((uint8)(value << ss_lcd_SHIFT) & ss_lcd_MASK);
}


/*******************************************************************************
* Function Name: ss_lcd_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  ss_lcd_DM_STRONG     Strong Drive 
*  ss_lcd_DM_OD_HI      Open Drain, Drives High 
*  ss_lcd_DM_OD_LO      Open Drain, Drives Low 
*  ss_lcd_DM_RES_UP     Resistive Pull Up 
*  ss_lcd_DM_RES_DWN    Resistive Pull Down 
*  ss_lcd_DM_RES_UPDWN  Resistive Pull Up/Down 
*  ss_lcd_DM_DIG_HIZ    High Impedance Digital 
*  ss_lcd_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void ss_lcd_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(ss_lcd_0, mode);
}


/*******************************************************************************
* Function Name: ss_lcd_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro ss_lcd_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 ss_lcd_Read(void) 
{
    return (ss_lcd_PS & ss_lcd_MASK) >> ss_lcd_SHIFT;
}


/*******************************************************************************
* Function Name: ss_lcd_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 ss_lcd_ReadDataReg(void) 
{
    return (ss_lcd_DR & ss_lcd_MASK) >> ss_lcd_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(ss_lcd_INTSTAT) 

    /*******************************************************************************
    * Function Name: ss_lcd_ClearInterrupt
    ********************************************************************************
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 ss_lcd_ClearInterrupt(void) 
    {
        return (ss_lcd_INTSTAT & ss_lcd_MASK) >> ss_lcd_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
