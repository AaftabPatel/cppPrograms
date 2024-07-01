//program to merge two array elements
#include <iostream>
using namespace std;
class arr            //class array
{
    int i,j;
    public:
    void display(int ar[], int n)         //function to display
    {
        cout<<"Elements of the array are:\n";
        for(i=0; i<n; i++)
            cout<<ar[i]<<" ";
    }

    void merge(int a1[], int a2[],int x, int y)     //function to merge
    {
        int mer[100];
        i=0;
        while(i<x)
            {
                mer[i]=a1[i];
                i++;
            }
        j=0;
        while(j<y)
            {
                mer[j+x]=a2[j];
                j++;
            }
        cout<<"Elements of the merged array are:\n";
        for(i=0; i<x+y; i++)
            cout<<mer[i]<<" ";        
    }
};
int main()
{
    arr a;
    int ar1[100],ar2[100],n1,n2,i;
    cout<<"Please enter the number of elements for first array:";
    cin>>n1;
    cout<<"Please enter the elements:\n";
    for(i=0; i<n1; i++)
        cin>>ar1[i];

    cout<<"Please enter the number of elements for second array:";
    cin>>n2;
    cout<<"Please enter the elements:\n";
    for(i=0; i<n2; i++)
        cin>>ar2[i];

    a.display(ar1,n1);
    a.display(ar2,n2);
    a.merge(ar1,ar2,n1,n2);
    return 0;
}