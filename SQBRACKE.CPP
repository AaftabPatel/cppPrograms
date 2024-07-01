#include<iostream.h>
#include<conio.h>
class array{
int *ptr;
int a[100];
public:
	int size;
	int &operator[](int);
	~array(){
		delete a;
	}
	array(int n){
		size=n;
		for(int i=0;i<size;i++){
			cout<<"enter value at index "<<i<<endl;
			cin>>a[i];
			}
	}
	array(const array &a1){
		for(int i=0;i<a1.size;i++)
			a[i]=a1[i];

		}

	friend ostream &operator<<(ostream &aout, array &a1){
		aout<<"\nArray is:\n";
		for(int i=0;i<a1.size;i++){
			aout<<a1[i];
			cout<<" ,";
			}
		return aout;
	}

};
int & array::operator[](int index){
	if (index>=size){
	cout<<"array index out of bounds! \nexiting";
	}
	return ptr[index];
}

void main(){
clrscr();
int n;
cout<<"Enter the number of elements of array:";
cin>>n;
array a1(n);
cout<<a1[1];
array a2=a1;
cout<<a1;
cout<<a2;
getch();
}
