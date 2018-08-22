#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int a[50];
bool vis[50];
int ave;
bool flag;
int n;
void dfs(int cnt,int sum,int k)
{
    if(flag) return ;
    if(cnt==3)//前3个边都选好了，那么最后一条边一定能满足
    {
        flag=true;
        return ;
    }
    for(int i=k;i<n;i++)
    {
        if(!vis[i]&&a[i]+sum<=ave)
        {
            vis[i]=true;
            if(sum+a[i]==ave)
                dfs(cnt+1,0,0);
            else
                dfs(cnt,sum+a[i],i+1);
            if(flag) return ;
            vis[i]=false;
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int sum=0;
        for(int i=0;i<n;i++)
            cin>>a[i],sum+=a[i];
        if(sum%4)//剪枝，如果不能被4整除，一定不能组成四边形
        {
            cout<<"no"<<endl;
            continue;
        }
        ave=sum/4;
        flag=false;
        memset(vis,false,sizeof(vis));
        dfs(0,0,0);
        if(flag)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}