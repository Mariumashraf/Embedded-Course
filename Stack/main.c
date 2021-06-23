#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include <D:\Embedded-Course\Stack\types.h>
#define SIZE 100
#define ESC 27

//Functions
void push(uint8_t);
uint8_t pull(void);
void printStack(void);
uint8_t* balancedParentheses(uint8_t*);


char expression[SIZE];
int tos ;
int i;

//Push to stack
void push(uint8_t u8_data)
{
    if(tos >= SIZE-1)
    {
        printf("\nSTACK is full");

    }
    else
    {
        tos++;
        expression[tos]=u8_data;
    }
}


//Pull from stack
uint8_t pull()
{
    char temp;
    if(tos == -1)
    {
        printf("\nSTACK is empty");

    }
    else
    {
        tos--;
        temp = expression[tos];
    }
    return temp;
}


//Print stack
void printStack()
{
    if(tos > -1)
    {
        printf("Elements in Stack:");
        for(i = tos; i >= 0; i--)
        {
            printf("%c",expression[i]);
        }
    }
    else
    {
        printf("Stack is empty");
    }
}


//Check for balanced parentheses
uint8_t* balancedParentheses(uint8_t* expression)
{
    for(i = 0; i < strlen(expression); i++)
    {
        if(expression[i] == '(' || expression[i] == '[' || expression[i] == '{')
        {
            push(expression[i]);
        }
        else if(expression[i] == ')' || expression[i] == ']' || expression[i] == '}')
        {
            if(expression[i] == ')')
            {
                if(expression[tos] == '(')
                {
                    pull();
                }
                else
                {
                    printf("\nNot BALANCED\n");
                    break;
                }
            }
            if(expression[i] == ']')
            {
                if(expression[tos] == '[')
                {
                    pull();
                }
                else
                {
                    printf("\nNot BALANCED\n");
                    break;
                }
            }

            if(expression[i] == '}')
            {
                if(expression[tos] == '{')
                {
                    pull();
                }
                else
                {
                    printf("\nNot BALANCED\n");
                    break;
                }
            }
        }

    }
    if(tos == -1)
    {
        printf("\nBALANCED\n");
    }
}



int main()
{
    printf("\t\t\t\t---- Check Expression For a Balanced Parentheses ----");

    tos = -1;
    char ch;

    do
    {
        printf("\n\n\nEnter Expression: \n");
        scanf("%s",expression);
        balancedParentheses(expression);
        printStack();
        ch = getchar();
    }
    while(ch!= ESC);
}
