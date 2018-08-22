#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1000000007;
typedef long long LL;
struct Matrix
{
    LL a[2][2];
    Matrix()
    {
        memset(a,0,sizeof(a));
    }
    void init()
    {
        for(int i=0;i<2;i++)
            a[i][i]=1;
    }
    Matrix operator *(const Matrix &B)
    {
        Matrix C;
        for(int i=0;i<2;i++)
            for(int k=0;k<2;k++)
                for(int j=0;j<2;j++)
                    C.a[i][j]=(C.a[i][j]+a[i][k]*B.a[k][j])%(mod-1);
        return  C;
    }
    Matrix operator ^(int n)
    {
        Matrix res,A=(*this);
        res.init();
        while(n)
        {
            if(n&1)
                res=res*A;
            A=A*A;
            n>>=1;
        }
        return res;
    }
};
LL quick_pow(int a,LL b)
{
    LL ans=1;
    LL tmp=1LL*a;
    while(b)
    {
        if(b&1)
            ans=(ans*tmp)%mod;
        tmp=(tmp*tmp)%mod;
        b>>=1;
    }
    return ans;
}
int main()
{
    int a,b,n;
    while(cin>>a>>b>>n)
    {
        if(n==0)
        {
            cout<<a<<endl;
            continue;
        }
        else if(n==1)
        {
            cout<<b<<endl;
            continue;
        }
        Matrix A;
        A.a[0][0]=A.a[0][1]=A.a[1][0]=1;
        A.a[1][1]=0;
        A=A^(n-2);
        LL ans=(quick_pow(a,A.a[1][0]+A.a[1][1])*quick_pow(b,A.a[0][0]+A.a[0][1]))%mod;
        cout<<ans<<endl;
    }
    return 0;
}