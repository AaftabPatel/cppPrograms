//program  for circular linked list
#include<iostream> 
using namespace std;
struct node
{
    int data;
    node *link;
};

class clinkedlist
{
    node *start;
    public:
        clinkedlist(){           //constructor
            start=NULL;
        }

        void add_at_begin(int num)      //function to add element at begining 
            {
                node *temp;
                temp = new node;
                if(start==NULL){
                    temp->data = num;
                    start = temp;
                    start->link=start;
                }
                else{
                    temp->data = num;
                    temp -> link = start -> link;
                    start -> link = temp;
                    start = temp;

                }
                    
            }
        void append(int num)          //function to add element at last
            {
                node *temp, *t;
                temp = new node;
                temp->link = NULL;
                t=start;
                int p=0;
                if (start == NULL)										//handle underflow condition
                    {
                    temp -> data = num;
                    start = temp;
                    start -> link = start;
                    }
                else{
                    do
                    {
                        t = t -> link;
                    } 
                    while (t -> link != start);							//traverse to the end of the list
                    
                    temp -> data = num;
                    temp -> link = t -> link;
                    t -> link = temp;
                }
                
                cout<<"element appended\n";
            }
            
        void display()         //function to display list
        {
            node *t;
            t=start;
            do {
                cout<<t->data <<" ";
                t = t->link;
            } 
            while(t!= start);
        }
        int count()            //function to count number of elements
        {
            node *t;
            int c=0;

            if(t==start)
                c = 0;
            t=start;
            do {
                c++;
                t = t->link;
            } 
           while(t != start);
            return c;
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
                else if(loc==c)
                {
                    append(num);
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

        int search(int n)          //function for searching
        {
            node *t;
            t=start;
            int p=0;
            do
            {   
                p++;
                if(t->data==n)
                    {
                        return p;
                    }
                t=t->link;            
            }while (t!=start);
            return -1;
        }   
        
        void del(int num)
        {
            node *temp = start;
            node *prev = NULL;
            int c=count();
            if(c==0)
                cout<<"empty list!";
            else if(temp->data==num)
                {
                    start = temp->link; // Changed head
                    delete temp;            // free old head
                    return;
                }
            else
                {
                    do
                    {
                        prev = temp;
                        temp = temp->link;
                    }while (temp != start && temp->data != num);
                    
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
};

int main()
{
    clinkedlist l1;
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
                cout<<"Thank you ";
                break;

            default:
                cout<<"please enter number from above only!!!";
        }
    }
    while(ch!=7);
    return 0;
}
