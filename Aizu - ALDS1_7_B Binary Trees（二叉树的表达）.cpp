#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=100;
const int NIL=-1;
struct Node
{
    int par,left,right;
};
Node T[maxn];
int D[maxn],H[maxn];
void setDepth(int u,int d)
{
    if(u==NIL)
        return ;
    D[u]=d;
    setDepth(T[u].left,d+1);
    setDepth(T[u].right,d+1);
}
int setHeight(int u)
{
    int h1=0,h2=0;
    if(T[u].left!=NIL)
        h1=setHeight(T[u].left)+1;
    if(T[u].right!=NIL)
        h2=setHeight(T[u].right)+1;
    return H[u]=h1>h2?h1:h2;
}
int getSibling(int u)
{
    if(T[u].par==NIL)
        return NIL;
    if(T[T[u].par].left!=u&&T[T[u].par].left!=NIL)
        return T[T[u].par].left;
    if(T[T[u].par].right!=u&&T[T[u].par].right!=NIL)
        return T[T[u].par].right;
    return NIL;
}
void print(int u)
{
    cout<<"node "<<u<<": ";
    cout<<"parent = "<<T[u].par<<", ";
    cout<< "sibling = " <<getSibling(u)<<", ";
    int deg=0;
    if(T[u].left!=NIL)
        deg++;
    if(T[u].right!=NIL)
        deg++;
    cout<<"degree = "<<deg<<", ";
    cout<<"depth = "<<D[u]<<", ";
    cout<<"height = "<<H[u]<<", ";
    if(T[u].par==NIL)
        cout<<"root"<<endl;
    else if(T[u].left==NIL&&T[u].right==NIL)
        cout<<"leaf"<<endl;
    else
        cout<<"internal node"<<endl;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        T[i].par=NIL;
    for(int i=0;i<n;i++)
    {
        int v,l,r;
        cin>>v>>l>>r;
        T[v].left=l;
        T[v].right=r;
        if(l!=NIL)
            T[l].par=v;
        if(r!=NIL)
            T[r].par=v;
    }  
    int root=0;
    for(int i=0;i<n;i++)
        if(T[i].par==NIL)
            root=i;  
    setDepth(root,0);
    setHeight(root);
    for(int i=0;i<n;i++)
        print(i);
    return 0;
}