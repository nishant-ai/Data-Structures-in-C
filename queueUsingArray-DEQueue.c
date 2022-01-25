#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

typedef struct dequeue{
    int q[SIZE];
    int FRONT;
    int REAR;
}DQ;

// Enqueue && Dequeue - F and R ) 4 + Display + Init + Overflow + Underflow
// _________________________
// | 1 | 2 | 3 | 4 | 5 | 6 | 
// -------------------------

void init(DQ* dq){
    dq->FRONT = -1;
    dq->REAR = -1;
}

int overflow(DQ* dq){
    if ( (dq->FRONT == 0 && dq->REAR == SIZE-1) || (dq->FRONT==dq->REAR+1) ){
        printf("Queue Overflow\n");
        return 1;
    }
    return 0;
}

int underflow(DQ* dq){
    if (dq->FRONT == -1 && dq->REAR == -1){
        printf("Queue Underflow\n");
        return 1;
    }
    return 0;
}

void enqueueFront(DQ* dq, int data){
    if (overflow(dq)) return; // overflow
    if (dq->FRONT == -1 && dq->REAR == -1) dq->FRONT = dq->REAR = 0; // if just started
    else if (dq->FRONT==0) dq->FRONT = SIZE-1; // edgecase
    else dq->FRONT--; // generalcase

    dq->q[dq->FRONT] = data;
}

void enqueueRear(DQ* dq, int data){
    if (overflow(dq)) return;
    if (dq->FRONT == -1 && dq->REAR == -1) dq->FRONT = dq->REAR = 0;
    else if (dq->REAR == SIZE-1) dq->REAR = 0;
    else dq->REAR++;

    dq->q[dq->REAR] = data;
}

int dequeueFront(DQ* dq, int data){ 
    if (underflow(dq)) return -1; // underflow
    int temp = dq->q[dq->FRONT];
    if (dq->FRONT == SIZE-1) dq->FRONT = 0;
    else dq->FRONT++;

    return temp;
}

int dequeueRear(DQ* dq, int data){
    if (underflow(dq)) return -1;
    int temp = dq->q[dq->REAR];
    if (dq->REAR == 0) dq->REAR = SIZE-1;
    else dq->REAR--;

    return temp;
}

void display(DQ* dq)  
{  
    int i=dq->FRONT;  
    printf("\n Elements in a deque : ");  
      
    while(i!=dq->REAR)  
    {  
        printf("%d ",dq->q[i]);  
        i=(i+1)%SIZE;  
    }  
    printf("%d",dq->q[dq->REAR]);  
}  

int main(){
    DQ* q = (DQ*)malloc(sizeof(DQ));
    init(q);
    enqueueFront(q, 10);
    enqueueRear(q, 20);
    enqueueFront(q, 30);
    display(q);

    return 0;
}