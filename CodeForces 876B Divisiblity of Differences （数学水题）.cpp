#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1e5+5;
int a[maxn];
int has[maxn];
int main()
{
    int n,k,m;
    while(cin>>n>>k>>m)
    {
        memset(has,0,sizeof(has));
        int flag=-1;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(++has[a[i]%m]>=k)
            {
                flag=a[i]%m;
            }
        }
        if(flag==-1)
            cout<<"No"<<endl;
        else
        {
            cout<<"Yes"<<endl;
            int cnt=0;
            for(int i=0;i<n&&cnt<k;i++)
            {
                if(a[i]%m==flag)
                {
                    cnt++;
                    cout<<a[i]<<' ';
                }
            }
            cout<<endl;
        }
    }
    return 0;
}