#include<iostream>
#include<algorithm>
using namespace std;
/********************************/
const int N=11;
int d[N];//d[N]�д洢����0~9�ֱ���ֵĴ���
int value;//��¼��Ӧ��Ȩֵ�仯
void deal(int n)
{
	if(n<=0)
		return ;
	int one,ten;//one,ten�ֱ��ʾ��λ��ʮλ
	one=n%10;
	n/=10;
	ten=n;
	for(int i=0;i<=one;i++)//����λ�ϳ��ֵ���ͳ������
		d[i]+=value;
	while(ten)
	{
		d[ten%10]+=(one+1)*value;
		ten/=10;
	}
	for(int i=0;i<10;i++)
		d[i]+=value*n;
	d[0]-=value;//����һλ��0������ų�
	value*=10;//Ȩֵ��Ϊԭ����10��
	deal(n-1);
}
int main()
{
	int a,b;
	while(cin>>a>>b,a||b)
	{
		if(a<b)//��֤a>=b
			swap(a,b);
		for(int i=0;i<10;i++)//��ʼ��
			d[i]=0;
		value=1;
		deal(a);
		value=-1;//ȨֵΪ-1����Ϊ���� -deal(b-1)
		deal(b-1);
		cout<<d[1]<<endl;
	}
	return 0;
}