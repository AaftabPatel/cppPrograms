//program to perform insertion sort
#include<iostream>
using namespace std;
class arr            //class array
{
    int ar[100],i,j,n;
    public:
        arr()           //constructor
        {
            cout<<"Please enter the number of elements you want:";
            cin>>n;
            cout<<"Please enter the elements:\n";
            for(i=0; i<n; i++)
                cin>>ar[i];
        }
        void display()         //function to display
        {
            cout<<"Elements of the array are:\n";
            for(i=0; i<n; i++)
                cout<<ar[i]<<" ";
        }
        void isort()                //function to do insertion sort
        {   
            int key;
            for (i = 1; i < n; i++)
            {
                key = ar[i];
                j = i - 1;    //moving element smaller to key ahead in array
                while (j >= 0 && ar[j] > key)   
                {
                    ar[j + 1] = ar[j];
                    j = j - 1;
                }
                ar[j + 1] = key;
            }
        
            cout<<"\narray after sorting:\n";     //printing sorted array
            for(i=0;i<n;i++)
                cout<<ar[i]<<" ";
                
        }
};
int main()
{
    arr a; 
    a.display();
    a.isort();
    return 0;
}