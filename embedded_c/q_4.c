#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BATTERY 100
#define MIN_BATTERY 0

typedef struct {
    int device_id;
    int status;  // 0 - Inactive, 1 - Active
    int battery_level;
} IoTDevice;

// Function to check if a string is numeric
int is_numeric(const char *str) {
    while (*str) {
        if (!isdigit(*str)) return 0;  // If any character is not a digit, return false
        str++;
    }
    return 1;
}

// Function to initialize an IoT device
int initialize_device(IoTDevice *device, int device_id, int status, int battery_level) {
    if (device_id <= 0) {
        printf("Error: Invalid Device ID. Must be positive.\n");
        return 0;
    }
    if (status != 0 && status != 1) {
        printf("Error: Invalid Status. Must be 0 (Inactive) or 1 (Active).\n");
        return 0;
    }
    if (battery_level < MIN_BATTERY || battery_level > MAX_BATTERY) {
        printf("Error: Invalid Battery Level. Must be between 0 and 100.\n");
        return 0;
    }

    device->device_id = device_id;
    device->status = status;
    device->battery_level = battery_level;
    return 1;
}

// Function to print IoT device details
void print_device(const IoTDevice *device) {
    printf("Device ID: %d, Status: %s, Battery Level: %d%%\n", 
           device->device_id, 
           device->status ? "Active" : "Inactive", 
           device->battery_level);
}

// Function to get a valid positive integer input
int get_valid_input(const char *prompt) {
    char input[10];
    int value;

    while (1) {
        printf("%s", prompt);
        scanf("%9s", input);

        if (is_numeric(input)) {
            value = atoi(input);
            if (value > 0) {
                return value; // Valid input
            }
        }
        printf("Error: Invalid input. Please enter a valid positive integer.\n");
    }
}

// Function to get a valid status (0 or 1)
int get_valid_status() {
    char input[10];
    int value;

    while (1) {
        printf("Enter Status (0 for Inactive, 1 for Active): ");
        scanf("%9s", input);

        if (is_numeric(input)) {
            value = atoi(input);
            if (value == 0 || value == 1) {
                return value;
            }
        }
        printf("Error: Invalid Status. Please enter 0 (Inactive) or 1 (Active).\n");
    }
}

// Function to get a valid battery level (0-100)
int get_valid_battery_level() {
    char input[10];
    int value;

    while (1) {
        printf("Enter Battery Level (0-100): ");
        scanf("%9s", input);

        if (is_numeric(input)) {
            value = atoi(input);
            if (value >= MIN_BATTERY && value <= MAX_BATTERY) {
                return value;
            }
        }
        printf("Error: Invalid Battery Level. Please enter a value between 0 and 100.\n");
    }
}

// Function to get yes/no response
int get_yes_no_response() {
    char response[10];

    while (1) {
        printf("\n \n ****** Do you want to enter custom device details? (yes/no): ");
        scanf("%9s", response);

        // Convert response to lowercase for case-insensitivity
        for (int i = 0; response[i]; i++) {
            response[i] = tolower(response[i]);
        }

        if (strcmp(response, "yes") == 0) {
            return 1;  // User chose yes
        } else if (strcmp(response, "no") == 0) {
            return 0;  // User chose no
        } else {
            printf("Invalid response. Please enter 'yes' or 'no'.\n");
        }
    }
}

int main() {
    IoTDevice device;
    
    // Print default example
    printf("\n--- Default Example ---\n");
    if (initialize_device(&device, 101, 1, 75)) {
        print_device(&device);
    }

    while (1) {
        // Ask if the user wants to enter custom device details
        if (get_yes_no_response()) {
            printf("\n--- Enter Custom Device Details ---\n");

            // Get user input with validation
            int device_id = get_valid_input("Enter Device ID (positive integer): ");
            int status = get_valid_status();
            int battery_level = get_valid_battery_level();

            // Initialize and print device
            if (initialize_device(&device, device_id, status, battery_level)) {
                print_device(&device);
            } else {
                printf("Device initialization failed due to invalid input.\n");
            }
        } else {
            printf("\nExiting program. No custom entry provided.\n");
            break;
        }
    }

    return 0;
}

