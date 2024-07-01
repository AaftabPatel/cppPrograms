//program to perform stack operation using array
#include <iostream>
using namespace std;

class arr
{   
    int stack[10], top=-1;
    public:
    void push() 
    {            ////function to push element
        if(top==9)
            cout<<"Overflow";
        else
        {
            int val;
            cout<<"please enter the value to push:";
            cin>>val;
            stack[++top]=val;
        }
    }

    int pop()             //function to pop item 
        {
        int p;
        if(top==-1)
            {
            cout<<"Stack Underflow"<<endl;
            return NULL;
            }
        else {
            int p;
            p=stack[top--];
            return p;
            }
        }

    void display()
     {         //function to dispaly stack
        if(top<0) 
            cout<<"Stack is empty";
        else
        {
            cout<<"Stack elements are:\n";
            for(int i=0; i<=top; i++)
                cout<<stack[i]<<" ";
        }
     }
};

int main() {
   arr a;
   int ch;
   do {
        cout<<"\n1) Push in stack"<<endl;
        cout<<"2) Pop from stack"<<endl;
        cout<<"3) Display stack"<<endl;
        cout<<"4) Exit"<<endl;
        cout<<"Enter choice: "<<endl;
        cin>>ch;
        switch(ch) {
         case 1: {
            a.push();
            break;
         }
         case 2: {
            int p;
            p=a.pop();
            cout<<"Poped element is:"<<p;
            break;
         }
         case 3: {
            a.display();
            break;
         }
         case 4: {
            cout<<"Exit"<<endl;
            break;
         }
         default: {
            cout<<"Invalid Choice"<<endl;
         }
      }
   }
   while(ch!=4);
   return 0;
}