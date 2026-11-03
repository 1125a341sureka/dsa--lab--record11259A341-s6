#include <stdio.h>
#include <stdlib.h>

struct Employee {
    int id;
    char name[50];
    char designation[30];
    float salary;
};

struct Employee *createRecords(int n) {
    struct Employee *emp = malloc((size_t)n * sizeof *emp);
    if (emp == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        printf("\nEnter details for employee %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &emp[i].id);
        printf("Name: ");
        scanf("%49s", emp[i].name);
        printf("Designation: ");
        scanf("%29s", emp[i].designation);
        printf("Salary: ");
        scanf("%f", &emp[i].salary);
    }
    return emp;
}

void displayRecords(struct Employee *emp, int n) {
    printf("\n%-6s %-15s %-15s %-10s\n", "ID", "Name", "Designation",
           "Salary");
    for (int i = 0; i < n; i++) {
        printf("%-6d %-15s %-15s %-10.2f\n", emp[i].id, emp[i].name,
               emp[i].designation, emp[i].salary);
    }
}

struct Employee *searchById(struct Employee *emp, int n, int id) {
    for (int i = 0; i < n; i++) {
        if (emp[i].id == id) {
            return &emp[i];
        }
    }
    return NULL;
}

int main(void) {
    int n, searchId;
    struct Employee *emp;

    printf("Enter number of employees: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of employees.\n");
        return 1;
    }

    emp = createRecords(n);
    displayRecords(emp, n);

    printf("\nEnter employee ID to search: ");
    scanf("%d", &searchId);
    struct Employee *found = searchById(emp, n, searchId);
    if (found != NULL) {
        printf("Found: %d %s %s %.2f\n", found->id, found->name,
               found->designation, found->salary);
    } else {
        printf("Employee not found.\n");
    }

    free(emp);
    return 0;
}
