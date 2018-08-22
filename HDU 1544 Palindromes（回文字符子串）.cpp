#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    string s;
    while(cin>>s)
    {
        int ans=0;
        int len=s.length();
        for(int i=1;i<len-1;i++)
        {
            for(int j=1;i-j>=0&&i+j<len;j++)
            {
                if(s[i-j]==s[i+j])
                    ans++;
                else
                    break;
            }
        }
        for(int i=0;i<len-1;i++)
        {
            for(int j=0;i-j>=0&&i+j+1<len;j++)
            {
                if(s[i-j]==s[i+j+1])
                    ans++;
                else
                    break;
            }
        }
        cout<<ans+len<<endl;
    }
    return 0;
}