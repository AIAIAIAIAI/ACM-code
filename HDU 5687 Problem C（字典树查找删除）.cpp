#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int tot,n;
const int maxn=3e6+5;
struct node
{
	int next[27];
	int cnt;
	void init()
	{
		cnt=0;//记录着字典树中每层以当前字符串为前缀的字符串的数目
		memset(next,-1,sizeof(next));
	}
}trie[maxn]; 
void insert(string s)
{
	int cur=0;
	for(int i=0;i<s.length();i++)
	{
		int temp=s[i]-'a';
		int next=trie[cur].next[temp];
		if(next==-1)
		{
			next=++tot;
			trie[next].init();
			trie[cur].next[temp]=next;
		}
		cur=next;
		trie[cur].cnt++;
	}
}
bool find(string s)
{
	int cur=0;
	for(int i=0;i<s.length();i++)
	{
		int tmp=s[i]-'a';
		int next=trie[cur].next[tmp];
		if(next==-1)
			return false;
		cur=next;
	}
	return trie[cur].cnt>0;//该字符串为前缀的数目>0
}
void del(string s)
{
	int cur=0;
	for(int i=0;i<s.length();i++)//删除前，首先判断是否存在该字符串
	{
		int tmp=s[i]-'a';
		int next=trie[cur].next[tmp];
		if(next==-1)
			return ;
		cur=next;
	}
	int tail;
	cur=0;
	for(int i=0;i<s.length();i++)//删除时不清空结点信息 
	{
		int tmp=s[i]-'a';
		int next=trie[cur].next[tmp];
		tail=cur;
		cur=next;
		trie[cur].cnt--;//字符串为前缀的数目减一
	}
	trie[cur].init();
	trie[tail].next[s[s.length()-1]-'a']=-1;
}
int main()
{
	cin>>n;
	string op,s;
	trie[0].init();
	while(n--)
	{
		cin>>op>>s;
		if(op=="insert")
			insert(s);
		else if(op=="search")
			if(find(s))
				cout<<"Yes"<<endl;
			else
				cout<<"No"<<endl;
		else
			del(s);
	}
	return 0;
}