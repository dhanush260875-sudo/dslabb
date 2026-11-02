#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
int main(void)
{
    struct Node *first, *second, *third, *temp;
    first = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    first->data = 10;
    second->data = 20;
    third->data = 30;
    first->next = second;
    second->next = third;
    third->next = NULL;
    printf("First node : %d\n", first->data);
    printf("Second node : %d\n", second->data);
    printf("Third node : %d\n", third->data);
    printf("Linked list : ");
    temp = first;
    while (temp != NULL) {
    printf("%d -> ", temp->data);
    temp = temp->next;
}
printf("NULL\n");
free(first);
free(second);
free(third);
return 0;
}
