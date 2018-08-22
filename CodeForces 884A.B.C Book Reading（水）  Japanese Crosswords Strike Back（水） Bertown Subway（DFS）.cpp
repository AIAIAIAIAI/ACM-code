#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1e5+5;
int a[maxn];
bool vis[maxn];
int b[maxn];
int dfs(int s,int next,int res)
{
    if(next==s)
        return res;
    if(!vis[next])
    {
        vis[next]=true;
        return dfs(s,a[next],res+1);
    }
    return res;
}
int main()
{
    int n;
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
            cin>>a[i];
        memset(vis,false,sizeof(vis));
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                vis[i]=true;
                b[cnt++]=dfs(i,a[i],1);
            }
        }
        sort(b,b+cnt);
        long long ans=0;
        for(int i=0;i<cnt-2;i++)
            ans+=b[i]*b[i];
        ans+=(long long)(b[cnt-2]+b[cnt-1])*(b[cnt-2]+b[cnt-1]);
        cout<<ans<<endl;
    }
    return 0;
}