#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<stack>
#include<cstdio>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int maxn=100005;
#define ms(a,x) memset(a,x,sizeof(a))
inline LL read()
{
    LL x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n;
vector<int> G[maxn];
int used[maxn];
void dfs(int x,int id)
{
	stack<int> S;
	S.push(x);
	used[x]=id;
	while(!S.empty())
	{
		int u=S.top();S.pop();
		for(int v:G[u])
			if(used[v]==-1)
			{
				used[v]=id;
				S.push(v);
			}
	}
}
void assignId()
{
	int id=1;
	ms(used,-1);
	for(int u=0;u<n;u++)
		if(used[u]==-1)
			dfs(u,id++);
}
int main()
{
	int m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	assignId();
	int q;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		int s,t;
		cin>>s>>t;
		if(used[s]==used[t])
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	return 0;
}