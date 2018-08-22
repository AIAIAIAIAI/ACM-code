#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const double INF=1e5+5,esp=1e-6;
const int maxn=1e4+5;
double a[maxn];
int n,k;
bool check(double x)
{
	int num=0;
	for(int i=0;i<n;i++)
	{
		num+=(int)(a[i]/x);
	}
	return num>=k;
}
void solve()
{
	double lb=0,ub=INF;
	while(lb+esp<ub)
	{
		double mid=(lb+ub)/2;
		if(check(mid))
			lb=mid;
		else
			ub=mid;
	}
	printf("%.2f\n",floor(ub*100)/100);
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
	{	
		scanf("%lf",&a[i]);
	}
	solve();
	return 0;
}