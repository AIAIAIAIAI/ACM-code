#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=500+5;
const double PI=3.141592625;
char maze[maxn][maxn];
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
int ex,ey;
bool vis[maxn][maxn];
int n,m;
struct node
{
	int x,y;
	int step;
};
int bfs(int sx,int sy,int gx,int gy)
{
	memset(vis,false,sizeof(vis));
	queue<node> que;
	node cur;
	cur.x=sx,cur.y=sy;
	cur.step=0;
	que.push(cur);
	vis[sx][sy]=true;
	while(!que.empty())
	{
		cur=que.front();
		que.pop();
		if(cur.x==gx&&cur.y==gy)
			return cur.step;
		node next=cur;
		for(int i=0;i<4;i++)
		{
			next.x=cur.x+dx[i],next.y=cur.y+dy[i];
			if(0<next.x&&next.x<n&&0<next.y&&next.y<m&&!vis[next.x][next.y]&&maze[next.x][next.y]!='W')
			{
				vis[next.x][next.y]=true;
				next.step=cur.step+1;
				que.push(next);
			}
		}
	}
	return -1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	int ex,ey,dx,dy,sx,sy,kx,ky;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			cin>>maze[i][j];
			if(maze[i][j]=='S')
				sx=i,sy=j;
			if(maze[i][j]=='E')
				ex=i,ey=j;
			if(maze[i][j]=='D')
				dx=i,dy=j;
			if(maze[i][j]=='K')
				kx=i,ky=j;
		}
	maze[dx][dy]='W';
	int ans1=bfs(sx,sy,ex,ey);
	int ans2=bfs(sx,sy,kx,ky);
	int ans3=-1;
	if(ans2!=-1)
	{
		maze[dx][dy]='.';
		ans3=bfs(kx,ky,ex,ey);
	}
	if(ans1==-1&&ans2==-1)
		cout<<"-1"<<endl;
	else if(ans1==-1)
	{
		if(ans3==-1)
			cout<<"-1"<<endl;
		else
			cout<<ans2+ans3<<endl;
	}
	else if(ans2==-1)
		cout<<ans1<<endl;
	else
		cout<<min(ans1,ans2+ans3)<<endl;
	return 0;
}