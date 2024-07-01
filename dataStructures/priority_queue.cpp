//program for priority queue
#include<iostream>
using namespace std;

struct dat{
    int p,d;
};
class pqueue{
      int f,r;
      dat arr[10];
    public:
    pqueue(){           //constructor
        f = r = -1;
    }

    void add(){         //function to add element 
        if(r == 9)
      {  cout << "\nThe queue is full !!!";
        return;
      } 
        dat temp;
        cout << "\nPlease enter the element to insert in the queue:";
        cin >> temp.d;
        int c;
        do{
            cout<<"priority:1 for lowest to 9 for highest\\n";
            cout << "\nPlease enter the priority:";
            cin >> temp.p;
            if(temp.p>=1 && temp.p<10)
                c=-1;
            else{
                c=0;
                cout<<"please enter the correct priority!!";
            }
        }
        while(c!=-1);
        r++;
        arr[r] = temp;
        if(f == -1)
         f = 0 ;
         sort();
         cout<<"element added\n";
    }
    
    void sort(){            //function to sort according to priority
        for(int i=f;i<=r;i++)
        {
            for(int j=i+1;j<=r;j++)
            {
                if(arr[i].p > arr[j].p)
                {
                      dat temp;
                      temp = arr[i];
                      arr[i] = arr[j];
                      arr[j] = temp;
                }
            }
        }
    }
    
    dat remove(){       //function to delete element 
        dat t;
        t.d = 0;
        t.p = 0;
        if(f == -1)
        {
        cout << "\nThe queue is empty!!!";
          return t;
        }
        dat temp;
        temp = arr[f];
        arr[f].d = -1;
        if(f == r)
        f = r = -1;
        else
        f++;

        return temp;
        
    }

    void display(){             //function to dispay queue 
        if(f == -1)
        {cout << "\nThe queue is empty!!!";
          return;
        }
        cout << "\nThe elements present in the queue are as follows: " ;
        for(int i=f;i<=r;i++)
        {
            cout << arr[i].d << "  ";
        }

    }
};

int main() {
   pqueue a;
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
            a.add();
            break;
         }
         case 2: {
            dat p;
            p=a.remove();
            cout<<"deleted element is:"<<p.d;
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