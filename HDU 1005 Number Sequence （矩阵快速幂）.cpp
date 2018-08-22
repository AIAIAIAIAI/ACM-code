#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int mod=7;
struct Matrix
{
    int a[2][2];
    Matrix()
    {
        memset(a,0,sizeof(a));
    }
    void init()
    {
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                a[i][j]=i==j?1:0;
    }
    Matrix operator *(const Matrix &B)
    {
        Matrix C;
        for(int i=0;i<2;i++)
            for(int k=0;k<2;k++)
                for(int j=0;j<2;j++)
                    C.a[i][j]=(C.a[i][j]+a[i][k]*B.a[k][j])%mod;
        return C;
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
int main()
{
    int a,b,n;
    while(cin>>a>>b>>n,a||b||n)
    {
        Matrix A;
        a%=mod,b%=mod;
        if(n<3)
        {
            cout<<"1"<<endl;
            continue;
        }
        A.a[0][0]=a;
        A.a[0][1]=b;
        A.a[1][0]=1;
        A.a[1][1]=0;
        A=A^(n-2);
        cout<<(A.a[0][0]+A.a[0][1])%mod<<endl;
    }
    return 0;
}