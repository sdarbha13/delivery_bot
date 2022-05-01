#include "driverlib.h"
#include "PWM.h"
#include "Motor.h"
#include "gpio.h"

//   Left Motor:                Right Motor:
//    - Direction: P5.4         - Direction: P5.5
//    - PWM:       P2.7         - PWM        P2.6
//    - Enable:    P3.7         - Enable     P3.6

// initialize PWM outputs to 0% duty cycle on the two motor PWM pins (P2.6 and P2.7)
// initialize motor enable and direction pins as GPIO outputs
// set motors to sleep mode
// set motor direction to forward initially
void Motor_Init(void){

    PWM_Duty_Left(0);
    PWM_Duty_Right(0);

    //Set Directions as Output Pin
    GPIO_setAsOutputPin(GPIO_PORT_P5, GPIO_PIN4 | GPIO_PIN5);
    //Set Enable as Output Pin
    GPIO_setAsOutputPin(GPIO_PORT_P3, GPIO_PIN6 | GPIO_PIN7);
    //Direction Pins
    GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN4); //Left
    GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN5); //Right
    //Enable Pins
    GPIO_setOutputLowOnPin(GPIO_PORT_P3, GPIO_PIN7); //Left
    GPIO_setOutputLowOnPin(GPIO_PORT_P3, GPIO_PIN6); //Right

}


// Drive both motors forwards at the given duty cycles
void Motor_Forward(uint16_t leftDuty, uint16_t rightDuty){
    //PWM Change based on Duty
    PWM_Duty_Left(leftDuty);
    PWM_Duty_Right(rightDuty);
    //Direction Pins
    GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN4); //Left
    GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN5); //Right
    //Enable Pins
    GPIO_setOutputHighOnPin(GPIO_PORT_P3, GPIO_PIN7); //Left
    GPIO_setOutputHighOnPin(GPIO_PORT_P3, GPIO_PIN6); //Right
}


// Drive both motors backwards at the given duty cycles
void Motor_Backward(uint16_t leftDuty, uint16_t rightDuty){
    //PWM Change based on Duty
    PWM_Duty_Left(leftDuty);
    PWM_Duty_Right(rightDuty);
    //Direction Pins
    GPIO_setOutputHighOnPin(GPIO_PORT_P5, GPIO_PIN4); //Left
    GPIO_setOutputHighOnPin(GPIO_PORT_P5, GPIO_PIN5); //Right
    //Enable Pins
    GPIO_setOutputHighOnPin(GPIO_PORT_P3, GPIO_PIN7); //Left
    GPIO_setOutputHighOnPin(GPIO_PORT_P3, GPIO_PIN6); //Right
}


// Drive the right motor forwards and the left motor backwards at the given duty cycles
void Motor_Left(uint16_t leftDuty, uint16_t rightDuty){
    //PWM Change based on Duty
    PWM_Duty_Left(leftDuty);
    PWM_Duty_Right(rightDuty);
    //Direction Pins
    GPIO_setOutputHighOnPin(GPIO_PORT_P5, GPIO_PIN4); //Left
    GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN5); //Right
    //Enable Pins
    GPIO_setOutputHighOnPin(GPIO_PORT_P3, GPIO_PIN7); //Left
    GPIO_setOutputHighOnPin(GPIO_PORT_P3, GPIO_PIN6); //Right
}


// Drive the right motor backwards and the left motor forwards at the given duty cycles
void Motor_Right(uint16_t leftDuty, uint16_t rightDuty){
    //PWM Change based on Duty
    PWM_Duty_Left(leftDuty);
    PWM_Duty_Right(rightDuty);
    //Direction Pins
    GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN4); //Left
    GPIO_setOutputHighOnPin(GPIO_PORT_P5, GPIO_PIN5); //Right
    //Enable Pins
    GPIO_setOutputHighOnPin(GPIO_PORT_P3, GPIO_PIN7); //Left
    GPIO_setOutputHighOnPin(GPIO_PORT_P3, GPIO_PIN6); //Right
}


// Stop the motors and enter sleep mode
void Motor_Stop(void){
    //Enable Pins
    GPIO_setOutputLowOnPin(GPIO_PORT_P3, GPIO_PIN7); //Left
    GPIO_setOutputLowOnPin(GPIO_PORT_P3, GPIO_PIN6); //Right
}
