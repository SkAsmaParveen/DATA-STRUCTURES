#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 20

char stack[size] ,arr[size];
int top = -1;

void push(char ele)
{
    if(top == size-1) {
        printf("STACK IS FULL!");
    }
    else {
        top++;
        stack[top] = ele;
    }
}

char pop()
{
    if(top == -1) {
        return -1;
    }
    else {
        return stack[top--];
    }
}

char peek()
{
    if(top != -1) {
        return stack[top];
    }
    return -1;
}

int main()
{
    char symbol;
    printf("ENTER THE EXPRESSION TO CHECK : ");
    gets(arr);
    for(int i=0; arr[i] != '\0'; i++) {
        symbol = arr[i];
        if(symbol == ')') {
            if(peek() == ')')
                pop();
            else {
                printf("INVALID EXPRESSION !");
                break;
            }
        }
        else if(symbol == '}') {
            if(peek() == '{')
                pop();
            else {
                printf("INVALID EXPRESSION !");
                break;
            }
        }
        else if(symbol == ']') {
            if(peek() == '[')
                pop();
            else {
                printf("INVALID EXPRESSION !");
                break;
            }
        }
        else if(symbol == '(' || symbol == '{' || symbol == '[') {
            push(symbol);
        }
    } 
    if(top != -1)
    {
        printf("INVALID EXPRESSION!");
    }
    else {
        printf("VALID EXPRESSION !");
    }

    
    return 0;
}
