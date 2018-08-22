#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=1005;
typedef long long LL;
inline LL read()
{
    LL x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

struct node
{
    int a,b,c,d;
    node(){}
    node(int a,int b,int c,int d):a(a),b(b),c(c),d(d){}
}q[1000005];
bool vis[105][105][105];
int l,r,s,n,m;
void pour(int a,int b,int c,int d)
{
    if(!vis[a][b][c])
    {
        vis[a][b][c]=true;
        q[r++]=node(a,b,c,d+1);
    }
}
int bfs()
{
    memset(vis,false,sizeof(vis));
    l=r=0;
    int a,b,c,d;
    q[r++]=node(s,0,0,0);
    while(l<r)
    {
        a=q[l].a,b=q[l].b,c=q[l].c,d=q[l++].d;
        if(a==s/2||b==s/2||c==s/2)
            return d+(a&&b&&c!=0);
        pour(a-m+b,m,c,d);//s->m
        pour(a-n+c,b,n,d);//s->n
        pour(a+b,0,c,d);//m->s
        pour(a+c,b,0,d);//n->s
        if(b>n-c)//m->n 判断能不能把m杯中的水全部倒进n中
            pour(a,b-n+c,n,d);
        else
            pour(a,0,c+b,d);
        if(c>m-b)//n->m 同理
            pour(a,m,c-m+b,d);
        else
            pour(a,b+c,0,d);
    }
    return 0;
}
int main()
{
    while(cin>>s>>n>>m,s||n||m)
    {
        if(s%2)//奇数肯定不能平分
        {
            cout<<"NO"<<endl;
            continue;
        }
        int ans=bfs();
        if(!ans)
            cout<<"NO"<<endl;
        else
            cout<<ans<<endl;
    }
    return 0;
}