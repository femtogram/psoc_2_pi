/*******************************************************************************
* File Name: Out_5.c  
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
#include "Out_5.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 Out_5__PORT == 15 && ((Out_5__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: Out_5_Write
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
void Out_5_Write(uint8 value) 
{
    uint8 staticBits = (Out_5_DR & (uint8)(~Out_5_MASK));
    Out_5_DR = staticBits | ((uint8)(value << Out_5_SHIFT) & Out_5_MASK);
}


/*******************************************************************************
* Function Name: Out_5_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Out_5_DM_STRONG     Strong Drive 
*  Out_5_DM_OD_HI      Open Drain, Drives High 
*  Out_5_DM_OD_LO      Open Drain, Drives Low 
*  Out_5_DM_RES_UP     Resistive Pull Up 
*  Out_5_DM_RES_DWN    Resistive Pull Down 
*  Out_5_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Out_5_DM_DIG_HIZ    High Impedance Digital 
*  Out_5_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Out_5_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Out_5_0, mode);
}


/*******************************************************************************
* Function Name: Out_5_Read
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
*  Macro Out_5_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Out_5_Read(void) 
{
    return (Out_5_PS & Out_5_MASK) >> Out_5_SHIFT;
}


/*******************************************************************************
* Function Name: Out_5_ReadDataReg
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
uint8 Out_5_ReadDataReg(void) 
{
    return (Out_5_DR & Out_5_MASK) >> Out_5_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Out_5_INTSTAT) 

    /*******************************************************************************
    * Function Name: Out_5_ClearInterrupt
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
    uint8 Out_5_ClearInterrupt(void) 
    {
        return (Out_5_INTSTAT & Out_5_MASK) >> Out_5_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
