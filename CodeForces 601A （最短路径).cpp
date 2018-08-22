#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>
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
int cost[maxn][maxn];
int d[maxn];
bool used[maxn];
bool G[maxn][maxn];
int n;
void dijkstra()
{
	ms(d,INF);
	ms(used,0);
	d[1]=0;
	while(true)
	{
		int v=-1;
		for(int u=1;u<=n;u++)
			if(!used[u]&&(v==-1||d[u]<d[v]))
				v=u;
		if(v==-1)
			break;
		used[v]=true;
		for(int u=1;u<=n;u++)
			d[u]=min(d[u],d[v]+cost[v][u]);

	}
}
int main()
{
	int m;
	while(cin>>n>>m)
	{
		ms(G,0);
		for(int i=0;i<m;i++)
		{
			int u,v;
			cin>>u>>v;
			G[u][v]=G[v][u]=true;
		}
		if(G[1][n])
		{
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
				{
					if(G[i][j])
						cost[i][j]=INF;
					else
						cost[i][j]=1;
				}
		}
		else
		{
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
				{
					if(G[i][j])
						cost[i][j]=1;
					else
						cost[i][j]=INF;
				}
		}
		dijkstra();
		if(d[n]==INF)
			cout<<"-1"<<endl;
		else
			cout<<d[n]<<endl;
	}
	return 0;
}