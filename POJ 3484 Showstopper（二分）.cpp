#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
const int maxn=1e5+5;
using namespace std;
typedef long long LL;
LL x[maxn],y[maxn],z[maxn];
int cnt;
char str[maxn];
LL check(LL mid)
{
    LL sum=0;
    for(int i=0;i<cnt;i++)
    {
        if(mid<x[i])
            continue;
        LL t=min(mid,y[i]);
        sum+=(t-x[i])/z[i]+1;
    }
    return sum;
}
void solve()
{
    cnt=0;
    x[0]=0;
    sscanf(str,"%lld%lld%lld",&x[cnt],&y[cnt],&z[cnt]);
    cnt++;
    if(!x[0])
        return ;
    while(gets(str)&&str[0])
        sscanf(str,"%lld%lld%lld",&x[cnt],&y[cnt],&z[cnt]),cnt++;
    LL lb=0,ub=1LL<<32;
    while(ub-lb>1)
    {
        LL mid=(lb+ub)>>1;
        if(check(mid)%2)
            ub=mid;
        else
            lb=mid;
    }
    if(lb+1==(1LL<<32))
        cout<<"no corruption"<<endl;
    else
        cout<<ub<<' '<<check(ub)-check(ub-1)<<endl;
}
int main()
{
    while(gets(str))
        solve();
    return 0;
}