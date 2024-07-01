//program to perform stack operation using linked list
#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};
node *top = NULL;

class linkedlist_stack{
    node *start;
    public:

    void push(int val) {
        node *temp;
        temp=new node;
        temp->data = val;
        temp->next = top;
        top = temp;
        cout<<"element pushed";
        }
        
    void display() {
        node *ptr;
        if(top==NULL)
        cout<<"stack is empty";
        else {
            ptr = top;
            cout<<"Stack elements are: ";
            while (ptr != NULL) {
                cout<< ptr->data <<" ";
                ptr = ptr->next;
            }
        }
        cout<<endl;
        }

    void pop() {
        if(top==NULL)
        cout<<"Stack Underflow"<<endl;
        else {
            cout<<"The popped element is "<< top->data <<endl;
            top = top->next;
        }
}

};

int main() {
   linkedlist_stack a;
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
            int num;
            cout << "Please enter a number to append:";
            cin >> num;
            a.push(num);
            break;
         }
         
         case 2: {
            a.pop();
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