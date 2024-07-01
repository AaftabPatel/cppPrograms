//program for linked list
#include<iostream>
using namespace std;

struct node
{
    int data;
    node *link;
};

class linkedlist{
    node *start;
    public:
        linkedlist(){           //constructor
            start=NULL;
        }

        void add_at_begin(int num)      //function to add element at begining 
            {
                node *temp;
                temp = new node;
                temp->data = num;
                temp->link = start;
                start = temp;
            }

        void append(int num)          //function to add element at last
        {
            node *temp, *t;
            temp = new node;
            temp->data = num;
            temp->link = NULL;
            int p=0;
            if(start==NULL)
                start=temp;
            
            else if(start->data > temp->data)
            {
                add_at_begin(num);

            }
            else{
                t=start;
                while(t->link!=NULL)
                    {   if(t->data < temp->data && t->link->data > temp->data)
                            {
                            temp->link=t->link;
                            t->link = temp;
                            t= t -> link;
                            p++;
                            break;
                            }
                        else
                            t=t->link;
                    }
                if(p==0) 
                    t->link=temp;
                cout<<"element appended\n";
            }
        }
        
        void display()         //function to display list
        {
            node *t;
            t=start;
            while(t!=NULL)
            {
                cout <<"\n"<<t->data;
                t = t->link;
            }
        }

        void insert(int loc,int num)          //function to insert element
        {    
            int c=count();
            if(loc==0)
            {
                add_at_begin(num);
            }
            else if(loc>c)
            {
                cout<<"invalid location!!";

            }
            else
            {
                node *temp,*t;            
                temp = new node;
                temp->data = num;
                t = start;
                for(int i=1;i<loc;i++)
                    t= t->link;
                temp->link=t->link;
                t->link = temp;
            }
        }
          
        int count()            //function to count number of elements
        {
            node *t;
            int c=0;

            if(t==start)
                c = 0;
            t=start;
            while(t != NULL)
            {
                c++;
                t = t->link;   
            }
        return c;
        }

        ~linkedlist(){              //destructor
            node *t;
            while(start!= NULL)
            {
                t=start;
                start = start->link;
                delete t;
            }
        }

        int search(int n)          //function for searching
        {
            node *t;
            t=start;
            int p=0;
            while (t!=NULL)
            {   
                p++;
                if(t->data==n)
                    {
                        return p;
                    }
                t=t->link;            
            }
            return -1;
        }   
        
        void del(int num)
        {
            node *temp = start;
            node *prev = NULL;
            if(temp!=NULL && temp->data==num)
                {
                    start = temp->link; // Changed head
                    delete temp;            // free old head
                    return;
                }
            else
                {
                    while (temp != NULL && temp->data != num)
                    {
                        prev = temp;
                        temp = temp->link;
                    }
                }
            // If key was not present in linked list
            if (temp == NULL)
                {
                cout<<"element not found!";
                return; 
                }
            // Unlink the node from linked list
            prev->link = temp->link;
        
            // Free memory
            delete temp;
        }

        void duplicate()            //function to remove duplicate
        {
            node *t1, *t2;
            t1=start;
            if(t1==NULL)
                return;
            else
                {                
                /* Traverse the list till last node */
                while (t1->link != NULL)
                    {
                        /* Compare current node with next node */
                        if (t1->data == t1->link->data)
                            {      
                            t2 = t1->link->link;
                            delete (t1->link);
                            t1->link = t2;
                            }
                        else 
                            t1 = t1->link;
                    }
                }
        }
        void reverse()      //function to reverse list
        {
            node *t ,*prev, *next;
            t=start;
            prev=next=NULL;
            while (t != NULL) {
                next = t->link;
                t->link = prev;
                prev = t;
                t = next;
            }
            start = prev;
            cout<<"List Reversed";
            display();
        }
};

int main()
{
    linkedlist l1;
    int n, ch;
    cout << "Please enter a number to add at beginning:";
    cin >> n;
    l1.add_at_begin(n);
    do{
        cout<<"\nPLEASE CHOOSE";
        cout<<"\n1=Append";
        cout<<"\n2=Count";
        cout<<"\n3=Display";
        cout<<"\n4=Insert";
        cout<<"\n5=Search";
        cout<<"\n6=Delete";
        cout<<"\n7=Duplicate";
        cout<<"\n8=Reverse";
        cout<<"\n9=Exit";
        cout<<"\nPlease enter your choice:";
        cin>>ch;
        switch(ch)              //switch case
        {
            case 1:
                int num;
                cout << "Please enter a number to append:";
                cin >> num;
                l1.append(num);
                break;
            
            case 2:
                int c;
                c=l1.count();
                cout << "\nThe number of elements is:"<< c;
                break;
            
            case 3:
                cout << "\nThe elements are as:";
                l1.display();
                break;
            
            case 4:
                int l,n1;
                cout<<"Please enter the location to insert the element:";
                cin>>l;
                cout<<"Please enter the element to be inserted:";
                cin>>n1;
                l1.insert(l,n1);
                break;

            case 5:
                int n2,res;
                cout<<"Please enter the value to search: ";
                cin>>n2;
                res=l1.search(n2);
                if(res!=-1)
                    cout<<"element found at position:"<<res;
                else    
                    cout<<"element not found";
                break;

            case 6:
                int n3;
                cout<<"Please enter the number to delete:";
                cin>>n3;
                l1.del(n3);
                break;
            
            case 7:
                l1.duplicate();
                cout<<"Duplicates removed";
                break;

            case 8:
                l1.reverse();
                break;

            case 9:
                cout<<"Thank you ";
                break;

            default:
                cout<<"please enter number from above only!!!";
        }
    }
    while(ch!=9);
    return 0;
}
