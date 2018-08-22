#include<iostream>
#include<cstdio>
using namespace std;
int a[505][505];
bool judge(int sx,int sy,int k)
{
	int ans;
	bool flag=false;
	for(int curx=sx;curx<sx+k;curx++)
	{
		int tmp=0;	
		for(int i=0;i<k;i++)
		{
			int posx=curx+i;
			if(posx>=sx+k)
				posx-=k;
			tmp+=a[posx][sy+i];
		}
		if(!flag)
		{
			ans=tmp;
			flag=true;
		}
		if(ans!=tmp)
			return false;
		tmp=0;
		for(int i=0;i<k;i++)
		{
			int posx=curx-i;
			if(posx<sx)
				posx+=k;
			tmp+=a[posx][sy+i];
		}
		if(ans!=tmp)
			return false;
	}
	return true;
}
int main()
{
	int n,m,t;
	scanf("%d%d%d",&n,&m,&t);
	for(int i=1  ;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(int i=0;i<t;i++)
	{
		int row,col,k;
		scanf("%d%d%d",&row,&col,&k);
		if(judge(row,col,k)||k==1)
			puts("Y");
		else
			puts("N");
	}
	return 0;
}