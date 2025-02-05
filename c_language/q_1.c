#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 5  // Define maximum stack size

typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

// Function to initialize the stack
void init_stack(Stack *stack) {
    stack->top = -1;
}

// Function to check if stack is full
int is_full(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to check if stack is empty
int is_empty(Stack *stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(Stack *stack, int value) {
    if (is_full(stack)) {
        printf("Error: Stack Overflow! Cannot push %d.\n", value);
        return;
    }
    stack->arr[++stack->top] = value;
    printf("Pushed %d onto the stack.\n", value);
}

// Function to pop an element from the stack
int pop(Stack *stack) {
    if (is_empty(stack)) {
        printf("Error: Stack Underflow! Cannot pop from an empty stack.\n");
        return -1; // Return an invalid value for error handling
    }
    int value = stack->arr[stack->top--];
    printf("Popped %d from the stack.\n", value);
    return value;
}

// Function to display the stack
void display(Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack contents (top to bottom): ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

// Function to check if input is numeric
int is_numeric(const char *str) {
    while (*str) {
        if (!isdigit(*str)) return 0;
        str++;
    }
    return 1;
}

// Function to get a valid integer input
int get_valid_integer(const char *prompt) {
    char input[10];
    int value;

    while (1) {
        printf("%s", prompt);
        scanf("%9s", input);

        if (is_numeric(input)) {
            value = atoi(input);
            return value; // Valid input
        } else {
            printf("Error: Invalid input. Please enter a valid integer.\n");
        }
    }
}

// Main function
int main() {
    Stack stack;
    init_stack(&stack);

    printf("Stack Implementation with Push, Pop, and Display Operations\n");

    // Run predefined test cases
    printf("\n--- Running Predefined Test Cases ---\n");
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);
    push(&stack, 60);  // Stack Overflow (should fail)
    
    display(&stack);

    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);  // Stack Underflow (should fail)
    
    display(&stack);

    // Now allow user input
    printf("\n--- Now Taking User Input ---\n");

    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display Stack\n");
        printf("4. Exit\n");

        int choice = get_valid_integer("Enter your choice: ");

        switch (choice) {
            case 1: {
                int value = get_valid_integer("Enter value to push: ");
                push(&stack, value);
                break;
            }
            case 2:
                pop(&stack);
                break;
            case 3:
                display(&stack);
                break;
            case 4:
                printf("\nExiting program.\n");
                exit(0);
            default:
                printf("Error: Invalid choice. Please enter a number between 1 and 4.\n");
        }
    }

    return 0;
}

