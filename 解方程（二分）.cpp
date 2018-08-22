#include<iostream>
#include<algorithm>
using namespace std;
int a[2005];
int n;
bool check(int x)
{
    int lb=0,ub=n-1;
    while(lb<ub)
    {
        int mid=(lb+ub)>>1;
        if(x==a[mid])
            return true;
        else if(x>a[mid])
            lb=mid+1;
        else
            ub=mid-1;
    }
    return false;
}
int main()
{
    int x;
    cin>>n>>x;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    bool flag=false;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int t=a[i]*x*x+a[j]*x;
            if(-t>a[n-1]||-t<a[0])
                continue;
            if(check(-t))
            {
                cout<<"YES"<<endl;
                flag=true;
                break;
            }
        }
        if(flag)
            break;
    }
    if(!flag)
        cout<<"NO"<<endl;
    return 0;
}