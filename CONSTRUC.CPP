#include<iostream.h>
#include<conio.h>
class point{
public:
	int a,b;
	point(){
		a=10;
		b=20;
	}
	point(int x, int y=7){
		a=x;
		b=y;
	}
	point(const point &c){
		a=c.a;
		b=c.b;
	}
	void displaydata(){
		cout<<"\na="<<a<<endl;
		cout<<"b="<<b<<endl;
	}
};
void main()
{
clrscr();
point p1;
point p2(5,2);
point p3(3);
point p4=p2;

p1.displaydata();
p2.displaydata();
p3.displaydata();
p4.displaydata();
getch();
}