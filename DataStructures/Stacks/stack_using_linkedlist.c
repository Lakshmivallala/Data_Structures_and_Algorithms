//Stack implementation using linked list

#include<stdio.h>
#include<stdlib.h>

/* ----------NODE---------- */

struct Node {
    int data;
    struct Node *next;
};

struct Node *HEAD = NULL;
void push(int x);
void pop();
void top();
void printStack();
int isEmpty();

int main() {
    top();
    push(0);
    push(1);
    top();
    push(3);
    push(2);
    printStack();
    pop();
    printStack();
}

/* ----------PUSH---------- */

void push(int x) {
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = HEAD;
    HEAD = temp;
}

/* ----------POP---------- */

void pop() {
    struct Node *temp = HEAD;
    if(temp==NULL) return;
    HEAD = temp->next;
    free(temp);
}

/* ----------TOP---------- */

void top() {
    if(isEmpty()) {
        printf("The list is empty\n");
        return;
    }
    printf("Top = %d\n", HEAD->data);
}

/* ----------PRINTING---------- */

void printStack() {
    struct Node *temp = HEAD;
    while(temp!=NULL) {
        printf("%d ", (temp->data));
        temp = temp->next;
    }
    printf("\n");
}

int isEmpty() {
    if(HEAD==NULL) return 1;
    return 0;
}
