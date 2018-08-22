#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e4+5,INF=0x3f3f3f3f;
int d[maxn];
int cost[maxn];
bool used[maxn];
int n,m;
struct edge
{
    int to,dis,c;
    edge(){}
    edge(int to,int dis,int c):to(to),dis(dis),c(c){}
};
vector<edge> G[maxn];
void SPFA()
{
    queue<int> que;
    memset(d,INF,sizeof(d));
    memset(used,false,sizeof(used));
    memset(cost,INF,sizeof(cost));
    d[1]=0;
    cost[1]=0;
    used[1]=true;
    que.push(1);
    while(que.size())
    {
        int u=que.front();
        que.pop();
        for(int i=0;i<G[u].size();i++)
        {
            edge e=G[u][i];
            if(d[e.to]>d[u]+e.dis)
            {
                d[e.to]=d[u]+e.dis;
                cost[e.to]=e.c;
                if(!used[e.to])
                {
                    used[e.to]=true;
                    que.push(e.to);
                }
            }
            else if(d[e.to]==d[u]+e.dis&&cost[e.to]>e.c)
            {
                cost[e.to]=e.c;
                if(!used[e.to])
                {
                    used[e.to]=true;
                    que.push(e.to);
                }
            }
        }
        used[u]=false;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        ans+=cost[i];
    cout<<ans<<endl;
}
int main()
{
    while(cin>>n>>m,n||m)
    {
        for(int i=0;i<m;i++)
        {
            int u,v,dis,c;
            cin>>u>>v>>dis>>c;
            G[u].push_back(edge(v,dis,c));
            G[v].push_back(edge(u,dis,c));
        }
        SPFA();
        for(int i=1;i<=n;i++)
            G[i].clear();
    }
    return 0;
}