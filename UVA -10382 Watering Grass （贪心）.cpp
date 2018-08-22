#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<string>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int maxn=1e4+5;
inline LL read()
{
    LL x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct node
{
    double l,r;
    bool operator <(const node& B)const
    {
        if(l==B.l)
            return r<B.r;
        return l<B.l;
    }
}a[maxn];
int main()
{
    int n,l,w;
    while(cin>>n>>l>>w)
    {
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            int x,r;
            cin>>x>>r;
            if(2*r<w)
                continue;
            double tmp=sqrt(1.0*r*r-w*w/4.0);
            a[cnt].l=x-tmp;
            a[cnt++].r=x+tmp;
        }
        sort(a,a+cnt);
        double st=0;
        int ans=0;
        if(a[0].l>0)
        {
            cout<<"-1"<<endl;
            continue;
        }
        while(st<l)
        {
            double ed=st;
            for(int i=0;i<cnt;i++)
                if(a[i].l<=st&&a[i].r>ed)
                    ed=a[i].r;
            if(st==ed)
            {
                ans=-1;
                break;
            }
            st=ed;
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}