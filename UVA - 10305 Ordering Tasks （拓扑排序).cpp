#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<cstdio>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int maxn=105;
#define ms(a,x) memset(a,x,sizeof(a))

inline LL read()
{
    LL x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

vector<int> G[maxn];
int n;
int c[maxn];
int topo[maxn],t;
bool dfs(int u)
{
	c[u]=-1;//访问标志
	for(int v:G[u])
	{
		if(c[v]<0)
			return false;//存在有向环，失败退出
		else if(!c[v]&&!dfs(v))
			return false;
	}
	c[u]=1;
	topo[--t]=u;
	return true;
}
bool toposort()
{
	t=n;
	ms(c,0);
	for(int i=1;i<=n;i++)
		if(!c[i])
			if(!dfs(i))
				return false;
	return true;
}
void clear()
{
	for(int i=1;i<=n;i++)
		G[i].clear();
}
int main()
{
	int m;
	while(cin>>n>>m,n||m)
	{
		clear();
		while(m--)
		{
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);
		}
		if(toposort())
		{
			for(int i=0;i<n;i++)
			{
				if(i==n-1)
					cout<<topo[i]<<endl;
				else
					cout<<topo[i]<<' ';
			}
		}
		else
			cout<<"impossible"<<endl;
	}
	return 0;
}