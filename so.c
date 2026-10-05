#include<stdio.h>
int max=5;
int stack[10];
int top=-1;
void push()
{
    int value;
    if(top==max-1)
    {
        printf("stack overflow");
    }
    else
    {
        printf("enter the value:");
        scanf("%d",&value);
        top++;
        stack[top]=value;
        printf("%d pushed into stack ",value);
    }
}
void pop()
{
    if (top==-1)
    {
        printf("stack underflow");
    }
    else
    {
        printf("%d popped out",stack[top]);
        top--;
    }
}
void display()
{
    int i;if(top==-1)
    {
        printf("stack is empty");
    }
    else
    {
        printf("stack elements are");
        for(i=top;i>=0;i--)
        {
            printf("%d\n",stack[i]);
        }
    }
}
int main()
{
    int choice;
    while(1)
    {
        printf("\n-----stack menu-------");
        printf("\n1.push");
        printf("\n2.pop");
        printf("\n3.display");
        printf("\n4.exit");
        printf("\nenter the choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            push();
            break;
         case 2:
            pop();
            break;
         case 3:
            display();
            break;
         case 4:
          return 0;
         default:
             printf("invalid");
        }
    }
}

