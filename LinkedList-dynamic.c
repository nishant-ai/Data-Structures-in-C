#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

// GET NODE, CREATE LINKED LIST, DISPLAY, INSERT FRONT, INSERT END, INSERT GENERAL, DELETE NODE

Node* createLinkedList(){
    Node* head = NULL;
    return head;
}

Node* getNode(){
    Node* newNode = (Node*)malloc(sizeof(Node));
    return newNode;
}

Node* insertGeneral(Node* head, int data, int posvalue){
    Node* newNode = getNode();
    Node* temp = head;

    // Overflow
    if (newNode == NULL){
        printf("Linked List Overflow");
        return head;
    }

    while (temp->next!= NULL && temp->data != posvalue){
        temp = temp->next;
    }

    if (temp == NULL){
        printf("Pos Error - No position matches the input\n");
        return head;
    }

    newNode->data = data;
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

Node* insertFront(Node* head, int data){
    Node* newNode = getNode();

    // Overflow
    if (newNode == NULL){
        printf("Linked List Overflow");
        return head;
    }

    Node* temp = head;
    head = newNode;
    newNode->data = data;
    newNode->next = temp;

    return head;
}

Node* insertEnd(Node* head, int data){
    Node* newNode = getNode();
    Node* temp = head;
    // Overflow
    if (newNode == NULL){
        printf("Linked List Overflow");
        return head;
    }

    newNode->data = data;

    if (head==NULL){
        head = newNode;
        newNode->next = NULL;
        return head;
    }

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = NULL;

    return head;
}

Node* deleteFront(Node* head){
    Node* temp;

    if (head == NULL){
        printf("Linked List Empty\n");
        return head;
    }

    temp = head;
    head = head->next;
    free(temp);
    
    return head;
}

Node* deleteEnd(Node* head){
    Node *temp1, *temp2;

    if (head==NULL){
        printf("Linked List Empty\n");
        return head;
    }

    else if (head->next == NULL){
        head=NULL;
        free(head);
    }

    else {
        temp1 = head;
        temp2 = head->next;
        while(temp2->next!= NULL){
            temp1 = temp2;
            temp2 = temp2->next;
        }
        temp1->next = NULL;
        free(temp2);
    }
    return head;
}

Node* deleteGeneral(Node* head, int posvalue){
    Node* temp2 = head;
    Node* temp1;
    
    while (temp2 != NULL && temp2->data != posvalue){
        temp1 = temp2;
        temp2 = temp2->next;
    }

    if (temp2->next == NULL && temp2->data != posvalue){
        printf("Pos Error - No position matches the input\n");
        return head;
    }

    temp1->next = temp2->next;
    free(temp2);

    return head;
}

void display(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    Node* head = createLinkedList();
    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    head = insertEnd(head, 40);
    head = insertEnd(head, 50);
    // head = insertFront(head, 5);
    // head = deleteEnd(head);
    // head = deleteFront(head);
    head = deleteGeneral(head, 20); // NOT WORKING
    head = insertGeneral(head, 15, 20); // NOT WORKING
    display(head);

    return 0;
}