#include<iostream.h>
#include<conio.h>
//program for swapping of two number:
void main(){
int n1, n2, temp;
clrscr();
cout<<"please enter the first number:";
cin>>n1;
cout<<"please enter the second number:";
cin>>n2;
cout<<"before swapping the value of n1 and n2 is:"<<n1<<" & "<<n2<<"\n";
temp=n1;
n1=n2;
n2=temp;
cout<<"after swapping the value of n1 and n2 is:"<<n1<<" & "<<n2;
getch();
}