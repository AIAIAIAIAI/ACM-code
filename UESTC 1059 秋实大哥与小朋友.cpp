#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
#define lson L,mid,rt<<1
#define rson mid+1,R,rt<<1|1
const int maxn=1e5+5;
int bit[maxn<<1];
int n,m;
struct node
{
	int l,r,v,x;
}node[maxn<<1];
int sum(int i)
{
	int s=0;
	while(i>0)
	{
		s+=bit[i];
		i-=i&-i;
	}
	return s;
}
void add(int i,int x)
{
	while(i<=n)
	{
		bit[i]+=x;
		i+=i&-i;
	}
}
int main()
{
	vector<int> vec;
	map<int,int> mp;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int op;
		cin>>op;
		if(op)
		{
			int x;
			cin>>x;
			vec.push_back(x);
			node[i].x=x;
		}
		else
		{
			int l,r,v;
			cin>>l>>r>>v;
			vec.push_back(l);
			vec.push_back(r);
			node[i].l=l;
			node[i].r=r;
			node[i].v=v;
		}
	}
	sort(vec.begin(),vec.end());
	for(int i=0;i<vec.size();i++)
		mp[vec[i]]=i+1;
	n=vec.size();
	for(int i=0;i<m;i++)
	{
		if(node[i].x==0)
		{
			add(mp[node[i].l],node[i].v);
			add(mp[node[i].r]+1,-node[i].v);
		}
		else
			cout<<sum(mp[node[i].x])<<endl;
	}
	return 0;
}
