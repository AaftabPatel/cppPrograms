//program to insert and delete an element in an array
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

    void insert()            //function to append 
        {
        int ins,pos;
        cout<<"\nPlease enter the value to insert:";
        cin>>ins;
        cout<<"\nPlease enter the index of value:";
        cin>>pos;
        if(pos>n+1 || pos<=0)
        {
            cout<<"Invalid position! Please enter position between 1 to "<<n;
        }
        else
        {
         for(i=n; i>=pos; i--)
        {
            arr[i] = arr[i-1];
        }
        arr[pos-1] = ins;
        n++;
        }
        }

    void del()                 //function to delete 
        {
        int d, j, found=0;
        cout<<"\nPlease enter the value to delete:";
        cin>>d;
        for(i=0; i<n; i++)
        {
            if(arr[i]==d)
            {   
                for(j=i; j<(n-1); j++)
                    arr[j] = arr[j+1];
                found++;
                i--;
                n--;
            }
        }
        if(found==0)                    //to chek number in array
            cout<<"\nElement doesn't found in the Array!";
        else
            cout<<"\nElement Deleted Successfully!";
        cout<<endl;
        
        }

};

int main()
{
    ar a;
    a.display();
    a.insert();
    cout<<"array after insertion is:"<<endl;
    a.display();
    a.del();
    a.display();
    return 0;
}

