#include <stdio.h>

int main() {
    int start, end, i, j, isPrime;

    printf("Enter lower limit: ");
    scanf("%d", &start);

    printf("Enter upper limit: ");
    scanf("%d", &end);

    printf("Prime numbers between %d and %d are:\n", start, end);

    i = start;

    while (i <= end) {
        if (i > 1) {
            isPrime = 1;
            j = 2;

            while (j <= i / 2) {
                if (i % j == 0) {
                    isPrime = 0;
                    break;
                }
                j++;
            }

            if (isPrime == 1) {
                printf("%d ", i);
            }
        }

        i++;
    }

    printf("\n");

    return 0;
}