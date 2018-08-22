#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct node
{
    int a[3];
}mp[25];
bool vis[25];
int order[25];
int m,cas;
void dfs(int x,int cnt)
{
    if(cnt>20)
        return ;
    if(cnt==20&&(mp[x].a[0]==m||mp[x].a[1]==m||mp[x].a[2]==m))
    {
        cout<<++cas<<":  ";
        for(int i=0;i<20;i++)
            cout<<order[i]<<' ';
        cout<<m<<endl;
        return ;
    }
    for(int i=0;i<3;i++)
    {
        int cur=mp[x].a[i];
        if(!vis[cur])
        {
            order[cnt]=cur;
            vis[cur]=true;
            dfs(cur,cnt+1);
            vis[cur]=false;
        }
    }
}
int main()
{
    for(int i=1;i<=20;i++)
    {
        cin>>mp[i].a[0]>>mp[i].a[1]>>mp[i].a[2];
        sort(mp[i].a,mp[i].a+3);
    }
    while(cin>>m&&m)
    {
        memset(vis,false,sizeof(vis));
        cas=0;
        order[0]=m;
        vis[m]=true;
        dfs(m,1);
    }
    return 0;
}