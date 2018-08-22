#include<iostream>
#include<string>
#include<set>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		string s;
		set<string> st;
		while(n--)
		{
			cin>>s;
			for(int i=s.length();i>=0;i--)
			{
				if(s[i]=='u')
					s.replace(i,1,"oo");
				else if(s[i]=='k'&&s[i+1]=='h')
					s.replace(i,2,"h");
			}
			st.insert(s);
		}
		cout<<st.size()<<endl;
	}
	return 0;
}