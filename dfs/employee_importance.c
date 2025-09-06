#include <stdio.h>
#include <stdlib.h>

#define MAX_EMPLOYEES 100

// Structure to store employee details
typedef struct Employee {
    int id;
    int importance;
    int subCount;
    int subordinates[MAX_EMPLOYEES]; // Array to store subordinates
} Employee;

// Function to find an employee by ID
Employee* findEmployee(Employee employees[], int n, int id) {
    for (int i = 0; i < n; i++) {
        if (employees[i].id == id)
            return &employees[i];
    }
    return NULL;
}

// DFS function to compute total importance
int getTotalImportance(Employee employees[], int n, int id) {
    Employee *emp = findEmployee(employees, n, id);
    if (emp == NULL) return 0; // If employee not found

    int total = emp->importance;

    // Recursively add importance of all subordinates
    for (int i = 0; i < emp->subCount; i++) {
        total += getTotalImportance(employees, n, emp->subordinates[i]);
    }

    return total;
}

// Main function
int main() {
    int n, id;

    // Input number of employees
    printf("Enter number of employees: ");
    scanf("%d", &n);

    Employee employees[MAX_EMPLOYEES];

    // Input employee data
    for (int i = 0; i < n; i++) {
        printf("\nEnter Employee ID, Importance, Number of Subordinates: ");
        scanf("%d %d %d", &employees[i].id, &employees[i].importance, &employees[i].subCount);

        // Input subordinates
        if (employees[i].subCount > 0) {
            printf("Enter Subordinates' IDs: ");
            for (int j = 0; j < employees[i].subCount; j++) {
                scanf("%d", &employees[i].subordinates[j]);
            }
        }
    }

    // Input employee ID to calculate importance
    printf("\nEnter employee ID to calculate total importance: ");
    scanf("%d", &id);

    // Compute total importance using DFS
    int totalImportance = getTotalImportance(employees, n, id);
    printf("\nTotal Importance of Employee %d: %d\n", id, totalImportance);

    return 0;
}
