#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=10005;
int perm[maxn];
bool used[maxn];
int n,k;
int cnt;
bool flag;
void permutation(int pos,int n)
{
    if(pos==n+1)//排列完毕
    {
        if(++cnt==k)
            flag=true;   
        return ;
    }
    for(int i=1;i<=n;i++)//数列的第pos个位置，用第1~n个的哪一个进行循环
    {
        if(!used[i])
        {
            perm[pos]=i;
            used[i]=true;//i被使用了，标记为true
            permutation(pos+1,n);
            if(flag)
                return ;
            used[i]=false;//返回后要复位
        }
    }
    return ;
}
int main()
{
    while(cin>>n>>k)
    {
        flag=false;
        memset(used,false,sizeof(used));
        cnt=0;
        for(int i=1;i<=n;i++)
            perm[i]=i;
        permutation(1,n);
        for(int i=1;i<n;i++)
            cout<<perm[i]<<' ';
        cout<<perm[n]<<endl;
    }
    return 0;
}