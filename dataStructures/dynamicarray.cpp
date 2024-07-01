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
  void search()  // function to search for an element
  {

    int i,n,t=0;
    cout<<"\nPlease enter an element to search : ";
    cin>>n;
    for( i=0;i<size;i++)
    {
      if(p[i]==n)
      {
        t++;
        break;
      }
    }
  if(t==1)
    {
      cout<<"\nElement found at index"<<i;
    }
  else
    cout<<"\nElement not found!";
}

void sort() // function to sort the elements in ascending order
{
  int temp;
  for(int i=0;i<size;i++){
    for(int j=i+1;j<size;j++){
      if(p[j]<p[i]){
      temp=p[i];
      p[i]=p[j];
      p[j]=temp;
      }
    }
}
cout<<"\nSorted array in ascending order is:"<<endl; 
for(int i=0;i<size;i++)
  {
    cout<<p[i]<<" ";
  }
}

void reverse()        //function to reverse array
{
  cout<<"\nThe reverse of array is: "<<endl;
  for(int i=size-1;i>=0;i--)
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
  a.search();
  a.sort();
  a.reverse();
  return 0;
}