#include<iostream>
using namespace std;
const int maxn=1e4+5;
int res[maxn];
int main()
{
	int a,b,f,k;
	while(cin>>a>>b>>f>>k)
	{
		int cnt=0;
		int lo=2*f,so=2*(a-f);
		int t=(k-1)/2;
		res[cnt++]=f;
		if(k&1)
		{
			
			for(int i=0;i<t;i++)
			{
				res[cnt++]=so;
				res[cnt++]=lo;
			}
			res[cnt++]=a-f;
		} 
		else 
		{
			res[cnt++]=so;
			for(int i=0;i<t;i++)
			{
				res[cnt++]=lo;
				res[cnt++]=so;
			}
			res[cnt++]=f;
		}
		int ans=0;
		if(b<f||b<a-f)
			cout<<"-1"<<endl;
		else
		{
			int temp=b;
			bool flag=false;
			for(int i=0;i<cnt-1;i++)
			{
				if(res[i]>b)
				{
					flag=true;
					break;
				}
				if(res[i]+res[i+1]<=temp)
				{
					temp-=res[i];
				}
				else
				{
					ans++;
					temp=b;
				}
			}
			if(flag)
				cout<<"-1"<<endl;
			else
				cout<<ans<<endl;
		}
	}
	return 0;
}