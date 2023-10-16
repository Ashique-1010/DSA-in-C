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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

char STACK[MAX];
int top = -1;

void Push(char);
char Pop();

void main()
{
    char INFIX[MAX], POSTFIX[MAX], z;
    printf("Enter infix expression\n");
    fgets(INFIX, MAX, stdin);
    printf("The infix expresiion: %s", INFIX);

    int i = 0, j = 0, k;
    while(INFIX[i] != '\0')
    {
        switch(INFIX[i])
        {
            case '(':
                Push('(');
            case ')':
                while(STACK[top] != '(')
                {
                    z = Pop();
                    POSTFIX[j] = z;
                    j++;
                }
            case '/':
                k = Check_precedence(INFIX[i], STACK[top])
                if(k == 0 || k > 1)
                {
                    Push('/');
                }
                else //if(k == 2)
                {
                    z = Pop();
                    POSTFIX[j] = z;
                    j++;
                    Push('*');
                }

            case '*':
                k = Check_precedence(INFIX[i], STACK[top])
                if(k == 0 || k > 2)
                {
                    Push('*');
                }
                else //if(k == 2)
                {
                    z = Pop();
                    POSTFIX[j] = z;
                    j++;
                    Push('*');
                }

        }
    }


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

int Check_precedence(char a, char b)
{
    char OPS[] = {'(', '/', '*', '+', '-'}
    for(int i = 0; i < 5; i++)
    {
        if(a == OPS[i])
        {
            for(int j = 0; j < 5; j++)
            {
                if(b == OPS[j])
                {
                    if(i < j)
                    {
                        return i;
                    }
                    else
                    {
                        return j;
                    }
                }
            }
        }
    }
}
