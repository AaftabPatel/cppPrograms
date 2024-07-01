//program to perform array sort and merging
#include<iostream>
using namespace std;

class ar              //class array
{
    int i, j;
    
    public:
        void swap(int* a, int* b)       //function to do swapping 
        { 
            int t = *a; 
            *a = *b; 
            *b = t; 
        } 

        void display(int ar[],int n)         //function to display array
    {
        cout<<"\nElements of the array are:\n";
        for(i=0; i<n; i++)
            {
            cout<<ar[i]<<" ";
            }
    }
    
    void sort(int ar[],int n)                //function to do sorting
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

        void merge(int ar1[], int ar2[], int n1, int n2)
            {
                int arr[100];
                i=0;
                j=0;
                int k=0;
                while(i<n1 && j<n2)
                    {
                        if(ar1[i]<ar2[j])
                            {
                            arr[k]=ar1[i];
                            i++;
                            k++;
                            }
                        else
                            {
                            arr[k]=ar2[j];
                            j++;
                            k++;
                            }
                    }
                // Store remaining elements of first array
                while (i < n1)
                    arr[k++] = ar1[i++];
            
                // Store remaining elements of second array
                while (j < n2)
                    arr[k++] = ar2[j++];

                //printing sorted and merged array
                cout<<"\narray after merging:\n";     
                for(i=0;i<n1+n2;i++)
                    cout<<arr[i]<<" ";
            }
};

int main()
{
    ar a;
    int n1,n2,i;
    int ar1[100],ar2[100];
    
    //taking array of first array
    cout<<"please enter the number of elements in first array:";
    cin>>n1;
    cout<<"Please enter the elements:\n";
            for(i=0; i<n1; i++)
                cin>>ar1[i];
    
    //taking elements of second array
    cout<<"please enter the number of elements in second array:";
    cin>>n2;
    cout<<"Please enter the elements:\n";
            for(i=0; i<n2; i++)
                cin>>ar2[i];
   
    //displaying arrays
    a.display(ar1,n1);
    a.display(ar2,n2);

    //sorting indivisual array
    a.sort(ar1,n1);
    a.sort(ar2,n2);

    //merging sorted array
    a.merge(ar1,ar2,n1,n2);
    return 0;
}