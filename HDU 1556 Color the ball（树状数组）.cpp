#include<iostream>
#include<cstring>
using namespace std;
const int maxn=1e5+5;
int BIT[maxn];
int N;
int lowbit(int i)
{
	return i&(-i);
}
int sum(int i)
{
	int s=0;
	while(i>0)
	{
		s+=BIT[i];
		i-=lowbit(i);
	}
	return s;
}
void add(int i,int x)
{
	while(i<=N)
	{
		BIT[i]+=x;
		i+=lowbit(i);
	}
}
int main()
{
	while(cin>>N&&N)
	{
		memset(BIT,0,sizeof(BIT));
		for(int i=0;i<N;i++)
		{
			int a,b;
			cin>>a>>b;
			add(a,1);
			add(b+1,-1);
		}
		for(int i=1;i<=N;i++)
			if(i==N)
				cout<<sum(i)<<endl;
			else
				cout<<sum(i)<<" ";

	}
}