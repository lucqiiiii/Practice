#include<ctype.h>
#include <iostream>

using namespace std;

char stack[100];
int size = 100;
int top = -1;


void push(char next)
{
    top = top+1;
    stack[top] = next;
}
char pop()
{
    char next ;
    next = stack[top];
    top = top-1;
    return(next);
}
int isoperator(char symbol)
{
    if(symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int order(char operand)
{
    if(operand == '*' || operand == '/')
    {
        return(2);
    }
    else if(operand == '+' || operand == '-')
    {
        return(1);
    }
    else
    {
        return(0);
    }
}
void in_postfix(char infix_exp[], char postfix_exp[])
{
    int i=0;
    int k=0;
    char next, post;
    push('(');
    strcat(infix_exp,")");
    next=infix_exp[i];
    while(next != false)
    {
        if(next == '(')
        {
            push(next);
        }
        else if( isdigit(next))
        {
            postfix_exp[k] = next;
            k++;
        }
        else if(isoperator(next) == 1)
        {
            post=pop();
            while(isoperator(post) == 1 && order(post)>= order(next))
            {
                postfix_exp[k] = post;
                k++;
                post = pop();
            }
            push(post);
            push(next);
        }
        else if(next == ')')
        {
            post = pop();
            while(post != '(')
            {
                postfix_exp[k] = post;
                k++;
                post = pop();
            }
        }
        i++;
        next = infix_exp[i];
    }
}
int main()
{
    char infix[size], postfix[size];
    cout << "Enter Fully Parenthesized Infix expression : " << endl;
    cin >> infix;
    
    in_postfix(infix,postfix);
    cout << "Postfix Expression: " << endl;
    cout << postfix <<endl;
    
    return 0;
}
