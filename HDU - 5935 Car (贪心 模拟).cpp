#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int maxn=100005;
const double eps=1e-7;
#define ms(a,x) memset(a,x,sizeof(a))
inline LL read()
{
    LL x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int a[maxn];
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	int cnt=0;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		double v=a[n]-a[n-1];
		int ans=1;
		for(int i=n-1;i;i--)
		{
			int s=a[i]-a[i-1];
			if(s<=v)
			{
				v=s;
				ans++;
			}
			else
			{
				int tmp=ceil((s-eps)/v);
				ans+=tmp;
				v=1.*s/tmp;
			}
		}
		cout<<"Case #"<<++cnt<<": "<<ans<<endl;
	}
	return 0;
}