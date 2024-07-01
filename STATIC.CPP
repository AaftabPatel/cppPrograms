#include<iostream.h>
#include<conio.h>
class item
{
static int count; //count is static int number;
int number;
public:

void getdata(int a)
{
number=a;
count++;
}

void getcount()
{
cout<<"count:";
cout<<count<<endl;
}
};
int item :: count ; //count defined
void main( )
{
item a,b,c;
a.get_count();
b.get_count();
c.get_count();
a.getdata();
b.getdata();
c.getdata();
cout<<"after reading data : "<<endl;
a.get_count( );
b.get_count( );
c.get count( );
getch();
}