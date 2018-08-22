#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
const int eps=1E-8;
typedef vector<double> vec;
typedef vector<vec> mat;
//求解Ax=b，A是方阵
//当方程组无解或者有无穷多解时，返回一个长度为0的数组
vec gauss_jordan(const mat& A,const vec& b)
{
    int n=A.size();
    mat B(n,vec(n+1));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            B[i][j]=A[i][j];
    //把b存放在A的右边方便一起处理
    for(int i=0;i<n;i++)
        B[i][n]=b[i];
    for(int i=0;i<n;i++)
    {
        //把正在处理的未知数系数的绝对值最大的式子换到第i行
        int pivot=i;
        for(int j=i;j<n;j++)
            if(abs(B[i][j])>abs(B[pivot][i]))
                pivot=i;
        swap(B[i],B[pivot]);
        if(abs(B[i][i])<eps)//无解或者有无穷多解
            return vec();
        for(int j=i+1;j<=n;j++)//把正在处理的未知数的系数变为1
            B[i][j]/=B[i][i];
        for(int j=0;j<n;j++)
        {
            if(i!=j)
            {
                //从第j个式子中消去第i个未知数
                for(int k=i+1;k<=n;k++)
                    B[j][k]-=B[j][i]*B[i][k];
            }
        }
    }
    vec x(n);
    for(int i=0;i<n;i++)//存放在右边的b就是答案
        x[i]=B[i][n];
    return x;
} 
int main()
{
    mat A;
    vec b;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        A.push_back(b);
        for(int j=0;j<n;j++)
        {
            int x;
            cin>>x;
            A[i].push_back(x);
        }

    }
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        b.push_back(x);
    }
    vec ans=gauss_jordan(A,b);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}