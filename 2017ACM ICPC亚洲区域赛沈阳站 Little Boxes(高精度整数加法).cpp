/*大数加法*/ 
# include<cstdio>
# include<cstring>
# include<cstdlib>
#include<iostream>
using namespace std;
void add(char* a,char* b,char* c)
{
    int i,j,k,max,min,temp;
    char *s,*pmax,*pmin;
    max=strlen(a);
    min=strlen(b);
    if (max<min)
    {
        temp=max;
        max=min;
        min=temp;
        pmax=b;
        pmin=a;
    }
    else
    {
        pmax=a;
        pmin=b;
    }
    s=(char*)malloc(sizeof(char)*(max+1));
    s[0]='0';
    for (i=min-1,j=max-1,k=max;i>=0;i--,j--,k--)
        s[k]=pmin[i]-'0'+pmax[j];
       for (;j>=0;j--,k--)
           s[k]=pmax[j];
    for (i=max;i>=0;i--)
        if (s[i]>'9')
        {
            s[i]-=10;
            s[i-1]++;
        }
    if (s[0]=='0')
    {
        for (i=0;i<=max;i++)
            c[i-1]=s[i];
           c[i-1]='\0';
    }
    else
    {
        for (i=0;i<=max;i++)
            c[i]=s[i];
           c[i]='\0';
    }
    free(s);
}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        char a[100],b[100],c[100],d[100],ans[100];
        cin>>a>>b>>c>>d;
        add(a,b,ans);
        add(ans,c,ans);
        add(ans,d,ans);
        cout<<ans<<endl;
    }
    return 0;
}