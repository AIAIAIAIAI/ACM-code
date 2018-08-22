#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int maxn=1e5+5;
#define ms(a,x) memset(a,x,sizeof(a))
inline LL read()
{
    LL x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int v[maxn],t[maxn];
LL f[maxn],m[maxn];
LL sum[maxn];
int n;
int binary_search(LL x)
{
    if(x>sum[n-1])
        return n;
    int lb=0,ub=n-1;
    while(lb<=ub)
    {
        int mid=(lb+ub)>>1;
        if(x>=sum[mid])
            lb=mid+1;
        else
            ub=mid-1;
    }
    return lb;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>v[i];
    for(int i=0;i<n;i++)
    {
        cin>>t[i];
        sum[i]=t[i];
        if(i)
            sum[i]+=sum[i-1];//求前缀和
    }
    for(int i=0;i<n;i++)
    {
        int j=binary_search(v[i]+sum[i-1]);//二分查找雪球在第j天能完全融化
        m[j]+=v[i]+sum[i-1]-sum[j-1];//计算第j天的雪球剩余量
        f[j]++;//第j天融化的雪球
        cout<<(i+1-f[i])*t[i]+m[i]<<' ';
        f[i+1]+=f[i];//第i+1天前融化的雪球数量
    }
    cout<<endl;
    return 0;
}