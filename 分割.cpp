#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1e5+5;
int a[maxn],n;
int partition(int p,int r)
{
    int x=a[r];
    int i=p-1;
    for(int j=p;j<r;j++)
        if(a[j]<=x)
            swap(a[++i],a[j]);
    swap(a[i+1],a[r]);
    return i+1;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int q=partition(0,n-1);
    for(int i=0;i<n;i++)
    {
        if(i)
            cout<<" ";
        if(i==q)
            cout<<'[';
        cout<<a[i];
        if(i==q)
            cout<<']';
    }
    cout<<endl;
    return 0;

}