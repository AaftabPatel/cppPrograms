#include<iostream.h>
#include<conio.h>
class flight
{
private:
	int fno;
	char dest[10];
	float dist;
	float fuel;
	float calfuel(float k);

public:
	void feedinfoo();
	void showinfoo();
};
float flight::calfuel(float k)
	  {
	  float total;
	  if(k<=1000)
		total=500;
	  else if((k>1000)&&(k<=2000))
	      {
	      total=1100;
	      }
	  else{
	      total=2200;
	      }
	  return total;
	  }

void flight::feedinfoo()
{
   cout<<"Enter the flight no:";
   cin>>fno;
   cout<<"\nEnter\n*destination:";
   cin>>dest;
   cout<<"\n*distance:";
   cin>>dist;
   float total;
   total=calfuel(dist);
}
void flight::showinfoo()
	{
		float total;
		cout<<"\n\n\t********INFORMATION*********";
		cout<<"\n*Flight number:"<<fno;
		cout<<"\n*Destination:"<<dest;
		cout<<"\n*Distance:"<<dist<<"km";
		cout<<"\n*Total fuel required:"<<total<<"liter"<<"\n";
	}
void main()
{
clrscr();
flight f;
f.feedinfoo();
f.showinfoo();
getch();
}
