#include <stdio.h>

// Define states
typedef enum {
    IDLE,
    RUNNING,
    STOPPED
} State;

// Function declarations for each state
void idle_state();
void running_state();
void stopped_state();

// Define the state machine structure
typedef void (*StateFunction)(void);  // Pointer to function type

// Global pointer to the current state function
StateFunction current_state;

// Function to transition to a new state
void transition_to(State state) {
    switch(state) {
        case IDLE:
            current_state = idle_state;
            break;
        case RUNNING:
            current_state = running_state;
            break;
        case STOPPED:
            current_state = stopped_state;
            break;
        default:
            printf("Invalid state\n");
            return;
    }
}

// Implementing the state functions

void idle_state() {
    printf("State: IDLE\n");
    // Transition to RUNNING state after some event, here for simulation
    transition_to(RUNNING);
}

void running_state() {
    printf("State: RUNNING\n");
    // Transition to STOPPED state after some event, here for simulation
    transition_to(STOPPED);
}

void stopped_state() {
    printf("State: STOPPED\n");
    // Transition to IDLE state after some event, here for simulation
    transition_to(IDLE);
}

int main() {
    // Initial state
    transition_to(IDLE);
    
    // Simulate FSM running through states
    for (int i = 0; i < 5; i++) {  // Simulate 5 state transitions
        current_state();
    }

    return 0;
}

