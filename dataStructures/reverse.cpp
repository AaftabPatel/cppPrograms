#include<iostream>
using namespace std;

class ar              //class array
{
    int arr[100], n, i;
    
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
    void reverse()           //function to reverse array
    {
        for(i=0; i<n/2; i++)
            {
                int temp=0;
                temp=arr[i];
                arr[i]=arr[n-i-1];
                arr[n-i-1]=temp;
            }

    }

};
int main()
{
    ar a; 
    a.display();
    a.reverse();
    cout<<"\nafter reversing:\n";
    a.display();
    return 0;
}