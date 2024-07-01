//program to convert infix to prefix
#include<iostream>
#include<string>
#define MAX 20
using namespace std;

char stk[20];
int top=-1;
// Push function here, inserts value in stack and increments stack top by 1
void push(char oper)
{
    if(top==MAX-1)
    {
        cout<<"stackfull!!!!";
    }
   
    else
    {
        top++;
        stk[top]=oper;
    }
}
// Function to remove an item from stack.  It decreases top by 1
char pop()
{
    char ch;
    if(top==-1)
    {
        cout<<"stackempty!!!!";
    }
    else
    {
        ch=stk[top];
        stk[top]='\0';
        top--;
        return(ch);
    }
    return 0;
}
int priority ( char alpha )     //funcion for priority
{
    if(alpha == '+' || alpha =='-')
    {
        return(1);
    }
 
    if(alpha == '*' || alpha =='/')
    {
        return(2);
    }
 
    if(alpha == '$')
    {
        return(3);
    }
 
    return 0;
}
string convert(string infix)    //function to covert
{
    int i=0;
    string prefix = "";   
    while(infix[i]!='\0')
    {       
        if(infix[i]>='a' && infix[i]<='z'|| infix[i]>='A'&& infix[i]<='Z')          
        {       //if scanned character is operand
            prefix.insert(prefix.end(),infix[i]);
            i++;
        }       //if scanned character is closing bracket 
        else if(infix[i]==')' || infix[i]=='}'  || infix[i]==']')
        {
            push(infix[i]);
            i++;
        }        
        else if(infix[i]=='(' || infix[i]=='{'  || infix[i]=='[')
        {       //if scanned character is opening bracket
            if(infix[i]=='(')
            {
                while(stk[top]!=')')
                {               
                    prefix.insert(prefix.end(),pop());
                }
                pop();
                i++;
            }
            if(infix[i]=='[')
            {
                while(stk[top]!=']')
                {
                    prefix.insert(prefix.end(),pop());
                }
                pop();
                i++;
            }
 
            if(infix[i]=='{')
            {
                while(stk[top]!='}')
                {
                    prefix.insert(prefix.end(),pop());
                }
                pop();
                i++;
            }
        }
        else            
        {
            if(top==-1)
            {
                push(infix[i]);
                i++;
            }
 
            else if( priority(infix[i]) < priority(stk[top])) {
                prefix.insert(prefix.end(),pop());
               
                while(priority(stk[top]) == priority(infix[i])){
                    prefix.insert(prefix.end(),pop());
                    if(top < 0) {
                        break;
                    }
                }
                push(infix[i]);
                i++;
            }
            else if(priority(infix[i]) >= priority(stk[top])) {
                push(infix[i]);
                i++;
            }
        }
    }
    while(top!=-1)
    {
        prefix.insert(prefix.end(),pop());
    }
    string temp2;
    int c=prefix.length();
    temp2="";
    for(int i=c-1;i>=0;i--)     //reversing the string again
        temp2+=prefix[i];
    prefix=temp2;
    cout<<"The converted prefix string is : "<<prefix<<endl; //it will print postfix conversion  
    return prefix;
}


int main()
{
    int cont;
    string infix, prefix, temp;
    cout<<"please enter the infix expression:";
    getline(cin, infix);
    int c=infix.length();
    temp="";
   for(int i=c-1;i>=0;i--)      //reversing the string
        temp+=infix[i];
    prefix = convert(temp);
    return 0;
}