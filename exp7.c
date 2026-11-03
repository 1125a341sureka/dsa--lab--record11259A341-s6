#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtEnd(int value) {
    struct Node *newNode = malloc(sizeof *newNode);
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtBeginning(int value) {
    struct Node *newNode = malloc(sizeof *newNode);
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void deleteValue(int value) {
    struct Node *temp = head;
    struct Node *prev = NULL;

    if (temp != NULL && temp->data == value) {
        head = temp->next;
        free(temp);
        printf("Deleted %d.\n", value);
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Value %d not found.\n", value);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Deleted %d.\n", value);
}

void traverse(void) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void freeList(void) {
    while (head != NULL) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int choice;
    int value;

    do {
        printf("\n1. Insert at End\n2. Insert at Beginning\n3. Delete\n"
               "4. Traverse\n5. Exit\nEnter choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            freeList();
            return 1;
        }

        switch (choice) {
            case 1:
                printf("Enter value: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input.\n");
                    freeList();
                    return 1;
                }
                insertAtEnd(value);
                break;
            case 2:
                printf("Enter value: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input.\n");
                    freeList();
                    return 1;
                }
                insertAtBeginning(value);
                break;
            case 3:
                printf("Enter value to delete: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input.\n");
                    freeList();
                    return 1;
                }
                deleteValue(value);
                break;
            case 4:
                traverse();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    freeList();
    return 0;
}
