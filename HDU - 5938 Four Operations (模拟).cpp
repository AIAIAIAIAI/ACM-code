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
LL fun(char *s,int p,int l)
{
	LL ans=0;
	while(p<=l)
		ans=ans*10+s[p++]-'0';
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	int cnt=0;
	LL a,b,c,d,e;
	while(t--)
	{
		char s[25];
		cin>>s;
		int len=strlen(s);
		LL ans=-INF;
		for(int i=0;i+4<len;i++)
		{
			a=fun(s,0,i);
			for(int j=i+1;j+3<len;j++)
			{
				b=fun(s,i+1,j);
				c=fun(s,j+1,j+1);
				d=fun(s,j+2,j+2);
				e=fun(s,j+3,len-1);
				ans=max(ans,a+b-c*d/e);
			}
		}
		cout<<"Case #"<<++cnt<<": "<<ans<<endl;
	}
	return 0;
}