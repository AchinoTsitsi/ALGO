#include <stdio.h>
#include <stdlib.h>

// Define a Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a value at a specific position in the linked list
void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (position == 0) {
        // Insert at the beginning
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    int count = 0;

    // Traverse to the desired position
    while (current != NULL && count < position - 1) {
        current = current->next;
        count++;
    }

    // If the position is greater than the length of the list, insert at the end
    if (current == NULL) {
        printf("Invalid position. Inserting at the end.\n");
        return;
    }

    // Insert the new node at the specified position
    newNode->next = current->next;
    current->next = newNode;
}

// Function to display the linked list
void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Main function for testing
int main() {
    struct Node* head = NULL;

    // Append some nodes
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1;
    head->next = NULL;

    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    second->data = 2;
    second->next = NULL;

    head->next = second;

    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    third->data = 4;
    third->next = NULL;

    second->next = third;

    // Display the original linked list
    printf("Original linked list:\n");
    display(head);

    // Insert 3 at position 2
    insertAtPosition(&head, 3, 2);

    // Display the linked list after insertion
    printf("Linked list after inserting 3 at position 2:\n");
    display(head);

    return 0;
}

