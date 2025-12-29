#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createList(int n) {
    struct Node *start = NULL;
    struct Node *newNode, *temp;
    int value;

    if (n <= 0) {
        printf("Number of nodes must be positive.\n");
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed!\n");
            exit(1);
        }
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);
        newNode->data = value;
        newNode->next = NULL;

        if (start == NULL) {
            start = newNode;
        } else {
            temp = start;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    return start;
}

struct Node* concatenate(struct Node *h1, struct Node *h2) {
    if (h1 == NULL) return h2;
    if (h2 == NULL) return h1;

    struct Node *t = h1;
    while (t->next != NULL) {
        t = t->next;
    }
    t->next = h2;
    return h1;
}

struct Node* sortList(struct Node* head) {
    if (head == NULL) return NULL;

    struct Node *i, *j;
    int temp_data;

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp_data = i->data;
                i->data = j->data;
                j->data = temp_data;
            }
        }
    }
    return head;
}

struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void display(struct Node *head) {
    struct Node *temp = head;
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *start = NULL;
    struct Node *h1 = NULL, *h2 = NULL;
    int choice, n;

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Concatenate\n");
        printf("2. Sort\n");
        printf("3. Reverse\n");
        printf("4. Display (Current List)\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of elements in list 1: ");
                scanf("%d", &n);
                h1 = createList(n);
                printf("Enter the number of elements in list 2: ");
                scanf("%d", &n);
                h2 = createList(n);
                display(concatenate(h1, h2));
                break;
            case 2:
                printf("Enter the number of elements in the list to sort: ");
                scanf("%d", &n);
                start = createList(n);
                display(sortList(start));
                break;
            case 3:
                printf("Enter the number of elements in the list to reverse: ");
                scanf("%d", &n);
                start = createList(n);
                display(reverseList(start));
                break;
            case 4:
                display(start);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid Choice!\n");
        }
    }
    return 0;
}
