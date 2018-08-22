#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=1005,INF=0x3f3f3f3f;
char maze[maxn][maxn];
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
int d[maxn][maxn];
bool vis[maxn][maxn];
int n,m,k;
int sx,sy,ex,ey;
struct node
{
    int x,y,step;
};
void bfs()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            d[i][j]=INF;
    node cur;
    cur.x=sx,cur.y=sy,cur.step=0;
    queue<node> que;
    que.push(cur);
    d[sx][sy]=0;//起点要设为0
    while(que.size())
    {
        cur=que.front();
        que.pop();
        for(int i=0;i<4;i++)
            for(int j=1;j<=k;j++)
            {
                node next;
                next.x=cur.x+dx[i]*j;
                next.y=cur.y+dy[i]*j;
                next.step=cur.step+1;
                if(next.x<1||next.x>n||next.y<1||next.y>m||maze[next.x][next.y]=='#'||(vis[next.x][next.y]&&cur.step>=d[next.x][next.y]))
                    break;//如果当前方向上的某个点访问过，并且到起点的距离大于当前点的距离，则该方向的就不用再搜索了
                if(next.step<d[next.x][next.y]&&!vis[next.x][next.y])
                {
                    vis[next.x][next.y]=true;
                    d[next.x][next.y]=next.step;
                    que.push(next);
                }                    
            }
    }
    if(d[ex][ey]==INF)
        cout<<"-1"<<endl;
    else
        cout<<d[ex][ey]<<endl;
}
int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        cin>>(maze[i]+1);
    cin>>sx>>sy>>ex>>ey;
    bfs();
    return 0;
}