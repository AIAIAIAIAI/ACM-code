#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=1e5+5,INF=1e9+5;
int a[maxn];
int n,m;
bool check(int x)
{
	int cnt=1;
	long long cost=0;
	for(int i=0;i<n;i++)
	{
		cost+=a[i];
		if(cost>x)
		{
			cost=a[i];
			cnt++;
		}
	}
	return cnt>m;
}
void solve()
{
	int lb=*max_element(a,a+n),ub=INF;
	while(lb<ub)
	{
		int mid=(lb+ub)>>1;
		if(check(mid))
			lb=mid+1;
		else
			ub=mid;
	}
	cout<<ub<<endl;
}
int main()
{
	ios::sync_with_stdio(false);
	while(cin>>n>>m)
	{
		for(int i=0;i<n;i++)
			cin>>a[i];
		solve();
	}
	return 0;
}