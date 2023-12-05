#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        (*head)->next = *head;
        (*head)->prev = *head;
    } else {
        newNode->next = *head;
        newNode->prev = (*head)->prev;
        (*head)->prev->next = newNode;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        (*head)->next = *head;
        (*head)->prev = *head;
    } else {
        newNode->next = *head;
        newNode->prev = (*head)->prev;
        (*head)->prev->next = newNode;
        (*head)->prev = newNode;
    }
}

void deleteNode(struct Node** head, int data) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;

    do {
        if (temp->data == data) {
            if (temp->next == temp) {  // Only one node in the list
                free(temp);
                *head = NULL;
                return;
            }

            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            if (*head == temp) {
                *head = temp->next;
            }

            free(temp);
            return;
        }
        temp = temp->next;
    } while (temp != *head);

    printf("Node with data %d not found.\n", data);
}

// Display Type 1

/*
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("Circular Doubly Linked List is empty.\n");
        return;
    }

    struct Node* current = head;
    do {
        printf("[Node: %p | Data: %d | Prev: %p | Next: %p] <--> ", (void*)current, current->data, (void*)current->prev, (void*)current->next);
        current = current->next;
    } while (current != head);
    printf("[Back to head]\n\n");
}
*/

void displayList(struct Node* head) {
    if (head == NULL) {
        printf("Circular Doubly Linked List is empty.\n\n");
        return;
    }

    printf("Doubly Linked List:\n");
    struct Node* current = head;
    do {
        printf("[Node: %p | Data: %d | Prev: %p | Next: %p] <--> ", (void*)current, current->data, (void*)current->prev, (void*)current->next);
        current = current->next;
    } while (current != head);
    printf("[Back to head]\n\n");
}

// Display Type 3
/* 
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("Circular Doubly Linked List is empty.\n\n");
        return;
    }

    printf("Doubly Linked List (Head Node is: %p)\n", (void*)head);
    struct Node* current = head;
    do {
        printf("[Node: %p | Data: %d | Prev: %p | Next: %p] <--> ", (void*)current, current->data, (void*)current->prev, (void*)current->next);
        current = current->next;
    } while (current != head);
    printf("[Back to head]\n\n");
}
*/
void freeList(struct Node* head) {
    if (head == NULL) {
        return;
    }

    struct Node* current = head;
    struct Node* nextNode;
    do {
        nextNode = current->next;
        free(current);
        current = nextNode;
    } while (current != head);
}

int main() {
    struct Node* head = NULL;
    int choice, data;

    do {
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Delete a node\n");
        printf("4. Display the list\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;

            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;

            case 3:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;

            case 4:
                displayList(head);
                break;

            case 0:
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    freeList(head);

    return 0;
}
