#include<bits/stdc++.h>
#include<windows.h>

using namespace std;

string s;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    while(1)
    {
        cout << "请输入:";
        cin>>s;
        if(s == "Dian")cout<<"2002"<<endl;
        else
        {
            if(s == "Quit")break;
            else cout<<"Error"<<endl;
        }
        }    
}