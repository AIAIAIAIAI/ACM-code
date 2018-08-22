#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
int main()
{
    int m;
    while(cin>>m&&m)
    {
        int a,b;
        cin>>a>>b;
        LL c=a+b;
        char s[100];
        int cnt=0;
        if(c==0)
        {
            cout<<0<<endl;
            continue;
        }
        while(c)
        {
            s[cnt++]=c%m+'0';
            c/=m;
        }
        for(int i=cnt-1;i>=0;i--)
            cout<<s[i];
        cout<<endl;
    }
    return 0;
}