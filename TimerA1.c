/* DriverLib Includes */
#include "driverlib.h"

/* Standard Includes */
#include <stdint.h>
#include <stdbool.h>
#include "gpio.h"

/* Project Includes */
#include "TimerA1.h"

Timer_A_UpModeConfig upConfig = {
    TIMER_A_CLOCKSOURCE_SMCLK, //Clock Source
    TIMER_A_CLOCKSOURCE_DIVIDER_24, //500 kHz
    1,
    TIMER_A_TAIE_INTERRUPT_DISABLE,
    TIMER_A_CCIE_CCR0_INTERRUPT_ENABLE,
    TIMER_A_DO_CLEAR
};

// Pointer to user function that gets called on timer interrupt
void (*timerTask)(void);

// Initializes Timer A1 in up mode and triggers a periodic interrupt at a desired frequency
void TimerA1_Init(void(*task)(void), uint16_t period){
    timerTask=task; //set pointer to task
    upConfig.timerPeriod=period; //configure the period
    Timer_A_configureUpMode(TIMER_A1_BASE, &upConfig); //Start in Up Mode
    Interrupt_enableInterrupt(INT_TA1_0); //enable overflow interrupt
    Timer_A_startCounter(TIMER_A1_BASE,TIMER_A_UP_MODE); //Start Counter
}//enable int, start counter

// stops Timer A1
void TimerA1_Stop(void){
    TIMER_A1->CTL &= ~0b0000000000110000; //write to register to stop timer
}

// ISR function for Timer A1 periodic interrupt
void TA1_0_IRQHandler(void){
    timerTask(); //does task passed in to init
    Timer_A_clearCaptureCompareInterrupt(TIMER_A1_BASE,TIMER_A_CAPTURECOMPARE_REGISTER_0); //clears flag
}
