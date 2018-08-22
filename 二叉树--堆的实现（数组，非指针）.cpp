#include<iostream>
using namespace std;
const int maxn=1e5+5;
int heap[maxn],sz;
void push(int x)
{
	int i=sz++;//自己节点的编号
	while(i>0)
	{
		int p=(i-1)/2;//父亲节点的编号
		if(heap[p]<=x)//如果已经没有大小颠倒则退出
			break;
		heap[i]=heap[p];//把父亲节点的数值放下来，把自己提上去
		i=p;
	}
	heap[i]=x;
}
int pop()
{
	int ret=heap[0];//根节点即最小值
	int x=heap[--sz];//要提到根的数值
	int i=0;//从根开始向下交换
	while(i*2+1<sz)
	{
		int lson=i*2+1,rson=i*2+2;
		if(rson<sz&&heap[rson]<heap[lson])//比较儿子的值
			lson=rson;
		if(heap[lson]>=x)//已经没有大小颠倒则退出
			break;
		heap[i]=heap[lson];//把儿子的数值提上来
		i=lson;
	}
	heap[i]=x;
	return ret;
}
int main()
{
	int a[11]={3,0,7,9,1,2,5,8,6,10,4};
	for(int i=0;i<11;i++)
		push(a[i]);
	for(int i=0;i<11;i++)
		cout<<heap[i]<<' ';
	for(int i=0;i<11;i++)
		cout<<pop()<<endl;
	return 0;
}