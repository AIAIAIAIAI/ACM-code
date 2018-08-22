#include<iostream>
#include<cstring>
using namespace std;
int a[3][6];
bool used[6];
bool vis[1005];
int n;
void dfs(int num,int k)//k为当前使用的正方体数量
{
    vis[num]=true;
    if(k>=n)
        return ;
    for(int i=0;i<n;i++)
    {
        if(!used[i])
        {
            for(int j=0;j<6;j++)
            {
                used[i]=true;
                dfs(10*num+a[i][j],k+1);
                used[i]=false;//DFS回溯
            }
        }
    }
}
int main()
{
    cin>>n;
    //memset(used,false,sizeof(used));
    //memset(vis,false,sizeof(vis));
    for(int i=0;i<n;i++)
        for(int j=0;j<6;j++)
            cin>>a[i][j];
    dfs(0,0);
    for(int i=1;i<=1000;i++)
        if(!vis[i])
        {
            cout<<i-1<<endl;
            break;
        }
    return 0;
}