#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 20

int stack[size] , top = -1;
char arr[size];

void push(int ele) 
{
    if(top == size-1)
        printf("STACK IS FULL !");
    else {
        top++;
        stack[top] = ele;
    }
}
int pop()
{
    if(top == -1)
        return -1;
    else {
        return stack[top--];
    }
}
int peak()
{
    if(top != -1)
        return stack[top]; 
    return -1;
}

int main()
{
    char symbol;
    double res,n1,n2,k;
    printf("ENTER THE POSTFIX EXPRESSION :");
    gets(arr);
    for(int i=0; arr[i] != '\0'; i++)
    {
        symbol = arr[i];
        switch(symbol)
        {
            case '+':
                n1 = pop();
                n2 = pop();
                push(n1+n2);
                break;
            case '-':
                n1 = pop();
                n2 = pop();
                res = n1-n2;
                push(res);
                break;
            case '*':
                n1 = pop();
                n2 = pop();
                res = n1*n2;
                push(res);
                break;
            case '/':
                n1 = pop();
                n2 = pop();
                res = n1/n2;
                push(res);
                break;
            default:
                k = symbol-'0';
                push(k);
        }
    }
    printf("%d",peak());
}
