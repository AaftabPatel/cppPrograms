//program for circular queue 
#include<iostream>
using namespace std;

class cqueue{
    int arr[10],f=-1 ,r=-1 ,max=10;

    public:
        
        void add(int item){              //function to add element
            if((f==0 && r==max-1) || f==r+1)
                cout<<"Queue is full\n";
            else{
                if(r==max-1)
                    r=0;
                else
                    r++;
                arr[r]=item;
                if(f==-1)
                    f++;
            cout<<"Element inserted\n ";
            }
       }

       int del()        //function to delete element
       {
        if(f == -1)    
          {
            cout << "\nThe queue is empty!!!";
            return -1;
          }                    
        int data = arr[f];            
        arr[f] = -1;   
        if(f == r)           
            f = r = -1;         
        else{           
            if(f == max-1)   
                f = 0;   
            else       
                f++;
        }
        return data;
       }

       void display()           //function to display elements in queue
        {
        if(f == -1)     // if queue is empty.
            {
            cout << "\nThe Queue is empty!!!";
            return ; 
            }
        cout<<"elements are:\n";
        if(r>=f){
            for(int i=f; i<=r; i++)
                cout<<arr[i]<<" ";
            }
        else{
            for(int i=f;i<max;i++)
                cout<<arr[i]<<" ";
            for(int i=0;i<=r;i++)
                cout<<arr[i]<<" ";
            }
        }

};

int main() {
   cqueue a;
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
            cout<<"Please enter the element to add:";
            cin>>item;
            a.add(item);
            break;
         }
         case 2: {
            int p;
            p=a.del();
            if(p!=-1)
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