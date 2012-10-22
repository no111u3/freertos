/* Standard includes. */
#include <stdlib.h>
#include <string.h>

/* includes */
#include "FreeRTOS.h"
#include "stm32f10x.h"
#include "task.h"
#include "croutine.h"

#define LED_PORT GPIOB
#define LED_BLUE (1 << 1)

/* blinking led task */
void vBlinkingLed(void *pvParameters) {
    while (1) {
        /* enable led */
        LED_PORT->ODR |= LED_BLUE;
        /* delay 100 ms */
        vTaskDelay(100);
        /* disable led */
        LED_PORT->ODR &= ~LED_BLUE;
        /* delay 100 ms */
        vTaskDelay(100);
        /* enable led */
        LED_PORT->ODR |= LED_BLUE;
        /* delay 100 ms */
        vTaskDelay(100);
        /* disable led */
        LED_PORT->ODR &= ~LED_BLUE;
        /* delay 800 ms */
        vTaskDelay(700);
    }
    /* destroy task */
    vTaskDelete(NULL);
}

/* work */
void work(void) {
    /* setup i/o port */
    RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
    LED_PORT->CRL |= GPIO_CRL_MODE1_0;
    LED_PORT->CRL &= ~GPIO_CRL_CNF1;
    /* create blinking led task */
    xTaskCreate(vBlinkingLed,
                (signed char *)"BLED",
                configMINIMAL_STACK_SIZE,
                NULL,
                2,
                (xTaskHandle *)NULL);
    /* starting task cheduler */
    vTaskStartScheduler();
    /* infinity loop if failed starting */
    while (1);
}

/* stack overflow hook function */
void vApplicationStackOverflowHook( xTaskHandle pxTask, signed char *pcTaskName )
{
    /* This function will get called if a task overflows its stack.   If the
    parameters are corrupt then inspect pxCurrentTCB to find which was the
    offending task. */

    ( void ) pxTask;
    ( void ) pcTaskName;

    for( ;; );
}

/* compiler needed functions */
void assert_failed( unsigned char *pucFile, unsigned long ulLine )
{
    ( void ) pucFile;
    ( void ) ulLine;

    for( ;; );
}

unsigned _sbrk( struct _reent *r,  int incr ) {
    
    (void)r;
    (void)incr;
    
    return(0);
}