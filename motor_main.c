///* DriverLib Includes */
//#include "driverlib.h"
//
///* Standard Includes */
//#include <stdint.h>
//
///* Project Includes */
//#include "Motor.h"
//#include "PWM.h"
//#include "Clock.h"
//#include "Launchpad.h"
//
//uint8_t data;
//void main (void) {
//
//
//    // Call Appropriate Initializations
//    Clock_Init();
//    LaunchPad_Init();
//    PWM_Init(32000,0,0);
//    Motor_Init();
//
//    while(1){
//        Motor_Forward(70,70);
//        Clock_Delay1ms(2000);
//        Motor_Backward(70,70);
//        Clock_Delay1ms(2000);
//        Motor_Left(70,70);
//        Clock_Delay1ms(2000);
//        Motor_Right(70,70);
//        Clock_Delay1ms(2000);
//        Motor_Stop();
//        Clock_Delay1ms(2000);
//    }
//}
//
