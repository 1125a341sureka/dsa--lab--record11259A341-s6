#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int value) {
    struct Node *newNode = malloc(sizeof *newNode);
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;
    if (front == NULL) {
        front = rear = newNode;
        newNode->next = front;
    } else {
        newNode->next = front;
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d enqueued.\n", value);
}

void dequeue(void) {
    if (front == NULL) {
        printf("Queue underflow\n");
        return;
    }

    struct Node *temp = front;
    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
        rear->next = front;
    }
    printf("%d dequeued.\n", temp->data);
    free(temp);
}

void display(void) {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct Node *temp = front;
    printf("Queue elements: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("\n");
}

void freeQueue(void) {
    if (front == NULL) {
        return;
    }

    struct Node *current = front->next;
    while (current != front) {
        struct Node *next = current->next;
        free(current);
        current = next;
    }
    free(front);
    front = rear = NULL;
}

int main(void) {
    int choice;
    int value;

    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            freeQueue();
            return 1;
        }

        switch (choice) {
            case 1:
                printf("Enter value: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input.\n");
                    freeQueue();
                    return 1;
                }
                enqueue(value);
                break;
            case 2:
                dequeue();
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

    freeQueue();
    return 0;
}
