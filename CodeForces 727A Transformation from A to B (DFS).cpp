#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1e7+5;
int a[maxn];
bool flag=false;
int ans,n,k;
void dfs(int x,int step)
{
	if(x==k)
	{
		flag=true;
		ans=step;
		return ;
	}
	if(x>k)
		return ;
	a[step]=x*10+1;
	if(x<=2e8)//防止乘10后爆int
		dfs(x*10+1,step+1);
	if(flag)
		return ;
	a[step]=x*2;
	dfs(x*2,step+1);
}
int main()
{
	while(cin>>n>>k)
	{
		flag=false;
		memset(a,0,sizeof(a));
		dfs(n,1);
		if(flag)
		{
			cout<<"YES\n"<<ans<<endl;
			a[0]=n;
			for(int i=0;i<ans;i++)
				cout<<a[i]<<' ';
			cout<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}