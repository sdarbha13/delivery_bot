#include "FSM.h"
#include "Clock.h"
#include "gpio.h"
#include "Motor.h"
#include "PWM.h"


//--------------------------------------------------------------------------
// Initialize FSM
//--------------------------------------------------------------------------
void InitializeFSM(FSMType *FSM)
{
    FSM->CurrentState = stop;
}

//--------------------------------------------------------------------------
// Determine next FSM state
//--------------------------------------------------------------------------
FSMState NextStateFunction(FSMType *FSM)
{
    FSMState NextState = FSM->CurrentState;

    switch (FSM->CurrentState){
    case stop: //State is entered if Bump Sensor Triggered, Light Below Threshold, Or there is Z-Acceleration beyond threshold
        if(FSM->CurrentInputBump != 0 || FSM->CurrentInputLight <10 || FSM->CurrentInputZacc > 50){ //if stop go to stop state
            NextState = stop;
        }
        else if(FSM->CurrentInputLine == 5){
            NextState = finish;
        }
        else if(FSM->CurrentInputLine == 3){
            NextState = center;
        }
        else if(FSM->CurrentInputLine == 2){
            NextState = left;
        }
        else if(FSM->CurrentInputLine == 1){
            NextState = right;
        }
        else if(FSM->CurrentInputLine == 0){
            NextState = lost;
        }
        else if(FSM->CurrentInputLine == 4){
            NextState = T;
        }
        else if(FSM->CurrentInputLine == 7){
            NextState = CurvedRight;
        }
        else if(FSM->CurrentInputLine == 6){
            NextState = CurvedLeft;
        }
        else{
            NextState = lost;
        }
        break;
    case center:
        if(FSM->CurrentInputBump != 0 || FSM->CurrentInputLight <10 || FSM->CurrentInputZacc > 50 ){
            NextState = stop;
        }
        else if(FSM->CurrentInputLine == 5){
            NextState = finish;
        }
        else if(FSM->CurrentInputLine == 3){
            NextState = center;
        }
        else if(FSM->CurrentInputLine == 2){
            NextState = left;
        }
        else if(FSM->CurrentInputLine == 1){
            NextState = right;
        }
        else if(FSM->CurrentInputLine == 0){
            NextState = lost;
        }
        else if(FSM->CurrentInputLine == 4){
            NextState = T;
        }
        else if(FSM->CurrentInputLine == 7){
            NextState = CurvedRight;
        }
        else if(FSM->CurrentInputLine == 6){
            NextState = CurvedLeft;
        }
        else{
            NextState = lost;
        }
        break;
    case left:
        if(FSM->CurrentInputBump != 0 || FSM->CurrentInputLight < 10 || FSM->CurrentInputZacc > 50 ){
            NextState = stop;
        }
        else if(FSM->CurrentInputLine == 5){
            NextState = finish;
        }
        else if(FSM->CurrentInputLine == 3){
            NextState = center;
        }
        else if(FSM->CurrentInputLine == 2){
            NextState = left;
        }
        else if(FSM->CurrentInputLine == 1){
            NextState = right;
        }
//        else if(FSM->CurrentInputLine == 0){
//            NextState = lostLeft;
//        }
        else if(FSM->CurrentInputLine == 4){
            NextState = T;
        }
        else if(FSM->CurrentInputLine == 7){
            NextState = CurvedRight;
        }
        else if(FSM->CurrentInputLine == 6){
            NextState = CurvedLeft;
        }
        else{
            NextState = lost;
        }
        break;
    case right:
        if(FSM->CurrentInputBump != 0 || FSM->CurrentInputLight < 10 || FSM->CurrentInputZacc > 50 ){
            NextState = stop;
        }
        else if(FSM->CurrentInputLine == 5){
            NextState = finish;
        }
        else if(FSM->CurrentInputLine == 3){
            NextState = center;
        }
        else if(FSM->CurrentInputLine == 2){
            NextState = left;
        }
        else if(FSM->CurrentInputLine == 1){
            NextState = right;
        }
//        else if(FSM->CurrentInputLine == 0){
//            NextState = lostRight;
//        }
        else if(FSM->CurrentInputLine == 4){
            NextState = T;
        }
        else if(FSM->CurrentInputLine == 7){
            NextState = CurvedRight;
        }
        else if(FSM->CurrentInputLine == 6){
            NextState = CurvedLeft;
        }
        else{
            NextState = lost;
        }
        break;
    case CurvedRight:
        if(FSM->CurrentInputBump != 0 || FSM->CurrentInputLight < 10 || FSM->CurrentInputZacc > 50 ){
            NextState = stop;
        }
        else if(FSM->CurrentInputLine == 5){
            NextState = finish;
        }
        else if(FSM->CurrentInputLine == 3){
            NextState = center;
        }
        else if(FSM->CurrentInputLine == 2){
            NextState = left;
        }
        else if(FSM->CurrentInputLine == 1){
            NextState = right;
        }
//        else if(FSM->CurrentInputLine == 0){
//            NextState = lostRight;
//        }
        else if(FSM->CurrentInputLine == 4){
            NextState = T;
        }
        else{
            NextState = CurvedRight;
            //NextState = lost;
        }
        break;
case CurvedLeft:
        if(FSM->CurrentInputBump != 0 || FSM->CurrentInputLight < 10 || FSM->CurrentInputZacc > 50 ){
            NextState = stop;
        }
        else if(FSM->CurrentInputLine == 5){
            NextState = finish;
        }
        else if(FSM->CurrentInputLine == 3){
            NextState = center;
        }
        else if(FSM->CurrentInputLine == 2){
            NextState = left;
        }
        else if(FSM->CurrentInputLine == 1){
            NextState = right;
        }
        else if(FSM->CurrentInputLine == 4){
            NextState = T;
        }
        else{
            NextState = CurvedLeft;
        }
        break;
case finish:
        if(FSM->CurrentInputBump != 0 || FSM->CurrentInputLight < 10 || FSM->CurrentInputZacc > 50 ){
            NextState = stop;
        }
        else if(FSM->CurrentInputLine == 5){
            NextState = finish;
        }
        else if(FSM->CurrentInputLine == 3){
            NextState = center;
        }
        else if(FSM->CurrentInputLine == 2){
            NextState = left;
        }
        else if(FSM->CurrentInputLine == 1){
            NextState = right;
        }
        else if(FSM->CurrentInputLine == 0){
            NextState = lostRight;
        }
        else if(FSM->CurrentInputLine == 4){
            NextState = T;
        }
        else if(FSM->CurrentInputLine == 7){
            NextState = CurvedRight;
        }
        else if(FSM->CurrentInputLine == 6){
            NextState = CurvedLeft;
        }
        else{
            NextState = lost;
        }
        break;
    case T:
        if(FSM->CurrentInputBump != 0 || FSM->CurrentInputLight < 10 || FSM->CurrentInputZacc > 50 ){
            NextState = stop;
        }
        else if(FSM->CurrentInputLine == 5){
            NextState = finish;
        }
        else if(FSM->CurrentInputLine == 3){
            NextState = center;
        }
        else if(FSM->CurrentInputLine == 2){
            NextState = left;
        }
        else if(FSM->CurrentInputLine == 1){
            NextState = right;
        }
//        else if(FSM->CurrentInputLine == 0){
//            NextState = lostRight;
//        }
        else if(FSM->CurrentInputLine == 4){
            NextState = T;
        }
        else if(FSM->CurrentInputLine == 7){
            NextState = CurvedRight;
        }
        else if(FSM->CurrentInputLine == 6){
            NextState = CurvedLeft;
        }
        else{
            NextState = lost;
        }
        break;
//    case lostLeft: //robot is lost and last state was to move left
//        if(FSM->CurrentInputBump != 0 || FSM->CurrentInputLight < 10 || FSM->CurrentInputZacc > 50 ){
//            NextState = stop;
//        }
//        else if(FSM->CurrentInputLine == 5){
//            NextState = finish;
//        }
//        else if(FSM->CurrentInputLine == 0){
//            NextState = lostLeft;
//        }
//        else if(FSM->CurrentInputLine == 3){
//            NextState = center;
//        }
//        else if(FSM->CurrentInputLine == 2){
//            NextState = left;
//        }
//        else if(FSM->CurrentInputLine == 1){
//            NextState = right;
//        }
//        else if(FSM->CurrentInputLine == 4){
//            NextState = T;
//        }
//        else if(FSM->CurrentInputLine == 7){
//            NextState = CurvedRight;
//        }
//        else if(FSM->CurrentInputLine == 6){
//            NextState = CurvedLeft;
//        }
//        else{
//            NextState = lost;
//        }
//        break;
//    case lostRight: //robot is lost and last state was to move right
//        if(FSM->CurrentInputBump != 0 || FSM->CurrentInputLight < 10 || FSM->CurrentInputZacc > 50 ){
//            NextState = stop;
//        }
//        else if(FSM->CurrentInputLine == 5){
//            NextState = finish;
//        }
//        else if(FSM->CurrentInputLine == 0){
//            NextState = lostRight;
//        }
//        else if(FSM->CurrentInputLine == 3){
//            NextState = center;
//        }
//        else if(FSM->CurrentInputLine == 2){
//            NextState = left;
//        }
//        else if(FSM->CurrentInputLine == 1){
//            NextState = right;
//        }
//        else if(FSM->CurrentInputLine == 4){
//            NextState = T;
//        }
//        else if(FSM->CurrentInputLine == 7){
//            NextState = CurvedRight;
//        }
//        else if(FSM->CurrentInputLine == 6){
//            NextState = CurvedLeft;
//        }
//        else{
//            NextState = lost;
//        }
//        break;
    case lost:
        if(FSM->CurrentInputBump != 0 || FSM->CurrentInputLight < 10 || FSM->CurrentInputZacc > 50 ){
            NextState = stop;
        }
        else if(FSM->CurrentInputLine == 5){
            NextState = finish;
        }
        else if(FSM->CurrentInputLine == 3){
            NextState = center;
        }
        else if(FSM->CurrentInputLine == 2){
            NextState = left;
        }
        else if(FSM->CurrentInputLine == 1){
            NextState = right;
        }
        else if(FSM->CurrentInputLine == 0){
            NextState = lost;
        }
        else if(FSM->CurrentInputLine == 4){
            NextState = T;
        }
        else if(FSM->CurrentInputLine == 7){
            NextState = CurvedRight;
        }
        else if(FSM->CurrentInputLine == 6){
            NextState = CurvedLeft;
        }
        else{
            NextState = lost;
        }
        break;
    }
    return NextState;
}

//--------------------------------------------------------------------------
// Determine LED output based on state
//--------------------------------------------------------------------------
void OutputFunction(FSMType *FSM)
{
    switch (FSM->CurrentState) {
    case center:
        if(FSM->CurrentInputLight <120){ //if light below low light threshold then go slowly
            Motor_Forward(10,10);
            Nokia5110_OutString("Slow Center");
        }else{ //else go at normal speed
            Motor_Forward(25,25);
            Nokia5110_OutString("Center :)");
        }
        TURN_ON_LED_FL;
        TURN_ON_LED_FR;
        TURN_OFF_LED_BL;
        TURN_OFF_LED_BR;
        break;
    case left:
        if(FSM->CurrentInputLight <120){
            Nokia5110_OutString("Slow Left");
            Motor_Left(15,15);
        }else{
            Nokia5110_OutString("Left");
            Motor_Left(20,20);
        }
        TURN_ON_LED_FL;
        TURN_OFF_LED_FR;
        TURN_OFF_LED_BL;
        TURN_OFF_LED_BR;
        break;
    case right:
        if(FSM->CurrentInputLight <120){
            Nokia5110_OutString("Slow Right");
            Motor_Right(15,15);
        }else{
            Nokia5110_OutString("Right");
            Motor_Right(20,20);
        }
        TURN_OFF_LED_FL;
        TURN_ON_LED_FR;
        TURN_OFF_LED_BL;
        TURN_OFF_LED_BR;
        break;
    case CurvedRight:
        Nokia5110_OutString("Curved Right");
        Motor_Forward(40,10);
//        Motor_Forward(10,10);
//        Clock_Delay1ms(15);
//        Motor_Right(20,20);
//        Clock_Delay1ms(280);
        TURN_OFF_LED_FL;
        TURN_ON_LED_FR;
        TURN_OFF_LED_BL;
        TURN_OFF_LED_BR;
        break;
    case CurvedLeft:
        Nokia5110_OutString("Curved Left");
        Motor_Forward(10,40);
//        Motor_Forward(10,10);
//        Clock_Delay1ms(15);
//        Motor_Left(20,20);
//        Clock_Delay1ms(280);
        TURN_ON_LED_FL;
        TURN_OFF_LED_FR;
        TURN_OFF_LED_BL;
        TURN_OFF_LED_BR;
        break;
    case T:
        Nokia5110_OutString("T Left");
        Motor_Right(20,20);
//        Motor_Forward(10,10);
//        Clock_Delay1ms(15);
//        Motor_Left(40,40);
//        Clock_Delay1ms(215);
        break;
//    case lostRight:
//        if(FSM->CurrentInputLight <120){
//            Nokia5110_OutString("Slow");
//            Motor_Left(10,10);
//        }else{
//            Nokia5110_OutString("Lost to the Left");
//            Motor_Left(25,25);
//        }
//        TURN_ON_LED_FL;
//        TURN_OFF_LED_FR;
//        TURN_OFF_LED_BL;
//        TURN_OFF_LED_BR;
//        break;
//    case lostLeft:
//        if(FSM->CurrentInputLight <120){
//            Nokia5110_OutString("Slow");
//            Motor_Right(10,10);
//        }else{
//            Nokia5110_OutString("Lost to the Right");
//            Motor_Right(25,25);
//        }
//        TURN_OFF_LED_FL;
//        TURN_ON_LED_FR;
//        TURN_OFF_LED_BL;
//        TURN_OFF_LED_BR;
//        break;
    case lost:
        if(FSM->CurrentInputLight <120){
            Nokia5110_OutString("Slow Lost");
            Motor_Right(10,10);
        }else{
            Nokia5110_OutString("Lost");
            Motor_Right(25,25);
        }
        TURN_OFF_LED_FL;
        TURN_OFF_LED_FR;
        TURN_ON_LED_BL;
        TURN_ON_LED_BR;
        break;
    case stop:
        Nokia5110_OutString("Stopped >:[");
        Motor_Stop();
        TURN_ON_LED_FL;
        TURN_ON_LED_FR;
        TURN_ON_LED_BL;
        TURN_ON_LED_BR;
        break;
    case finish:
        Nokia5110_OutString("All Done :)");
        Motor_Stop();
        TURN_ON_LED_FL;
        TURN_ON_LED_FR;
        TURN_ON_LED_BL;
        TURN_ON_LED_BR;
        break;
}
}
