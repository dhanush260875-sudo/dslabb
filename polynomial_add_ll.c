
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coeff;
    int pow;
    struct node *next;
};
struct node *create()
{
    struct node *head = NULL, *temp, *newnode;
    int n, i;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        newnode = malloc(sizeof(struct node));
        printf("Enter coefficient and power: ");
        scanf("%d%d", &newnode->coeff, &newnode->pow);
        newnode->next = NULL;
        if (head == NULL)
            head = temp = newnode;
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}
void append(struct node **head, int coeff, int pow)
{
    struct node *newnode, *temp;
    newnode = malloc(sizeof(struct node));
    newnode->coeff = coeff;
    newnode->pow = pow;
    newnode->next = NULL;
    if (*head == NULL)
        *head = newnode;
    else
    {
        temp = *head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
    }
}
struct node *add(struct node *p1, struct node *p2)
{
    struct node *p3 = NULL;
    int sum;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->pow == p2->pow)
        {
            sum = p1->coeff + p2->coeff;
            if (sum != 0)
                append(&p3, sum, p1->pow);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->pow > p2->pow)
        {
            append(&p3, p1->coeff, p1->pow);
            p1 = p1->next;
        }
        else
        {
            append(&p3, p2->coeff, p2->pow);
            p2 = p2->next;
        }
    }
    while (p1 != NULL)
    {
        append(&p3, p1->coeff, p1->pow);
        p1 = p1->next;
    }
    while (p2 != NULL)
    {
        append(&p3, p2->coeff, p2->pow);
        p2 = p2->next;
    }
    return p3;
}
void display(struct node *head)
{
    while (head != NULL)
    {
        printf("%dx^%d", head->coeff, head->pow);

        head = head->next;

        if (head != NULL)
            printf(" + ");
    }
    printf("\n");
}
int main()
{
    struct node *p1, *p2, *p3;
    printf("Enter first polynomial:\n");
    p1 = create();
    printf("Enter second polynomial:\n");
    p2 = create();
    printf("\nFirst Polynomial: ");
    display(p1);
    printf("Second Polynomial: ");
    display(p2);
    p3 = add(p1, p2);
    printf("Addition: ");
    display(p3);
    return 0;
}
