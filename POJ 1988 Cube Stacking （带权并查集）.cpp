#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=3e4+5;
int par[maxn];
int dis[maxn],num[maxn];//dis为到根节点的距离，只有当该结点直接连接根节点时，这个值才有效。
//num[i]为i所在的堆的所有立方体数量
void init()
{
    for(int i=0;i<=maxn;i++)
        par[i]=i,dis[i]=0,num[i]=1;
}
int find(int x)
{
    if(par[x]==x)
        return x;
    int fa=par[x];//
    par[x]=find(par[x]);//路径压缩，注意这两步，一定要理解递归
    dis[x]+=dis[fa];//此时x的父亲节点已经连接到根节点上了
    return par[x];
}
void unite(int x,int y)
{
    x=find(x),y=find(y);
    if(x==y)
        return ;
    par[x]=y;
    dis[x]+=num[y];
    num[y]+=num[x];//两个堆合并
}
int main()
{
    init();
    int n;
    cin>>n;
    while(n--)
    {
        char op;
        cin>>op;
        if(op=='M')
        {
            int x,y;
            cin>>x>>y;
            unite(x,y);
        }
        else
        {
            int x;
            cin>>x;
            find(x);//输出前对dis[a]进行更新
            cout<<dis[x]<<endl;
        }
    }
    return 0;
}