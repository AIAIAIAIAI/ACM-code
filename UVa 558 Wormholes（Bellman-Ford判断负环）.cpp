#include<iostream>
#include<cstring>
using namespace std;
const int maxn=2005;
int d[maxn];
int n,m;
struct edge
{
	int from,to,cost;
}es[maxn];
bool find_negative_loop()
{
	memset(d,0,sizeof(d));
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			edge e=es[j];
			if(d[e.to]-d[e.from]>e.cost)
			{
				d[e.to]=d[e.from]+e.cost;
				if(i==n-1)//第n次还进行了更新，则存在负环
					return true;
			}
		}
	return false;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=0;i<m;i++)
			cin>>es[i].from>>es[i].to>>es[i].cost;
		if(find_negative_loop())
			cout<<"possible"<<endl;
		else
			cout<<"not possible"<<endl;
	}
	return 0;
}