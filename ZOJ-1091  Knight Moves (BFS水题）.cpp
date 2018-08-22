#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<cstdio>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int maxn=1e5+5;
#define ms(a,x) memset(a,x,sizeof(a))
inline LL read()
{
    LL x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
bool vis[10][10];
int dx[]={-1,-2,-2,-1,1,2,2,1},dy[]={2,1,-1,-2,2,1,-1,-2};
struct node
{
    int x,y,step;
};
int bfs(int sx,int sy,int ex,int ey)
{
    ms(vis,0);
    queue<node> que;
    vis[sx][sy]=true;
    que.push((node){sx,sy,0});
    while(!que.empty())
    {
        node cur=que.front();
        que.pop();
        if(cur.x==ex&&cur.y==ey)
            return cur.step;
        for(int i=0;i<8;i++)
        {
            int nx=cur.x+dx[i],ny=cur.y+dy[i];
            if(0<=nx&&nx<8&&0<=ny&&ny<8&&!vis[nx][ny])
            {
                vis[nx][ny]=true;
                que.push((node){nx,ny,cur.step+1});
            }
        }
    }
    return 0;
}
int main()
{
    char ch1,ch2;
    int y1,y2;
    while(scanf("%c%d%*c%c%d%*c",&ch1,&y1,&ch2,&y2)!=EOF)
    {
        int x1=ch1-'a',x2=ch2-'a';
        printf("To get from %c%d to %c%d takes %d knight moves.\n",ch1,y1,ch2,y2,bfs(x1,y1-1,x2,y2-1));
    }

    return 0;
}