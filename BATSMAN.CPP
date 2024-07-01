#include<iostream.h>
#include<conio.h>
class batsman
{
 private:
       long int bcode;
       char bname[20];
       float innings,notout,runs;
       float batavg;
       void  calavg()
         {
                  batavg=runs/(innings-notout);
          }
   public:
            void    readdata()
        {
                  cout<<"\n Enter batsman code:"<<"\n";
                  cin>>bcode;
               cout <<"Enter bats name:"<<"\n";
               cin>>bname;
               cout<<"Enter innings,notout,runs"<<"\n";
               cin>>innings>>notout>>runs;
               calavg();
                           }
              void displaydata()
                 {   
                    cout<<"Bats man code:"<<bcode<<"\n";
                    cout<<"Bats name:"<<bname<<"\n";
                    cout<<"Bats man innings:"<<innings<<"\n";
                    cout<<"Bats man notout:"<<notout<<"\n";
                    cout<<"Bats man runs:"<<runs<<"\n";
                   cout<<"Bats man avg:"<<batavg<<"\n";
                  }
      };
   void main()
   {
       clrscr();
       int n;
       batsman b[50];
       cout<<"Enter the number of batsman:"<<"\n";
       cin>>n;
      for(int i=0;i<n;i++)
         {
             b[i].readdata();
             b[i].displaydata();
          }
            getch();
   } 
