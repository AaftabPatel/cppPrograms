#include<iostream.h>
#include<conio.h>

class time
{
 int hour;
 int min;
 public:
    time(){}

    time(int h,int m)
    {

     hour = h;
     min = m;
    }
    time operator+(time t);
    friend time operator>(time t1,time t2);

    void disp()
    {
     cout << hour<<":"<<min<<endl<<endl;
    }
};

time time:: operator+(time t)
{
 time temp;
 temp.min = min+t.min;

 temp.hour=min/60;
 temp.min= temp.min%60;

 temp.hour=temp.hour+hour+t.hour;

  return(temp);
}

time operator>(time t1,time t2)
{
 time rest;

 if (t1.hour>t2.hour)
    rest = t1;

 else  if(t1.hour<t2.hour)
    rest = t2;

 else if(t1.min>t2.min)
   rest = t1;

 else
    rest = t2;

   return(rest);
}


void main()
{
 clrscr();
 time t1(5,50);
 time t2(5,40);

 time t3,t4;

  t3 = t1+t2;     //calling opreator+();
  t4 = t1>t2;

  t1.disp();
  t2.disp();
   cout<<"\nThe addition of the above two times given here:";
  t3.disp();
   cout<<"\nThe greater time be:";
  t4.disp();

  getch();

}