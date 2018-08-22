#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn=1e5+5;
typedef long long LL;
typedef pair<LL,LL> P;
P p[maxn];
int a[maxn];
LL sqr(LL x)
{
	return x*x;
}
LL dis(P x1,P x2)
{
	return sqr(x1.first-x2.first)+sqr(x1.second-x2.second);
}
bool cmpy(int x,int y)
{
	return p[x].second<p[y].second;
}
LL find(int l,int r)
{
	if(l+1==r)
		return dis(p[l],p[r]);
	int mid=(l+r)>>1;
	LL ans=min(find(l,mid),find(mid,r));//递归求解左右两侧的最短距离
	int cnt=0;
	for(int i=l;i<=r;i++)
		if(abs(p[i].first-p[mid].first)<=ans)
			a[cnt++]=i;
	sort(a,a+cnt,cmpy);//筛选的点然后按y轴排序
	for(int i=0;i<cnt;i++)
		for(int j=i+1;j<cnt&&sqr(p[a[j]].second-p[a[i]].second)<ans;j++)//这里可以剪枝
			ans=min(ans,dis(p[a[i]],p[a[j]]));
	return ans;
}
int main()
{
	int n;
	scanf("%d",&n);
	LL sum=0;
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		p[i].first=i+1;
		sum+=x;
		p[i].second=sum;
	}
	printf("%lld\n",find(0,n-1));
	return 0;
}