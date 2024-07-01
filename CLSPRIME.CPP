#include<iostream.h>
#include<conio.h>
class prime
{
int num;
public:
	void getdata(){
		cout<<"please enter the number to check:";
		cin>>num;
	}
	void check(){
		for(int i=2;i<num;i++){
		if (num%i==0) {
			cout<<"the number "<<num<<" is not prime\n";
			break;}
		else{
			cout<<"the number "<<num<<" is  prime\n";
		break;}
		}
	}

};
void main(){
prime p;
clrscr();
p.getdata();
p.check();
getch();
}