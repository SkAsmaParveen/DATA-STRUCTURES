#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 100

char stack[size]; //here we're taking char as it contains both nums and operators
char infix[size] , postfix[size];
int top = -1;

//PRECEDENCE FUNCTION

int precedence(char symbol)
{
    switch(symbol)
    {
        //Higher value means higher precedence
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

/*
int space(char c)
{
    ...if the symbol is white space or tab
    if(c == ' ' || c == '\t')
        return 1;
    else 
        return 0;
} */

void Infix_to_post()
{
    int j = 0;
    char symbol, next;
    for(int i=0; i<strlen(infix); i++)
    {
        //if the symbol is not a white space
        symbol = infix[i]; //assigning each symbol of infix array to symbol variable
        switch(symbol)
        {
            case '(':
                push(symbol);
                break;
            case ')':
                while((next = pop() != '(')) //excluding '(' pop and store in postfix array)
                postfix[j++] = next;
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while(!isEmpty() && precedence(stack[top]) >= precedence(symbol))
                    postfix[j++] = pop();
                push(symbol);
                break;
            default:
                postfix[j++] = symbol; // condition for operands like 2,3 ...
        }
    }

    //at the end print and store all the operators left in the postfix array...

    while(!isEmpty())
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0'; //its a convention as it is a string
}


void print_postfix()
{
    printf("OUR RESULTANT POSTFIX EXPRESSION IS:: ");
    while(postfix[i]) {
        printf("%c",postfix[i++]);
    }
    printf("\n");
}

int main()
{
    printf("ENTER THE INFIX EXPRESSION :: ");
    gets(infix);

    Infix_to_post();

    print_postfix();
    return 0;
}

