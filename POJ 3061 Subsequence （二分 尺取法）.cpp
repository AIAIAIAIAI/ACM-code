/*#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn=1e5+5;
int sum[maxn];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,S;
        cin>>n>>S;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            sum[i+1]=sum[i]+x;
        }
        if(sum[n]<S)
        {
            puts("0");
            continue;
        }
        int res=n;
        for(int s=0;sum[s]+S<=sum[n];s++)
        {
            int t=lower_bound(sum+s,sum+n,sum[s]+S)-sum;
            res=min(res,t-s);
        }
        cout<<res<<endl;
    }
    return 0;
}*/
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1e5+5;
int a[maxn];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int s=0,t=0,sum=0;
        for(int i=0;i<n;i++)
            cin>>a[i];
        int res=n+1;
        for(;;)
        {
            while(t<n&&sum<k)
                sum+=a[t++];
            if(sum<k)
                break;
            res=min(res,t-s);
            sum-=a[s++];
        }
        if(res>n)
            res=0;
        cout<<res<<endl;
    }
    return 0;
}