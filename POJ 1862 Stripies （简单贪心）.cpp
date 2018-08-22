#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
int a[105];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    double ans=a[n-1];
    for(int i=n-2;i>=0;i--)
    {
        ans=2*sqrt(ans*a[i]);
    }
    cout.setf(ios::fixed);
    cout.precision(3);
    cout<<ans<<endl;
    return 0;
}