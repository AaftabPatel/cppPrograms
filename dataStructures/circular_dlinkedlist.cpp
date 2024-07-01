//program for doubly linked list 
#include<iostream>
using namespace std;

struct node
{
    int data;
    node *prev, *next;
};

class dlinkedlist
{
    node *start, *end;
    public:
        dlinkedlist()               //constructor
        {
            start=end=NULL;
        }
        void add_at_begin(int num)      //function to add element at begining 
            {
                node *temp;
                temp = new node;
                temp->data=num;
                if (start == end && start == NULL)
                {    
                    cout<<"Element inserted in empty list"<<endl;
                    start = end = temp;
                    start->next = end->next = NULL;
                    start->prev = end->prev = NULL;
                }
                else
                {
                    temp->next = start;
                    start->prev = temp;
                    start = temp;
                    start->prev = end;
                    end->next = start;
                    cout<<"Element inserted"<<endl;
                }
            }
        void append(int n)          //function to add element at last
        {
            node *temp=new node;
            temp->data=n;
            temp->next=NULL;
            if (start == end && start == NULL)
            {
                cout<<"Element inserted in empty list"<<endl;
                start = end = temp;
                start->next = end->next = NULL;    
                start->prev = end->prev = NULL;
            }
            else
            {
                end->next = temp;
                temp->prev = end;
                end = temp;
                start->prev = end;
                end->next = start;
                cout<<"element appended";
            }
        }

        void display()         //function to display list
        {
            node *t;
            t=start;
            do
            {
                cout <<"\n"<<t->data;
                t = t->next;
            }while(t!=start);
        }

        int count()           //function to count number of elements
        {
            node *t;
            int c=0;

            if(t==start)
                c = 0;
            t=start;
            do
                {
                c++;
                t = t->next;   
                }while(t != start);
            return c;
        }

        
        void insert(int loc, int num)       //function to insert an element
        {   
            int c=count();
            if (loc<1)         //if location is less than 1
                cout<<"invalid location!!";
            else if(loc==1)    //if location is 1
                add_at_begin(num);
            else if(loc==c)    //if location is at last 
                append(num);
            
            else
            {
                node *temp=new node;
                node *t;
                temp->data=num;
                t=start;
                for(int i=1;i<loc;i++)
                    t= t->next;
                
                t->next->prev=temp;
                temp->next=t->next;
                t->prev=t;
                t->next = temp;
            }
        }

        int search(int n)          //function for searching
        {
            node *t=new node;
            t=start;
            int p=0;
            do
            {   
                p++;
                if(t->data==n)
                    {
                        return p;
                    }
                t=t->next;            
            }while (t!=start);
            return -1;
        }   

        void del(int n)     //functtion to delte an element
        {
            node *t= new node;
            int c=0;
            if(n==start->data)
                {   
                    if(t->next==NULL)
                        start=end=NULL;
                    else
                    {   
                        t=start;
                        end->next=t->next;
                        t->next->prev=end;
                        start=t->next;
                        delete t;   
                        
                    }
                    c++;
                }
            else
            {
                t=start;
                do
                    {      
                        if(t->data==n)
                            {
                                if(t->next==start)
                                {
                                    t->prev->next=start;
                                    end=t->prev;
                                    end->next=start;
                                    c=c++;
                                    delete t;
                                    break;    

                                }
                                else
                                {
                                    t->prev->next=t->next;
                                    t->next->prev=t->prev;
                                    c=c++;
                                    delete t;
                                    break;
                                }
                             }
                        else
                            t = t->next;
                    }while (t!=start);
            }
                // If key was not present in linked list
                if (c==0)
                    {
                    cout<<"element not found!";
                    return; 
                    }
        }    

};

int main()
{
    dlinkedlist l1;
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
        cout<<"\n5=Delete";
        cout<<"\n6=Search";
        cout<<"\n7=Exit";
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
                int loc,n1;
                cout<<"Please enter the location to insert the element:";
                cin>>loc;
                cout<<"Please enter the element to be inserted:";
                cin>>n1;
                l1.insert(loc,n1);
                break;

            case 5:
                int n3;
                cout<<"Please enter the number to delete:";
                cin>>n3;
                l1.del(n3);
                break;

            case 6:
                int n2,res;
                cout<<"Please enter the value to search: ";
                cin>>n2;
                res=l1.search(n2);
                if(res!=-1)
                    cout<<"element found at position:"<<res;
                else    
                    cout<<"element not found";
                break;
            
            case 7:
                cout<<"Thank you ";
                break;

            default:
                cout<<"please enter number from above only!!!";
        }
    }
    while(ch!=7);
    return 0;
}
