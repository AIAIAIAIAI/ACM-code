#include<iostream>
#include<cstdio>              
#include<cstring>
using namespace std;
int dp[100005][15];
const int INF=0x3f3f3f3f;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF&&n)
    {
        memset(dp,0,sizeof(dp));
        int T=0;
        for(int i=0;i<n;i++)
        {
            int x,t;
            scanf("%d%d",&x,&t);
            dp[t][x+1]++;//方便后面处理，位置+1
            T=max(t,T);
        }
        for(int i=0;i<=12;i++)
            dp[0][i]=-INF;
        dp[0][6]=0;//从5号位置开始dp
        for(int i=1;i<=T;i++)
        {
            for(int j=1;j<12;j++)
            {
                dp[i][j]+=max(dp[i-1][j],max(dp[i-1][j+1],dp[i-1][j-1]));//dp转移方程
            }
        }
        int ans=0;
        for(int i=1;i<12;i++)
            ans=max(ans,dp[T][i]);//找出T时刻的最大值
        printf("%d\n",ans);
    }
    return 0;
}