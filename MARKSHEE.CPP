#include<iostream.h>
#include<conio.h>
class result
{
public:
     int eno, rno;
     char sname[25];
     float s1,s2,s3,s4,s5,p1,p2,p3,p4,p5;
     float total1,total2,per;
     void  thtotal(){
	       total1=s1+s2+s3+s4+s5;
	       }
     void  ptotal(){
	       total2=p1+p2+p3+p4+p5;
	       }
     void percentage(){
		per=(s1+s2+s3+s4+s5)/5;
     }
char grade(int s){
char g;
if (s>=90)
	g='A';
else if (s>=80 && s<90)
	g='B';
else if (s>=70 && s<80)
	g='C';
else if (s>=60 && s<70)
	g='D';
else if (s>=33 && s<60)
	g='E';
else
	g='F';
return g;
}

friend istream &operator >>(istream &in, result &r);
friend ostream &operator <<(ostream &out, result &r);
};
istream &operator >>(istream &in, result &r){
		cout<<"Enter enrollment no.:";
		in>>r.eno;
		cout<<"Enter the roll no.:";
		in>>r.rno;
		cout<<"Enter student name:";
		in>>r.sname;
		cout<<"Enter theory marks:";
		in>>r.s1>>r.s2>>r.s3>>r.s4>>r.s5;
		cout<<"Enter practical marks:";
		in>>r.p1>>r.p2>>r.p3>>r.p4>>r.p5;
		r.thtotal();
		r.ptotal();
		r.percentage();
		return in;
}
ostream &operator <<(ostream &out, result &r){
	     out<<"..Student result.."<<"\n";
	     out<<"Enrollment number="<<r.eno<<"\n";
	     out<<"Roll number="<<r.rno<<"\n";
	     out<<"Student name:"<<r.sname<<"\n";
	     out<<"Subject1 marks:\ntheory:"<<r.s1<<" practical:"<<r.p1<<" grade:"<<r.grade(r.s1)<<"\n";
	     out<<"Subject2 marks:\ntheory:"<<r.s2<<" practical:"<<r.p2<<" grade:"<<r.grade(r.s2)<<"\n";
	     out<<"Subject3 marks:\ntheory:"<<r.s3<<" practical:"<<r.p3<<" grade:"<<r.grade(r.s3)<<"\n";
	     out<<"Subject4 marks:\ntheory:"<<r.s4<<" practical:"<<r.p4<<" grade:"<<r.grade(r.s4)<<"\n";
	     out<<"Subject5 marks:\ntheory:"<<r.s5<<" practical:"<<r.p5<<" grade:"<<r.grade(r.s5)<<"\n";
	     out<<"Total theory marks:"<<r.total1<<"\n";
	     out<<"Total practical marks:"<<r.total2<<"\n";
	     out<<"Percentage is:"<<r.per<<"\n";
	     return out;
}

void  main()
{
result r1;
clrscr();
char ch;

do{
cout<<"Please enter the data:\n";
cin>>r1;
cout<<r1;
cout<<"Do you want to cuntinue(y for yes & n for no):";
cin>>ch	;
}
while(ch!='n');
getch();
}

