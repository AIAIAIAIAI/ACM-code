#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int INF=0x3f3f3f3f;
const int maxn=2000;
#define ms(a,x) memset(a,x,sizeof(a))
inline LL read()
{
    LL x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int main()
{
	int t;
	cin>>t;
	int a[]={1,9,41,109,205};
	int cnt=0;
	while(t--)
	{
		ULL n;
		cin>>n;
		cout<<"Case #"<<++cnt<<": ";
		if(n<5)
			cout<<a[n]<<endl;
		else
			cout<<14*n*n-6*n+5<<endl;
	}	

	return 0;
}