#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
#define ms(a, s) memset(a, s, sizeof(a));
const int maxn = 1005;
int n, m;
vector<int> G[maxn];
int match[maxn];//对应匹配点的标号
bool used[maxn];//DFS中的访问标记
inline void add_edge(int u, int v){//向图中增加一条连接u和v的边
	G[u].push_back(v);
	G[v].push_back(u);
}
void init(){
	for(int i = 0; i < maxn; i++){
		G[i].clear();
	}
}
bool dfs(int v){
	used[v] = true;
	for(auto u : G[v]){
		int w = match[u];
		if(w == -1 || !used[w] && dfs(w)){//未匹配点
			match[v] = u;
			match[u] = v;
			return true;//如果是未匹配点，说明交替路为增广路，则交换路径，并返回true
		}
	}
	return false;
}
int bipartite_matching(){//二分图的最大匹配数
	int res = 0;
	ms(match, -1);
	for(int i = 1; i <= n + m; i++){
		if(match[i] == -1){
			ms(used, false);
			if(dfs(i)) res++;
		}
	}
	return res;
}
int main(){
	int k;
	while(~scanf("%d", &k) && k){
		init();
		scanf("%d%d", &n, &m);
		for(int i = 0; i < k; i++){
			int u, v;
			scanf("%d%d", &u, &v);
			add_edge(u, v + n);
		}
		printf("%d\n", bipartite_matching());
	}
	return 0;
}