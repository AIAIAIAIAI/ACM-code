#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main()
{
    string s;
    while(cin>>s)
    {
        int i,len=s.length();
        bool flag=false;
        for(i=0;i<len;i++)
            if(s[i]=='1')
            {    
                flag=true;
                break;
            }
        int cnt=0;
        for(;i<len;i++)
            if(s[i]=='0')
                cnt++;
        if(flag&&cnt>=6)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}