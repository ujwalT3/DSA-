
#include<stdio.h>
#define max 5
int qu[max];
int f=-1,r=-1;
void insert(int val)
{
    if(r==max-1)
    {
        printf("Queue Overflow!Cannot insert%d\n",val);
    }
    else
    {
        if(f==-1)
        {
            f=0;
        }
        r++;
        qu[r]=val;
        printf("%d inserted into the queue",val);
    }
}
void first()
{
    printf("%d is the front element",qu[f]);
}
void rear()
{
    printf("%d is the rear element",qu[r]);
}
void Delete()
{
    if(f==-1||f>r)
    {
        printf("Queue Underflow! Queue is empty\n");
    }
    else
    {
        printf("Deleted element:%d\n",qu[f]);
        f++;
    }
}
void display()
{
    if   (f==-1||f>r)
    {
        printf("Queue is empty.\n");

    }
    else
    {
        printf("queue Elements:");
        for(int i=f;i<=r;i++)
        {
            printf("%d",qu[i]);
            printf("  ");
        }
        printf("\n");
    }
}
int main()
{
    int choice,val;
    while(1)
    {
        printf("\n Queue Operation:\n");\
        printf("1.insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.front\n");
        printf("5.rear\n");
        printf("6.Exit\n");

        printf("enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            {
                printf("Enter value to insert:");
                scanf("%d",&val);
                insert(val);
                break;
            }
        case 2:
            {
                Delete();
                break;
            }
        case 3:
            {
                display();
                break;
            }
            case 4:
            {
                first();
                break;
            }
            case 5:
            {
                rear();
                break;
            }
        case 6:
            {
                printf("Exiting the menue");
                return 0;
            }
        default:
            {
                printf("Wrong input:");
            }
        }

    }
    return 0;
}

