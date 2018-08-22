#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define lson rt<<1,l,m
#define rson rt<<1|1,m+1,r
const int maxn=1e5+5;
typedef long long LL;
LL seg[maxn<<2];
LL lazy[maxn<<2];
int N;
void push_up(int rt)
{
	seg[rt]=seg[rt<<1]+seg[rt<<1|1];
}
void push_down(int rt,int len)//释放lazy
{
	seg[rt<<1]+=lazy[rt]*(len-(len>>1));
	lazy[rt<<1]+=lazy[rt];
	seg[rt<<1|1]+=lazy[rt]*(len>>1);
	lazy[rt<<1|1]+=lazy[rt];
	lazy[rt]=0;
}
void build(int rt,int l,int r)
{
	if(l==r)
	{	
		scanf("%lld",&seg[rt]);
		return ;
	} 
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	push_up(rt);
}
LL query(int L,int R,int rt,int l,int r)
{
	if(L<=l&&R>=r)
		return seg[rt];
	if(lazy[rt])
		push_down(rt,r-l+1);
	int m=(l+r)>>1;
	LL res=0;
	if(L<=m)
		res+=query(L,R,lson);
	if(R>m)
		res+=query(L,R,rson);
	return res;
}
void updata(int L,int R,int delta,int rt,int l,int r)
{
	if(L<=l&&R>=r)
	{
		seg[rt]+=(LL)delta*(r-l+1);//这里可能会溢出
		lazy[rt]+=delta;
		return ;
	}
	if(lazy[rt])
		push_down(rt,r-l+1);
	int m=(l+r)>>1;
	if(L<=m)
		updata(L,R,delta,lson);
	if(R>m)
		updata(L,R,delta,rson);
	push_up(rt);
}
int main()
{
	//ios::sync_with_stdio(false);//UESTC OJ的G++不支持流加速？
	scanf("%d",&N);
	build(1,1,N);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		updata(a,b,c,1,1,N);
		printf("%lld\n",query(a,b,1,1,N));
	}
	return 0;
}