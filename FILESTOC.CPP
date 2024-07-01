#include<iostream.h>
#include<conio.h>
#include<fstream.h>
class inventory
{
public:
void store_data(){
	char data[100];
	ofstream out;
	out.open("stock.dat");
	cout<<"enter data into file:\n";
	cout<<"enter stock id:";
	cin.getline(data, 100);
	out<<data<<endl;

	cout<<"enter stock name:";
	cin>>data;
	out<<data<<endl;

	cout<<"enter stock arrival date:";
	cin>>data;
	out<<data<<endl;

	cout<<"enter stock price:";
	cin>>data;
	out<<data<<endl;

	out.close();

	}
void disp(){
	char data[100];
	ifstream in;
	in.open("stock.dat");
	cout<<"reading data from file:\n";
	in>>data;
	cout<<data<<endl;
	in>>data;
	cout<<data<<endl;
	in>>data;
	cout<<data<<endl;
	in>>data;
	cout<<data<<endl;

	in.close();

}
void modify(){
	char data[100];
	fstream mod;
	mod.open("stock.dat", ios::ate);
	cout<<"modify data into file:\n";
	cout<<"enter stock id:";
	cin.getline(data, 100);
	mod<<data<<endl;

	cout<<"enter stock name:";
	cin>>data;
	mod<<data<<endl;

	cout<<"enter stock arrival date:";
	cin>>data;
	mod<<data<<endl;

	cout<<"enter stock price:";
	cin>>data;

	cout<<"modified data is";
	mod<<data<<endl;
	mod>>data;

	cout<<data<<endl;
	mod>>data;

	cout<<data<<endl;
	mod>>data;

	cout<<data<<endl;
	mod>>data;

	cout<<data<<endl;
	mod>>data;

	mod.close();

}
};

void main()
{
clrscr();
inventory i1;
i1.store_data();
i1.disp();
i1.modify();
i1.disp();
getch();
}