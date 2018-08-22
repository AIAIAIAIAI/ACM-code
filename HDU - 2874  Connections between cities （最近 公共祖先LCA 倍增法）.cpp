#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include <cmath>
using namespace std;
typedef long long LL;
#define ms(a, s) memset(a, s, sizeof(a))
const int maxn = 10005;
const int INF = 0x3f3f3f3f;
struct edge {
	int to, val;
};
vector<edge> G[maxn]; 
int parent[20][maxn];
int depth[maxn];
int dis[maxn];
int root[maxn];
void dfs(int u, int p, int d, int id){
	parent[0][u] = p;
	depth[u] = d;
	root[u] = id;
	for(int i = 0; i < G[u].size(); i++){
		if(G[u][i].to != p) {
			int v = G[u][i].to;
			dis[v] = dis[u] + G[u][i].val;
			dfs(v, u, d + 1, id);
		}
	}
}
void init(int n){
	for(int k = 0; k < 20; k++){
		for(int v = 1; v <= n; v++){
			parent[k + 1][v] = parent[k][parent[k][v]];
		}
	}
}
int lca(int u, int v){
	if(depth[u] > depth[v]) swap(u, v);
	for(int k = 0; k < 20; k++){
		if((depth[v] - depth[u]) >> k & 1) v = parent[k][v];
	}
	if(u == v) return u;
	for(int k = 19; k >= 0; k--){
		if(parent[k][u] != parent[k][v]){
			u = parent[k][u];
			v = parent[k][v];
		}
	}
	return parent[0][u];
}
int main() {
	int n, m, q;
	while(scanf("%d%d%d", &n, &m, &q) != EOF){
		for(int i = 0; i <= n; i++) G[i].clear();
		ms(root, 0);
		ms(dis, 0);
		ms(parent, 0);
		for(int i = 0; i < m; i++){
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			G[u].push_back((edge){v, c});
			G[v].push_back((edge){u, c});
		}
		for(int i = 1; i <= n; i++){
			if(root[i] == 0) dfs(i, -1, 0, i);
		}
		init(n);
		while(q--){
			int u, v;
			scanf("%d%d", &u, &v);
			if(root[u] != root[v]) printf("Not connected\n");
			else printf("%d\n", dis[u] + dis[v] - 2 * dis[lca(u, v)]);
		}
	}
	return 0;
}