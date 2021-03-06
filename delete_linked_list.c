#include <stdio.h>
#include <stdlib.h>

struct node
    {
    int data;
    struct node *next;
    };

display(struct node *head)
    {
    if(head == NULL)
        {
        printf("NULL\n");
        }
    else
        {
        printf("%d ", head -> data);
        display(head->next);
        }
    }

del (struct node *before_del)
    {
    struct node *temp;
    temp = before_del->next;
    before_del->next = temp->next;
    free(temp);
    }

int main()
    {
    struct node *prev,*head, *p;
    int i;

    head=NULL;

    for(i=0;i<6;i++)
        {
        p=malloc(sizeof(struct node));
        scanf("%d",&p->data);
        p->next=NULL;
        if(head==NULL)
        head=p;
        else
            prev->next=p;
            prev=p;
        }

    del(head->next);
    display(head);

return 0;
}
