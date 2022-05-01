///* DriverLib Includes */
//#include "driverlib.h"
//
///* Standard Includes */
//#include <stdint.h>
//#include <stdbool.h>
//#include "LaunchPad.h"
//#include "gpio.h"
//#include "Clock.h"
//
///* Project Includes */
//#include "TimerA1.h"
//#include "Reflectance.h"
//#include "Bump.h"
//#include "FSM.h"
//#include "PortPins.h"
//#include "LED.h"
//#include "PushButton.h"
//#include "Motor.h"
//#include "PWM.h"
//#include "Nokia5110.h"
//
//int counter = 0; //counter for timer based interrupts
//uint8_t lineData; //global variable for the reflectance sensor
//uint8_t bumpData; //global variable for the bump sensors
//uint8_t lineRaw; //variable for debug
//
//FSMType LINE_FSM;
//
//
//void task(){ //interrupt based on time updates sensor values
//
//    counter++; //an interrupt has occurred
//    if (counter==1){
//        Reflectance_Start();
//    }
//    if (counter==2){
//        lineData=Reflectance_Center(Reflectance_End()); //line sensor data
//        //lineRaw=Reflectance_Center(Reflectance_Read(1000));
//    }
//    if (counter==3){
//        bumpData=Bump_Read(); //bump sensor data
//    }
//    if (counter==10){
//        counter=0; //reset loop
//    }
//}
//
//int main(void)
//{
//    SwitchDefine PushButtonS1;
//
//    // Init
//    Clock_Init();
//    LaunchPad_Init();
//    Reflectance_Init();
//    Nokia5110_Init();
//    Bump_Init();
//    uint16_t period = 500; //set period for timer
//
//    //Initialize necessary hardware
//    InitializeLEDPortPin();
//    InitializePushButtonPortPins();
//
//    //Initialize push buttons S1 to active low,
//    //Logic 0  <->  Active   (Switch pressed)
//    //Logic 1  <->  Inactive (Switch released)
//    InitializeSwitch(&PushButtonS1, (uint8_t *) &(PUSHBUTTON_S1_PORT->IN),
//                             (uint8_t) PUSHBUTTON_S1_BIT, Active, Inactive);
//
//    //Initialize Motors
//    PWM_Init(32000,0,0);
//    Motor_Init();
//
//
//    //Initialize Finite State Machine (FSM) state variables
//    InitializeFSM(&LINE_FSM);
//
//    // Main loop
//    TimerA1_Init(&task,period); //passes task and period to init function for interrupt based on time
//    while(ReadSwitchStatus(&PushButtonS1)!=1){
//    }
//    while(1){
//        //Read current input
//        LINE_FSM.CurrentInputLine = lineData;
//        LINE_FSM.CurrentInputBump = bumpData;
//
//        //Using input value and current state, determine next state
//        LINE_FSM.CurrentState = NextStateFunction(&LINE_FSM);
//
//        //Produce outputs based on current state
//        OutputFunction(&LINE_FSM);
//
//        Nokia5110_Clear();
//        Nokia5110_SetCursor(0, 1);
//    }
//}
