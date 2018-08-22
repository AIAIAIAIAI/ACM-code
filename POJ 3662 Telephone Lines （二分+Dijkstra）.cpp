#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=1005,INF=0x3f3f3f3f;
int d[maxn];
int n,p,k;
struct edge
{
    int to,cost;
    edge(){}
    edge(int to,int cost):to(to),cost(cost){}
};
typedef pair<int,int> P;
vector<edge> G[maxn];
void dijkstra(int s,int x)
{
    priority_queue<P,vector<P>,greater<P> >que;
    fill(d+1,d+n+1,INF);
    d[s]=0;
    que.push(P(0,s));
    while(que.size())
    {
        P p=que.top();
        que.pop();
        int v=p.second;
        if(d[v]<p.first)
            continue;
        for(int i=0;i<G[v].size();i++)
        {
            edge e=G[v][i];
            int dis=d[v]+(e.cost>=x?1:0);
            if(d[e.to]>dis)
            {
                d[e.to]=dis;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}
void solve()
{
    int lb=0,ub=1000000+2;
    while(ub-lb>1)
    {
        int mid=(lb+ub)>>1;
        dijkstra(1,mid);
        if(d[n]>k)
        {
            lb=mid;
        }
        else
        {
            ub=mid;
        }
    }
    cout<<(lb>1000000?-1:lb)<<endl;
}
int main()
{
    cin>>n>>p>>k;
    for(int i=0;i<p;i++)
    {
        int u,v,c;
        cin>>u>>v>>c;
        G[u].push_back(edge(v,c));
        G[v].push_back(edge(u,c));
    }
    solve();
}