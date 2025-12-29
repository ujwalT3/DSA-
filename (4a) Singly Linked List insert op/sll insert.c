#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* next;
};

struct node* start = NULL;

struct node* insertsllbeg(int item, struct node* start) {
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->info = item;
    p->next = start;
    start = p;
    return start;
}

struct node* insertsllend(int item, struct node* start) {
    struct node *p, *temp;
    p = (struct node*)malloc(sizeof(struct node));
    p->info = item;
    p->next = NULL;

    if (start == NULL) {
        return p;
    } else {
        temp = start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = p;
    }
    return start;
}

struct node* insertsllinp(int item, struct node* start, int pos) {
    struct node *p, *temp;
    p = (struct node*)malloc(sizeof(struct node));
    p->info = item;

    if (pos == 1 || start == NULL) {
        p->next = start;
        return p;
    }

    temp = start;
    for (int i = 1; i < pos - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }

    p->next = temp->next;
    temp->next = p;
    return start;
}

void display(struct node* start) {
    struct node* temp = start;
    if (temp == NULL) {
        printf("The SLL is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int it, pos, c;
    while (1) {
        printf("\n1. Insert Beg\n2. Insert End\n3. Insert Pos\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);

        if (c == 5) break;

        switch (c) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &it);
                start = insertsllbeg(it, start);
                break;
            case 2:
                printf("Enter element: ");
                scanf("%d", &it);
                start = insertsllend(it, start);
                break;
            case 3:
                printf("Enter element: ");
                scanf("%d", &it);
                printf("Enter position: ");
                scanf("%d", &pos);
                start = insertsllinp(it, start, pos);
                break;
            case 4:
                display(start);
                break;
            default:
                printf("Wrong key!\n");
        }
    }
    return 0;
}
