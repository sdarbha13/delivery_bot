///* DriverLib Includes */
//#include "driverlib.h"
//
///* Standard Includes */
//#include <stdint.h>
//
///* Project Includes */
//#include "RGB_PWM.h"
//#include "RGB_Cycle.h"
//#include "Clock.h"
//#include "Launchpad.h"
//
//
//uint8_t data;
//
//int main(void)  {
//
//    // Stop watchdog timer
//    WDT_A_holdTimer();
//
//    // Call Appropriate Initializations
//    Clock_Init();
//    LaunchPad_Init();
//    LED_PWM_Init();
//    Spectrum_Init(10);
//
//    // Continuously Check SW1 and SW2 and set Duty Cycle According to their value
//    while(1){
//        data = LaunchPad_Input();
//
//        if (data == 0) {
//            Set_Spectrum_Duty(25);
//        }
//        else if (data == 1) {
//            Set_Spectrum_Duty(10);
//        }
//        else if (data == 2) {
//            Set_Spectrum_Duty(0);
//        }
//        else if (data == 3) {
//            Set_Spectrum_Duty(100);
//        }
//    }
//}
