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

        void add_at_begin(int n)              //function to add element at begining 
        {
            node *temp=new node;
            temp->data=n;
            temp->prev=NULL;
            temp->next=start;
            if(start!=NULL)
                start->prev=temp;
            start=temp;
            end=temp;
        }

        void append(int n)          //function to add element at last
        {
            node *temp=new node;
            temp->data=n;
            temp->next=NULL;
            if(start==NULL)
                {
                    start=temp;
                    end=temp;
                    temp->prev=NULL;
                }
            else
                {
                    temp->prev=end;
                    end->next=temp;
                    end=temp;
                    
                }
        }

        void display()         //function to display list
        {
            node *t;
            t=start;
            while(t!=NULL)
            {
                cout <<"\n"<<t->data;
                t = t->next;
            }
        }

        int count()           //function to count number of elements
        {
            node *t;
            int c=0;

            if(t==start)
                c = 0;
            t=start;
            while(t != NULL)
                {
                c++;
                t = t->next;   
                }
            return c;
        }

        void reverse()          //function to reverse list
        {
            node *t=new node;
            t=end;
            if(t==NULL)
                cout<<"Empty List";
            else
                {
                cout<<"list in reversed order is:";
                while(t!=NULL)
                    {
                    cout<<t->data<<"\n";
                    t=t->prev;
                    }
                }
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
            while (t!=NULL)
            {   
                p++;
                if(t->data==n)
                    {
                        return p;
                    }
                t=t->next;            
            }
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
                        start=start->next;
                        start->prev=NULL;
                    }
                    c++;
                }
            else
            {
                t=start;
                while (t!= NULL)
                        {      
                            if(t->data==n)
                                {
                                    if(t->next==NULL)
                                    {
                                        t->prev->next=NULL;
                                        end=t->prev;
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
                        }
            }
                // If key was not present in linked list
                if (c==0)
                    {
                    cout<<"element not found!";
                    return; 
                    }
        }    

        void duplicate()            //function to remove duplicate
        {
            node *t1, *t2;
            t2=start;
            while(t2!=NULL)
            {
            if(t2->next==NULL)
                return;
            else
                t1=t2->next;
            while(t1!=NULL)
                    {
                        if(t1->data == t2->data)
                            {
                                if(t1==start)
                                    {
                                        if(start->next==NULL)
                                            start=end=NULL;
                                        else    
                                            {
                                                start=start->next;
                                                start->prev=NULL;
                                            }
                                    }
                                else if(t1->next==NULL)
                                    {
                                        t1->prev->next=NULL;
                                        end=t1->prev;
                                    }
                                else
                                    t1->next->prev=t1->prev;
                                delete t1;
                            }                           
                        t1=t1->next;
                    }
            t2=t2->next;
            }
        }
        
        int palindrome()            //function to check palindrome
        {
            node *t1,*t2;
            t1=start;
            t2=end;
            int r=0;
            if(t1==NULL)
                cout<<"Empty List";
            else
                {
                    while (t1!=NULL)
                    {
                        if(t1->data==t2->data)
                            {
                                t1->next;
                                t2->prev;
                                return 0;
                            }
                        else
                            return r=-1;
                    }
                }
        }

        void max_and_min()           //function to find the largest
        {
            node *t;
            t=start;
            int max,min;
            max=min=t->data;
            if (t==NULL)
                cout<<"Empty list";
            else
            {
                while(t!=NULL)
                    {
                        if(t->data> max)
                            max=t->data;
                        else
                            min=t->data;
                        t=t->next;
                    }
                cout<<"largest element is:"<<max;
                cout<<"\nsmallest element is:"<<min;
            }
        }

        void swap(int loc1,int loc2)       //function to swap two numbers
        {
            node *t1,*t2;
            int temp;
            t1=t2=start;
            for(int i=0;i<loc1;i++)
                t1=t1->next;
            for(int i=0;i<loc2;i++)
                t2=t2->next;
            temp=t1->data;        //swapping
            t1->data=t2->data;
            t2->data=temp;
            cout<<"Swapping done\n";
            display();
        }

        void sort()         //function for sorting
        {
            int swapped, i;
            node *ptr1;
            node *lptr = NULL;
            
            /* Checking for empty list */
            if (start == NULL)
                return;
            
            do
            {
                swapped = 0;
                ptr1 = start;
            
                while (ptr1->next != lptr)
                {
                    if (ptr1->data > ptr1->next->data)
                    { 
                        int s=ptr1->data;
                            ptr1->data=ptr1->next->data;
                            ptr1->next->data=s;
                        swapped = 1;
                    }
                    ptr1 = ptr1->next;
                }
                lptr = ptr1;
            }
            while (swapped);
            cout<<"List Sorted";
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
        cout<<"\n7=Reverse";
        cout<<"\n8=Remove Duplicate";
        cout<<"\n9=Check Palindrome";
        cout<<"\n10=Largest & Smallest element";
        cout<<"\n11=Swap";
        cout<<"\n12=Sorting";
        cout<<"\n13=Exit";
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
                l1.reverse();
                break;
            
            case 8:
                l1.duplicate();
                cout<<"Duplicates removed";
                break;
                
            case 9:
                int r;
                r=l1.palindrome();
                if(r==0)
                    cout<<"list is a palindrome";
                else
                    cout<<"list is not a palindrome";
                break;

            case 10:
                l1.max_and_min();
                break;

            case 11:
                int loc1,loc2;
                cout<<"Please enter the location of the first element:";
                cin>>loc1;
                cout<<"Please enter the location of the second element:";
                cin>>loc2;
                l1.swap(loc1, loc2);
                break;

            case 12:
                l1.sort();
                break;

            case 13:
                cout<<"Thank you ";
                break;

            default:
                cout<<"please enter number from above only!!!";
        }
    }
    while(ch!=13);
    return 0;
}
