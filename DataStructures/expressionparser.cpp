#include <iostream>
using namespace std;

int precedence(char op)
{
    switch(op){
        case '+':return 1;
        case '-':return 1;
        case '*':return 2;
        case '%':return 2;
        case '/':return 2;
        case '(':return 4;
        case ')':return 4;
        case '^':return 3;
        default:return 0;
    }
}
int isOperator(char val)
{
    switch(val){
        case '+':return 1;
        case '-':return 1;
        case '*':return 1;
        case '%':return 1;
        case '/':return 1;
        case '(':return 1;
        case ')':return 1;
        case '^':return 1;
        default:return 0;
    }
}
void infix_to_postfix(char *infix, int a)
{

    char stack[a];
    char postfix[a];
    int top = -1;
    int i = 0;
    int j = 0;

    while (infix[i] != '\0')
    {

        if (isOperator(infix[i]) == 1)
        {
            if (stack[top] != -1)
            {
                while (precedence(infix[i]) <= precedence(stack[top]))
                {
                    postfix[j++] = stack[top];
                    top--;
                }

                top++;
                stack[top] = infix[i];
            }
            else
            {
                stack[++top] = infix[i];
            }
        }

        else if (isOperator(infix[i]) == 0)
        {
            postfix[j++] = infix[i];
        }

        else if (infix[i] == ')')
        {
            while (stack[top] != '(')
            {
                postfix[j++] = stack[top];
                top--;
            }
            top--;
        }

        else if (infix[i] == '(')
        {
            top++;
            stack[top] = infix[i];
        }

        i++;
    }

    while (top != -1)
    {
        postfix[j++] = stack[top];
        top--;
    }

    for (int i = 0; i < sizeof(postfix); i++)
    {
        cout << postfix[i];
    }
    cout << endl;
}

main()
{

    int a;
    cout << " enter no.of elements in your equation: " << endl;
    cin >> a;
    char infix[a];
    char b;

    for (int i = 0; i < a; i++)
    {
        cout << "Enter equation element: " << endl;
        cin >> b;
        infix[i] = b;
    }

    infix_to_postfix(infix, a);
}