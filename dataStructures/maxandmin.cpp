#include<iostream>
using namespace std;

class ar              //class array
{
    int arr[100], n, i, max, min;
    
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


        void maximum()           //function to find maximum value
            {
            max = arr[0];
            for (i = 0; i < n; i++)
                {
                if (max < arr[i])
                    max = arr[i];
                }
            cout << "\nLargest element : " << max;
            }
        void minimum()           //function to find minimum value
            {
            min = arr[0];
            for (i = 0; i < n; i++)
                {
                if (min > arr[i])
                    min = arr[i];
                }
                cout << "\nSmallest element : " << min<<endl;
            }
};

int main()
{
    ar a;
    a.display();
    a.maximum();
    a.minimum();
    return 0;
}