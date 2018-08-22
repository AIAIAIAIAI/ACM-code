#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int INF=0x3f3f3f3f;
int dp[50][50],a[50][50];
int main()
{
    int n,k;
    while(cin>>n>>k)
    {
        memset(dp,INF,sizeof(dp));
        for(int i=0;i<n;i++)
            for(int j=0;j<k;j++)
            {    
                cin>>a[i][j];
                if(!i)
                    dp[i][j]=0;
            }
        for(int i=1;i<n;i++)
            for(int j=0;j<k;j++)
                for(int t=0;t<k;t++)
                    dp[i][j]=min(dp[i][j],dp[i-1][t]+abs(a[i][j]-a[i-1][t]));
        int ans=INF;
        for(int j=0;j<k;j++)
            ans=min(ans,dp[n-1][j]);
        cout<<ans<<endl;
    }
    return 0;
}