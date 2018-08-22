#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int cnt;
int n,m;
int s[1005];
bool dfs(int cur)
{
    if(cnt++==n)
    {
        for(int i=0;i<cur;i++)
        {
            if(i&&i%64==0)
                puts("");
            else if(i&&i%4==0)
                putchar(' ');
            printf("%c",'A'+s[i]);
        }
        printf("\n%d\n",cur);
        return true;
    }
    for(int i=0;i<m;i++)
    {
        s[cur]=i;
        int ok=1;
        for(int j=1;j*2<=cur+1;j++)//尝试长度为j*2的后缀
        {
            int equal=1;
            for(int k=0;k<j;k++)//检查前一半是否等于后一半
                if(s[cur-k]!=s[cur-j-k])
                {
                    equal=0;
                    break;
                }
            if(equal)//后一半等于前一半，方案不合法
            {
                ok=0;
                break;
            }
        }
        if(ok&&dfs(cur+1))//递归搜索。如果找到解就直接退出
            return true;
    }
    return false;
}
int main()
{
    while(~scanf("%d%d",&n,&m),n||m)
    {
        cnt=0;
        memset(s,0,sizeof(s));
        dfs(0); 
    }
    return 0;
}