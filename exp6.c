#include <stdio.h>

#define MAX 100

struct Element {
    int data;
    int priority; /* Lower value means higher priority. */
};

struct Element pqueue[MAX];
int n = 0;

void insert(int data, int priority) {
    if (n == MAX) {
        printf("Priority queue is full.\n");
        return;
    }

    pqueue[n].data = data;
    pqueue[n].priority = priority;
    n++;
    printf("Inserted %d with priority %d.\n", data, priority);
}

void deleteHighestPriority(void) {
    if (n == 0) {
        printf("Priority queue is empty.\n");
        return;
    }

    int highIdx = 0;
    for (int i = 1; i < n; i++) {
        if (pqueue[i].priority < pqueue[highIdx].priority) {
            highIdx = i;
        }
    }

    printf("Removed %d (priority %d).\n", pqueue[highIdx].data,
           pqueue[highIdx].priority);
    for (int i = highIdx; i < n - 1; i++) {
        pqueue[i] = pqueue[i + 1];
    }
    n--;
}

void display(void) {
    if (n == 0) {
        printf("Priority queue is empty.\n");
        return;
    }

    printf("Data\tPriority\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\n", pqueue[i].data, pqueue[i].priority);
    }
}

int main(void) {
    int choice;
    int data;
    int priority;

    do {
        printf("\n1. Insert\n2. Delete Highest Priority\n3. Display\n"
               "4. Exit\nEnter choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            return 1;
        }

        switch (choice) {
            case 1:
                printf("Enter data and priority: ");
                if (scanf("%d%d", &data, &priority) != 2) {
                    printf("Invalid input.\n");
                    return 1;
                }
                insert(data, priority);
                break;
            case 2:
                deleteHighestPriority();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}
