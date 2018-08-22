#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int maxn=5005,INF=0x3f3f3f3f;
struct edge
{
    int to,cost;
    edge(int to,int c):to(to),cost(c){}
};
vector<edge> G[maxn];
int dist[maxn];
int dist2[maxn];
int n,m;
typedef pair<int,int> P;
void dijkstra(int s)
{
    priority_queue<P,vector<P>,greater<P> > que;
    fill(dist,dist+maxn,INF);
    fill(dist2,dist2+maxn,INF);
    dist[s]=0;
    que.push(P(0,s));
    while(!que.empty())
    {
        P p=que.top();
        que.pop();
        int v=p.second,d=p.first;
        if(dist2[v]<d)
            continue;
        for(int i=0;i<G[v].size();i++)
        {
            edge &e=G[v][i];
            int d2=d+e.cost;
            if(dist[e.to]>d2)
            {
                swap(dist[e.to],d2);
                que.push(P(dist[e.to],e.to));
            }
            if(dist2[e.to]>d2&&dist[e.to]<d2)
            {
                dist2[e.to]=d2;
                que.push(P(dist2[e.to],e.to));
            }
        }
    }
    cout<<dist2[n]<<endl;
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v,c;
        cin>>u>>v>>c;
        G[u].push_back(edge(v,c));
        G[v].push_back(edge(u,c));
    }
    dijkstra(1);
    return 0;
}