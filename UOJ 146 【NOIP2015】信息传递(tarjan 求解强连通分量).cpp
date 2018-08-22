#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<string>
#include<vector>
#include<stack>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int maxn=1e4+5;
#define ms(a,x) memset(a,x,sizeof(a))
inline LL read()
{
    LL x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
vector<int> G[maxn];
stack<int> S;
int n,m,tot,scc;
int dfn[maxn],low[maxn],id[maxn];
bool vis[maxn];
void tarjan(int u)
{
	dfn[u]=low[u]=++tot;
	S.push(u);
	vis[u]=true;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(!dfn[v])
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(vis[v])
			low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u])
	{
		scc++;
		while(1)
		{
			int now=S.top();
			S.pop();
			vis[now]=false;
			id[now]=scc;
			if(now==u)
				break;
		}
	}
}
void solve()
{
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	for(int u=1;u<=n;u++)
		for(int i=0;i<G[u].size();i++)
		{
			int v=G[u][i];
			if(id[u]!=id[v])
				vis[id[u]]=true;
		}
	int cnt=0,p;
	for(int i=1;i<=scc;i++)
		if(!vis[i])
		{
			p=i;
			cnt++;
		}
	if(cnt>1)
	{
		cout<<"0"<<endl;
	}
	else
	{
		cnt=0;
		for(int i=1;i<=n;i++)
			if(id[i]==p)
				cnt++;
		cout<<cnt<<endl;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);		
	}
	solve();
}