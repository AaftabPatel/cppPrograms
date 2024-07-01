#include<iostream.h>
#include<conio.h>
void main()
{
int i=2,num,count=0;
clrscr();
cout<<"pleae enter the number:";
cin>>num;
for (;i<=num;i++)
	{
	if (num%i==0)
		count=count+1;
		break;
	}
if (count==0)
	cout<<num<<" is  a prime number";
else
	cout<<num<<" is not a prime number";
getch();
}