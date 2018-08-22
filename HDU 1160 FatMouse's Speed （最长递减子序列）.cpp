#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=1005;
typedef long long LL;
int dp[maxn],path[maxn];
struct mouse
{
    int id,w,s;
    bool operator <(const mouse& x)const 
    {
        if(w==x.w)
            return  s>x.s;
        return w<x.w;
    }
}m[maxn];
void print(int x)
{
    if(x==-1)
        return ;
    print(path[x]);
    printf("%d\n",x);
}
int main()
{
    int n=0,we,sp;
    while(~scanf("%d%d",&we,&sp))
    {
        m[n].id=n+1;
        m[n].w=we;
        m[n++].s=sp;
    }
    sort(m,m+n);
    memset(path,-1,sizeof(path));
    int ans=0,ans_id;
    for(int i=0;i<n;i++)
    {
        dp[i]=1;
        for(int j=0;j<i;j++) 
        {
            if(m[j].w<m[i].w&&m[j].s>m[i].s&&dp[i]<=dp[j])
            {
                dp[i]=dp[j]+1;
                path[m[i].id]=m[j].id;
            }
        }
        if(dp[i]>ans)
        {
            ans=dp[i];
            ans_id=m[i].id;
        }
    }
    printf("%d\n",ans);
    print(ans_id);
    return 0;
}