#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<fstream.h>
class student
{
    char admno[6];
    char name[20];
    char stbno[6];
    int token;
public:
    void create_student()
    {
        clrscr();
         cout<<"\nNEW STUDENT ENTRY...\n";
        cout<<"\nEnter The admission no. ";
        cin>>admno;
        cout<<"\n\nEnter The Name of The Student ";
        gets(name);
        token=0;
        stbno[0]='/0';
        cout<<"\n\nStudent Record Created..";
    }

    void show_student()
    {
        cout<<"\nAdmission no. : "<<admno;
        cout<<"\nStudent Name : ";
        puts(name);
        cout<<"\nNo of Book issued : "<<token;
        if(token==1)
            cout<<"\nBook No "<<stbno;
    }

    void modify_student()
    {
        cout<<"\nAdmission no. : "<<admno;
        cout<<"\nModify Student Name : ";
        gets(name);
    }


class book
{
	char bno[6];
	char bname[50];
	char aname[20];
  public:
	void create_book()
	{
        cout<<"\nNEW BOOK ENTRY...\n";
        cout<<"\nEnter The book no.";
        cin>>bno;
        cout<<"\n\nEnter The Name of The Book ";
        gets(bname);
        cout<<"\n\nEnter The Author's Name ";
        gets(aname);
        cout<<"\n\n\nBook Created..";
    }

    void show_book()
    {
        cout<<"\nBook no. : "<<bno;
        cout<<"\nBook Name : ";
        puts(bname);
        cout<<"Author Name : ";
        puts(aname);
    }

    void modify_book()
    {
        cout<<"\nBook no. : "<<bno;
        cout<<"\nModify Book Name : ";
        gets(bname);
        cout<<"\nModify Author's Name of Book : ";
        gets(aname);
    }
};

class student
{
    char admno[6];
    char name[20];
    char stbno[6];
    int token;
public:
    void create_student()
    {
        clrscr();
         cout<<"\nNEW STUDENT ENTRY...\n";
        cout<<"\nEnter The admission no. ";
        cin>>admno;
        cout<<"\n\nEnter The Name of The Student ";
        gets(name);
        token=0;
        stbno[0]='/0';
        cout<<"\n\nStudent Record Created..";
    }

    void show_student()
    {
        cout<<"\nAdmission no. : "<<admno;
        cout<<"\nStudent Name : ";
        puts(name);
        cout<<"\nNo of Book issued : "<<token;
        if(token==1)
            cout<<"\nBook No "<<stbno;
    }

    void modify_student()
    {
        cout<<"\nAdmission no. : "<<admno;
        cout<<"\nModify Student Name : ";
        gets(name);
    }

};


void display_allb()
{
    clrscr();
    fp.open("book.dat",ios::in);
    if(!fp)
    {
        cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
               getch();
               return;
         }

    cout<<"\n\n\t\tBook LIST\n\n";
    cout<<"=========================================================================\n";
    cout<<"Book Number"<<setw(20)<<"Book Name"<<setw(25)<<"Author\n";
    cout<<"=========================================================================\n";

    while(fp.read((char*)&bk,sizeof(book)))
    {
        bk.report();
    }
         fp.close();
         getch();
}


void book_deposit()
{
    char sn[6],bn[6];
    int found=0,flag=0,day,fine;
    clrscr();
    cout<<"\n\nBOOK DEPOSIT ...";
    cout<<"\n\n\tEnter The student’s admission no.";
    cin>>sn;
    fp.open("student.dat",ios::in|ios::out);
    fp1.open("book.dat",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(student)) && found==0)
       {
        if(strcmpi(st.retadmno(),sn)==0)
        {
            found=1;
            if(st.rettoken()==1)
            {
            while(fp1.read((char*)&bk,sizeof(book))&& flag==0)
            {
               if(strcmpi(bk.retbno(),st.retstbno())==0)
            {
                bk.show_book();
                flag=1;
                cout<<"\n\nBook deposited in no. of days";
                cin>>day;
                if(day>15)
                {
                   fine=(day-15)*1;
                   cout<<"\n\nFine has to deposited Rs. "<<fine;
                }
                    st.resettoken();
                    int pos=-1*sizeof(st);
                    fp.seekp(pos,ios::cur);
                    fp.write((char*)&st,sizeof(student));
                    cout<<"\n\n\t Book deposited successfully";
            }
            }
          if(flag==0)
            cout<<"Book no does not exist";
              }
         else
            cout<<"No book is issued..please check!!";
        }
       }
      if(found==0)
    cout<<"Student record not exist...";
    getch();
  fp.close();
  fp1.close();
  }






void book_issue()
{
    char sn[6],bn[6];
    int found=0,flag=0;
    clrscr();
    cout<<"\n\nBOOK ISSUE ...";
    cout<<"\n\n\tEnter The student's admission no.";
    cin>>sn;
    fp.open("student.dat",ios::in|ios::out);
        fp1.open("book.dat",ios::in|ios::out);
        while(fp.read((char*)&st,sizeof(student)) && found==0)
           {
        if(strcmpi(st.retadmno(),sn)==0)
        {
            found=1;
            if(st.rettoken()==0)
            {
                      cout<<"\n\n\tEnter the book no. ";
                cin>>bn;
                while(fp1.read((char*)&bk,sizeof(book))&& flag==0)
                {
                       if(strcmpi(bk.retbno(),bn)==0)
                    {
                        bk.show_book();
                        flag=1;
                        st.addtoken();
                        st.getstbno(bk.retbno());
                               int pos=-1*sizeof(st);
                        fp.seekp(pos,ios::cur);
                        fp.write((char*)&st,sizeof(student));
                        cout<<"\n\n\t Book issued successfully\n\nPlease Note: Write current date 
                        in backside of book and submit within 15 days fine Rs. 1 for each day     
                        after 15 days period";
                    }
                    }
                  if(flag==0)
                        cout<<"Book no does not exist";
            }
                else
                  cout<<"You have not returned the last book ";

        }
    }
          if(found==0)
        cout<<"Student record not exist...";
    getch();
      fp.close();
      fp1.close();
}







void intro()
{
    clrscr();
    gotoxy(35,11);
    cout<<"LIBRARY";
    gotoxy(35,14);
    cout<<"MANAGEMENT";
    gotoxy(35,17);
    cout<<"SYSTEM";
    cout<<"\n\nMADE BY : YOUR NAME";
    cout<<"\n\nSCHOOL : SCHOOL NAME";
    getch();
}













void main()
{
    char ch;
    intro();
    do
    {
        clrscr();
        cout<<"\n\n\n\tMAIN MENU";
        cout<<"\n\n\t01. BOOK ISSUE";
        cout<<"\n\n\t02. BOOK DEPOSIT";
          cout<<"\n\n\t03. BOOK LIST";
          cout<<"\n\n\t04. EXIT";
          cout<<"\n\n\tPlease Select Your Option (1-4) ";
          ch=getche();
          switch(ch)
          {
            case '1':clrscr();
                 book_issue();
                    break;
              case '2':book_deposit();
                     break;
              case '3':book_list();
                 break;
              case '4':exit(0);
              default :cout<<"\a";
        }
        }while(ch!='4');
getch();
}