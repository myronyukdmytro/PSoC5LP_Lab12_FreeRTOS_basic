/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#include "project.h"
#include "FreeRTOS_PSoC.h"

extern void vPortSVCHandler(void);
extern void xPortPendSVHandler(void);
extern void xPortSysTickHandler(void);

void FreeRTOS_Init(void)
{
    CyIntSetSysVector(
        CY_INT_SVCALL_IRQN,
        (cyisraddress)vPortSVCHandler);

    CyIntSetSysVector(
        CY_INT_PEND_SV_IRQN,
        (cyisraddress)xPortPendSVHandler);

    CyIntSetSysVector(
        CY_INT_SYSTICK_IRQN,
        (cyisraddress)xPortSysTickHandler);
}

/* [] END OF FILE */
