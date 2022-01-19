#include <stdio.h>
#include <stdlib.h>
#define SIZE 6

typedef struct stack{
    int TOP;
    int stack[SIZE];
}Stack;

void initStack(Stack* s){
    s->TOP = -1;
}

int overflow(Stack* s){
    if (s->TOP == SIZE-1){
        printf("Stack Overflow\n");
        return 1;
    }
    return 0;
}

int underflow(Stack* s){
    if (s->TOP == -1){
        printf("Stack Underflow\n");
        return 1;
    }
    return 0;
}

void push(Stack* s ,int data){
    if (overflow(s) == 1) return;
    s->TOP++;
    s->stack[s->TOP] = data;
}

int pop(Stack* s){
    int temp;
    if (underflow(s) == 1) return 0;
    temp = s->stack[s->TOP];
    s->TOP--;
    return temp;
}

void display(Stack* s){
    int i;
    if (underflow(s) == 1) return;
    for (i=s->TOP; i>=0; --i)
        printf("%d\t", s->stack[i]);
    printf("\n");
}

int main(){
    Stack* s = (Stack*)malloc(sizeof(Stack));
    initStack(s);
    int num = 0;
    int data;
    while(1){
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("\nEnter command : ");
        scanf("%d", &num);
        printf("\n");
        switch(num){
            case 1:
                printf("Enter element : ");
                scanf("%d", &data);
                push(s, data);
                break;
            
            case 2:
                printf("Popped : %d\n", pop(s));
                break;

            case 3:
                display(s);
                break;

            case 4:
                return 0;
        }
    }
    return 0;
}