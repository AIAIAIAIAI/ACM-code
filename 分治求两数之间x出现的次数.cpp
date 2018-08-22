#include<iostream>
#include<algorithm>
using namespace std;
/********************************/
const int N=11;
int d[N];//d[N]中存储数字0~9分别出现的次数
int value;//记录相应的权值变化
void deal(int n)
{
	if(n<=0)
		return ;
	int one,ten;//one,ten分别表示个位和十位
	one=n%10;
	n/=10;
	ten=n;
	for(int i=0;i<=one;i++)//将个位上出现的数统计下来
		d[i]+=value;
	while(ten)
	{
		d[ten%10]+=(one+1)*value;
		ten/=10;
	}
	for(int i=0;i<10;i++)
		d[i]+=value*n;
	d[0]-=value;//将第一位是0的情况排除
	value*=10;//权值变为原来的10倍
	deal(n-1);
}
int main()
{
	int a,b;
	while(cin>>a>>b,a||b)
	{
		if(a<b)//保证a>=b
			swap(a,b);
		for(int i=0;i<10;i++)//初始化
			d[i]=0;
		value=1;
		deal(a);
		value=-1;//权值为-1，是为了求 -deal(b-1)
		deal(b-1);
		cout<<d[1]<<endl;
	}
	return 0;
}