#include <stdio.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main() {
    // Test cases to check the MIN macro
    printf("Test Case 1: MIN(10, 20) = %d\n", MIN(10, 20)); // Expected output: 10
    printf("Test Case 2: MIN(30, 15) = %d\n", MIN(30, 15)); // Expected output: 15
    printf("Test Case 3: MIN(-5, -10) = %d\n", MIN(-5, -10)); // Expected output: -10
    printf("Test Case 4: MIN(0, 0) = %d\n", MIN(0, 0)); // Expected output: 0
    printf("Test Case 5: MIN(100, 100) = %d\n", MIN(100, 100)); // Expected output: 100

    return 0;
}

