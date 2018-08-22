#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int maxn=1005;
#define ms(a,x) memset(a,x,sizeof(a))

inline LL read()
{
    LL x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int d[256];
bool vis[256];
bool G[256][256];
void dfs(int u)//从起点dfs
{
	vis[u]=false;
	for(int i='a';i<='z';i++)
	{
		if(G[u][i]&&vis[i])
			dfs(i);
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ms(vis,0);
		ms(d,0);
		ms(G,0);
		int n;
		cin>>n;
		char s[1005];
		for(int i=0;i<n;i++)
		{
			cin>>s;
			int u=s[0],v=s[strlen(s)-1];
			d[u]--,d[v]++;//入度+1,出度-1
			vis[u]=vis[v]=true;
			G[u][v]=true;
		}
		bool flag=false;
		int num=0,st=s[0];
		for(int i='a';i<='z';i++)
		{
			if(vis[i])
			{
				if(d[i]>1||d[i]<-1)//存在度数不等于出度且不满足奇点
				{
					flag=true;
					break;
				}
				else if(d[i]==1)//奇点
					num++;
				else if(d[i]==-1)//奇点(标记为起点)
					num++,st=i;
			}
		}
		if(num!=0&&num!=2)//奇点的数量
			flag=true;
		dfs(st);
		for(int i='a';i<='z'&&!flag;i++)//判断是否连通
		{
			if(vis[i])
				flag=true;
		}
		if(flag)
			cout<<"The door cannot be opened."<<endl;
		else
			cout<<"Ordering is possible."<<endl;
	}
	return 0;
}