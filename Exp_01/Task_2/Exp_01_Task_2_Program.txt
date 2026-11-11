
#include <stdio.h>

int main() {
    float physics, chemistry, maths;
    float total, average;

    // Input marks for PCM
    printf("Enter Physics marks (out of 100): ");
    scanf("%f", &physics);

    printf("Enter Chemistry marks (out of 100): ");
    scanf("%f", &chemistry);

    printf("Enter Mathematics marks (out of 100): ");
    scanf("%f", &maths);

    // Validate mark inputs
    if (physics < 0 || physics > 100 ||
        chemistry < 0 || chemistry > 100 ||
        maths < 0 || maths > 100) {
        printf("\nError: Marks must be between 0 and 100.\n");
        return 1;
    }

    // Calculations
    total = physics + chemistry + maths;
    average = total / 3.0;

    // Display total and average
    printf("\n--- Student Performance ---\n");
    printf("Total Marks: %.2f / 300\n", total);
    printf("Average Marks: %.2f%%\n", average);

    // Eligibility Check
    // Criteria: Average >= 50% and Total >= 150
    if (average >= 50.0 && total >= 150.0) {
        printf("Eligibility Status: ELIGIBLE for admission.\n");
    } else {
        printf("Eligibility Status: NOT ELIGIBLE for admission.\n");
    }

    return 0;
}
