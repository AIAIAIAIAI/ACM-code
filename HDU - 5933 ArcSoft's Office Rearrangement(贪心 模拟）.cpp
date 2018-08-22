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
		int n,k;
		cin>>n>>k;
		LL sum=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}
		cout<<"Case #"<<++cnt<<": ";
		if(sum%k)
		{
			cout<<"-1"<<endl;
			continue;
		}
		LL avg=sum/k;
		LL tmp=0,ans=0;
		for(int i=0;i<n;i++)
		{
			if(tmp)
				ans++;
			tmp+=a[i];
			if(tmp%avg==0)
			{
				ans+=tmp/avg-1;
				tmp=0;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}