/*大数加法*/ 
# include<stdio.h>
# include<string.h>
# include<malloc.h>

void add(char* a,char* b,char* c)
{
    int i,j,k,max,min,n,temp;
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

/*大数减法*/ 
void subtract(char* a,char* b,char* c)
{
    int i,j,ca,cb;
    ca=strlen(a);
    cb=strlen(b);
    if (ca>cb||(ca==cb&&strcmp(a,b)>=0))
    {
        for (i=ca-1,j=cb-1;j>=0;i--,j--)
            a[i]-=(b[j]-'0');
           for (i=ca-1;i>=0;i--)
               if (a[i]<'0')
               {
                   a[i]+=10;
                   a[i-1]--;
            }
        i=0;
        while (a[i]=='0')
            i++;
           if (a[i]=='\0')
          {
              c[0]='0';
              c[1]='\0';
        }
        else
        {
            for (j=0;a[i]!='\0';i++,j++)
                c[j]=a[i];
               c[j]='\0';
        }
    }
    else
    {
        for (i=ca-1,j=cb-1;i>=0;i--,j--)
            b[j]-=(a[i]-'0');
           for (j=cb-1;j>=0;j--)
               if (b[j]<'0')
               {
                   b[j]+=10;
                   b[j-1]--;
            }
        j=0;
        while (b[j]=='0')
            j++;
           i=1;
           c[0]='-';
           for (;b[j]!='\0';i++,j++)
               c[i]=b[j];
          c[i]='\0';
    }            
}

/* 大数乘法*/ 
void multiply(char* a,char* b,char* c)
{
    int i,j,ca,cb,* s;
    ca=strlen(a);
    cb=strlen(b);
    s=(int*)malloc(sizeof(int)*(ca+cb));
    for (i=0;i<ca+cb;i++)
        s[i]=0;
    for (i=0;i<ca;i++)
        for (j=0;j<cb;j++)
            s[i+j+1]+=(a[i]-'0')*(b[j]-'0');
    for (i=ca+cb-1;i>=0;i--)
        if (s[i]>=10)
        {
            s[i-1]+=s[i]/10;
            s[i]%=10;
        }
    i=0;
    while (s[i]==0)
        i++;
       for (j=0;i<ca+cb;i++,j++)
           c[j]=s[i]+'0';
    c[j]='\0';
    free(s);
}

/*大数除法,返回余数*/
int dividor(char* a,int b,char* c)
{
    int i,j,temp=0,n;
    char* s;
    n=strlen(a);
    s=(char*)malloc(sizeof(char)*(n+1));
    for (i=0;a[i]!=0;i++)
       {
           temp=temp*10+a[i]-'0';
           s[i]=temp/b+'0';
           temp%=b;
    }
    s[i]='\0';
    for (i=0;s[i]=='0'&&s[i]!='\0';i++);
    if (s[i]=='\0')
    {
        c[0]='0';
        c[1]='\0';
    }
    else
    {
        for (j=0;s[i]!='\0';i++,j++)
            c[j]=s[i];
           c[j]='\0';
    }
    free(s);
    return temp;
}