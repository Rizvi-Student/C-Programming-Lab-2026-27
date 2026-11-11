#include <stdio.h>

int main() {
    int start, end, sum = 0;

    // Input range
    printf("Enter the starting number: ");
    scanf("%d", &start);

    printf("Enter the ending number: ");
    scanf("%d", &end);

    // Calculate sum of odd numbers
    for (int i = start; i <= end; i++) {
        if (i % 2 != 0) {
            sum += i;
        }
    }

    printf("Sum of odd numbers = %d\n", sum);

    return 0;
}