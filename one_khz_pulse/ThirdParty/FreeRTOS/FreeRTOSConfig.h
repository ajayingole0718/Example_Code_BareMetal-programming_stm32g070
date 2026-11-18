/*
 * FreeRTOS V202212.00
 * Configuration for STM32G070RBT6
 * Cortex-M0+
 */

#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/*-----------------------------------------------------------
 * Hardware configuration
 *----------------------------------------------------------*/

extern uint32_t SystemCoreClock;

#define configCPU_CLOCK_HZ                         ( SystemCoreClock )
#define configTICK_RATE_HZ                         ( 1000 )

/*
 * Cortex-M0/M0+ does not support the optimized
 * task-selection mechanism used by some other ports.
 */
#define configUSE_PORT_OPTIMISED_TASK_SELECTION    0

/*-----------------------------------------------------------
 * Scheduler configuration
 *----------------------------------------------------------*/

#define configUSE_PREEMPTION                       1
#define configMAX_PRIORITIES                       5
#define configMINIMAL_STACK_SIZE                   128
#define configMAX_TASK_NAME_LEN                    16

#define configUSE_16_BIT_TICKS                     0
#define configIDLE_SHOULD_YIELD                    1
#define configUSE_TIME_SLICING                     1

/*-----------------------------------------------------------
 * Memory allocation
 *----------------------------------------------------------*/

/* CHANGED TO 0: Disables complex manual static allocation structures */
#define configSUPPORT_STATIC_ALLOCATION             0
#define configSUPPORT_DYNAMIC_ALLOCATION            1

/*
 * STM32G070RBT6 has limited RAM.
 * Start with 8 KB FreeRTOS heap.
 * Increase if your application requires it.
 */
#define configTOTAL_HEAP_SIZE                      ( 10 * 1024 )

/*-----------------------------------------------------------
 * Synchronization
 *----------------------------------------------------------*/

#define configUSE_MUTEXES                           1
#define configUSE_RECURSIVE_MUTEXES                1
#define configUSE_COUNTING_SEMAPHORES               1

#define configUSE_QUEUE_SETS                        0
#define configQUEUE_REGISTRY_SIZE                   5

/*-----------------------------------------------------------
 * Software timers
 *----------------------------------------------------------*/

#define configUSE_TIMERS                            1
#define configTIMER_TASK_PRIORITY                   2
#define configTIMER_QUEUE_LENGTH                    5
#define configTIMER_TASK_STACK_DEPTH                128

/*-----------------------------------------------------------
 * Hooks
 *----------------------------------------------------------*/

#define configUSE_IDLE_HOOK                         0
#define configUSE_TICK_HOOK                         0

#define configCHECK_FOR_STACK_OVERFLOW              0
#define configUSE_MALLOC_FAILED_HOOK                0

/*-----------------------------------------------------------
 * Run-time statistics
 *----------------------------------------------------------*/

/*
 * Disable initially.
 * Enable later when you actually configure a hardware timer
 * for run-time statistics.
 */
#define configGENERATE_RUN_TIME_STATS               0

/*-----------------------------------------------------------
 * Co-routines
 *----------------------------------------------------------*/

#define configUSE_CO_ROUTINES                       0
#define configMAX_CO_ROUTINE_PRIORITIES             2

/*-----------------------------------------------------------
 * Thread local storage
 *----------------------------------------------------------*/

#define configNUM_THREAD_LOCAL_STORAGE_POINTERS     0

/*-----------------------------------------------------------
 * Trace
 *----------------------------------------------------------*/

#define configUSE_TRACE_FACILITY                    0

/*-----------------------------------------------------------
 * API functions
 *----------------------------------------------------------*/

#define INCLUDE_vTaskPrioritySet                    1
#define INCLUDE_uxTaskPriorityGet                   1

#define INCLUDE_vTaskDelete                         1
#define INCLUDE_vTaskCleanUpResources               0

#define INCLUDE_vTaskSuspend                        1
#define INCLUDE_vTaskDelayUntil                     1
#define INCLUDE_vTaskDelay                          1

#define INCLUDE_eTaskGetState                       1

#define INCLUDE_xTimerPendFunctionCall              0

#define INCLUDE_xSemaphoreGetMutexHolder            1

#define INCLUDE_xTaskGetHandle                      1
#define INCLUDE_xTaskGetCurrentTaskHandle            1
#define INCLUDE_xTaskGetIdleTaskHandle               1

#define INCLUDE_xTaskAbortDelay                     1
#define INCLUDE_xTaskGetSchedulerState              1

#define INCLUDE_uxTaskGetStackHighWaterMark         1

/*-----------------------------------------------------------
 * Cortex-M interrupt configuration
 *----------------------------------------------------------*/

/*
 * STM32G070 Cortex-M0+ implements 2 priority bits.
 */
#ifdef __NVIC_PRIO_BITS
    #define configPRIO_BITS                         __NVIC_PRIO_BITS
#else
    #define configPRIO_BITS                         2
#endif

/*
 * Lowest interrupt priority.
 *
 * With 2 implemented bits:
 *
 * 0 = highest
 * 1
 * 2
 * 3 = lowest
 */
#define configLIBRARY_LOWEST_INTERRUPT_PRIORITY     3

/*
 * Highest interrupt priority from which
 * FreeRTOS FromISR() APIs may be called.
 *
 * Interrupt priorities 2 and 3 are safe for
 * FreeRTOS API calls.
 */
#define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY 2

#define configKERNEL_INTERRUPT_PRIORITY \
    ( configLIBRARY_LOWEST_INTERRUPT_PRIORITY << \
      ( 8 - configPRIO_BITS ) )

#define configMAX_SYSCALL_INTERRUPT_PRIORITY \
    ( configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << \
      ( 8 - configPRIO_BITS ) )

/*-----------------------------------------------------------
 * CMSIS interrupt handlers
 *----------------------------------------------------------*/

#define xPortPendSVHandler                          PendSV_Handler
#define vPortSVCHandler                             SVC_Handler
#define xPortSysTickHandler                         SysTick_Handler

/*-----------------------------------------------------------
 * Assert
 *----------------------------------------------------------*/

#define configASSERT( x )                                      \
    if( ( x ) == 0 )                                           \
    {                                                          \
        taskDISABLE_INTERRUPTS();                              \
        for( ;; );                                              \
    }

/*-----------------------------------------------------------
 * MPU
 *----------------------------------------------------------*/

/*
 * STM32G070 Cortex-M0+ does not have the MPU required by
 * the MPU FreeRTOS configuration you originally copied.
 *
 * Therefore these MPU options are disabled/not required.
 */
#define configUSE_MPU_WRAPPERS_V1                    0

/*-----------------------------------------------------------
 * Other configuration
 *----------------------------------------------------------*/

#define configUSE_APPLICATION_TASK_TAG               0
#define configUSE_TICKLESS_IDLE                      0
#define configUSE_STATS_FORMATTING_FUNCTIONS         0

#define configENFORCE_SYSTEM_CALLS_FROM_KERNEL_ONLY  0
#define configALLOW_UNPRIVILEGED_CRITICAL_SECTIONS   0

#ifdef __cplusplus
}
#endif

#endif /* FREERTOS_CONFIG_H */
