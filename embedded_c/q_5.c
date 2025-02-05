#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

#define SENSOR_MIN 0
#define SENSOR_MAX 800
#define SPEED_MIN 0
#define SPEED_MAX 255
#define ACCELERATION_STEP 5  // Defines smooth acceleration step
#define DELAY 50000          // 50ms delay for smooth transition

// Function to map sensor value (0-800) to motor speed (0-255)
int map_sensor_to_speed(int sensor_value) {
    return (sensor_value - SENSOR_MIN) * (SPEED_MAX - SPEED_MIN) / (SENSOR_MAX - SENSOR_MIN) + SPEED_MIN;
}

// Function to simulate smooth acceleration and deceleration
void set_motor_speed(int *current_speed, int target_speed) {
    while (*current_speed != target_speed) {
        if (*current_speed < target_speed) {
            *current_speed += ACCELERATION_STEP;
            if (*current_speed > target_speed) *current_speed = target_speed;  // Prevent overshooting
        } else {
            *current_speed -= ACCELERATION_STEP;
            if (*current_speed < target_speed) *current_speed = target_speed;  // Prevent overshooting
        }
        printf("Current Motor Speed: %d\n", *current_speed);
        usleep(DELAY);  // Delay to simulate smooth transition
    }
}

// Function to check if a string is numeric
int is_numeric(const char *str) {
    while (*str) {
        if (!isdigit(*str)) return 0;
        str++;
    }
    return 1;
}

// Function to get valid sensor input
int get_sensor_input() {
    char input[10];
    int sensor_value;

    while (1) {
        printf("Enter Sensor Value (0-800): ");
        scanf("%9s", input);

        if (is_numeric(input)) {
            sensor_value = atoi(input);
            if (sensor_value >= SENSOR_MIN && sensor_value <= SENSOR_MAX) {
                return sensor_value;
            }
        }
        printf("Error: Invalid input. Enter a number between 0 and 800.\n");
    }
}

// Function to get user response (yes/no)
int get_yes_no_response() {
    char response[10];

    while (1) {
        printf("\nDo you want to enter another sensor value? (yes/no): ");
        scanf("%9s", response);

        // Convert response to lowercase for case-insensitivity
        for (int i = 0; response[i]; i++) {
            response[i] = tolower(response[i]);
        }

        if (strcmp(response, "yes") == 0) {
            return 1;  // Continue
        } else if (strcmp(response, "no") == 0) {
            return 0;  // Exit
        } else {
            printf("Invalid response. Please enter 'yes' or 'no'.\n");
        }
    }
}

// Main function
int main() {
    int current_speed = 0;  // Initially, the motor is stopped

    printf("Motor Speed Simulation with Smooth Acceleration & Deceleration\n");

    while (1) {
        int sensor_value = get_sensor_input();
        int target_speed = map_sensor_to_speed(sensor_value);
        
        printf("Sensor Value: %d -> Target Motor Speed: %d\n", sensor_value, target_speed);
        
        set_motor_speed(&current_speed, target_speed);

        // Ask if the user wants to enter another value
        if (!get_yes_no_response()) {
            printf("\nExiting program. No more entries.\n");
            break;
        }
    }

    return 0;
}

