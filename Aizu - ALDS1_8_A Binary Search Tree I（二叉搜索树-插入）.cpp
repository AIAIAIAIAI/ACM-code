#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
struct Node
{
    int key;
    Node *right, *left, *parent;
};
Node *root;
void insert(int k)
{
    Node *y = NULL;
    Node *x = root;//
    Node *z;
    z = (Node *)malloc(sizeof(Node));
    z->key = k;
    z->left = NULL;
    z->right = NULL;
    while (x)
    {
        y = x;//设置父结点
        if (z->key<x -> key)
            x = x->left;//移动至左结点
        else
            x = x->right;//移动至右结点
    }
    z->parent = y;
    if (y == NULL)//树为空树时
        root = z;
    else
        if (z->key<y->key)
            y->left = z;//将z定为y的左子结点
        else
            y->right = z;//将z定为y的右子结点
}
void inorder(Node *u)//中序遍历
{
    if (u == NULL)
        return;
    inorder(u->left);
    cout << " " << u->key;
    inorder(u->right);
}
void preorder(Node *u)//前序遍历
{
    if (u == NULL)
        return;
    cout << " " << u->key;
    preorder(u->left);
    preorder(u->right);
}
int main()
{
    int n;
    cin >> n;
    string com;
    for (int i = 0; i<n; i++)
    {
        cin >> com;
        if (com == "insert")
        {
            int x;
            cin >> x;
            insert(x);
        }
        else if (com == "print")
        {
            inorder(root);
            cout << endl;
            preorder(root);
            cout << endl;
        }
    }
    return 0;
}