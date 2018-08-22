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
int bit[maxn][maxn];
int n;
int lowbit(int i)
{
	return i&-i;
}
int sum(int x,int y)
{
	int s=0;
	for(int i=x;i>0;i-=lowbit(i))
		for(int j=y;j>0;j-=lowbit(j))
			s+=bit[i][j];
	return s;
}
void add(int x,int y)//单点加1
{
	for(int i=x;i<=n;i+=lowbit(i))
		for(int j=y;j<=n;j+=lowbit(j))
			bit[i][j]++;
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		ms(bit,0);
		int q;
		cin>>n>>q;
		while(q--)
		{
			char op;
			int x1,y1,x2,y2;
			cin>>op;
			if(op=='C')
			{
				cin>>x1>>y1>>x2>>y2;
				add(x1,y1),add(x2+1,y1),add(x1,y2+1),add(x2+1,y2+1);
			}
			else
			{
				cin>>x1>>y1;
				cout<<sum(x1,y1)%2<<endl;
			}
		}
		if(t)
			cout<<endl;
	}
	return 0;
}