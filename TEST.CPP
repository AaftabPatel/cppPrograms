#include<iostream.h>
#include<conio.h>
class test
{
  private:
  int testcode;
  int nocad;
  int cenreq;
  char description[100];
  void calcntr()
  {
     cenreq=(nocad)/(100+1);
  }

  public:
  void schedule()
  {
    cout<<"Enter the test code:”<<”\N”;
    cin>>testcode;
   cout<<”Enter the description:”<<”\n”;
    cin>>description;
    cout<< “Enter the no of candidates greater than 101"<<"\n";
    cin>>nocad;
    calcntr();
  }
  void disptest()
  {
    cout<<"Test code="<<testcode<<"\n";
    cout<<"Description:"<<description <<"\n";
    cout<<"Number of candidates:"<<nocad<<"\n";
    cout<<"Centers required:"<<cenreq<<"\n";
  }
  };
  void main()
  {
  clrscr();

    test t;
      t.schedule();
      t.disptest();
     getch();
     }
