#include <iostream.h>
#include<conio.h>
class HelloWorld{
public:
  //Constructor
  HelloWorld(){
    cout<<"Constructor is called"<<endl;
  }
  //Destructor
  ~HelloWorld(){
    cout<<"Destructor is called"<<endl;
   }
   //Member function
   void display(){
     cout<<"Hello World!"<<endl;
   }
};
void main(){
   clrscr();
   //Object created
   HelloWorld obj;
   //Member function called
   obj.display();
   getch();
}
