#include<iostream.h>
#include<conio.h>
class student
{
private:
     int admno;
     char sname[20];
     float eng,math,sci;
     float total;
     void  ctotal(){
	       total=eng+math+sci;
	       }
public:
	void  takedata(){
		cout<<"Enter admission no.:";
		cin>>admno;
		cout<<"Enter student name:";
		cin>>sname;
		cout<<"Enter marks of english,maths,science:";
		cin>>eng>>math>>sci;
		ctotal();
		}

	void  showdata(){
	     cout<<"..Student details.."<<"\n";
	     cout<<"Admission number="<<admno<<"\n";
	     cout<<"Student name:"<<sname<<"\n";
	     cout<<"English marks:"<<eng<<"\n";
	     cout<<"Maths  marks:"<<math<<"\n";
	     cout<<"Science marks:"<<sci<<"\n";
	     cout<<"Total marks:"<<total;
	     }
	   };

 void  main()
{
clrscr();
student s[50];
int n,i;
cout<<"Enter the number of student:";
cin>>n;
for(i=0;i<n;i++)
	{
	s[i].takedata();
	s[i].showdata();
	}
getch();
}

