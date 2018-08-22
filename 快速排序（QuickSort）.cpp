#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1e5+5;
int partition(int a[],int p,int r)
{
    int x=a[r];
    int i=p-1;
    for(int j=p;j<r;j++)
        if(a[j]<=x)
            swap(a[++i],a[j]);
    swap(a[i+1],a[r]);
    return i+1;
}
void quickSort(int a[],int p,int r)
{
    if(p<r)
    {
        int q=partition(a,p,r);
        quickSort(a,p,q-1);
        quickSort(a,q+1,r);
    }
}
int main()
{
    int n;
    cin>>n;
    int a[maxn];
    for(int i=0;i<n;i++)
        cin>>a[i];
    quickSort(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        if(i)
            cout<<" ";
        cout<<a[i];
    }
    cout<<endl;
    return 0;
}
