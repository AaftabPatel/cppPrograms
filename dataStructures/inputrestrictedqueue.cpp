//program to perform input restricted queue
#include <iostream>
using namespace std;

class arr
{   
    int dqueue[10], front=-1, rear=-1,max=10;
    public:
    arr(){      //constructor
        front=rear=-1;
    }
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
            dqueue[rear] = val;
            cout<<"Element inserted\n";
        }
    }

    int delf()             //function to delete item from front 
        {
        int p;
        if (front == - 1 || front > rear) {
            cout<<"Queue Underflow ";
            return NULL;
        } 
        else {
            int p;
            p=dqueue[front++];
            return p;
            }
        }

    int delr(){             //function to delete item from end
        int p;
        if(front==-1){
            cout<<"queue is empty!!\n";
            return -1;
        }
        p=dqueue[rear];
        if(front==rear)
            front=rear=-1;
        else
            rear--;
        return p;
    }

    void display()
     {         //function to dispaly queue
        if (front == - 1)
        cout<<"Queue is empty"<<endl;
        else {
            cout<<"Queue elements are : ";
            for (int i = front; i <= rear; i++)
            cout<<dqueue[i]<<" ";
                cout<<endl;
        }
     }
};

int main() {
   arr a;
   int ch;
   do {
        cout<<"\n1) Add in queue"<<endl;
        cout<<"2) Delete from front"<<endl;
        cout<<"3) Delete from end"<<endl;
        cout<<"4) Display queue"<<endl;
        cout<<"5) Exit"<<endl;
        cout<<"Enter choice: "<<endl;
        cin>>ch;
        switch(ch) {
         case 1: {
            a.add();
            break;
         }
         case 2: {
            int p1;
            p1=a.delf();
            cout<<"deleted element is:"<<p1;
            break;
         }
         case 3: {
            int p2;
            p2=a.delr();
            cout<<"deleted element is:"<<p2;
            break;
         }
         case 4: {
            a.display();
            break;
         }
         case 5: {
            cout<<"Exit"<<endl;
            break;
         }
         default: {
            cout<<"Invalid Choice"<<endl;
         }
      }
   }
   while(ch!=5);
   return 0;
}