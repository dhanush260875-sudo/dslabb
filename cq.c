#include<stdio.h>
#define MAX 5
int main()
{
    int q[MAX];
    int front=-1, rear=-1;
    int choice,item,i;
    while(1)
    {
        printf("--Circular Queue--\n");
        printf("1.Insert 2.Delete 3.Display 4.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
            {
            case 1:
                if((rear+1)%MAX==front)
                    printf("Queue overflow\n");
                else{
                    printf("Enter item\n");
                    scanf("%d",&item);
                    if(front==-1){
                      front=0;
                      rear=0;
                    }
                    else{
                        rear=(rear+1)%MAX;
                    }
                    q[rear]=item;
                    printf("Item inserted\n");
                }
                break;
            case 2:
                if (front==-1)
                    printf("Queue underflow\n");
                else{
                    item=q[front];
                    printf("Deleted %d\n",q[front]);
                    if(front==rear){
                        front=-1;
                        rear=-1;
                    }
                else{
                    front=(front+1)%MAX;
                }
                }
                break;
            case 3:
                if(front==-1)
                    printf("Queue is empty\n");
                else{
                    printf("Queue elements:\n");
                    i=front;
                    while(1){
                        printf("%d\n",q[i]);
                        if(i==rear)
                            break;
                        i=(i+1)%MAX;
                    }
                }
                    break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
                }
            }
    }

