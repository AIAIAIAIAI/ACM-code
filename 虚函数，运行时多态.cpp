#include<iostream>

using namespace std;
const float PI=3.1415;
class Graph
{
public:
	virtual float area()=0;
	virtual float volume()=0;
};
class Circle:public Graph
{
protected:
	float x,y,r;
public:
	Circle(float a,float b,float c):x(a),y(b),r(c){}
	float area()
	{
		return PI*r*r;
	}
	float volume()
	{
		return 0;
	}
};
class Cylinder:public Circle
{
private:
	float h;
public:
	Cylinder(float a,float b,float c,float d):Circle(a,b,c),h(d){}
	float area()
	{
		return 2*PI*r*r+2*PI*r*h;
	}
	float volume()
	{
		return area()*h;
	}
};
int main()
{
	Graph *p;
	Circle a(1,2,3);
	Cylinder b(2,3,4,5);
	p=&a;
	cout<<p->area()<<endl;
	p=&b;
	cout<<p->volume()<<endl;
	return 0;
} 