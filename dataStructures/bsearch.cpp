// C++ program to implement recursive Binary Search
#include <iostream>
using namespace std;
 
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
  
        // If the element is present at the middle
        if (arr[mid] == x)
            return mid;
  
        // If element is smaller than mid
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
  
        // Else the element can only be present in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }
  
    return -1;
}
  
int main(void)
{   int arr[100], n, i, x;
    cout << "Enter the size of the array : ";
        cin >> n;
    cout << "Enter the elements of the array : ";
        for (i = 0; i < n; i++)
            cin >> arr[i];
    cout<<"\nplease enter the number to search:";
    cin>>x;
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at index " << result;
    return 0;
}