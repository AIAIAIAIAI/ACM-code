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
int p[10][10];
LL sum[maxn];
LL pre[maxn];
int num;
int x,k;
void init()
{
	ms(sum,0);
	num=0;
	for(int i=1;i<100000;i++)
	{
		int tmp=i;
		while(tmp)
		{
			sum[i]+=p[tmp%10][k];
			tmp/=10;
		}
		pre[num++]=sum[i]-i;
	}
	sort(pre,pre+num);
}
int solve()
{
	int ans=0;
	for(int i=0;i<100000;i++)
	{
		LL t=x-sum[i]+i*100000LL;
		int j=lower_bound(pre,pre+num,t)-pre;
		int res=0;
		while(j<num&&pre[j++]==t)
			res++;
		ans+=res;
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	for(int i=1;i<10;i++)
	{
		p[i][0]=1;
		for(int j=1;j<10;j++)
			p[i][j]=p[i][j-1]*i;
	}
	int t;
	cin>>t;
	int cnt=0;
	while(t--)
	{
		cin>>x>>k;
		init();
		cout<<"Case #"<<++cnt<<": "<<solve()<<endl;
	}
	return 0;
}