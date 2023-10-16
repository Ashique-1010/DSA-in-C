/*
create stack, initialise top
create infix array, recieve infix expression and store to infix array
create a postfix array
traverse through the infix array
    if operand add to postfix array
    if operator add to stack
        if '(' push to stack, push all operators following '(' until ')' then pop till '(' and add to postfix
        check precedence while pushing to stack
            if operator has higher precedence than top, push operator to stack
            if operator has lower precedence, pop top and add to postfix, push operator to stack
            if operator has equal precedence, check associativity
                L->R : pop top and add to postfix, check precedence of top again., push operator to stack
                if expression literal is null, pop all operands in stack and add to postfix
*/

// ONLY WORKING FOR * OR ONCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

char STACK[MAX];
int top = -1;

void Push(char);
char Pop();
int Check_operator(char);
int Check_precedence(char, char);

void main()
{
    char INFIX[MAX], POSTFIX[MAX], z;
    printf("Enter infix expression\n");
    fgets(INFIX, MAX, stdin);
    printf("The infix expresiion: %s\n", INFIX);

    int i = 0, j = 0, is_operator, pre;
    while(INFIX[i] != '\0')
    {
        is_operator = Check_operator(INFIX[i]);
        if(is_operator == 1)
        {
                pre = Check_precedence(INFIX[i], STACK[top]);
                if(pre == 1)
                {
                    Push(INFIX[i]);
                    i++;
                }
                else
                {
                    z = Pop();
                    POSTFIX[j] = z;
                    j++;
                    Push(INFIX[i]);
                }
                i++;
        }
        else if(i == 1)
        {
            Push(INFIX[i]);
            i++;
        }
        else        // adds operands to postfix
        {
            POSTFIX[j] = INFIX[i];
            i++;
            j++;
        }
    }
    printf("The postfix expression is: %s\n", POSTFIX);

}

void Push(char x)
{
    top++;
    STACK[top] = x;
}

char Pop()
{
    int y = STACK[top];
    top--;
}

int Check_operator(char c)
{
    int i = 0;
    char OPS[] = {'(', '/', '*', '+', '-'};
    while(c != '\0')
    {
        if(c == OPS[i])
        {
            return 1;
        }
        else
        {
            return 0;
        }
        i++;
    }
}
int Check_precedence(char a, char b)
{
    int i = 0, f1, f2;
    char OPS[] = {'(', '/', '*', '+', '-'};
    for(i = 0; i < 5; i++)
    {
        if(a == OPS[i])
        {
            f1 = i;
        }
        if(b == OPS[i])
        {
            f2 = i;
        }
    }
    if(f1 == 0 || f2 == 0)
    {
        return 1;
    }
    else
    {
        if((f1 == 1 || f1 == 2) && (f2 == 3 || f2 == 4))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
