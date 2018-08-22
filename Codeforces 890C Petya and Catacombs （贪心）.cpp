#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=2e5+5,INF=0x3f3f3f3f;
int a[maxn];
int num[maxn];
int last[maxn];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int ans=1;
    for(int i=1;i<=n;i++)
    {
        int cur=a[i];
        if(last[num[cur]]==cur)
        {
            last[num[cur]]=i;
            num[i]=num[cur];
        }
        else
        {
            num[i]=ans++;
            last[num[i]]=i;
        }
    }
    cout<<ans<<endl;
    return 0;
}