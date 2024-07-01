//program to perform selection sort
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
    void ssort()                //function to do selection sort
    {   
        for(i=0;i<(n-1);i++)
        {
            int pos=i;
            for(j=(i+1);j<n;j++)
                {
                if(ar[pos]>ar[j])
                    pos=j;
                }
            if(pos != i)
                {
                int s=ar[i];
                ar[i]=ar[pos];
                ar[pos]=s;
                }
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
    a.ssort();
    return 0;
}