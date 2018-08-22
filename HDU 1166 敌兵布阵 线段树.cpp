#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
typedef long long LL;
inline LL read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
const int maxn=50005;
struct Node
{
	int l,r,sum;
}seg[maxn<<2];
int num[maxn];
void build(int i,int l,int r)
{
	seg[i].l=l;
	seg[i].r=r;
	if(l==r)
	{
		seg[i].sum=num[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(i<<1,l,mid);
	build(i<<1|1,mid+1,r);
	seg[i].sum=seg[i<<1].sum+seg[i<<1|1].sum;
}
void add(int i,int t,int b)
{
	seg[i].sum+=b;
	if(t==seg[i].l&&seg[i].r==t)
		return ;
	int mid=(seg[i].l+seg[i].r)>>1;
	if(t<=mid)
		add(i<<1,t,b);
	else
		add(i<<1|1,t,b);
}
int query(int i,int l,int r)
{
	if(seg[i].l==l&&seg[i].r==r)
		return seg[i].sum;
	int mid=(seg[i].l+seg[i].r)>>1;
	if(r<=mid)
		return query(i<<1,l,r);
	else if(l>mid)
		return query(i<<1|1,l,r);
	return query(i<<1,l,mid)+query(i<<1|1,mid+1,r);
}
int cnt;
int main()
{
	int t;
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--)
	{
		cout<<"Case "<<++cnt<<":\n";
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>num[i];
		build(1,1,n);
		string s;
		while(cin>>s)
		{
			if(s=="End")
				break;
			int a,b;
			cin>>a>>b;
			if(s=="Add")
				add(1,a,b);
			else if(s=="Sub")
				add(1,a,-b);
			else
				cout<<query(1,a,b)<<endl;
		}
	}
	return 0;
}