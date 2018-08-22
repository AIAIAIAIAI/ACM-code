#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
double ans[15];
int main()
{
    double a[12],b[12],c[12];
    for(int i=0;i<36;i++)
        if(i<12)
            cin>>a[i];
        else if(i<24)
            cin>>b[i%12];
        else
            cin>>c[i%12];
    double p[12];
    for(int i=0;i<12;i++)
        p[i]=a[i]+(1-a[i])*(b[i]+c[i]-b[i]*c[i]);
    for(int i=0;i<(1<<12);i++)
    {
        int t=i,cnt=0;
        int temp=12;
        double res=1;
        while(temp--)
        {
            if(t&1)
            {
                cnt++;
                res*=p[temp];
            }
            else
                res*=1-p[temp];
            t>>=1;
        }
        ans[cnt]+=res;
    }
    for(int i=0;i<13;i++)
        printf("%.6lf\n",ans[i]);
    return 0;
}