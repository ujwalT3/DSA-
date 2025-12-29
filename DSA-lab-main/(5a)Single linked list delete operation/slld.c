#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *start = NULL;

void createList(int n) {
    int value;
    struct Node *newNode, *temp;

    for(int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i+1);
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;

        if(start == NULL) start = newNode;
        else {
            temp = start;
            while(temp->next != NULL) temp = temp->next;
            temp->next = newNode;
        }
    }
}
void deleteFirst() {
    if(start == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node *temp = start;
    start = start->next;
    printf("Deleted: %d\n", temp->data);
    free(temp);
}
void deleteatposition(int key) {
    struct Node *temp = start, *prev = NULL;
    int count=1;
    while(temp != NULL && count != key) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if(temp == NULL) {
        printf("Element not found!\n");
        return;
    }

    if(prev == NULL) start = temp->next;
    else prev->next = temp->next;

    printf("Deleted: %d\n", temp->data);
    free(temp);
}

void deleteLast() {
    if(start == NULL) {
        printf("List is empty!\n");
        return;
    }

    if(start->next == NULL) {
        printf("Deleted: %d\n", start->data);
        free(start);
        start = NULL;
        return;
    }

    struct Node *temp = start;
    while(temp->next->next != NULL)
        temp = temp->next;

    printf("Deleted: %d\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}

void display() {
    struct Node *temp = start;
    if(start == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("Linked List: ");
    while(temp != NULL) {
        printf("%d , ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    int choice, key, n;

    while(1) {
        printf("\n--- Singly Linked List Operations (Deletion) ---\n");
        printf("1. Create List\n2. Delete First\n3. Delete Specific\n4. Delete Last\n5. Display\n6. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                createList(n);
                break;

            case 2:
                deleteFirst();
                break;

            case 3:
                printf("Enter the position to delete: ");
                scanf("%d", &key);
                deleteatposition(key);
                break;

            case 4:
                deleteLast();
                break;

            case 5:
                display();
                break;

            case 6:
                exit(0);
                break;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
