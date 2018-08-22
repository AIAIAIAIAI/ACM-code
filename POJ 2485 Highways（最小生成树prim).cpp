#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=505,INF=0x3f3f3f3f;
int cost[maxn][maxn];
int mincost[maxn];
bool used[maxn];
int n;
void prim()
{
    for(int i=0;i<n;i++)
    {
        mincost[i]=INF;
        used[i]=false;
    }
    mincost[0]=0;
    int maxcost=0;
    while(true)
    {
        int v=-1;
        for(int u=0;u<n;u++)
            if(!used[u]&&(v==-1||mincost[u]<mincost[v]))
                v=u;
        if(v==-1)
            break;
        used[v]=true;
        maxcost=max(maxcost,mincost[v]);
        for(int u=0;u<n;u++)
            mincost[u]=min(mincost[u],cost[v][u]);
    }
    printf("%d\n",maxcost);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&cost[i][j]);
        prim();
    }
    return 0;
}