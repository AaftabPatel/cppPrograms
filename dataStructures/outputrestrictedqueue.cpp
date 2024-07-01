    //program to perform output restricted queue
    #include <iostream>
    using namespace std;

    class arr
    {   
        int dqueue[10], front=-1, rear=-1,max=10;
        public:
        arr(){      //constructor
            front=rear=-1;
        }
        void addf() 
        {            //function to add element at front
            int val;
            cout<<"Insert the element in queue : "<<endl;
            cin>>val;
            if (front == 0)
                cout<<"first position is already taken\n";
            else{
                if(front==-1)
                    rear=front=0;
                else
                    front--;
                dqueue[rear] = val;
            cout<<"Element inserted\n";
            }        
        }

        void addr() 
        {            //function to add element at last
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

        int del()             //function to delete item from front 
            {
            int p;
            if (front == - 1 || front > rear) {
                cout<<"Queue Underflow ";
                return -1;
            } 
            else {
                int p;
                p=dqueue[front++];
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
                cout<<dqueue[i]<<" ";
                    cout<<endl;
            }
        }
    };

    int main() {
    arr a;
    int ch;
    do {
            cout<<"\n1) Add in front"<<endl;
            cout<<"2) Addd at end"<<endl;
            cout<<"3) Delete an element"<<endl;
            cout<<"4) Display queue"<<endl;
            cout<<"5) Exit"<<endl;
            cout<<"Enter choice: "<<endl;
            cin>>ch;
            switch(ch) {
            case 1: {
                a.addf();
                break;
            }
            case 2: {
                a.addr();
                break;
            }
            case 3: {
                int p;
                p=a.del();
                if(p!=-1)
                    cout<<"deleted element is:"<<p;
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