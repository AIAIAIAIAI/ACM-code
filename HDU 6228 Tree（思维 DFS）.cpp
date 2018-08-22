#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int ans;
const int maxn=2e5+5;
int num[maxn];
vector<int> G[maxn];
int n,k;
int dfs(int u,int pre)
{
    num[u]=1;//结点本身也算进去
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(v==pre)
            continue;
        dfs(v,u);
        num[u]+=num[v];
        if(num[v]>=k&&n-num[v]>=k)
            ans++;
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(num,0,sizeof(num));
        cin>>n>>k;
        for(int i=1;i<=n;i++)
            G[i].clear();
        for(int i=0;i<n-1;i++)
        {
            int u,v;
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        ans=0;
        cout<<dfs(1,-1)<<endl;
    }
    return 0;
}