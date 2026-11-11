#include <stdio.h>

int main() {
    int num;

    // Input number
    printf("Enter an integer: ");
    scanf("%d", &num);

    // Check even or odd using modulus operator
    if (num % 2 == 0) {
        printf("%d is EVEN.\n", num);
    } else {
        printf("%d is ODD.\n", num);
    }

    return 0;
}