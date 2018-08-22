#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;
typedef long long LL;
#define ms(a, s) memset(a, s, sizeof(a));
const int maxn = 40005;
const int INF = 0x3f3f3f3f;
struct edge {
	int to, cost;
};
vector<edge> G[maxn];
int n;
int root;
int parent[20][maxn];
int depth[maxn];
int dis[maxn];
void dfs(int v, int p, int d, int cos){
	parent[0][v] = p;
	depth[v] = d;
	dis[v] = cos;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i].to != p) dfs(G[v][i].to, v, d + 1, cos + G[v][i].cost);
	}
}
void init(){	
	ms(dis, 0);
	dfs(root, -1, 0, 0);
	for(int k = 0; (1 << k) < n; k++) {
		for(int v = 1; v <= n; v++) {
			if(parent[k][v] < 0) parent[k + 1][v] = -1;
			else parent[k + 1][v] = parent[k][parent[k][v]];
		}
	}
}
int lca(int u, int v) {
	if(depth[u] > depth[v]) swap(u, v);
	for(int k = 0; (1 << k) < n; k++){
		if((depth[v] - depth[u]) >> k & 1) {
			v = parent[k][v];
		}
	}
	if(u == v) return u;
	for(int k = 15; k >= 0; k--) {
		if(parent[k][u] != parent[k][v]) {
			u = parent[k][u];
			v = parent[k][v];
		}
	}
	return parent[0][u];
}
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		for(int i = 0; i <= n; i++) {
			G[i].clear();
		}		
		int m;
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n - 1; i++) {
			int u, v, cost;
			scanf("%d%d%d",&u, &v, &cost);
			G[u].push_back((edge) {v, cost});
			G[v].push_back((edge) {u, cost});
		}
		root = 1;
		init();
		while(m--) {
			int u, v;
			scanf("%d%d", &u, &v);
			int ans = dis[u] + dis[v] - 2 * dis[lca(u, v)];
			printf("%d\n", ans);
		}
	}
	return 0;
}