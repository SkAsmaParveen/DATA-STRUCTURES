#include<stdio.h>
#include<stdlib.h>
#define n 5

int CQue[n], front = -1, rear = -1;

void Enqueue(int ele)
{
    if((rear+1) % n == front)
    {
        printf("QUEUE IS FULL !");
        return;
    }
    rear = (rear+1) % n;
    CQue[rear] = ele;
    if(front == -1)   front = 0;
}

int Dequeue()
{
    int temp;
    if(front == -1 && rear == -1) {
        printf("QUEUE IS EMPTY !");
        return -99; //This means deletion not possible
    }  
    temp = CQue[front]; 
    if(front == rear) //if only one ele is left,both f and r pointing to same ele
    {
        front = rear = -1;
    }
    else
    {
        front = (front+1) % n;
    }
    return temp;;
}

void print_queue()
{
    int i = front;
    if(front == -1 && rear == -1) {
        printf("QUEUE IS EMPTY !");
        return;
    }
    while(i != rear)
    {
        printf("%d ",CQue[i]);
        i = (i+1) % n;
    }
    printf("%d ",CQue[i]);
}

int main()
{
    Enqueue(9);
    Enqueue(23);
    Enqueue(88);
    Enqueue(1);
    Enqueue(333);
    Dequeue();
    print_queue();
}