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

int main()
{
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int n;
	while(cin>>n,n)
	{
		int a[105];
		for(int i=0;i<n;i++)
			cin>>a[i];
		if(a[n-1]==0||a[n-1]==15||n==1)
		{
			if(a[n-1]==0)
				cout<<"UP"<<endl;
			else if(a[n-1]==15)
				cout<<"DOWN"<<endl;
			else
				cout<<"-1"<<endl;
			continue;
		}
		int t=a[n-1]-a[n-2];
		if(t>0)
		{
			if(a[n-1]==15)
				cout<<"DOWN"<<endl;
			else
				cout<<"UP"<<endl;
		}
		else
		{
			if(a[n-1]==1)
				cout<<"UP"<<endl;
			else
				cout<<"DOWN"<<endl;
		}
	}
	return 0;
}