#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int INF=0x3f3f3f3f;
typedef long long LL;

inline LL read()
{
    LL x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int main()
{
    int a1,a2,a3,a4,a5,a6;
    int p[4]={0,5,3,1};
    while(cin>>a1>>a2>>a3>>a4>>a5>>a6,a1||a2||a3||a4||a5||a6)
    {
        int ans=a6+a5+a4+(a3+3)/4;
        int cnt2=a4*5+p[a3%4];
        if(cnt2<a2)
            ans+=(a2-cnt2+8)/9;
        int cnt1=36*ans-36*a6-25*a5-16*a4-9*a3-4*a2;
        if(cnt1<a1)
            ans+=(a1-cnt1+35)/36;
        cout<<ans<<endl;
    }
    return 0;
}