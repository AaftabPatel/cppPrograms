#include<iostream.h>
#include<conio.h>
void main()
{
int n1,ch,n2,res;
clrscr();
cout<<"\nMENU";
cout<<"\n1=and operator";
cout<<"\n2=or operator";

cout<<"\nplease enter your choice:";
cin>>ch;

cout<<"please enter the first number(1 or 0):";
cin>>n1;

cout<<"please enter the second number(1 or 0):";
cin>>n2;

switch(ch)
	{
	case 1:res=n1&n2;
	       cout<<res;
	       break;
	case 2:res=n1|n2;
	       cout<<res;
	       break;
	default:cout<<"please enter the correct number!!!";
	}
getch();
}
