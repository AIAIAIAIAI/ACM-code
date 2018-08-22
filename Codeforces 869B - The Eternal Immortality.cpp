#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	long long a,b;
	while(cin>>a>>b)
	{
		if(a==b)
			cout<<1<<endl;
		else if(b>a+4)
		{
			cout<<0<<endl;
		}
		else
		{
			int ans=1;
			for(long long i=a+1;i<=b;i++)
			{
				
				ans=ans*(i%10)%10;
			}
			cout<<ans<<endl;
		}
	}
	return 0;	
}