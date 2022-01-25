#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

// circular queue
typedef struct queue{
    int queue[SIZE];
    int FRONT;
    int REAR;
}Queue;

void initQueue(Queue* q){
    q->FRONT = -1;
    q->REAR = -1;
}

int underflow(Queue* q){
    if (q->FRONT == q->REAR || q->FRONT == -1){
        printf("Queue Underflow\n");
        return 1;
    }
    return 0;
}

int overflow(Queue* q){
    if (q->FRONT == q->REAR+1 || (q->REAR == SIZE-1 && q->FRONT == 0)){
        printf("Queue Overflow\n");
        return 1;
    }
    return 0;
}

// ENQUEUE DEQUEUE DISPLAY
void enqueue(Queue* q,int data){
    if (overflow(q)) return;
    if (q->FRONT==-1) q->FRONT++;
    if (q->REAR == SIZE-1) q->REAR = -1;
    q->REAR++;
    q->queue[q->REAR] = data;
}

int dequeue(Queue* q){
    if (underflow(q)) return -1;
    int temp = q->queue[q->FRONT];
    if (q->FRONT == SIZE-1) q->FRONT = 0;
    else if (q->FRONT == q->REAR) { q->FRONT = -1; q->REAR = -1; }
    else q->FRONT++;
    return temp;
}

void display(Queue* q){
    int i = q->FRONT;
    if (underflow(q)) return;

    if (q->REAR < q-> FRONT){
        while(i <= SIZE-1){
            printf("%d ", q->queue[i]);
            i++;
        }
        i=0;
        while(i <= q->REAR){
            printf("%d ", q->queue[i]);
            i++;
        }
    }
    else{
        while(i <= q->REAR){
            printf("%d ", q->queue[i]);
            i++;
        }
    }

}

int main(){
    Queue queue1;
    int operation;
    int element;

    printf("\n");
    printf("Enter value for following functions : \n");
    printf("Enter 1 to create a queue\n");
    printf("Enter 2 to display a queue\n");
    printf("Enter 3 to enter an element to the queue\n");
    printf("Enter 4 to delete element from queue\n");
    printf("Enter 5 to exit the program\n");

    while (1==1){

        printf("=> ");
        scanf("%d", &operation);

        switch(operation){
            case(1):
                initQueue(&queue1);
                break;
            case(2):
                display(&queue1);
                break;
            case(3):
                printf("Enter element to insert : ");
                scanf("%d", &element);
                enqueue(&queue1, element);
                break;
            case (4):
                dequeue(&queue1);
                break;
            case(5):
                return 0;
            default:
                printf("Command Not Found!\n");
                return 0;
        }

    }
    printf("\n");




    return 0;
}