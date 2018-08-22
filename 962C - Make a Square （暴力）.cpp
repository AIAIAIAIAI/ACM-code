#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int maxn=100005;
#define ms(a,x) memset(a,x,sizeof(a))
inline LL read()
{
    LL x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
char s[15],t[15];
int ans;
int fun(LL x)
{
	int cnt=0;
	while(x)
	{
		t[cnt++]='0'+x%10;
		x/=10;
	}
	return cnt;
}
void solve(int n)
{
	ans=INF;
	for(LL i=1;i<100000;i++)
	{
		int len=fun(i*i);
		int res=0;
		bool flag=false;
		for(int j=len-1,k=0;j>=0;j--,k++)
		{
			while(s[k]&&s[k]!=t[j])
				k++;
			if(k<n)
			{
				res++;
				flag=true;
			}
			else
			{
				flag=false;
				break;
			}
		}
		if(flag)
			ans=min(ans,n-res);
	}
	if(ans==INF)
		cout<<"-1"<<endl;
	else
		cout<<ans<<endl;
}
int main()
{
	while(cin>>s)
	{
		solve(strlen(s));
	}
	return 0;
}