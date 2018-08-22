#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=305,INF=0x3f3f3f3f;
int d[maxn][maxn];
int a[maxn];
int n,m;
void init()
{
    for(int i=0;i<maxn;i++)
        for(int j=0;j<maxn;j++)
            if(i==j)
                d[i][j]=0;
            else
                d[i][j]=INF;
}
void warshall_floyd()
{
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}
int main()
{
    cin>>n>>m;
    init();
    while(m--)
    {
        int k;
        cin>>k;
        for(int i=0;i<k;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<k;i++)
            for(int j=i+1;j<k;j++)
                d[a[i]][a[j]]=d[a[j]][a[i]]=1;
    }
    warshall_floyd();
    int ans=INF;
    for(int i=1;i<=n;i++)
    {
        int sum=0;
        for(int j=1;j<=n;j++)
            sum+=d[i][j];
        ans=min(ans,sum);
    }
    cout<<ans*100/(n-1)<<endl;
    return 0;
}