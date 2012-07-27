/* provided by linker script */
extern unsigned long _estack;
extern void xPortPendSVHandler();
extern void xPortSysTickHandler();
extern void vPortSVCHandler();
/* extern work function */
extern void work(void);
/* reset handler */
void reset_handler(void) {
    work();
}
/* Table of Cortex vectors */
void *vector_table[] __attribute__ ((section(".vectors"))) = {
    &_estack,           /*! stack begin */
    /* Core interrupts */
    reset_handler,      /*!#0 cortex-m3 reset interrupt begin code of this */
    0,                  /*!#1 cortex-m3 non maskable interrupt */
    0,                  /*!#2 cortex-m3 hardware fault interrupt */
    0,                  /*!#3 cortex-m3 memory management interrupt */
    0,                  /*!#4 cortex-m3 bus fault interrupt */
    0,                  /*!#5 cortex-m3 usage fault interrupt */
    0,                  /*!#6 reserved */
    0,                  /*!#7 reserved */
    0,                  /*!#8 reserved */
    0,                  /*!#9 reserved */
    vPortSVCHandler,    /*!#10 cortex-m3 system service interrupt */
    0,                  /*!#11 cortex-m3 debug monitor interrupt */
    0,                  /*!#12 reserved */
    xPortPendSVHandler, /*!#13 cortex-m3 penable request for system service interrupt */
    xPortSysTickHandler,/*!#14 cortex-m3 system tick timer interrupt */
    /* External Interrupts */
    0,                  /*!%0 window watchdog interrupt */
    0,                  /*!%1 PVD through EXTI line detection interrupt */
    0,                  /*!%2 tamper adn timestamp through EXTI interrupt */
    0,                  /*!%3 RTC wakeup through EXTI interrupt */
    0,                  /*!%4 flash global interrupt */
    0,                  /*!%5 RCC global interrupt */
    0,                  /*!%6 EXTI line0 interrupt */
    0,                  /*!%7 EXTI line1 interrupt */
    0,                  /*!%8 EXTI line2 interrupt */
    0,                  /*!%9 EXTI line3 interrupt */
    0,                  /*!%10 EXTI line4 interrupt */
    0,                  /*!%11 DMA1 channel 1 global interrupt */
    0,                  /*!%12 DMA1 channel 2 global interrupt */
    0,                  /*!%13 DMA1 channel 3 global interrupt */
    0,                  /*!%14 DMA1 channel 4 global interrupt */
    0,                  /*!%15 DMA1 channel 5 global interrupt */
    0,                  /*!%16 DMA1 channel 6 global interrupt */
    0,                  /*!%17 DMA1 channel 7 global interrupt */
    0,                  /*!%18 ADC1 and ADC2 global Interrupt  */
    0,                  /*!%19 USB Device High Priority or CAN1 TX Interrupts */
    0,                  /*!%20 USB Device Low Priority or CAN1 RX0 Interrupts */
    0,                  /*!%21 CAN1 RX1 Interrupt */
    0,                  /*!%22 CAN1 SCE Interrupt */
    0,                  /*!%23 External Line[9:5] Interrupts */
    0,                  /*!%24 TIM1 Break Interrupt */
    0,                  /*!%25 TIM1 Update Interrupt */
    0,                  /*!%26 TIM1 Trigger and Commutation Interrupt */
    0,                  /*!%27 TIM1 Capture Compare Interrupt */
    0,                  /*!%28 TIM2 global Interrupt */
    0,                  /*!%29 TIM3 global Interrupt */
    0,                  /*!%30 TIM4 global Interrupt */
    0,                  /*!%31 I2C1 Event Interrupt */
    0,                  /*!%32 I2C1 Error Interrupt */
    0,                  /*!%33 I2C2 Event Interrupt */
    0,                  /*!%34 I2C2 Error Interrupt */
    0,                  /*!%35 SPI1 global Interrupt */
    0,                  /*!%36 SPI2 global Interrupt */
    0,                  /*!%37 USART1 global Interrupt */
    0,                  /*!%38 USART2 global Interrupt */
    0,                  /*!%39 USART3 global Interrupt */
    0,                  /*!%40 External Line[15:10] Interrupts */
    0,                  /*!%41 RTC Alarm through EXTI Line Interrupt */
    0,                  /*!%42 USB Device WakeUp from suspend through EXTI Line Interrupt */ 
}; 
