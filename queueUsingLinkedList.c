#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node* next;
    int val;
}Node;

Node* FRONT=NULL;
Node* REAR=NULL;

Node* getNode(){
    Node* newNode = (Node*)malloc(sizeof(Node));
    return newNode;
}

void enqueue(int data){
    Node* newNode = getNode();
    // Overflow
    if (newNode == NULL){
        printf("Queue Overflow\n");
        return;
    }

    newNode->next = NULL;
    newNode->val = data;

    if (FRONT == NULL && REAR == NULL) FRONT = REAR = newNode;

    else{
        REAR->next = newNode;
        REAR = newNode;
    }

}

int dequeue(){
    Node* temp = FRONT;
    int retVal = -1;

    if (FRONT == NULL){
        printf("Queue Underflow\n");
        return retVal;
    }

    temp = FRONT; 
    retVal = temp->val;
    FRONT = FRONT->next;
    free(temp);

    return retVal;
}

void display(){
    Node* temp = FRONT;

    if (FRONT == NULL){
        printf("Queue is Empty\n");
        return;
    }

    while (temp != NULL){
        printf("%d | ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    enqueue(10);
    enqueue(20);
    display();
    enqueue(30);
    display();
    dequeue();
    display();
    dequeue();
    display();
    dequeue();
    display();

    return 0;
}