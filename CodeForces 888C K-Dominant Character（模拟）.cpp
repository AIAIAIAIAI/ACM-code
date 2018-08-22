/*#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
    string s;
    while(cin>>s)
    {
        int last[26];
        int a[26]={0},len=s.length();
        memset(last,-1,sizeof(last));
        for(int i=0;i<len;i++)
        {
            int t=s[i]-'a';
            if(last[t]==-1)
            {
                a[t]=i+1;
                last[t]=i;
            }
            else
            {
                a[t]=max(a[t],i-last[t]);
                last[t]=i;
            }
        }
        int ans=100000;
        for(int i=0;i<26;i++)//处理到字符串结尾的间隔
        {           
            if(last[i]!=-1)
            {
                a[i]=max(a[i],len-last[i]);
                ans=min(ans,a[i]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    string s;
    while(cin>>s)
    {
        int ans=1e6;
        for(int i='a';i<='z';i++)
        {
            int t=0,k=0;
            for(int j=0;j<s.length();j++)
            {
                if(s[j]==i)
                    t=0;
                else
                    t++;
                k=max(k,t);
            }
            ans=min(ans,k);
        }
        cout<<ans+1<<endl;
    }
    return 0;
}

