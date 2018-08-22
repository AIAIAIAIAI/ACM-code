#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn=3e4;
struct shift
{
    int beg,end;
    bool operator <(const shift& a) const
    {
        return beg==a.beg?end>a.end:beg<a.beg;
    }
}a[maxn];
int main()
{
    int n,t;
    scanf("%d%d",&n,&t);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a[i].beg,&a[i].end);
    }
    sort(a,a+n);
    int cur=0;
    int l=0;
    int ans=0;
    while(cur<n)
    {
        if(a[cur].beg>l+1)
            return puts("-1");
        int tmp=1;
        while(cur<n&&a[cur].beg<=l+1)
        {
            tmp=max(tmp,a[cur].end);
            cur++;
        }
        l=tmp;
        ans++;
        if(l>=t)
            return printf("%d\n",ans);
    }
    return puts("-1");
}