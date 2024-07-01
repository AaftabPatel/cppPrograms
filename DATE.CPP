#include<iostream.h>
#include<conio.h>
class date
{
int mm,dd,yy;
public:
date(){}
date(int d, int m, int y)
{
dd=d;
mm=m;
yy=y;
}
date operator++(){
date temp;
temp.dd=dd+1;
temp.mm=mm;
temp.yy=yy;
return temp;
}
friend istream &operator>>(istream &in, date &d)
friend ostream &operator<<(ostream &out, date &d)
};
istream &operator>>(istream &in, date &d)
{
cout<<"\n Enter the day:";
in>>d.dd;
cout<<"\n Enter the month:";
in>>d.mm;
cout<<"\n Enter the year:";
in>>d.yy;
return in;
}
ostream &operator<<(ostream &out, date &d)
{
out<<"\n Date is:\n";
out<<d.dd<<"/"<<d.mm<<"/"<<d.yy;
return out;
}
void main(){
date d1(2,3,2003);
clrscr();
date d2,d3;
cin>>d2;
d3=++d2;
cout<<d1;
cout<<d2;
cout<<d3;
getch();
}