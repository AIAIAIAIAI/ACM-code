#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int maxn=1005,N=10005;
#define ms(a,x) memset(a,x,sizeof(a))

inline LL read()
{
    LL x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,ML,MD;
int AL[N],BL[N],DL[N];
int AD[N],BD[N],DD[N];
int d[maxn];//最短距离
bool updated;//是否有更新
void update(int &x,int y)//是否有更新
{
	if(x>y)
	{
		x=y;
		updated=true;
	}
}
void bellmanford()//计算d
{
	for(int k=1;k<=n+1;k++)
	{
		updated=false;
		for(int i=1;i+1<=n;i++)// 从i+1到i的权值为0
			if(d[i+1]<INF)
				update(d[i],d[i+1]);
		for(int i=0;i<ML;i++)// 从AL到BL的权值为DL
			if(d[AL[i]]<INF)
				update(d[BL[i]],d[AL[i]]+DL[i]);
		for(int i=0;i<MD;i++)// 从BD到AD的权值为-DD
			if(d[BD[i]]<INF)
				update(d[AD[i]],d[BD[i]]-DD[i]);
	}
}
void solve()
{
	ms(d,0);//
	bellmanford();//检查是否存在负圈
	if(updated)//存在负圈即无解
	{
		cout<<"-1"<<endl;
		return;
	}
	ms(d,INF);
	d[1]=0;
	bellmanford();
	int res=d[n];
	if(res==INF)
		res=-2;
	cout<<res<<endl;
}
int main()
{
	cin>>n>>ML>>MD;
	for(int i=0;i<ML;i++)
		cin>>AL[i]>>BL[i]>>DL[i];
	for(int i=0;i<MD;i++)
		cin>>AD[i]>>BD[i]>>DD[i];
	solve();
	return 0;
}