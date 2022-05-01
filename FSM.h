#ifndef FSM_H_
#define FSM_H_

#include "PortPins.h"
#include "Switch.h"

// Type Definitions
typedef enum {
    center,
    left,
    right,
    lost,
    stop,
    lostLeft,
    lostRight,
    finish,
    T,
    CurvedRight,
    CurvedLeft
} FSMState;

typedef struct {
    FSMState     CurrentState;      // Current state of the FSM
    uint8_t CurrentInputLine;    // Current input of the FSM Reflectance Sensor
    uint8_t CurrentInputBump;    // Current input of the FSM Bump Sensors
    uint8_t CurrentInputZacc; //Current input of Z acceleration
    uint8_t CurrentInputLight; //Current input of Light
} FSMType;

// Function Prototypes
void InitializeFSM(FSMType *FSM);
FSMState NextStateFunction(FSMType *FSM);
void OutputFunction(FSMType *FSM);

#endif /* FSM_H_ */
