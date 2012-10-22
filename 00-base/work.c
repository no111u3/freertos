/* Standard includes. */
#include <stdlib.h>
#include <string.h>

/* includes */
#include "FreeRTOS.h"
#include "task.h"
#include "croutine.h"

/* work */
void work(void) {
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