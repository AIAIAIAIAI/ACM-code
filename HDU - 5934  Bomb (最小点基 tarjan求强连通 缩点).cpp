#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<cstdio>
#include<stack>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int maxn=1005;
#define ms(a,x) memset(a,x,sizeof(a))
inline LL read()
{
    LL x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct node
{
	LL x,y,r;
	int c;
}p[maxn];
inline LL sqr(LL x)//平方
{
	return x*x;
}
bool check(node& a,node& b)//判断是否能引爆
{
	if(sqr(a.x-b.x)+sqr(a.y-b.y)<=sqr(a.r))
		return true;
	return false;
}
vector<int> G[maxn];
int dfn[maxn],low[maxn],id[maxn];
bool vis[maxn];
int mincost[maxn],deg[maxn];
int tot,scc;
stack<int> S;
void tarjan(int u)//tarjan缩点
{
	dfn[u]=low[u]=++tot;
	S.push(u);
	vis[u]=true;
	for(int v:G[u])
	{
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
			int v=S.top();
			S.pop();
			vis[v]=false;
			id[v]=scc;
			if(v==u)
				break;
		}
	}
}
int n;
void init()
{
	tot=0;
	scc=0;
	for(int i=0;i<n;i++)
		G[i].clear();
	ms(vis,0);
	ms(deg,0);
	ms(mincost,INF);
	ms(low,0);
	ms(dfn,0);
	ms(id,0);
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	int cnt=0;
	while(t--)
	{
		init();
		cin>>n;
		for(int i=0;i<n;i++)
		{
			LL x,y,r;
			int c;
			cin>>x>>y>>r>>c;
			p[i]=(node){x,y,r,c};
		}
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(check(p[i],p[j]))
					G[i].push_back(j);
				if(check(p[j],p[i]))
					G[j].push_back(i);
			}
		}
		for(int u=0;u<n;u++)
			if(!dfn[u])
				tarjan(u);
		for(int u=0;u<n;u++)
		{
			for(int v:G[u])
				if(id[u]!=id[v])
					deg[id[v]]++;//入度+1
		}
		for(int u=0;u<n;u++)
		{
			if(deg[id[u]]==0)
				mincost[id[u]]=min(mincost[id[u]],p[u].c);//更新入度为0的点集中花费最少的点
		}
		int ans=0;
		for(int i=1;i<=scc;i++)
			if(mincost[i]!=INF)
				ans+=mincost[i];
		cout<<"Case #"<<++cnt<<": "<<ans<<endl;
	}
	return 0;
}