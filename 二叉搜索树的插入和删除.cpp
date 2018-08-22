#include<iostream>
#include<cstdio>
using namespace std;
struct node
{
	int val;
	node *lson,*rson;
};
node *insert(node *p,int x)
{
	if(p==NULL)
	{
		node *q=new node;
		q->val=x;
		q->lson=q->rson=NULL;
		return q;
	}
	else
	{
		if(x<p->val)
			p->lson=insert(p->lson,x);
		else
			p->rson=insert(p->rson,x);
		return p;
	}
}
bool find(node *p,int x)
{
	if(p==NULL)
		return false;
	else if(x<p->val)
		return find(p->lson,x);
	else if(x>p->val)
		return find(p->rson,x);
	else
		return true;
}
node *remove(node *p,int x)
{
	if(p==NULL)
		return NULL;
	else if(x<p->val)
		p->lson=remove(p->lson,x);
	else if(x>p->val)
		p->rson=remove(p->rson,x);
	else if(p->lson==NULL)
	{
		node *q=p->rson;
		delete p;
		return q;
	}
	else if(p->lson->rson==NULL)
	{
		node *q=p->lson;
		q->rson=p->rson;
		delete p;
		return q;
	}
	else
	{
		node *q;
		for(q=p->lson;q->rson->rson!=NULL;q=q->rson);
		node *r=q->rson;
		q->rson=r->rson;//NULL
		r->lson=p->lson;
		r->rson=p->rson;
		delete p;
		return r;
	}
	return p;
}
int main()
{
	node *root=NULL;
	return 0;
}