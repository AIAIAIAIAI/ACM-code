#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
int main()
{
    int a,b;
    while(cin>>a>>b,a||b)
    {
        if(a<b)
            swap(a,b);
        int ta=a,tb=b;
        int num=0;
        while(tb)
        {
            if(ta>2*tb||ta%tb==0)
                break;
            ta-=tb;
            num++;
            swap(ta,tb);
        }
        if(num%2==0)
            cout<<"Stan wins"<<endl;
        else
            cout<<"Ollie wins"<<endl;
    }
    return 0;
}