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
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void deleteNode(struct Node** head, int data) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;

    while (temp != NULL && temp->data != data) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with data %d not found.\n", data);
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
}

void displayList(struct Node* head) {
    printf("Doubly Linked List:\n");
    while (head != NULL) {
        // printf("[Node: %p | Data: %d | Prev: %p | Next: %p] ", (void*)head, head->data, (void*)head->prev, (void*)head->next);
        printf("[Address of this Node: %p | ", (void*)head);
        printf("Data: %d | ", head->data);
        printf("Prev: %p | ", (void*)head->prev);
        printf("Next: %p]", (void*)head->next);
        if (head->next != NULL) {
            printf(" <--> ");
        }
        head = head->next;
    }
    printf("\n\n");
}


// void freeList(struct Node* head) {
//     while (head != NULL) {
//         struct Node* temp = head;
//         head = head->next;
//         free(temp);
//     }
// }

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

    // freeList(head);

    return 0;
}
