#include <stdio.h>

int multiply_by_9(int num) {
    return (num << 3) + num; 
}

// Test function to verify correctness
void test_multiplication() {
    int test_cases[] = {0, 1, 2, 5, 10, 15, -3, -7, 100, -100};
    int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < num_cases; i++) {
        int num = test_cases[i];
        int result = multiply_by_9(num);
        printf("%d * 9 = %d\n", num, result);
    }
}

int main() {
    printf("Testing multiplication by 9 using bitwise operations:\n");
    test_multiplication();
    return 0;
}

