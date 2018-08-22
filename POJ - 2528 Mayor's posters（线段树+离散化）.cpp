	#include<iostream>
	#include<algorithm>
	#include<map>
	#include<cstring>
	#include<set>
	#define lson L,mid,rt<<1
	#define rson mid+1,R,rt<<1|1
	using namespace std;
	const int maxn=1e4+5;
	int lazy[maxn<<4];
	bool flag[maxn<<4];
	struct node
	{
		int x,y;
		int val;
	}p[maxn];
	int s[maxn<<2];
	void push_down(int rt)
	{
		lazy[rt<<1]=lazy[rt<<1|1]=lazy[rt];
		lazy[rt]=0;
	}
	void updata(int L,int R,int rt,int l,int r,int v)
	{
		if(L>=l&&R<=r)
		{
			lazy[rt]=v;
			return ;
		}
		if(lazy[rt])
			push_down(rt);
		int mid=(L+R)>>1;
		if(l<=mid)
			updata(lson,l,r,v);
		if(r>mid)
			updata(rson,l,r,v);
	}
	int ans;
	void query(int L,int R,int rt)
	{
		if(lazy[rt])
		{
			if(!flag[lazy[rt]])
			{
				flag[lazy[rt]]=true;
				ans++;
			}
			return ;
		}
		if(L==R)
			return ;
		int mid=(L+R)>>1;
		query(lson);
		query(rson);
	}
	int main()
	{
		ios::sync_with_stdio(false);
		int t;
		cin>>t;
		while(t--)
		{ 
			int k;
			cin>>k;
			memset(lazy,0,sizeof(lazy));
			memset(flag,false,sizeof(flag));
			for(int i=0;i<k;i++)
			{
				int a,b;
				cin>>a>>b;
				s[i<<1]=a,s[i<<1|1]=b;
				p[i].x=a;
				p[i].y=b;
				p[i].val=i+1;
			}
			sort(s,s+2*k);
			int cnt=1;
			for(int i=1;i<2*k;i++)//去重
				if(s[i]!=s[i-1])
					s[cnt++]=s[i];
			for(int i=cnt-1;i>=1;i--)//原本不相邻的两个数之间添加一个数隔开
				if(s[i]!=s[i-1]+1)
					s[cnt++]=s[i-1]+1;
			sort(s,s+cnt);//再次排序
			for(int i=0;i<k;i++)
			{
				int l=lower_bound(s,s+cnt,p[i].x)-s;//二分查找
				int r=lower_bound(s,s+cnt,p[i].y)-s;
				updata(0,cnt-1,1,l,r,p[i].val);
			}
			ans=0;
			query(0,cnt-1,1);
			cout<<ans<<endl;
		}
		return 0;
	}