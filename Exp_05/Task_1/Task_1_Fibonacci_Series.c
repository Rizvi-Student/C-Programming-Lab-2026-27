#include <stdio.h>

// Recursive function to find the nth Fibonacci number
int fibonacci_recursive(int n) {
    if (n <= 1) {
        return n; // Base case: 0th term is 0, 1st term is 1
    }
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

// Iterative function to generate and print Fibonacci series
void fibonacci_iterative(int n) {
    int t1 = 0, t2 = 1, nextTerm;

    printf("Iterative Fibonacci Series: ");

    for (int i = 1; i <= n; ++i) {
        printf("%d ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }

    printf("\n");
}

int main() {
    int n;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return 0;
    }

    // 1. Call Iterative Method
    fibonacci_iterative(n);

    // 2. Call Recursive Method
    printf("Recursive Fibonacci Series: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci_recursive(i));
    }

    printf("\n");

    return 0;
}