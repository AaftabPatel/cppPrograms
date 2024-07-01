//program to add two matrix
#include<iostream>
using namespace std;

class matrix             //class matrix
{
	int i,j,k,n;
	public:
		int a[3][3]={0},res[3][3]={0};
		
		void display(int m[3][3])       //function to display matrix
		{
			for(j=0;j<3;++j)
				{
				for(i=0;i<3;++i)
					{
					cout<<m[j][i]<<" ";
					if(i==2)
						cout<<"\n\n";
					}
				}
		}
		
		int takematrix()	//function to take matrix data
		{
		cout<<"please eneter the elements of the matrix:\n";
		for(j=0;j<3;++j)
			{
			for(i=0;i<3;++i)
				{
				cout<<"enter element e"<<j+1<<i+1<<":";
				cin>>a[j][i];
				}
			}
			return a[3][3];
		}
		
		void matadd(int m1[3][3],int m2[3][3])    //function to add two matrix
		{
			for(j=0;j<3;++j)
			{
			for(i=0;i<3;++i)
				{
				res[j][i]=m1[j][i]+m2[j][i];	
				}
			}
			cout<<"after addition:\n";    //printing added matrix
			for(j=0;j<3;++j)
				{
				for(i=0;i<3;++i)
					{
					cout<<res[j][i]<<" ";
					if(i==2)
						cout<<"\n\n";
					}
				}
		}
};

int main()
{
	matrix m1,m2,m3;
	int a[3][3],b[3][3],i,j;
	a[3][3]=m1.takematrix();
	b[3][3]=m2.takematrix();
	cout<<"Fist matrix is:\n";
	m1.display(a);
	cout<<"Second matrix is:\n";
	m2.display(b);
	m3.matadd(a,b);
	return 0;
}
