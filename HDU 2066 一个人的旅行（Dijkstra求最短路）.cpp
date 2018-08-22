#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=1005,INF=0x3f3f3f3f;
int cost[maxn][maxn];//边的权值
int d[maxn];
bool used[maxn];
int n=maxn;
void dijkstra(int s)//从起点s出发到各个顶点的最短距离	
{
	fill(used,used+n,false);
	fill(d,d+n,INF);
	d[s]=0;
	while(true)
	{
		int v=-1;
		for(int u=0;u<n;u++)//从尚未使用过的顶点里选择一个距离最小的顶点
			if(!used[u]&&(v==-1||d[u]<d[v]))
				v=u;
		if(v==-1)
			break;
		used[v]=true;
		for(int u=0;u<n;u++)
			d[u]=min(d[u],d[v]+cost[v][u]);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int t,s,q;
	while(cin>>t>>s>>q)
	{
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				cost[i][j]=cost[j][i]=INF;
		while(t--)
		{
			int u,v,c;
			cin>>u>>v>>c;
			if(c<cost[u][v])
				cost[u][v]=cost[v][u]=c;
		}
		while(s--)
		{
			int x;
			cin>>x;
			cost[0][x]=cost[x][0]=0;
		}
		dijkstra(0);
		int ans=INF;
		while(q--)
		{
			int x;
			cin>>x;
			ans=min(ans,d[x]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
