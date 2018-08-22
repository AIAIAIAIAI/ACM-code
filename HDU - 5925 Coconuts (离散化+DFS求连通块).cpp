#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int INF=0x3f3f3f3f;
const int maxn=2000;
#define ms(a,x) memset(a,x,sizeof(a))
inline LL read()
{
    LL x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int vx[500],vy[500];
int x[205],y[205];
bool vis[500][500];
int pos[205];
int a[205];
int n,m;
int nc,nr;
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
vector<LL> ans;
LL dfs(int x,int y)
{
	LL ans=(LL)vx[x]*vy[y];
	vis[x][y]=true;
	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i],ny=y+dy[i];
		if(0<nx&&nx<=nr&&0<ny&&ny<=nc&&!vis[nx][ny])
			ans+=dfs(nx,ny);
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	int cnt=0;
	while(t--)
	{
		ms(vis,0);
		ans.clear();
		cout<<"Case #"<<++cnt<<":"<<endl;
		cin>>n>>m;
		int q;
		cin>>q;
		for(int i=0;i<q;i++)
			cin>>x[i]>>y[i];
		int cnt=0;
		a[cnt++]=0,a[cnt++]=n;
		for(int i=0;i<q;i++)
			a[cnt++]=x[i];
		sort(a,a+cnt);
		cnt=unique(a,a+cnt)-a;//无重复的坏点
		nr=0;
		for(int i=1;i<cnt;i++)//离散化
		{
			if(a[i]-a[i-1]>1)
				vx[++nr]=a[i]-a[i-1]-1;
			vx[++nr]=1;
			pos[i]=nr;//记录离散化后第i个坏点在的行
		}
		for(int i=0;i<q;i++)
		{
			int t=lower_bound(a,a+cnt,x[i])-a;
			x[i]=pos[t];//
		}
		nc=cnt=0;
		a[cnt++]=0,a[cnt++]=m;
		for(int i=0;i<q;i++)
			a[cnt++]=y[i];
		sort(a,a+cnt);
		cnt=unique(a,a+cnt)-a;
		for(int i=1;i<cnt;i++)
		{
			if(a[i]-a[i-1]>1)
				vy[++nc]=a[i]-a[i-1]-1;
			vy[++nc]=1;
			pos[i]=nc;//同理
		}
		for(int i=0;i<q;i++)
		{
			int t=lower_bound(a,a+cnt,y[i])-a;
			y[i]=pos[t];//此时y[i]是第i个坏点离散化后坏点的所在的列
		}
		for(int i=0;i<q;i++)
			vis[x[i]][y[i]]=true;
		for(int i=1;i<=nr;i++)
			for(int j=1;j<=nc;j++)
				if(!vis[i][j])
					ans.push_back(dfs(i,j));
		sort(ans.begin(),ans.end());
		cout<<ans.size()<<endl;
		for(int i=0;i<ans.size();i++)
		{
			if(i)
				cout<<" ";
			cout<<ans[i];
		}
		cout<<endl;
	}
	return 0;
}