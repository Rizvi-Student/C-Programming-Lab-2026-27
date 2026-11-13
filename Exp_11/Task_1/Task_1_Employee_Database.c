#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for Employee
struct Employee {
    int emp_id;
    char name[50];
    char designation[30];
    float salary;
};

// Function prototypes
void addEmployee();
void displayEmployees();
void searchEmployee();
void deleteEmployee();

int main() {
    int choice;

    while (1) {
        printf("\n====================================\n");
        printf("      EMPLOYEE DATABASE MANAGEMENT   \n");
        printf("====================================\n");
        printf("1. Add Employee Record\n");
        printf("2. Display All Employee Records\n");
        printf("3. Search Employee by ID\n");
        printf("4. Delete Employee Record\n");
        printf("5. Exit\n");
        printf("------------------------------------\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee();
                break;

            case 2:
                displayEmployees();
                break;

            case 3:
                searchEmployee();
                break;

            case 4:
                deleteEmployee();
                break;

            case 5:
                printf("\nExiting program. Goodbye!\n");
                exit(0);

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Function to append a new employee record to file
void addEmployee() {
    FILE *fp = fopen("employees.dat", "ab");

    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    struct Employee emp;

    printf("\n--- Add New Employee ---\n");

    printf("Enter Employee ID: ");
    scanf("%d", &emp.emp_id);

    printf("Enter Name: ");
    scanf(" %[^\n]", emp.name);

    printf("Enter Designation: ");
    scanf(" %[^\n]", emp.designation);

    printf("Enter Salary: ");
    scanf("%f", &emp.salary);

    // Write binary record to file
    fwrite(&emp, sizeof(struct Employee), 1, fp);

    fclose(fp);

    printf("\nEmployee record saved successfully!\n");
}

// Function to display all employee records
void displayEmployees() {
    FILE *fp = fopen("employees.dat", "rb");

    if (fp == NULL) {
        printf("\nNo employee database found or file is empty.\n");
        return;
    }

    struct Employee emp;
    int count = 0;

    printf("\n============================================================\n");
    printf("%-10s %-25s %-20s %-10s\n",
           "ID", "Name", "Designation", "Salary");
    printf("============================================================\n");

    while (fread(&emp, sizeof(struct Employee), 1, fp) == 1) {
        printf("%-10d %-25s %-20s %-10.2f\n",
               emp.emp_id, emp.name, emp.designation, emp.salary);
        count++;
    }

    printf("============================================================\n");
    printf("Total Records: %d\n", count);

    fclose(fp);
}

// Function to search for an employee by ID
void searchEmployee() {
    FILE *fp = fopen("employees.dat", "rb");

    if (fp == NULL) {
        printf("\nNo employee database found.\n");
        return;
    }

    int target_id, found = 0;
    struct Employee emp;

    printf("\nEnter Employee ID to search: ");
    scanf("%d", &target_id);

    while (fread(&emp, sizeof(struct Employee), 1, fp) == 1) {
        if (emp.emp_id == target_id) {
            printf("\n--- Record Found ---\n");
            printf("ID          : %d\n", emp.emp_id);
            printf("Name        : %s\n", emp.name);
            printf("Designation : %s\n", emp.designation);
            printf("Salary      : %.2f\n", emp.salary);

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nEmployee with ID %d not found.\n", target_id);
    }

    fclose(fp);
}

// Function to delete an employee record by ID
void deleteEmployee() {
    FILE *fp = fopen("employees.dat", "rb");

    if (fp == NULL) {
        printf("\nNo employee database found.\n");
        return;
    }

    FILE *temp_fp = fopen("temp.dat", "wb");

    if (temp_fp == NULL) {
        printf("Error creating temporary file!\n");
        fclose(fp);
        return;
    }

    int target_id, found = 0;
    struct Employee emp;

    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &target_id);

    while (fread(&emp, sizeof(struct Employee), 1, fp) == 1) {
        if (emp.emp_id == target_id) {
            found = 1; // Skip writing this record to temp file
        } else {
            fwrite(&emp, sizeof(struct Employee), 1, temp_fp);
        }
    }

    fclose(fp);
    fclose(temp_fp);

    if (found) {
        remove("employees.dat");
        rename("temp.dat", "employees.dat");

        printf("\nEmployee record deleted successfully!\n");
    } else {
        remove("temp.dat");
        printf("\nEmployee with ID %d not found.\n", target_id);
    }
}