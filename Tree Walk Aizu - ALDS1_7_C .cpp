#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1000,NIL=-1;
struct Node
{
    int l,r,p;
}T[maxn];
void preParse(int u)//前序遍历
{
    if(u==NIL)
        return ;
    cout<<" "<<u;
    preParse(T[u].l);
    preParse(T[u].r);
}
void inParse(int u)//中序遍历
{
    if(u==NIL)
        return ;
    inParse(T[u].l);
    cout<<" "<<u;
    inParse(T[u].r);
}
void postParse(int u)//后序遍历
{
    if(u==NIL)
        return ;
    postParse(T[u].l);
    postParse(T[u].r);
    cout<<" "<<u;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        T[i].p=NIL;
    for(int i=0;i<n;i++)
    {
        int v,l,r;
        cin>>v>>l>>r;
        T[v].l=l;
        T[v].r=r;
        if(l!=NIL)
            T[l].p=v;
        if(r!=NIL)
            T[r].p=v;
    }
    int root;
    for(int i=0;i<n;i++)
        if(T[i].p==NIL)
            root=i;
    cout<<"Preorder\n";
    preParse(root);
    cout<<endl;
    cout<<"Inorder\n";
    inParse(root);
    cout<<endl;
    cout<<"Postorder\n";
    postParse(root);
    cout<<endl;
    return 0;
}