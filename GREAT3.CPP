#include<iostream.h>
#include<conio.h>
void main()
{
int n1, n2, n3;
clrscr();
cout<<"please enter the first number:";
cin>>n1;
cout<<"please enter the second number:";
cin>>n2;
cout<<"please enter the third number:";
cin>>n3;
if((n1==n2) && (n2==n3))
	cout<<"all three numbers are equal";
else if((n1>n2) && (n1>n3))
	cout<<n1<<" is greatest ";
else if((n2>n1) && (n2>n3))
	cout<<n2<<" is greatest";
else
	cout<<n3<<" is greatest";
getch();
}