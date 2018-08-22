#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>
#include<map>
using namespace std;
typedef long long LL;
inline LL read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
const int maxn=1e5+5;
struct Node
{
	int l,r;
	LL sum;
}seg[maxn<<2];
int num[maxn];
void push_up(int n)
{
	seg[n].sum=seg[n<<1].sum+seg[n<<1|1].sum;
}
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
	push_up(i);
}
void updata(int i,int t,int val)
{
	if(seg[i].l==t&&seg[i].r==t)
	{
		seg[i].sum=val;
		return ;
	}
	int mid=(seg[i].l+seg[i].r)>>1;
	if(t<=mid)
		updata(i<<1,t,val);
	else
		updata(i<<1|1,t,val);
	push_up(i);
}
LL query(int i,int l,int r)
{
	if(seg[i].l>=l&&seg[i].r<=r)
		return seg[i].sum;
	int mid=(seg[i].l+seg[i].r)>>1;
	if(r<=mid)
		return query(i<<1,l,r);
	if(l>mid)
		return query(i<<1|1,l,r);
	return query(i<<1,l,mid)+query(i<<1|1,mid+1,r);
}
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>num[i];
	build(1,1,n);
	int t;
	cin>>t;
	while(t--)
	{
		int q,a,b;
		cin>>q>>a>>b;
		if(q==1)
			updata(1,a,b);
		else
			cout<<query(1,a,b)<<endl;
	}
	return 0;
}