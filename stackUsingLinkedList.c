#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

//getNode initStack Display Push Pop Peek

Node* getNode(){
    Node* newNode = (Node*)malloc(sizeof(Node));
    return newNode;
}

Node* initStack(Node* head){
    head = NULL;
    return head;

}

Node* push(Node* head, int data){
    Node* newNode = getNode();

    // Overflow
    if (newNode == NULL){
        printf("Stack Overflow\n");
        return head;
    }

    newNode->next = head;
    newNode->data = data;
    head = newNode;

    return head;
}


void display(Node* head){
    Node* temp = head;

    if (head == NULL){
        printf("Stack Empty\n");
        return;
    }

    while (temp!=NULL){
        printf("%d | ", temp->data);
        temp = temp->next;
    }
    printf("\b\b\b\n");
}

Node* pop(Node* head){
    Node* temp = head;

    if (head == NULL){
        printf("Stack Undeflow\n");
        return head;
    }

    head = head->next;
    free(temp);
    return head;
}

int peek(Node* head){
    return head->data;
}

int main(){
    Node* head = initStack(head);
    head = push(head, 10);
    head = push(head, 20);
    head = push(head, 30);
    display(head);
    head = pop(head);
    display(head);
    printf("%d\n", peek(head));

    return 0;
}