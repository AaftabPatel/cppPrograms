#include<iostream.h>
#include<conio.h>
void main()
{
int ch,i,j,k;
clrscr();
do
{
cout<<"\nMENU";
cout<<"\n1=input a matrix";
cout<<"\n2=display a matrix";
cout<<"\n3=add two matrix";
cout<<"\n4=multiplication of two matrix";
cout<<"\n5=transpose of a matrix";
cout<<"\n6=exit";
cout<<"\nplease enter your choice:";
cin>>ch;
int a[3][3];
int b[3][3];
int add[3][3];
int res[3][3];
switch(ch)
	{
	case 1:
		for(j=0;j<3;++j)
		{
		for(i=0;i<3;++i)
			{
			cout<<"enter element"<<j+1<<i+1<<":";
			cin>>a[j][i];
			}
	       }
	       break;
	case 2:
		for(j=0;j<3;++j)
		{
			for(i=0;i<3;++i)
			{
			cout<<a[j][i]<<" ";
			if(i==2)
				{
				cout<<"\n";
				}
			}
		}
		break;
	case 3:cout<<"please eneter the elements of the second matrix:\n";
		for(j=0;j<3;++j)
			{
			for(i=0;i<3;++i)
				{
				cout<<"enter element a"<< j+1<<i+1<<":";
					cin>>b[j][i];
				}
			}
		for(j=0;j<3;++j)
				{
			for(i=0;i<3;++i)
				add[j][i]=a[j][i]+b[j][i];
			}
		for(j=0;j<3;++j)
			{
			for(i=0;i<3;++i)
			{
				cout<<add[j][i]<<" ";
				if(i==2)
					{
					cout<<"\n\n";
					}
				}
			}
		break;
	case 4: cout<<"please eneter the elements of the second matrix:\n";
		for(j=0;j<3;++j)
		{
		for(i=0;i<3;++i)
			{
			cout<<"enter element b"<<j+1<<i+1<<":";
			cin>>b[j][i];
			}
		}
	for(j=0;j<3;++j)
		{
		for(i=0;i<3;++i)
			{
			int n=0;
			for(k=0;k<3;++k)
				{
				n+=a[j][k]*b[k][i];
				}
			res[j][i]=n;
			}
		}
	for(j=0;j<3;++j)
		{
		for(i=0;i<3;++i)
			{
			cout<<res[j][i]<<" ";
			if(i==2)
				{
				cout<<"\n";
				}
			}
	}
	break;
	case 5:for(i=0;i<3;++i)
		{
		for(j=0;j<3;++j)
			{
			cout<<a[j][i]<<" ";
			if(j==2)
				{
				cout<<"\n";
				}
			}
		}
		break;
	case 6:cout<<"thank you";
		break;
	default:cout<<"please enter correct choice!!!";
	}
}
while(ch!=6);
getch();
}