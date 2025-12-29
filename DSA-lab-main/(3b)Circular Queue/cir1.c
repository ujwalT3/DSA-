#include <stdio.h>
#define s 5

int f = -1, r = -1;
int a[s];

void enq(int x) {
    if ((r + 1) % s == f) {
        printf("Queue is full\n");
    } else {
        if (f == -1) f = 0;
        r = (r + 1) % s;
        a[r] = x;
    }
}

void deq() {
    if (f == -1) {
        printf("Empty queue\n");
    } else {
        printf("Dequeued: %d\n", a[f]);
        if (f == r) {
            f = -1;
        } else {
            f = (f + 1) % s;
        }
    }
}

void display() {
    if (f == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements:\n");
        int i = f;
        while (i != r) {
            printf("%d\n", a[i]);
            i = (i + 1) % s;
        }
        printf("%d\n", a[r]);
    }
}

int main() {
    char c;
    do {
        printf("\nEnter your choice:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nChoice: ");
        scanf(" %c", &c);
        switch (c) {
            case '1': {
                int val;
                printf("Enter element: ");
                scanf("%d", &val);
                enq(val);
                break;
            }
            case '2':
                deq();
                break;
            case '3':
                display();
                break;
            case '4':
                printf("Exiting...\n");
                break;
            default:
                printf("Wrong choice\n");
        }
    } while (c != '4');

    return 0;
}
