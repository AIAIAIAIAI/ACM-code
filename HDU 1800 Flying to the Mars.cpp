#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[3005];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        int ans=1,t=1;
        for(int i=1;i<n;i++)
        {
            if(a[i]==a[i-1])
                t++;
            else
                t=1;
            ans=max(ans,t);
        }
        printf("%d\n",ans);
    }
    return 0;
}