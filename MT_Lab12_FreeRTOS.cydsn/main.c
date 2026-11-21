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
#include "FreeRTOS.h"
#include "task.h"

#include "FreeRTOS_PSoC.h"

#include <stdio.h>

static void vLedTask(void *pvParameters);
static void prvFatalError(void);

/* UART access is owned by the UART task in this demo. */

int main(void)
{
    BaseType_t result;
    CyGlobalIntEnable;

    /* Install FreeRTOS exception handlers. */
    FreeRTOS_Init();
    /* Initialize PSoC peripherals. */
    UART_Start();
    /* LED starts OFF (active-low onboard LED). */
    Pin_LED_Write(1u);
    /* Create LED task. */
    result = xTaskCreate(vLedTask, "LED", 256, NULL,  2, NULL);

    if (result != pdPASS)
        prvFatalError();
    /* Start multitasking. */
    vTaskStartScheduler();
    /* Scheduler should not return. */
    prvFatalError();
    return 0;
}

static void vLedTask(void *pvParameters)
{
    TickType_t lastWakeTime;
    uint8 ledState = 1u;

    (void)pvParameters;

    lastWakeTime = xTaskGetTickCount();

    for (;;)
    {
        ledState ^= 1u;
        Pin_LED_Write(ledState);

        vTaskDelayUntil(
            &lastWakeTime,
            pdMS_TO_TICKS(500)
        );
    }
}

static void prvFatalError(void)
{
    taskDISABLE_INTERRUPTS();

    for (;;)
    {
        /* Set a debugger breakpoint here. */
    }
}

void vApplicationMallocFailedHook(void)
{
    prvFatalError();
}

void vApplicationStackOverflowHook(
    TaskHandle_t xTask,
    char *pcTaskName)
{
    (void)xTask;
    (void)pcTaskName;

    prvFatalError();
}


/* [] END OF FILE */
