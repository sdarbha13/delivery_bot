/* DriverLib Includes */
#include "driverlib.h"

/* Standard Includes */
#include <stdint.h>
#include "PWM.h"

/* Timer_A Left PWM Configuration Parameter */
Timer_A_PWMConfig pwmLeftConfig =
{
    TIMER_A_CLOCKSOURCE_SMCLK,
    TIMER_A_CLOCKSOURCE_DIVIDER_1,
    32000,
    TIMER_A_CAPTURECOMPARE_REGISTER_3,
    TIMER_A_OUTPUTMODE_RESET_SET,
    3200
};

/* Timer_A Right PWM Configuration Parameter */
Timer_A_PWMConfig pwmRightConfig =
{
    TIMER_A_CLOCKSOURCE_SMCLK,
    TIMER_A_CLOCKSOURCE_DIVIDER_1,
    32000,
    TIMER_A_CAPTURECOMPARE_REGISTER_4,
    TIMER_A_OUTPUTMODE_RESET_SET,
    3200
};

void PWM_Init(uint16_t period, uint16_t duty3, uint16_t duty4) {
    // Stop watchdog timer
        WDT_A_holdTimer();

     //Modify the period value in the configuration
     pwmLeftConfig.timerPeriod = period;
     pwmRightConfig.timerPeriod = period;

    //Generate PWM signals
    Timer_A_generatePWM(TIMER_A0_BASE, &pwmLeftConfig);
    Timer_A_generatePWM(TIMER_A0_BASE, &pwmRightConfig);

    //Set Duty Cycle
    PWM_Duty_Left(duty3);
    PWM_Duty_Right(duty4);

    // Configuring GPIO2.6 as peripheral output for PWM
    GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P2, GPIO_PIN6,
    GPIO_PRIMARY_MODULE_FUNCTION);

    // Configuring GPIO2.7 as peripheral output for PWM
    GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P2, GPIO_PIN7,
    GPIO_PRIMARY_MODULE_FUNCTION);

    Interrupt_enableInterrupt(INT_TA0_N);
    Interrupt_enableMaster();

}

// converts Duty cycle from 0-100 to a CCR value
uint16_t Duty_To_CCR2(uint16_t duty) {
    return (((duty)*32000)/100);
}

// Sets the duty cycle of the Left PWM signal according to the argument
void PWM_Duty_Left(uint16_t duty4) {
    // Convert Duty Cycle into the appropriate CCR Value
    uint16_t CCR_Value = Duty_To_CCR2(duty4);

    // Initialize the timer with the modified configuration
    Timer_A_setCompareValue(TIMER_A0_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_3, CCR_Value);
}

// Sets the duty cycle of the Right PWM signal according to the argument
void PWM_Duty_Right(uint16_t duty1) {
    // Convert Duty Cycle into the appropriate CCR Value
    uint16_t CCR_Value = Duty_To_CCR2(duty1);

    // Initialize the timer with the modified configuration
    Timer_A_setCompareValue(TIMER_A0_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_4, CCR_Value);
}
