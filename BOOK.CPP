#include<iostream.h>
#include<conio.h>

class book
{
   private:
             int bno;
            char btytle[20];
            float price;
           float total_cost(int x)
            {
                    float total;
                    total=price*x;
                    return total;
             }
public:
          void input()
               {
                           cout<<"\nEnter book no\tbook tytle\tprice of the book"<<"\n";
                           cin>>bno;
                          cin>>btytle;
                           cin>>price;
            }
          void purchase()
          {
            cout<<"Enter the number of copies to be purchased"<<"\n";
             int n;
            cin>>n;
            float total;
           total=total_cost(n);
             cout<<"Total cost to be paid by the user:"<<total<<"/- rupees"<<"\n";
         }
};
void main()
{
clrscr();
book b;
b.input();
b.purchase();
getch();
}
