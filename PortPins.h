#ifndef PORTPINS_H_
#define PORTPINS_H_

//  LEDFR - P8.5
#define LED_FR_PIN                  5
#define LED_FR_BIT                 (0x01 << LED_FR_PIN)
#define LED_FR_PORT                 P8
#define SET_LED_FR_AS_AN_OUTPUT     LED_FR_PORT->DIR |= LED_FR_BIT
#define TURN_ON_LED_FR              LED_FR_PORT->OUT |= LED_FR_BIT
#define TURN_OFF_LED_FR             LED_FR_PORT->OUT &= ~LED_FR_BIT
#define TOGGLE_LED_FR               LED_FR_PORT->OUT ^= LED_FR_BIT

//  LEDFL - P8.0
#define LED_FL_PIN                  0
#define LED_FL_BIT                 (0x01 << LED_FL_PIN)
#define LED_FL_PORT                 P8
#define SET_LED_FL_AS_AN_OUTPUT     LED_FL_PORT->DIR |= LED_FL_BIT
#define TURN_ON_LED_FL              LED_FL_PORT->OUT |= LED_FL_BIT
#define TURN_OFF_LED_FL             LED_FL_PORT->OUT &= ~LED_FL_BIT
#define TOGGLE_LED_FL               LED_FL_PORT->OUT ^= LED_FL_BIT

//  LEDBL - P8.6
#define LED_BL_PIN                  6
#define LED_BL_BIT                 (0x01 << LED_BL_PIN)
#define LED_BL_PORT                 P8
#define SET_LED_BL_AS_AN_OUTPUT     LED_BL_PORT->DIR |= LED_BL_BIT
#define TURN_ON_LED_BL              LED_BL_PORT->OUT |= LED_BL_BIT
#define TURN_OFF_LED_BL             LED_BL_PORT->OUT &= ~LED_BL_BIT
#define TOGGLE_LED_BL               LED_BL_PORT->OUT ^= LED_BL_BIT

//  LEDBR - P8.7
#define LED_BR_PIN                  7
#define LED_BR_BIT                 (0x01 << LED_BR_PIN)
#define LED_BR_PORT                 P8
#define SET_LED_BR_AS_AN_OUTPUT     LED_BR_PORT->DIR |= LED_BR_BIT
#define TURN_ON_LED_BR              LED_BR_PORT->OUT |= LED_BR_BIT
#define TURN_OFF_LED_BR             LED_BR_PORT->OUT &= ~LED_BR_BIT
#define TOGGLE_LED_BR               LED_BR_PORT->OUT ^= LED_BR_BIT

//  LED2 - Red
#define LED2_R_PIN                  0
#define LED2_R_BIT                 (0x01 << LED2_R_PIN)
#define LED2_R_PORT                 P2
#define SET_LED2_R_AS_AN_OUTPUT     LED2_R_PORT->DIR |= LED2_R_BIT
#define TURN_ON_LED2_RED            LED2_R_PORT->OUT |= LED2_R_BIT
#define TURN_OFF_LED2_RED           LED2_R_PORT->OUT &= ~LED2_R_BIT
#define TOGGLE_LED2_RED             LED2_R_PORT->OUT ^= LED2_R_BIT

//  LED2 - Green
#define LED2_G_PIN                  1
#define LED2_G_BIT                  (0x01 << LED2_G_PIN)
#define LED2_G_PORT                 P2
#define SET_LED2_G_AS_AN_OUTPUT     LED2_G_PORT->DIR |= LED2_G_BIT
#define TURN_ON_LED2_GREEN          LED2_G_PORT->OUT |= LED2_G_BIT
#define TURN_OFF_LED2_GREEN         LED2_G_PORT->OUT &= ~LED2_G_BIT
#define TOGGLE_LED2_GREEN           LED2_G_PORT->OUT ^= LED2_G_BIT

//  LED2 - Blue
#define LED2_B_PIN                  2
#define LED2_B_BIT                  (0x01 << LED2_B_PIN)
#define LED2_B_PORT                 P2
#define SET_LED2_B_AS_AN_OUTPUT     LED2_B_PORT->DIR |= LED2_B_BIT
#define TURN_ON_LED2_BLUE           LED2_B_PORT->OUT |= LED2_B_BIT
#define TURN_OFF_LED2_BLUE          LED2_B_PORT->OUT &= ~LED2_B_BIT
#define TOGGLE_LED2_BLUE            LED2_B_PORT->OUT ^= LED2_B_BIT

// Pushbutton S1
#define PUSHBUTTON_S1_PIN                       1
#define PUSHBUTTON_S1_BIT                       (0x01 << PUSHBUTTON_S1_PIN)
#define PUSHBUTTON_S1_PORT                      P1
#define SET_PUSHBUTTON_S1_TO_AN_INPUT           PUSHBUTTON_S1_PORT->DIR &= ~PUSHBUTTON_S1_BIT
#define ENABLE_PULL_UP_PULL_DOWN_RESISTORS_S1   PUSHBUTTON_S1_PORT->REN |= PUSHBUTTON_S1_BIT
#define SELECT_PULL_UP_RESISTORS_S1             PUSHBUTTON_S1_PORT->OUT |= PUSHBUTTON_S1_BIT

// Pushbutton S2
#define PUSHBUTTON_S2_PIN                       4
#define PUSHBUTTON_S2_BIT                       (0x01 << PUSHBUTTON_S2_PIN)
#define PUSHBUTTON_S2_PORT                      P1
#define SET_PUSHBUTTON_S2_TO_AN_INPUT           PUSHBUTTON_S2_PORT->DIR &= ~PUSHBUTTON_S2_BIT
#define ENABLE_PULL_UP_PULL_DOWN_RESISTORS_S2   PUSHBUTTON_S2_PORT->REN |= PUSHBUTTON_S2_BIT
#define SELECT_PULL_UP_RESISTORS_S2             PUSHBUTTON_S2_PORT->OUT |= PUSHBUTTON_S2_BIT

#endif /* PORTPINS_H_ */
