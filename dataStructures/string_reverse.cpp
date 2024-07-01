//program to reverse a string
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    cout<<"please enter the string you want to reverse:";
    getline(cin, s);
    int c=s.length();
    cout<<"string is:\n";
    cout <<s<<endl;
    cout<<"string in reverse is:\n";
    for(int i=c-1;i>=0;i--)
        cout<<s[i];
    return 0;
}