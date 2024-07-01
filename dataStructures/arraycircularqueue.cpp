//program to perform circular queue operation using array
#include <iostream>
using namespace std;

class arr
{   
    public:
    int queue[10], front=-1, rear=-1,max=10;
    void add(int val) 
    {            ////function to add element
        if ((front == 0 && rear == max-1) || (front == rear+1)) {
            cout<<"Queue Overflow \n";
            return;
        }
        if (front == -1) {
            front = 0;
            rear = 0;
        } else {
            if (rear == max - 1)
            rear = 0;
            else
            rear = rear + 1;
        }
        queue[rear] = val ;
    }

    int del()             //function to delete item 
        {
        int p;
        
        if (front == - 1) {
            cout<<"Queue Underflow ";
            return -1;
        } 
        p=queue[front];
        if(front==rear)
            front=rear=-1;
        else {
            if(front==max-1)
                front=0;
            else
                front++;
            }
        return p;
        }

    void display()
     {         //function to dispaly queue
        int f = front, r = rear;
        if (front == -1) {
            cout<<"Queue is empty"<<endl;
            return;
        }
        cout<<"Queue elements are :\n";
        if (f <= r) {
            while (f <= r){
                cout<<queue[f]<<" ";
                f++;
            }
        } else {
            while (f <= max - 1) {
                cout<<queue[f]<<" ";
                f++;
            }
            f = 0;
            while (f <= r) {
                cout<<queue[f]<<" ";
                f++;
            }
        }
        cout<<endl;
     }
};

int main() {
   arr a;
   int ch;
   do {
        cout<<"\n1) Add in stack"<<endl;
        cout<<"2) Delete from stack"<<endl;
        cout<<"3) Display stack"<<endl;
        cout<<"4) Exit"<<endl;
        cout<<"Enter choice: "<<endl;
        cin>>ch;
        switch(ch) {
         case 1: {
            int val;
            cout<<"Insert the element in queue : "<<endl;
            cin>>val;
            a.add(val);
            break;
         }
         case 2: {
            int p;
            p=a.del();
            if(p!=-1)
                cout<<"deleted element is:"<<p;
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