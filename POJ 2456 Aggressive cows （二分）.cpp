#include<iostream>
#include<algorithm>
using namespace std;
const int INF=1e9+5,maxn=1e5+5;
int n,k;
int a[maxn];
bool check(int x)
{
	int cur=0,cnt=1;
	for(int i=1;i<n;i++)
	{
		if(a[i]-a[cur]>=x)
			cur=i,cnt++;
		if(cnt>=k)
			break;
	}
	return cnt>=k;
}
void solve()
{
	int lb=0,ub=INF;
	while(lb<=ub)
	{
		int mid=(lb+ub)>>1;
		if(check(mid))
			lb=mid+1;
		else
			ub=mid-1;
	}
	cout<<ub<<endl;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	solve();
	return 0;
}