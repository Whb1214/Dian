 
#include<bits/stdc++.h>

using namespace std;

string s,key,num;
map <string,string> mp;
int mark;
char str[100010] ;


bool check(string s)
{
    for(int i = 0;i <= s.length();i++)
    {
        if(s[i] == ':')
        {
            mark = i;
            return true;
        }
    }
    return false;
}

int main()
{
    freopen("data.txt","r",stdin);
    while(cin >> s)
    {
        if(check(s))
        {
            mp.insert(make_pair(s.substr(0,mark),s.substr(mark+1,s.length()-mark)));
        }
    }
    fclose(stdin);
    freopen("CON","r",stdin);
    while(scanf("%s" , str))
    {
//        if(s == "Quit")return 0;
//        else 
//        {
//            for(auto it = mp.begin(); it != mp.end();it++)
//            {
//                //it->first it->second
//                if(s == it->first)
//                {
//                    cout << it->second << endl;
//                    continue;
//                }
//            }
//            cout << "Error" << endl;
//        }
        s = (string)str;
        if(s == "Quit")break;
        auto it = mp.find(s);
        if(it != mp.end())cout << it->second << endl; 
        
        else printf("%s\n","Error");
        
    }
}