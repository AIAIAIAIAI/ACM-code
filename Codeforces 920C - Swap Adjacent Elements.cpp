#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=2e5+5;
int a[maxn];
char s[maxn];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	cin>>s;
	for(int i=0;i<n-1;i++)
	{
		if(s[i]=='1')
		{
			int j=i;
			for(;s[j]=='1';j++);
			sort(a+i,a+j+1);
			i=j;
		}
	}
	for(int i=0;i<n-1;i++)
		if(a[i]>a[i+1])
			return puts("NO"),0;
	puts("YES");
	return 0;
}