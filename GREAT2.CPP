#include<iostream.h>
#include<conio.h>
void main()
{
int n1, n2;
clrscr();
cout<<"please enter the first number:";
cin>>n1;
cout<<"please enter the second number:";
cin>>n2;
if(n1>n2)
	cout<<n1<<" is greater than "<<n2;
else if(n2>n1)
	cout<<n2<<" is greater than "<<n1;
else

	cout<<n1<<" and"<<n2<<" are equal";
getch();
}