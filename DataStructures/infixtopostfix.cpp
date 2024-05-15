#include<iostream>
#include<stack>
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

string InfixToPostfix(stack<char> s, string infix)
{
    string postfix;
    for(int i=0;i<infix.length();i++)
    {
        if((infix[i]>='a' && infix[i]<='z')||(infix[i]>='A' && infix[i]<='Z'))
            postfix+=infix[i];
        else if(infix[i]=='(')
            s.push(infix[i]);
        else if(infix[i]==')')
        {
            while((s.top()!='(') && (!s.empty()))
            {
                char temp=s.top();
                postfix+=temp;
                s.pop();
            }
            if(s.top()=='(')
                s.pop();
        }
        else if(isOperator(infix[i]))
        {
            if(s.empty())
                s.push(infix[i]);
            else
            {
                if(precedence(infix[i])>precedence(s.top()))
                    s.push(infix[i]);
                else if((precedence(infix[i])==precedence(s.top())))
                    s.push(infix[i]);
                else
                {
                    while((!s.empty()) && (precedence(infix[i])<=precedence(s.top())))
                    {
                        postfix+=s.top();
                        s.pop();
                    }
                    s.push(infix[i]);
                }
            }
        }
    }
    while(!s.empty())
    {
        postfix+=s.top();
        s.pop();
    }
    return postfix;
}