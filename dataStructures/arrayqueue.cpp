//program to perform queue operation using array
#include <iostream>
using namespace std;

class arr
{   
    int queue[10], front=-1, rear=-1,max=10;
    public:
    void add() 
    {            //function to add element
        int val;
        if (rear == max - 1)
        cout<<"Queue Overflow"<<endl;
        else {
            if (front == - 1)
            front = 0;
            cout<<"Insert the element in queue : "<<endl;
            cin>>val;
            rear++;
            queue[rear] = val;
            cout<<"Element inserted\n";
        }
    }

    int del()             //function to delete item 
        {
        int p;
        if (front == - 1 || front > rear) {
            cout<<"Queue Underflow ";
            return NULL;
        } else {
            int p;
            p=queue[front++];
            return p;
        }
        }
    void display()
     {         //function to dispaly queue
        if (front == - 1)
        cout<<"Queue is empty"<<endl;
        else {
            cout<<"Queue elements are : ";
            for (int i = front; i <= rear; i++)
            cout<<queue[i]<<" ";
                cout<<endl;
        }
     }
};

int main() {
   arr a;
   int ch;
   do {
        cout<<"\n1) Add in queue"<<endl;
        cout<<"2) Delete from queue"<<endl;
        cout<<"3) Display queue"<<endl;
        cout<<"4) Exit"<<endl;
        cout<<"Enter choice: "<<endl;
        cin>>ch;
        switch(ch) {
         case 1: {
            a.add();
            break;
         }
         case 2: {
            int p;
            p=a.del();
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