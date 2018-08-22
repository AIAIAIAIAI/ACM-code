#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
const int maxn=1e5+5;
#define lson L,mid,rt<<1
#define rson mid+1,R,rt<<1|1
int seg[maxn<<2];
bool lazy[maxn<<2];
void build(int L,int R,int rt)
{
	seg[rt]=1;
	if(L==R)
		return ;
	int mid=(L+R)>>1;
	build(lson);
	build(rson);
}
void push_up(int rt)
{
	seg[rt]=seg[rt<<1]|seg[rt<<1|1];
}
void push_down(int rt)//lazy操作
{
	seg[rt<<1]=seg[rt<<1|1]=seg[rt];
	lazy[rt<<1]=lazy[rt<<1|1]=true;
	lazy[rt]=false;
}
void updata(int L,int R,int rt,int l,int r,int val)
{
	if(L>=l&&R<=r)
	{
		seg[rt]=val;
		lazy[rt]=true;
		return ;
	}
	if(seg[rt]==val)//剪枝。已经是同种颜色，不需要再涂了
		return ;
	if(lazy[rt])
		push_down(rt);
	int mid=(L+R)>>1;
	if(l>mid)
		updata(rson,l,r,val);
	else if(r<=mid)
		updata(lson,l,r,val);
	else
		updata(lson,l,r,val),updata(rson,l,r,val);
	push_up(rt);//更新
}
int sum;
void query(int L,int R,int rt,int l,int r)
{
	if(L>=l&&R<=r)
	{
		sum|=seg[rt];
		return ;
	}
	if(lazy[rt])//剪枝。当前区间被一种颜色所覆盖，不用再向下分解区间
	{
		sum|=seg[rt];
		return ;
	}
	int mid=(L+R)>>1;
	if(l>mid)
		query(rson,l,r);
	else if(r<=mid)
		query(lson,l,r);
	else
		query(lson,l,r),query(rson,l,r);
}
int cal(int num)//计算有多少种颜色
{
	int ans=0;
	while(num)
	{
		if(num&1)
			ans++;
		num>>=1;
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	int n,t,q;
	cin>>n>>t>>q;
	build(1,n,1);
	while(q--)
	{
		char op;
		cin>>op;
		int x,y,c;
		if(x>y)
			swap(x,y);
		if(op=='C')
		{
			cin>>x>>y>>c;
			updata(1,n,1,x,y,1<<(c-1));
		}
		else
		{
			cin>>x>>y;
			sum=0;
			query(1,n,1,x,y);
			cout<<cal(sum)<<endl;
		}
	}
	return 0;
}