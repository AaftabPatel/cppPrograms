//program to take and display array elements using pointer with address
#include <iostream>
using namespace std;
class arr            //class array
{
    int ar[100],i,n;
    public:
        arr()           //constructor
        {
            cout<<"Please enter the number of elements you want:";
            cin>>n;
            cout<<"Please enter the elements:\n";
            for(i=0; i<n; i++)
                cin>>ar[i];
        }
    void display()         //function to display using pointer
    {
        int *ptr=&ar[0];
        cout<<"Elements of the array are:\n";
        for(i=0; i<n; i++)
            {
            cout<<*ptr<<" "<<"at address:"<< &ar[i]<<endl;
            *ptr++;
            }
    }

};
int main()
{
    arr a;
    a.display();
    return 0;
}