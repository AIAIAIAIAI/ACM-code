#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=1005;
typedef long long LL;
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
    bool operator < (const node b)const
    {
        return l<b.l;
    }
}seg[maxn];
int main()
{
    int n,d;
    int cnt=1;
    while(cin>>n>>d)
    {
        if(!(n||d))
            break;
        int x,y;
        bool flag=false;
        for(int i=0;i<n;i++)
        {
            cin>>x>>y;
            if(y>d)
                flag=true;
            double tmp=sqrt(d*d-y*y);
            seg[i].l=x-tmp,seg[i].r=x+tmp;
        }
        cout<<"Case "<<cnt++<<": ";
        if(flag)
        {
            cout<<"-1"<<endl;
            continue;
        }
        sort(seg,seg+n);
        node line=seg[0];
        int ans=1;
        for(int i=1;i<n;i++)
        {
            if(seg[i].l>line.r)
            {
                ans++;
                line=seg[i];
            }
            else if(seg[i].r<line.r)
                line=seg[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}