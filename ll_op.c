
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
struct node *head2 = NULL;
void create()
{
    struct node *newnode, *temp;
    int n, i;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        newnode = malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL)
            head = temp = newnode;
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
}
void create_second()
{
    struct node *newnode, *temp;
    int n, i;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        newnode = malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (head2 == NULL)
            head2 = temp = newnode;
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
}
void sort()
{
    struct node *ptr, *temp;
    int t;
    for (ptr = head; ptr != NULL; ptr = ptr->next)
    {
        for (temp = ptr->next; temp != NULL; temp = temp->next)
        {
            if (ptr->data > temp->data)
            {
                t = ptr->data;
                ptr->data = temp->data;
                temp->data = t;
            }
        }
    }
}
void reverse()
{
    struct node *prev = NULL, *current = head, *next;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
void concatenate()
{
    struct node *temp;

    if (head == NULL)
    {
        head = head2;
        return;
    }
    temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head2;
}
void display()
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main()
{
    int choice;
    while (1)
    {
        printf("\n1. Create First List");
        printf("\n2. Create Second List");
        printf("\n3. Sort");
        printf("\n4. Reverse");
        printf("\n5. Concatenate");
        printf("\n6. Display");
        printf("\n7. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                create();
                break;
            case 2:
                create_second();
                break;
            case 3:
                sort();
                printf("List sorted\n");
                break;
            case 4:
                reverse();
                printf("List reversed\n");
                break;
            case 5:
                concatenate();
                printf("Lists concatenated\n");
                break;
            case 6:
                display();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
