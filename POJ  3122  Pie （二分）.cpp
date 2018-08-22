#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int a[10004];
int n,f;
const double eps=1e-5;
int c(double mid)
{
    int sum=0;
    for(int i=n-1;i>=0;i--)
    {
        sum+=a[i]/mid;
    }
    return sum>=f+1;
}
int main()
{
    int m;
    cin>>m;
    while(m--)
    {      
        cin>>n>>f;
        int s=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            a[i]*=a[i];
            s=max(s,a[i]);
        }
        double l=0;
        double r=s;
        while(l+eps<r)
        {
            double mid=(l+r)/2;
            if(c(mid))
                l=mid;
            else
                r=mid;
        }
        printf("%.4f\n",l*3.14159265359);
    }
    return 0;
}