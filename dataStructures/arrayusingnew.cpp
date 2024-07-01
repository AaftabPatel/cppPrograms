//program to dynamically allocate memory
#include<iostream>
using namespace std;

class ar{          //array class
  int *p;
  int size;
public:
     ar()           //constructor
     {
      cout<<"Please enter the size of array : ";
      cin>>size;
      p = new int[size];
      cout<<"Please enter the elements of array : ";
      for(int i=0;i<size;i++)
      {
        cin>>p[i];
      }
     }

  void display()         // function to display elemnts
  {
    cout<<"The elements of array are : ";
    for(int i=0;i<size;i++)
      {
        cout<<p[i]<<" ";
      }
  }
 ~ar()  // the destructor
 {
   delete p;
 } 
};
 int main()
{
  ar a;
  a.display();
  return 0;
}