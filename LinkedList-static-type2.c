#include <stdio.h>
#include <stdlib.h>

typedef struct node{

    int data;
    struct node* next;

}Node;
 
// Linked List in C
int main(){
    Node* head;
    Node* n1;
    Node* n2;
    Node* n3;

    // Memory Allocation
    head = (Node*)malloc(sizeof(Node));
    n1   = (Node*)malloc(sizeof(Node));
    n2   = (Node*)malloc(sizeof(Node));
    n3   = (Node*)malloc(sizeof(Node));

    // Passing data and address
    head->data = 10;  head->next = n1;
    n1->data   = 20;    n1->next = n2;
    n2->data   = 30;    n2->next = n3;
    n3->data   = 40;    n3->next = NULL;

    // displayLinkedList(head);
    printf("%d\t", head->data);
    printf("%d\t", n1->data);
    printf("%d\t", n2->data);
    printf("%d\n", n3->data);

    return 0;
}