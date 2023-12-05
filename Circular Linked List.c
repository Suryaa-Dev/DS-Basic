#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        (*head)->next = *head;
    } else {
        newNode->next = *head;
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        *head = newNode;
    }
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        (*head)->next = *head;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

void deleteNode(struct Node** head, int data) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = *head, *prev = NULL;

    // If the node to be deleted is the head
    if (temp->data == data) {
        struct Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }

        *head = temp->next;
        last->next = *head;
        free(temp);
        return;
    }

    // If the node is not the head, find the previous node
    while (temp->next != *head && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    // If the node is not found
    if (temp->data != data) {
        printf("Node with data %d not found.\n", data);
        return;
    }

    // Remove the node
    prev->next = temp->next;
    free(temp);
}

void displayList(struct Node* head) {
    if (head == NULL) {
        printf("Circular Linked List is empty.\n\n");
        return;
    }

    // printf("Circular Linked List:\n");
    printf("Circular Linked List (Head Node is: %p)\n", (void*)head);
    struct Node* current = head;
    do {
        printf("[This Node: %p | Data: %d | Next: %p] <--> ", (void*)current, current->data, (void*)current->next);
        current = current->next;
    } while (current != head);
    printf("[Back to head]\n\n");
}

// void freeList(struct Node** head) {
//     if (*head == NULL) {
//         return;
//     }

//     struct Node *temp, *last;
//     temp = last = *head;

//     do {
//         last = temp;
//         temp = temp->next;
//         free(last);
//     } while (temp != *head);

//     *head = NULL;
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
                exit(0);
                break;

            default:
                printf("Enter Valid Choice\n");
        }
    } while (choice != 0);

    // freeList(&head);

    return 0;
}
