#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1e5+5;
typedef long long LL;
struct cow
{
    int t,cost;
    bool operator <(const cow& a) const
    {
        return cost*a.t>t*a.cost;//赶走一只奶牛需要花费花朵的数量，从大到小
    }
}c[maxn];
int main()
{
    int n;
    cin>>n;
    LL sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>c[i].t>>c[i].cost;
        sum+=c[i].cost;
    }
    sort(c,c+n);
    LL ans=0;
    for(int i=0;i<n-1;i++)
    {
        sum-=c[i].cost;
        ans+=2*sum*c[i].t;
    }
    cout<<ans<<endl;
    return 0;
}