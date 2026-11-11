#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 100

struct Student {
    int id;
    char name[50];
    float marks;
    char grade;
};

int main() {
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice, searchId, found, i;
    float totalMarks = 0, averageMarks = 0;

main_menu:
    printf("\n=========================================\n");
    printf(" STUDENT GRADE & RESULT MANAGEMENT SYSTEM\n");
    printf("=========================================\n");
    printf("1. Add Student Record\n");
    printf("2. Display All Student Records\n");
    printf("3. Search Student by ID\n");
    printf("4. Calculate Class Average\n");
    printf("5. Exit\n");
    printf("-----------------------------------------\n");
    printf("Enter your choice (1-5): ");

    if (scanf("%d", &choice) != 1) {
        printf("\nInvalid input! Please enter a valid number.\n");

        while (getchar() != '\n');

        goto main_menu;
    }

    switch (choice) {

        case 1:
            if (count >= MAX_STUDENTS) {
                printf("\nDatabase is full! Cannot add more students.\n");
                goto main_menu;
            }

            printf("\n--- Add Student Record ---\n");

            printf("Enter Student ID: ");
            scanf("%d", &students[count].id);

            printf("Enter Student Name: ");
            scanf("%s", students[count].name);

            printf("Enter Marks (out of 100): ");
            scanf("%f", &students[count].marks);

            if (students[count].marks < 0 ||
                students[count].marks > 100) {

                printf("\nInvalid marks! Please enter a value between 0 and 100.\n");
                goto main_menu;
            }

            if (students[count].marks >= 90)
                students[count].grade = 'A';
            else if (students[count].marks >= 75)
                students[count].grade = 'B';
            else if (students[count].marks >= 60)
                students[count].grade = 'C';
            else if (students[count].marks >= 40)
                students[count].grade = 'D';
            else
                students[count].grade = 'F';

            count++;

            printf("\nStudent record added successfully!\n");
            goto main_menu;

        case 2:
            if (count == 0) {
                printf("\nNo student records found!\n");
                goto main_menu;
            }

            printf("\n--- All Student Records ---\n");

            printf("%-10s %-20s %-10s %-10s\n",
                   "ID", "Name", "Marks", "Grade");

            printf("---------------------------------------------------\n");

            for (i = 0; i < count; i++) {
                printf("%-10d %-20s %-10.2f %-10c\n",
                       students[i].id,
                       students[i].name,
                       students[i].marks,
                       students[i].grade);
            }

            goto main_menu;

        case 3:
            if (count == 0) {
                printf("\nNo student records found!\n");
                goto main_menu;
            }

            printf("\nEnter Student ID to search: ");
            scanf("%d", &searchId);

            found = 0;

            for (i = 0; i < count; i++) {
                if (students[i].id == searchId) {

                    printf("\nRecord Found:\n");
                    printf("ID : %d\n", students[i].id);
                    printf("Name : %s\n", students[i].name);
                    printf("Marks : %.2f\n", students[i].marks);
                    printf("Grade : %c\n", students[i].grade);

                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("\nStudent with ID %d not found.\n", searchId);
            }

            goto main_menu;

        case 4:
            if (count == 0) {
                printf("\nNo student records found to calculate average!\n");
                goto main_menu;
            }

            totalMarks = 0;

            for (i = 0; i < count; i++) {
                totalMarks += students[i].marks;
            }

            averageMarks = totalMarks / count;

            printf("\nTotal Students: %d\n", count);
            printf("Class Average Marks: %.2f\n", averageMarks);

            goto main_menu;

        case 5:
            printf("\nExiting program. Thank you!\n");
            exit(0);

        default:
            printf("\nInvalid choice! Please select between 1 and 5.\n");
            goto main_menu;
    }

    return 0;
}