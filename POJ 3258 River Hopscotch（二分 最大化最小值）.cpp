#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=50005,INF=1e9+5;
int L,n,m;
int a[maxn];
bool check(int x)//移除M颗石头后，能使相邻的两颗石头的间距>=x
{
	int cnt=0;
	int pre=0;//记录需要维护的前一颗石头
	for(int i=1;i<=n+1;i++)
	{
		if(a[i]-a[pre]<x)
			cnt++;
		else
			pre=i;//更新
	}

	return cnt<=m;
}
void solve()
{
	int lb=0,ub=INF;
	while(lb+1<ub)
	{
		int mid=(lb+ub)>>1;
		if(check(mid))
			lb=mid;
		else 
			ub=mid;
	}
	cout<<lb<<endl;
}
int main()
{
	cin>>L>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	a[n+1]=L;
	sort(a+1,a+n+1);
	solve();
	return 0;
}