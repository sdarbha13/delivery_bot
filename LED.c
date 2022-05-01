#include "LED.h"

void InitializeLEDPortPin(void)
{
    // Initialize the value and port pin direction of the LEDs.
    TURN_OFF_LED_FR;
    SET_LED_FR_AS_AN_OUTPUT;
    TURN_OFF_LED_FL;
    SET_LED_FL_AS_AN_OUTPUT;
    TURN_OFF_LED_BL;
    SET_LED_BL_AS_AN_OUTPUT;
    TURN_OFF_LED_BR;
    SET_LED_BR_AS_AN_OUTPUT;
}
