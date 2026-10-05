#include<stdio.h>
#define MAX 5
int main()
{

    int q[MAX];
    int front=-1, rear=-1;
    int choice,item,i;
    while(1)
    {
        printf("--Patient Queue Management System--\n");
        printf("1.Insert Patient 2.Delete patient 3.Display patient 4.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
            {
            case 1:
                if(rear==MAX-1)
                    printf("Queue overflow\n");
                else{
                    printf("Enter patient id\n");
                    scanf("%d",&item);
                    if(front==-1)
                        front=0;
                    rear++;
                    q[rear]=item;
                    printf("Patient added\n");
                }
                break;
            case 2:
                if (front==-1||front>rear)
                    printf("Queue underflow\n");
                else{
                    printf("Patient removed with ID %d\n",q[front]);
                    front++;
                    if(front>rear){
                        front=-1;
                        rear=-1;
                    }
                }
                break;
            case 3:
                if(front==-1)
                    printf("Queue is empty\n");
                else{
                    printf("Queue elements:\n");
                    for(i=front;i<=rear;i++)
                        printf("%d\n",q[i]);
                }
                    break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
                }
            }
    }
