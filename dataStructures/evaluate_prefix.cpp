//program to evaluate prefix expression
#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class stack
{   
    float stk[10];
    int top=-1;
    public:
    void push( float val) 
    {            ////function to push element
        if(top==9)
            cout<<"Overflow";
        else
            stk[++top]=val;
    }

    int pop()             //function to pop item 
        {
        if(top==-1)
            {
            cout<<"Stack Underflow"<<endl;
            return NULL;
            }
        else {
            int p;
            p=stk[top--];
            return p;
            }
        }
};

float scanNum(char ch) {
   int value;
   value = ch;
   return float(value-'0');   //return float from character
}

int isOperator(char ch) {
   if(ch == '+'|| ch == '-'|| ch == '*'|| ch == '/' || ch == '$')
      return 1;    //character is an operator
   return -1;   //not an operator
}

int isOperand(char ch) {
   if(ch >= '0' && ch <= '9')
      return 1;   //character is an operand
   return -1;   //not an operand
}
float operation(int a, int b, char op) {
   //Perform operation
   if(op == '+')
      return b+a;
   else if(op == '-')
      return b-a;
   else if(op == '*')
      return b*a;
   else if(op == '/')
      return b/a;
   else if(op == '$')
      return pow(b,a); //find b^a
   else
      return NULL; //return null
}
float postfix_eval(string postfix) {
   int a, b;
   float o1;
   stack stk;
   for (char c: postfix) {
      //read elements and perform postfix evaluation
      if(isOperator(c) != -1) {
         a = stk.pop();
         b = stk.pop();
         o1=operation(a, b, c);
         stk.push(o1);
      }
      else if(isOperand(c) > 0) {
         stk.push(scanNum(c));
      }
   }
   return stk.pop();
}
main() {
    string post, temp;
    cout<<"Please enter the postfix expresion:";
    getline(cin , post); 
    int l=post.length();
    for(int i=l-1;i>=0;i--)      //reversing the string
        temp+=post[i];
    cout << "The result is: "<<postfix_eval(temp)-2*(postfix_eval(temp));
}