#include<iostream.h>
#include<conio.h>
class complex
{
float img,real;
public:
complex(){
img=0;
real=0;
}
complex(float r, float i){
img=i;
real=r;
}
void show(){
cout<<real<<"+i"<<img;
}
complex operator+(complex &p){
complex z;
z.real=	real+p.real;
z.img=img+p.img;
return z;
}
};
void main(){
int r1,r2,i2,i1;
clrscr();
cout<<"please enter the real and imaginary part of first complex number:";
cin>>r1>>i1;
cout<<"please enter the real and imaginary part of second complex number:";
cin>>r2>>i2;
complex c1(r1,i1);
complex c2(r2,i2);
complex c;

cout<<"\nfirst compex number:";
c1.show();
cout<<"\nsecond complex number:";
c2.show();
c=c1+c2;
cout<<"\nsum of complex number:";
c.show();
getch();
}