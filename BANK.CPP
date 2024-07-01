#include<iostream.h>
#include<conio.h>
#include<string.h>
class bank
{
char name[20];
int ano;
char atype[20];
float bal;
public:
void get(int no,char *n,char *t,float b)
{
strcpy(name,n);
ano=no;
strcpy(atype,t);
bal=b;
}
float deposit()
{
float amt;
cout<<"\nEnter amount to deposit:" ;
cin>>amt;
bal=bal+amt;
return bal;
}
float withdrw()
{
float amt;
cout<<"\nHow many Rupees to withdraw: ";
cin>>amt;
bal=bal-amt;
return bal;
}
void disp()
{
cout<<"\n\nAccount number: "<<ano;
cout<<"\n\nName: "<<name;
cout<<"\n\nAccount type: "<<atype;
cout<<"\n\nDeposit Amount: "<<deposit();
cout<<"\n\nAfter Withdraw Amount balnace: "<<withdrw();
}
};
void main()
{
int n;
char nm[20],t[20];
float a;
bank bk;
clrscr();
cout<<"\nEnter Account no.: ";
cin>>n;
cout<<"\nEnter Name: ";
cin>>nm;
cout<<"\nEnter account type: ";
cin>>t;
cout<<"\nEnter balance amount: ";
cin>>a;
bk.get(n,nm,t,a);
bk.disp();
getch();
}