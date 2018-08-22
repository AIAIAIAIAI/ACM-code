#include<iostream>
#include<cmath>
using namespace std;
#define pi acos(-1)
int main()
{
	double n,m;
	while(cin>>n>>m)
	{
		double a[3][2];
		for(int i=0;i<3;i++)
			cin>>a[i][0]>>a[i][1];
		double b[3];
		for(int i=0;i<3;i++)
			b[i]=sqrt((a[i][0]-a[(i+1)%3][0])*(a[i][0]-a[(i+1)%3][0])+(a[i][1]-a[(i+1)%3][1])*(a[i][1]-a[(i+1)%3][1]));
		double r,p=(b[0]+b[1]+b[2])/2;
		double s=sqrt(p*(p-b[0])*(p-b[1])*(p-b[2]));
		r=b[0]*b[1]*b[2]/s/4;
		if(pi*r*r-s<n||pi*r*r-s>m)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
	return 0;
}