#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int maxn=1005;
#define ms(a,x) memset(a,x,sizeof(a))

inline LL read()
{
    LL x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int p[20] = {0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
LL n,ans;
void dfs(LL num,int pos,int pr,LL res)//num 当前数，pos 第pos个素数，pr 最高幂次数,res 当前答案
{
	if(pos>15)//
		return ;
	if(res>ans)
		ans=res;
	for(int i=1;i<=pr;i++)
	{
		if(num>n/p[pos])
			return ;
		num*=p[pos];
		dfs(num,pos+1,i,res*(i+1));
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans=0;
		dfs(1,1,15,1);
		cout<<ans<<endl;
	}
	return 0;
}