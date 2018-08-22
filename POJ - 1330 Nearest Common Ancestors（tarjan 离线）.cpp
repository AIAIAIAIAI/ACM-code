#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int maxn=10005;
#define ms(a,x) memset(a,x,sizeof(a))
inline LL read()
{
    LL x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
vector<int> G[maxn],Q[maxn];
int par[maxn];
bool vis[maxn],root[maxn];
int ans,n;
void init()
{
    for(int i=0;i<=n;i++)
        par[i]=i;
    for(int i=0;i<=n;i++)
        G[i].clear(),Q[i].clear();
    for(int i=0;i<=n;i++)
        root[i]=true;
    ms(vis,false);
}
int find(int x)
{
    return x==par[x]?x:par[x]=find(par[x]);
}
void unite(int x,int y)
{
    x=find(x),y=find(y);
    if(x!=y)
        par[y]=x;
}
void dfs(int u)
{
    vis[u]=true;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(vis[v]) continue;
        dfs(v);
        unite(u,v);
    }
    for(int i=0;i<Q[u].size();i++){
        int v=Q[u][i];
        if(!vis[v]) continue;
        ans=find(v);
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        init();
        int u,v;
        for(int i=1;i<n;i++){
            cin>>u>>v;
            G[u].push_back(v);
            root[v]=false;
        }
        cin>>u>>v;
        Q[u].push_back(v);
        Q[v].push_back(u);
        for(int i=1;i<=n;i++){
            if(root[i]){
                dfs(i);
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}