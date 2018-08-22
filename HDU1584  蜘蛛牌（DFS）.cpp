#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int ans;
bool vis[15];
int a[15];
void dfs(int cnt,int sum)
{
    if(sum>ans)
        return ;
    if(cnt==10)
    {
        ans=sum;
        return ;
    }
    for(int i=1;i<10;i++)
    {
        if(!vis[i])
        {
            vis[i]=true;
            for(int j=i+1;j<=10;j++)//把当前牌放在比他大的牌的上面
                if(!vis[j])//访问过代表这张牌已经挪到其他牌上去了
                {
                    dfs(cnt+1,sum+abs(a[i]-a[j]));
                    break;
                }
            vis[i]=false;//状态回溯
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        for(int i=1;i<=10;i++)
        {
            int x;
            cin>>x;
            a[x]=i;
        }
        ans=1e9;
        memset(vis,false,sizeof(vis));
        dfs(1,0);
        cout<<ans<<endl;
    }
    return 0;
}