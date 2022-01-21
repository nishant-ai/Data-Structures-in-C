#include <stdio.h>
#include <stdlib.h>

typedef struct node{

    int data;
    struct node* next;

}Node;

void displayLinkedList(Node* start){
    while(start != NULL){
        printf("%d\t", start->data);
        start = start->next;
    }
}
 
// Linked List in C
int main(){
    Node n1;
    Node n2;
    Node n3;
    Node n4;
    Node* start = &n1;

    n1.data = 10; n2.data = 20; n3.data = 30; n4.data = 40;
    n1.next = &n2; n2.next = &n3; n3.next = &n4; n4.next = NULL;

    displayLinkedList(start);

    return 0;
}