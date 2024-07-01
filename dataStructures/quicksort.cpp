//program to perform quick sort
#include <iostream>
using namespace std;

class ar                    //class array
{
    int arr[100],i,j;
    public:
        int n;
        void swap(int* a, int* b)       //function to do swapping 
        { 
            int t = *a; 
            *a = *b; 
            *b = t; 
        } 

        int takearray()                   //function to take array
        {
            cout<<"Please enter the number of elements you want:";
            cin>>n;
            cout<<"Please enter the elements:\n";
            for(i=0; i<n; i++)
                cin>>arr[i];        
            return n;
        }
        
        // partition the array using last element as pivot
        int partition (int low, int high) 
        { 
            int pivot = arr[high];    // pivot 
            i = (low - 1);   
        
            for (j = low; j <= high- 1; j++) 
            { 
                //if current element is smaller than pivot, increment the low element
                //swap elements at i and j
                if (arr[j] < pivot) 
                { 
                    i++;    // increment index of smaller element 
                    swap(&arr[i], &arr[j]); 
                } 
            } 
            swap(&arr[i + 1], &arr[high]);   //swapping 
            return (i + 1); 
        } 
        
        void quickSort(int low, int high)    //function for quik sort 
        { 
            if (low < high) 
            { 
                //partition the array 
                int pivot = partition(low, high); 
        
                //sort the sub arrays independently 
                quickSort(low, pivot - 1);         //recursion
                quickSort(pivot + 1, high); 
            } 
        } 
        
        void display(int size) //function to display array
        {  
            for (i=0; i < size; i++) 
                cout<<arr[i]<<"   "; 
            
        } 
}; 
 
int main() 
{ 
    ar a;
    int n=a.takearray();            //taking the size of the array
    cout<<"Array is:"<<endl;
    a.display(n);
    a.quickSort( 0, n-1); 
    cout<<"\nArray after quick sort is:"<<endl;   
    a.display(n); 
    return 0; 
}