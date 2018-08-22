#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<queue>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int maxn=1005;
#define ms(a,n) memset(a,n,sizeof(a))
inline LL read()
{
    LL x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct edge{
	int s,cost,pos;
	bool operator <(const edge& x)const
	{
		return cost>x.cost;//边权小的优先
	}
};
typedef pair<int,int> P;//first为顶点编号，second为权值
int n,m;
int dist[maxn][2];
int cnt[maxn][2];
bool vis[maxn][2];
vector<P> G[maxn];
void dijkstra(int s,int f)
{
	priority_queue<edge> que;
	ms(dist,INF);
	ms(cnt,0);
	ms(vis,false);
	cnt[s][0]=1;
	dist[s][0]=0;
	que.push((edge){s,0,0});
	while(!que.empty())
	{
		edge p=que.top();que.pop();
		if(vis[p.s][p.pos])
			continue;
		int u=p.s,t=p.pos;
		vis[u][t]=true;
		for(int i=0;i<G[u].size();i++)
		{
			int v=G[u][i].first,d=G[u][i].second;
			if(dist[v][0]>d+dist[u][t])
			{
				dist[v][1]=dist[v][0];
				cnt[v][1]=cnt[v][0];
				dist[v][0]=d+dist[u][t];
				cnt[v][0]=cnt[u][t];
				que.push((edge){v,dist[v][0],0});
				que.push((edge){v,dist[v][1],1});
			}
			else if(dist[v][0]==d+dist[u][t])
				cnt[v][0]+=cnt[u][t];
			else if(dist[v][1]>d+dist[u][t])
			{
				dist[v][1]=d+dist[u][t];
				cnt[v][1]=cnt[u][t];
				que.push((edge){v,dist[v][1],1});
			}
			else if(dist[v][1]==d+dist[u][t])
				cnt[v][1]+=cnt[u][t];
		}
	}
	int ans=cnt[f][0];
	if(dist[f][1]==dist[f][0]+1)
		ans+=cnt[f][1];
	printf("%d\n",ans);
}
void clear()
{
	for(int i=1;i<=n;i++)
		G[i].clear();
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		clear();
		for(int i=0;i<m;i++)
		{
			int u,v,c;
			scanf("%d%d%d",&u,&v,&c);
			G[u].push_back(P(v,c));
		}
		int s,f;
		scanf("%d%d",&s,&f);
		dijkstra(s,f);
	}
	return 0;
}