#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
typedef long long LL;
const LL INF=(1LL<<16)*50000;
const int maxn=50005;
typedef long long LL;
#define ms(s,v) memset(s,v,sizeof(s))
inline LL read()
{
    LL x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

struct edge
{
	int to, cost;
};
typedef pair<int,int> P;
int n,m;
int w[maxn];
LL d[maxn];
vector<edge> G[maxn];
void clear()
{
	for(int i=1;i<=n;i++)
		G[i].clear();
}
void dijkstra()
{
	priority_queue<P,vector<P>,greater<P> > que;
	fill(d+1,d+n+1,INF);
	d[1]=0;
	que.push(P(0,1));
	while(!que.empty())
	{
		P p=que.top();que.pop();
		int v=p.second;
		if(d[v]<p.first) continue;
		for(int i=0;i<G[v].size();i++)
		{
		    edge &e=G[v][i];
			if(d[e.to]>d[v]+e.cost)
			{
				d[e.to]=d[v]+e.cost;
				que.push(P(d[e.to],e.to));
			}
		}
	}
	LL sum=0;
	for(int i=1;i<=n;i++)
	{
		if(d[i]==INF)
		{
		    puts("No Answer");
			return ;
		}
		sum+=w[i]*d[i];
	}
	printf("%lld\n",sum);
}
int main()
{
	//ios::sync_with_stdio(false);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		clear();
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%d",&w[i]);
		for(int i=0;i<m;i++)
		{
			int u,v,c;
			scanf("%d%d%d",&u,&v,&c);
			G[u].push_back((edge){v,c});
			G[v].push_back((edge){u,c});
		}
		dijkstra();
	}
	return 0;
}