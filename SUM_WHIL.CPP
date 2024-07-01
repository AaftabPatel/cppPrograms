#include<iostream.h>
#include<conio.h>
void main()
{
int i=1, n, sum=0;
clrscr();
cout<<"plese enter the number till you want to sum:";
cin>>n;
while(i<=n){
	cout<<i<<",";
	sum=sum+i;
	i++;
	}
cout<<"\nsum is:"<<sum;
getch();
}