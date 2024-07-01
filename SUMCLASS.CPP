#include<iostream.h>
#include<conio.h>
class sum
{
float num1;
float num2;
public:
	void getdata(){
		cout<<"please enter the first number:";
		cin>>num1;
		cout<<"please enter the second number:";
		cin>>num2;
	}
	void showdata(){
		cout<<"the first number is:"<<num1<<"\n";
		cout<<"the second number is:"<<num2<<"\n";
	}
	float add(){
		float add;
		add=num1+num2;
		return(add);
	}
};
void main(){
float s;
sum sum1;
clrscr();
sum1.getdata();
sum1.showdata();
s=sum1.add();
cout<<"sum of the numbers is:"<<s;
getch();
}