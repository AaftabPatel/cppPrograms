//program to take and display array elements using pointer with address
#include <iostream>
using namespace std;
class arr            //class array
{
    int ar[100],i,n;
    public:
        int* takearray()           //constructor
        {
            cout<<"Please enter the number of elements you want:";
            cin>>n;
            cout<<"Please enter the elements:\n";
            for(i=0; i<n; i++)
                cin>>ar[i];
            int *p=ar;
            return p;
        }
    void display(int *ptr)         //function to display using pointer
    {
        ptr=&ar[0];
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
    int *ptr=a.takearray();
    a.display(ptr);
    return 0;
}