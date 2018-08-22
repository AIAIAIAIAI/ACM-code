#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=105,INF=0x3f3f3f3f;
int cost[maxn][maxn];
int d[maxn];
bool used[maxn];
int n;
void dijkstra(int s)
{
	fill(d,d+n+1,INF);
	fill(used,used+n+1,false);
	d[s]=0;
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
	ios::sync_with_stdio(false);
	int m;
	while(cin>>n>>m,n||m)
	{
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				cost[i][j]=cost[j][i]=INF;
		for(int i=0;i<m;i++)
		{
			int u,v,c;
			cin>>u>>v>>c;
			cost[u][v]=cost[v][u]=c;
		}
		dijkstra(1);
		cout<<d[n]<<endl;
	}
	return 0;
}