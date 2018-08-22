/*#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=1e5+5;
int n,c,f;
typedef long long LL;
LL low[maxn],high[maxn];
struct node
{
    int id,cost;
    bool operator <(const node& a) const
    {
        return id<a.id;
    }
}a[maxn];
int main()
{
    ios::sync_with_stdio(false);
    priority_queue<int,vector<int>,less<int> >que;
    cin>>n>>c>>f;
    for(int i=0;i<c;i++)
        cin>>a[i].id>>a[i].cost;
    sort(a,a+c);
    n>>=1;
    LL sum=0;
    for(int i=0;i<n;i++)
    {
        que.push(a[i].cost);
        sum+=a[i].cost;
    }
    for(int i=n;i<=c-n-1;i++)
    {
        low[i]=sum;
        if(a[i].cost<que.top())
        {
            sum-=que.top();
            que.pop();
            que.push(a[i].cost);
            sum+=a[i].cost;
        }
    }
    sum=0;
    while(que.size()) que.pop();
    for(int i=c-1;i>c-n-1;i--)
    {
        que.push(a[i].cost);
        sum+=a[i].cost;
    }
    for(int i=c-n-1;i>=n;i--)
    {
        high[i]=sum;
        if(a[i].cost<que.top())
        {
            sum-=que.top();
            que.pop();
            que.push(a[i].cost);
            sum+=a[i].cost;
        }
    }
    int ans=-1;
    for(int i=c-n-1;i>=n;i--)
    {
        if(low[i]+a[i].cost+high[i]<=f)
        {
            ans=a[i].id;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e5+5;
struct cow
{
    int rank,id,cost;
}a[maxn],s[maxn];//a数组按分数排序，s数组按花费排序
int n,c,f;
bool cmp1(cow a,cow b)
{
    return a.id<b.id;
}
bool cmp2(cow a,cow b)
{
    return a.cost<b.cost;
}
int main()
{
    //ios::sync_with_stdio(false);
    scanf("%d%d%d",&n,&c,&f);
    n>>=1;
    for(int i=0;i<c;i++)
        scanf("%d%d",&a[i].id,&a[i].cost);
    sort(a,a+c,cmp1);
    for(int i=0;i<c;i++)
        a[i].rank=i;
    memcpy(s,a,sizeof(cow)*c);
    sort(s,s+c,cmp2);
    int lb=0,ub=c-1;
    int ans;
    while(ub-lb>1)
    {
        int mid=(lb+ub)>>1;
        int l=0,r=0,sum=a[mid].cost;
        for(int i=0;i<c;i++)//排序是为了先选取花费小的
        {
            if(l<n&&s[i].rank<mid&&sum+s[i].cost<=f)
            {
                l++;
                sum+=s[i].cost;
            }
            else if(r<n&&s[i].rank>mid&&sum+s[i].cost<=f)
            {
                r++;
                sum+=s[i].cost;
            }
        }
        if(l<n&&r<n)
        {
            ans=-1;
            break;
        }
        else if(l<n)
        {
            lb=mid;
        }
        else if(r<n)
        {
            ub=mid;
        }
        else
        {
            ans=a[mid].id;
            lb=mid;
        }
    }
    printf("%d\n",ans);
    return 0;
}