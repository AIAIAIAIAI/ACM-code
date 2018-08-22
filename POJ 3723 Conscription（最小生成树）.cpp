#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=2e4+5;
int par[maxn];
struct edge
{
    int u,v,cost;
    bool operator <(const edge &a) const
    {
        return cost<a.cost;
    }
}es[50005];
int n,m,r;
void init()
{
    for(int i=0;i<n+m;i++)
        par[i]=i;
}
int find(int x)
{
    return par[x]==x?x:par[x]=find(par[x]);
}
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x!=y)
        par[x]=y;
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
void Kruskal()
{
    init();
    sort(es,es+r);
    int res=0;
    for(int i=0;i<r;i++)
    {
        edge e=es[i];
        if(!same(e.u,e.v))
        {
            unite(e.u,e.v);
            res+=e.cost;
        }
    }
    printf("%d\n",10000*(n+m)+res);
}
int main()
{
    //ios::sync_with_stdio(false);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&r);
        for(int i=0;i<r;i++)
        {
            int u,v,cost;
            scanf("%d%d%d",&u,&v,&cost);
            es[i]=(edge){u,v+n,-cost};
        }
        Kruskal();
    }
    return 0;
}