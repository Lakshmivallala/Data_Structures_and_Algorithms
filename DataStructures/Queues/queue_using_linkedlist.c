//Queue implementation using linked list

#include<stdio.h>
#include<stdlib.h>

/* ----------NODE---------- */

struct Node {
    int data;
    struct Node *next;
};

struct Node *REAR = NULL;
struct Node *FRONT = NULL;
void enqueue(int x);
void dequeue();
void rear();
void printQueue();
int isEmpty();

int main() {
    rear();
    enqueue(1);
    enqueue(2);
    enqueue(3);
    printQueue();
    dequeue();
    printQueue();
}

int isEmpty() {
    if(REAR==NULL) return 1;
    return 0;
}

void enqueue(int x) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if(isEmpty()) {
        REAR = temp;
        FRONT = temp;
        return;
    }
    REAR->next = temp;
    REAR = temp;
}

void dequeue() {
    struct Node *temp = FRONT;
    if(isEmpty()) return;
    FRONT = FRONT->next;
    free(temp);
}

void rear() {
    if(isEmpty()) {
        printf("The list is empty\n");
        return;
    }
    printf("Rear = %d\n", REAR->data);
}

void printQueue() {
    struct Node *temp = FRONT;
    while(temp!=NULL) {
        printf("%d ", (temp->data));
        temp = temp->next;
    }
    printf("\n");
}
