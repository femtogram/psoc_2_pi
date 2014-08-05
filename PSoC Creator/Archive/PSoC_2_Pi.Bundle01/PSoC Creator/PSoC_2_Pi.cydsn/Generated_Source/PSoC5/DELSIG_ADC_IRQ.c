/*******************************************************************************
* File Name: DELSIG_ADC_IRQ.c  
* Version 1.70
*
*  Description:
*   API for controlling the state of an interrupt.
*
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/


#include <cydevice_trm.h>
#include <CyLib.h>
#include <DELSIG_ADC_IRQ.h>

#if !defined(DELSIG_ADC_IRQ__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START DELSIG_ADC_IRQ_intc` */

/* `#END` */

#ifndef CYINT_IRQ_BASE
#define CYINT_IRQ_BASE      16
#endif /* CYINT_IRQ_BASE */
#ifndef CYINT_VECT_TABLE
#define CYINT_VECT_TABLE    ((cyisraddress **) CYREG_NVIC_VECT_OFFSET)
#endif /* CYINT_VECT_TABLE */

/* Declared in startup, used to set unused interrupts to. */
CY_ISR_PROTO(IntDefaultHandler);


/*******************************************************************************
* Function Name: DELSIG_ADC_IRQ_Start
********************************************************************************
*
* Summary:
*  Set up the interrupt and enable it.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
void DELSIG_ADC_IRQ_Start(void)
{
    /* For all we know the interrupt is active. */
    DELSIG_ADC_IRQ_Disable();

    /* Set the ISR to point to the DELSIG_ADC_IRQ Interrupt. */
    DELSIG_ADC_IRQ_SetVector(&DELSIG_ADC_IRQ_Interrupt);

    /* Set the priority. */
    DELSIG_ADC_IRQ_SetPriority((uint8)DELSIG_ADC_IRQ_INTC_PRIOR_NUMBER);

    /* Enable it. */
    DELSIG_ADC_IRQ_Enable();
}


/*******************************************************************************
* Function Name: DELSIG_ADC_IRQ_StartEx
********************************************************************************
*
* Summary:
*  Set up the interrupt and enable it.
*
* Parameters:  
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void DELSIG_ADC_IRQ_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    DELSIG_ADC_IRQ_Disable();

    /* Set the ISR to point to the DELSIG_ADC_IRQ Interrupt. */
    DELSIG_ADC_IRQ_SetVector(address);

    /* Set the priority. */
    DELSIG_ADC_IRQ_SetPriority((uint8)DELSIG_ADC_IRQ_INTC_PRIOR_NUMBER);

    /* Enable it. */
    DELSIG_ADC_IRQ_Enable();
}


/*******************************************************************************
* Function Name: DELSIG_ADC_IRQ_Stop
********************************************************************************
*
* Summary:
*   Disables and removes the interrupt.
*
* Parameters:  
*
* Return:
*   None
*
*******************************************************************************/
void DELSIG_ADC_IRQ_Stop(void)
{
    /* Disable this interrupt. */
    DELSIG_ADC_IRQ_Disable();

    /* Set the ISR to point to the passive one. */
    DELSIG_ADC_IRQ_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: DELSIG_ADC_IRQ_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for DELSIG_ADC_IRQ.
*
*   Add custom code between the coments to keep the next version of this file
*   from over writting your code.
*
* Parameters:  
*
* Return:
*   None
*
*******************************************************************************/
CY_ISR(DELSIG_ADC_IRQ_Interrupt)
{
    /*  Place your Interrupt code here. */
    /* `#START DELSIG_ADC_IRQ_Interrupt` */

    /* `#END` */
}


/*******************************************************************************
* Function Name: DELSIG_ADC_IRQ_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling DELSIG_ADC_IRQ_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use DELSIG_ADC_IRQ_StartEx instead.
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void DELSIG_ADC_IRQ_SetVector(cyisraddress address)
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    ramVectorTable[CYINT_IRQ_BASE + (uint32)DELSIG_ADC_IRQ__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: DELSIG_ADC_IRQ_GetVector
********************************************************************************
*
* Summary:
*   Gets the "address" of the current ISR vector for the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Address of the ISR in the interrupt vector table.
*
*******************************************************************************/
cyisraddress DELSIG_ADC_IRQ_GetVector(void)
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    return ramVectorTable[CYINT_IRQ_BASE + (uint32)DELSIG_ADC_IRQ__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: DELSIG_ADC_IRQ_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. Note calling DELSIG_ADC_IRQ_Start
*   or DELSIG_ADC_IRQ_StartEx will override any effect this method 
*   would have had. This method should only be called after 
*   DELSIG_ADC_IRQ_Start or DELSIG_ADC_IRQ_StartEx has been called. To set 
*   the initial priority for the component use the cydwr file in the tool.
*
* Parameters:
*   priority: Priority of the interrupt. 0 - 7, 0 being the highest.
*
* Return:
*   None
*
*******************************************************************************/
void DELSIG_ADC_IRQ_SetPriority(uint8 priority)
{
    *DELSIG_ADC_IRQ_INTC_PRIOR = priority << 5;
}


/*******************************************************************************
* Function Name: DELSIG_ADC_IRQ_GetPriority
********************************************************************************
*
* Summary:
*   Gets the Priority of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Priority of the interrupt. 0 - 7, 0 being the highest.
*
*******************************************************************************/
uint8 DELSIG_ADC_IRQ_GetPriority(void)
{
    uint8 priority;


    priority = *DELSIG_ADC_IRQ_INTC_PRIOR >> 5;

    return priority;
}


/*******************************************************************************
* Function Name: DELSIG_ADC_IRQ_Enable
********************************************************************************
*
* Summary:
*   Enables the interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void DELSIG_ADC_IRQ_Enable(void)
{
    /* Enable the general interrupt. */
    *DELSIG_ADC_IRQ_INTC_SET_EN = DELSIG_ADC_IRQ__INTC_MASK;
}


/*******************************************************************************
* Function Name: DELSIG_ADC_IRQ_GetState
********************************************************************************
*
* Summary:
*   Gets the state (enabled, disabled) of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   1 if enabled, 0 if disabled.
*
*******************************************************************************/
uint8 DELSIG_ADC_IRQ_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*DELSIG_ADC_IRQ_INTC_SET_EN & (uint32)DELSIG_ADC_IRQ__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: DELSIG_ADC_IRQ_Disable
********************************************************************************
*
* Summary:
*   Disables the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void DELSIG_ADC_IRQ_Disable(void)
{
    /* Disable the general interrupt. */
    *DELSIG_ADC_IRQ_INTC_CLR_EN = DELSIG_ADC_IRQ__INTC_MASK;
}


/*******************************************************************************
* Function Name: DELSIG_ADC_IRQ_SetPending
********************************************************************************
*
* Summary:
*   Causes the Interrupt to enter the pending state, a software method of
*   generating the interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void DELSIG_ADC_IRQ_SetPending(void)
{
    *DELSIG_ADC_IRQ_INTC_SET_PD = DELSIG_ADC_IRQ__INTC_MASK;
}


/*******************************************************************************
* Function Name: DELSIG_ADC_IRQ_ClearPending
********************************************************************************
*
* Summary:
*   Clears a pending interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void DELSIG_ADC_IRQ_ClearPending(void)
{
    *DELSIG_ADC_IRQ_INTC_CLR_PD = DELSIG_ADC_IRQ__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
