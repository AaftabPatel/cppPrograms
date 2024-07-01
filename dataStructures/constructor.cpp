//program to illusrate class object and types of constructor
#include<iostream>
using namespace std;

class point{         //class
public:
	int a,b;
	point(){          //default constructor
		a=10;
		b=20;
	}

	point(int x, int y=7){     //parameterised constructor
		a=x;
		b=y;
	}

	point(const point &c){     //copy constructor
		a=c.a;
		b=c.b;
	}

	void displaydata(){        
		cout<<"\na="<<a<<endl;
		cout<<"b="<<b<<endl;
	}
};

int main()
{
point p1;            //object
point p2(5,2);
point p3(3);
point p4=p2;

p1.displaydata();
p2.displaydata();
p3.displaydata();
p4.displaydata();
return 0;
}