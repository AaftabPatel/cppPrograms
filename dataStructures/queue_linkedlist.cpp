//program to make queue using linked list
#include<iostream>
using namespace std;

struct node{
    int data;
    node *link;
};

class queue{
    node *f, *r;
    public:
        queue(){                  //constructor
            f=r=NULL;
        }        
        void add(int item){            //function to add element
            node *temp=new node;
            temp->data=item;
            temp->link=NULL;
            if(r==NULL)
                f=r=temp;
            else{
                r->link=temp;
                r=temp;
            }
        }

        int del(){          //function to delete element
            if(f==NULL){
                cout<<"Queue is empty\n";
                return -1;
            }
            else{
                int num=f->data;
                node *temp=f;
                if(f->link==NULL)
                    f=r=NULL;
                else
                    f=f->link;
                delete temp;
                return num;
            }
        }

        void display(){             //function to display
            node *t;
            t=f;
            if(f == NULL)  
            {  
                printf("\nEmpty queue\n");  
            }
            else{
                cout<<"queue is:\n";
                while(t != NULL){
                    cout<<t->data<<"  ";
                    t=t->link;
                }
            }
        }

        ~queue(){               //destructor
            node *temp;
            while(f!=NULL){
                temp=f;
                f=f->link;
                delete temp;
            }
        }
};

int main() {
   queue a;
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
            int item;
            cout<<"please netr th element to add:\n";
            cin>>item;
            a.add(item);
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