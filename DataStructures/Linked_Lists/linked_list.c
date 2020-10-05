#include <stdio.h>
#include <stdlib.h>

/* ----------NODE---------- */

struct Node
{
    int data;
    struct Node *next;
};

struct Node *HEAD = NULL;

/* ----------PRINTING---------- */

void print_list()
{
    struct Node *temp = HEAD;
    if(temp==NULL)
    {
        printf("\tThere are no elements in the list\n");
        return;
    }
    printf("\tThe elements in the list:\n\t");
    while(temp->next!=NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("%d", temp->data);
}

void recursive_print(struct Node *current)
{
    if(current==NULL){
        printf("\n");
        return;
    }
    printf("%d ", current->data);
    recursive_print(current->next);
}

void recursive_reverse_print(struct Node *current)
{
    if(current==NULL)
    {
        printf("\n");
        return;
    }
    recursive_reverse_print(current->next);
    printf("%d ", current->data);
}

/* ----------INSERTION---------- */

void insert_beginning()
{
    int x;
    printf("\tEnter the value: ");
    scanf("%d", &x);
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = HEAD;
    HEAD = temp;
}

void insert_at()
{
    int x, loc;
    printf("\tEnter the value and location: ");
    scanf("%d %d", &x, &loc);
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    struct Node *current = HEAD;
    if(HEAD==NULL && loc>1)
    {
        printf("\tThe list is empty");
        return;
    }
    if(loc==1)
    {
        temp->next = HEAD;
        HEAD = temp;
        return;
    }
    else if(loc<1)
    {
        printf("\tLocation should be greater than 0");
        return;
    }
    for(int i=1; i<loc-1; i++)
    {
        if(current==NULL)
        {
            printf("\tLocation not in range");
            return;
        }
        current = current->next;
    }
    temp->next = current->next;
    current->next = temp;
}

void insert_end()
{
    int x;
    printf("\tEnter the value: ");
    scanf("%d", &x);
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if(HEAD==NULL)
    {
        HEAD = temp;
        return;
    }
    struct Node *current = HEAD;
    while(current->next!=NULL)
    {
        current = current->next;
    }
    current->next = temp;
}

/* ----------DELETING---------- */

void delete_at()
{
    if(HEAD==NULL)
    {
        printf("\tList is empty");
        return;
    }
    int x;
    printf("\tEnter the position: ");
    scanf("%d", &x);
    struct Node *temp = HEAD;
    if(x<1)
    {
        printf("\tLocation not available");
        return;
    }
    else if(x==1)
    {
        HEAD = temp->next;
        free(temp);
        return;
    }
    for(int i=1; i<x-1; i++)
    {
        if(temp->next->next==NULL)
        {
            printf("\tLocation not found");
            return;
        }
        temp = temp->next;
    }
    struct Node *del = temp->next;
    temp->next = del->next;
    free(del);
}

/* ----------REVERSE---------- */

void reverse_list()
{
    struct Node *prevNode, *curNode;
    if(HEAD != NULL)
    {
        prevNode = HEAD;
        curNode = HEAD->next;
        HEAD = HEAD->next;
        prevNode->next = NULL;
        while(HEAD != NULL)
        {
            HEAD = HEAD->next;
            curNode->next = prevNode;
            prevNode = curNode;
            curNode = HEAD;
        }
        HEAD = prevNode;
    }
    else
    {
        printf("\tThe list is empty");
    }
}

void recursive_reverse(struct Node *current)
{
    if(current->next==NULL)
    {
        HEAD = current;
        return;
    }
    current->next->next = current;
    current->next = NULL;
}

/* ----------MAIN---------- */

int main()
{
    printf("----------LINKED LIST----------");
    while(1)
    {
        int n;
        printf("\n\n1.  Insert at the beginning\n2.  Insert at a position\n3.  Insert in the end\n4.  Print the list\n5.  Delete at a position\n6.  Reverse\n-1. Exit\n\nEnter your choice: ");
        scanf("%d", &n);
        switch (n)
        {
            case 1:
                insert_beginning();
                break;
            case 2:
                insert_at();
                break;
            case 3:
                insert_end();
                break;
            case 4:
                print_list();
                break;
            case 5:
                delete_at();
                break;
            case 6:
                reverse_list();
                break;
            case -1:
                exit(1);
            default:
                printf("Choose from the above options...\n");
        }
    }
}
