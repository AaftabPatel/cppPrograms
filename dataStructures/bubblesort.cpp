//program to perform bubble sort
#include<iostream>
using namespace std;

class ar              //class array
{
    int arr[100], n, i, j;
    
    public:
        ar()              //constructor
            {
            cout << "Enter the size of the array : ";
            cin >> n;
            cout << "Enter the elements of the array : ";
            for (i = 0; i < n; i++)
                cin >> arr[i];
            
            }

        void display()         // function to display elemnts
            {
            cout<<"The elements of array are : ";
            for(int i=0;i<n;i++)
                {
                cout<<arr[i]<<" ";
                }
            
            }
        void bsort()               //function to do bubble sorting
            {
            for(j=0;j<n;j++)
            {
            for(i=0;i<n;i++)
                {
                if(arr[i]>arr[i+1])
                    {
                    int s=arr[i];
                    arr[i]=arr[i+1];
                    arr[i+1]=s;
                    }
                }
            }
            cout<<"\narray after sorting:";
            for(int k=0;k<=n;k++)
                cout<<arr[k]<<" ";
            }
};
int main()
{
    ar a;
    a.display();
    a.bsort();
    return 0;
}