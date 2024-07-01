    //program for dqueue using linked list
    #include<iostream>
    using namespace std;
    struct node
    {
        int data;
        node *link;
    };

    class arr{
        int dqueue[10],max=10;    
        node *start;
        public:
            arr(){           //constructor
                start=NULL;
            }
            void add()          //function to add element at last
            {
                int num;
                cout<<"enter the element to add:";
                cin>>num; 
                node *temp = new node;
                node *t = new node;
                t->data=num;
                t->link=NULL;
                if(start==NULL)
                    start=t;
                else{
                    temp=start;
                    while(temp->link !=NULL)
                        temp=temp->link;    
                }
                temp->link=t;
                cout<<"element added\n";
            }

        int delf()             //function to delete item from front 
            {
            int p;
            node *t;
            t=start;
            start = t->link; // Changed head
            p=t->data;
            delete t;  
            return p;
            }

        int delr(){             //function to delete item from end
            int p;
            node *t;
            t=start;
            while(t->link !=NULL)
                t = t->link;
            p=t->data;
            delete t;  
            return p;
            
        }
        void display()         //function to display list
            {
                node *t;
                t=start;
                while(t->link!=NULL)
                {
                    cout <<"\n"<<t->data;
                    t = t->link;
                }
            }

    };

    int main() {
    arr a;
    a.add();
    a.add();
    a.add();
    a.display();
    int p1,p2;
    p1=a.delf();
    p2=a.delr();
    cout<<"del:"<<p1<<p2; 
    return 0;
    }