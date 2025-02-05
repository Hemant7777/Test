#include <stdio.h>

void decimal_to_binary(int num) {
    if (num == 0) {
        printf("0");
        return;
    }

    int binary[32], i = 0;
    while (num > 0) {
        binary[i++] = num % 2;
        num /= 2;
    }

    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    printf("\n");
}

int main() {
    int num = 545;
    printf("Decimal: %d\n", num);
    printf("Binary: ");
    decimal_to_binary(num);

    printf("\nTest Cases:\n");
    int test_cases[] = {0, 1, 2, 3, 10, 255, 1024, 2048, 4095};
    for (int i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++) {
        printf("Decimal: %d -> Binary: ", test_cases[i]);
        decimal_to_binary(test_cases[i]);
    }

    return 0;
}

