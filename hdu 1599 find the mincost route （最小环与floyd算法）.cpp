#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=105,INF=0x3f3f3f3f;
int cost[maxn][maxn],d[maxn][maxn];
int mincost;
int n,m;
void Floyd()
{
    mincost=INF;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            d[i][j]=cost[i][j];
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<k;i++)
            for(int j=i+1;j<k;j++)
                if(mincost>cost[i][j]+d[i][k]+d[k][j])
                    mincost=cost[i][j]+d[i][k]+d[k][j];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(cost[i][j]>cost[i][k]+cost[k][j]
                    cost[i][j]=cost[i][k]+cost[k][j];
    }
}
int main()
{
    while(cin>>n>>m)
    {
        memset(cost,INF,sizeof(cost));
        for(int i=0;i<m;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            if(cost[a][b]>c)
                cost[a][b]=cost[b][a]=c;
        }
        Floyd();
        if(mincost==INF)
            cout<<"It's impossible."<<endl;
        else
            cout<<mincost<<endl;
    }
    return 0;
}