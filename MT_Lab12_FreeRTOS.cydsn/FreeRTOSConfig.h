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

#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#include "project.h"

#define configUSE_PREEMPTION                 1
#define configUSE_TIME_SLICING               1
#define configUSE_TICKLESS_IDLE              0

#define configCPU_CLOCK_HZ                   (67000000UL)
#define configTICK_RATE_HZ                   ((TickType_t)1000)

#define configMAX_PRIORITIES                 5
#define configMINIMAL_STACK_SIZE            128
#define configMAX_TASK_NAME_LEN             16

#define configTOTAL_HEAP_SIZE               (16 * 1024)
#define configSUPPORT_DYNAMIC_ALLOCATION    1
#define configSUPPORT_STATIC_ALLOCATION     0

#define configUSE_16_BIT_TICKS               0
#define configIDLE_SHOULD_YIELD             1

#define configUSE_MUTEXES                    1
#define configUSE_RECURSIVE_MUTEXES          1
#define configUSE_COUNTING_SEMAPHORES        1

#define configUSE_TIMERS                     1
#define configTIMER_TASK_PRIORITY            2
#define configTIMER_QUEUE_LENGTH             8
#define configTIMER_TASK_STACK_DEPTH         256

#define configUSE_IDLE_HOOK                  0
#define configUSE_TICK_HOOK                  0
#define configCHECK_FOR_STACK_OVERFLOW       2
#define configUSE_MALLOC_FAILED_HOOK         1

#define configUSE_TRACE_FACILITY             0
#define configGENERATE_RUN_TIME_STATS        0

/* Confirm __NVIC_PRIO_BITS from device headers. */
#define configPRIO_BITS                      3

#define configLIBRARY_LOWEST_INTERRUPT_PRIORITY 7
#define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY 5

#define configKERNEL_INTERRUPT_PRIORITY \
    (configLIBRARY_LOWEST_INTERRUPT_PRIORITY << (8 - configPRIO_BITS))

#define configMAX_SYSCALL_INTERRUPT_PRIORITY \
    (configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << (8 - configPRIO_BITS))

#define configASSERT(x) \
    if ((x) == 0) { taskDISABLE_INTERRUPTS(); for (;;) {} }

#define INCLUDE_vTaskDelay                   1
#define INCLUDE_vTaskDelayUntil              1
#define INCLUDE_vTaskDelete                  1
#define INCLUDE_vTaskSuspend                 1
#define INCLUDE_uxTaskGetStackHighWaterMark  1
#define INCLUDE_xTaskGetSchedulerState       1

#endif

/* [] END OF FILE */
