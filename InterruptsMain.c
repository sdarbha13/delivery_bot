///*
// * InterruptsMain.c
// */
//#include "Bump.h"
//#include "Clock.h"
//#include "UART0.h"
//#include "LaunchPad.h"
//#include <stdint.h>
//
//void Hello_World_Example(void){
//    Clock_Init();
//    Bump_Init();
//    UART0_Init();
//    while(1){
//        UART0_OutString("Hello Wolrd /n/r");
//        Clock_Delay1ms(1000);
//    }
//}
//
//void Interrupts_Warm_Up(void){
//    Clock_Init();
//    Bump_Init();
//    UART0_Init();
//    while(1){
//        //Write code to print which bump sensors are pressed using UART
//        UART0_OutUDec(Bump_Read());
//        //Wait a second before polling again
//        Clock_Delay1ms(1000);
//    }
//}
//
////void toggleLedFor2Seconds(uint8_t bumpSensors){
////    LaunchPad_LED(1);
////    Clock_Delay1ms(2000);
////    LaunchPad_LED(0);
////}
//
//void Interrupts_Race_Day(void){
//    Clock_Init();
//    Bump_Interrupt_Init(&toggleLedFor2Seconds);
//    LaunchPad_Init();
//    while(1){
//    }
//}
//
////int main(void){
////    //Un-commment only the function you are useing
////    //Hello_World_Example();
////    //Interrupts_Warm_Up();
////    Interrupts_Race_Day();
////}
