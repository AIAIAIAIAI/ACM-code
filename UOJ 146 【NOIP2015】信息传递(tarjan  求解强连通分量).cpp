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
const int maxn=1e5+5;
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
int dfn[maxn],vis[maxn],low[maxn];
int n,tot;
int ans=INF;
void tarjan(int u)
{
	dfn[u]=low[u]=++tot;
	vis[u]=true;
	S.push(u);
	for(int v:G[u])
	{
		if(!dfn[v])
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(vis[v])
		{
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(low[u]==dfn[u])
	{
		int cnt=0;
		while(1)
		{
			int now=S.top();
			S.pop();
			vis[now]=false;
			cnt++;
			if(now==u)
				break;
		}
		if(cnt>1)
			ans=min(ans,cnt);
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		G[i].push_back(x);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	cout<<ans<<endl;
	return 0;
}