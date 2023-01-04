#include<stdio.h>
#include<stdlib.h>
#define size 5

int Queue[size], rear = -1, front = -1;

void Enqueue(int ele)
{
    if(rear == size-1)
    {
        printf("QUEUE IS FULL !"); //overflow
        return;
    }
    rear++;
    Queue[rear] = ele; //insertion => rear
    if(front == -1)    front++;
}

int Dequeue()
{
    if(front == -1 && rear == -1) {
        printf("QUEUE IS EMPTY !");
        return -99; //underflow
    }
    front++;
    return Queue[front];
}

void print_queue()
{
    if(front == -1 && rear == -1)
    {
        printf("QUEUE IS EMPTY !");
        return;
    }
        for(int i=front; i<=rear; i++)
        {
            printf("%d ",Queue[i]);
        }
        printf("\n");
}


void peek()
{
    if(front == -1 && rear == -1) {
        printf("QUEUE IS EMPTY !");
        return;
    }
    else {
        printf("%d ",Queue[front]); //display the front ele
    }
}

int main()
{
    Enqueue(2);
    Enqueue(3);
    Enqueue(-1);
    print_queue();
    Dequeue();
    print_queue();
    peek();
    
}

OUTPUT:
2 3 -1
3 -1
3 
