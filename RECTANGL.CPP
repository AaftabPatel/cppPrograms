#include<iostream.h>
#include<conio.h>
class rectangle
{
float length;
float breadth;
public:
	void setlength(float l){
	length=l;
	}
	void setbreadth(float b){
	breadth=b;
	}
	float area(){
		float area;
		area=length*breadth;
		return(area);
		}
	float perimeter(){
		float perimeter;
		perimeter=2*(length+breadth);
		return(perimeter);
		}
	void show(){
		cout<<"length of the rectangle is:"<<length<<"\n";
		cout<<"breadth of the rectangle is:"<<breadth<<"\n";
		}
	int samearea(int rectangle){
		cout<<"on comparing :"<<rectangle;
		int s;
		if (r1.area()==r2.area())
			s=1;
		else
			s=0;

		return s;
		}
};
void main(){
clrscr();
float ar1, ar2, p1, p2;
rectangle r1, r2;
r1.setlength(5);
r1.setbreadth(2.5);
r2.setlength(5);
r2.setbreadth(18.9);
r1.show();
r2.show();
ar1=r1.area();
ar2=r2.area();
p1=r1.perimeter();
p2=r2.perimeter();
cout<<"area of rectangle 1 is:"<<ar1<<"\n";
cout<<"area of rectangle 2 is:"<<ar2<<"\n";
cout<<"perimeter of rectangle 1 is:"<<p1<<"\n";
cout<<"perimeter of rectangle 2 is:"<<p2<<"\n";
int s;
s=r1.samearea(r2);
cout<<s;
getch();
}