#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
char maze[200][200];
const int INF=0x3f3f3f3f;
int lft[200];
int rht[200];
int main()
{
    while(cin>>n>>m)
    {
        memset(lft,INF,sizeof(lft));//需要移动到的最左边
        memset(rht,0,sizeof(rht));//最右边
        int last=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>maze[i][j];
                if(maze[i][j]=='W')
                {
                    last=i;
                    lft[i]=min(lft[i],j);
                    rht[i]=max(rht[i],j);
                }
            }
        }
        int ans=0;
        int cur=1;//起始位置
        for(int i=1;i<=last;i++)
        {
            int next;
            if(i%2)
            {
                next=max(rht[i],rht[i+1]);
                if(next-cur>0)
                    ans+=next-cur,cur=next;
            }
            else
            {
                next=min(lft[i],lft[i+1]);
                if(cur-next>0)
                    ans+=cur-next,cur=next;
            }
        }
        cout<<ans+last-1<<endl;
    }
    return 0;
}