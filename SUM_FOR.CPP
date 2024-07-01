#include<iostream.h>
#include<conio.h>
void main()
{
int i, n, sum=0;
clrscr();
cout<<"plese enter the number till you want to sum:";
cin>>n;
for(i=1;i<=n;i++)
	{cout<<i<<",";
	sum=sum+i;
	}
cout<<"\nsum is:"<<sum;
getch();
}