#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=1e5+5;
const double INF=1e6+5,esp=1e-6;
int v[maxn],w[maxn];
double y[maxn];
int n,k;
bool check(double x)//可以选择使得单位重量的价值不小于x
{
	for(int i=0;i<n;i++)
	{
		y[i]=v[i]-x*w[i];
	}
	sort(y,y+n);
	double sum=0;
	for(int i=k;i<n;i++)
		sum+=y[i];
	return sum>=0;
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
	printf("%.f\n",floor(100*lb+0.5));
}
int main()
{
	while(cin>>n>>k,n||k)
	{
		for(int i=0;i<2*n;i++)
		{
			if(i<n)
				scanf("%d",&v[i]);
			else
				scanf("%d",&w[i%n]);;
		}
		solve();
	}
	return 0;
}