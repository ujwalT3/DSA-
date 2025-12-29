#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node *head = NULL;

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// a) Create a doubly linked list (Insert at end)
void createList(int value) {
    struct Node *newNode = createNode(value);

    if (head == NULL) {   // First node
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    printf("Node %d added to list.\n", value);
}

// b) Insert new node to the LEFT of a specific node value
void insertLeft(int value, int target) {
    struct Node *temp = head;

    while (temp != NULL && temp->data != target)
        temp = temp->next;

    if (temp == NULL) {
        printf("Target node %d not found.\n", target);
        return;
    }

    struct Node* newNode = createNode(value);

    newNode->next = temp;
    newNode->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = newNode;
    else
        head = newNode;

    temp->prev = newNode;

    printf("Inserted %d to the left of %d.\n", value, target);
}

// c) Delete a node based on a specific value
void deleteNode(int value) {
    struct Node *temp = head;

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) {
        printf("Node %d not found.\n", value);
        return;
    }

    // If node is head
    if (temp->prev == NULL)
        head = temp->next;
    else
        temp->prev->next = temp->next;

    // If node is not last
    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    printf("Node %d deleted.\n", value);
}

// d) Display list
void display() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main menu
int main() {
    int choice, value, target;

    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Create list (Insert at end)\n");
        printf("2. Insert to left of a node\n");
        printf("3. Delete a node\n");
        printf("4. Display list\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            createList(value);
            break;

        case 2:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            printf("Insert to the left of: ");
            scanf("%d", &target);
            insertLeft(value, target);
            break;

        case 3:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            deleteNode(value);
            break;

        case 4:
            display();
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
