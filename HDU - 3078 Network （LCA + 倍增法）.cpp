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
const int maxn = 80005;
const int INF = 0x3f3f3f3f;
int cost[maxn];
int par[30][maxn];
int depth[maxn];
vector<int> G[maxn];
int n;
void dfs(int v, int p, int d){
	par[0][v] = p;
	depth[v] = d;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] != p) dfs(G[v][i], v, d + 1);
	}
}
void init(){
	dfs(1, -1, 0);
	for(int k = 0; k + 1 < 20; k++){
		for(int v = 1; v <= n; v++){
			if(par[k][v] < 0) par[k + 1][v] = -1;
			else par[k + 1][v] = par[k][par[k][v]];
		}
	}
}
int lca(int u, int v){
	if(depth[u] > depth[v]) swap(u, v);
	for(int k = 0; k < 20; k++){
		if((depth[v] - depth[u]) >> k & 1) v = par[k][v];
	}
	if(u == v) return u;
	for(int k = 19; k >= 0; k--){
		if(par[k][u] != par[k][v]){
			u = par[k][u];
			v = par[k][v];
		}
	}
	return par[0][u];
}
int main() {
	int q;
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++){
		scanf("%d", &cost[i]);
	}
	for(int i = 0; i < n - 1; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	init();
	while(q--){
		int k, u, v;
		scanf("%d%d%d", &k, &u, &v);
		if(k == 0){
			cost[u] = v;
		} else{
			int ans = lca(u, v);
			vector<int> path;
			path.push_back(cost[ans]);
			while(u != ans){
				path.push_back(cost[u]);
				u = par[0][u];
			}
			while(v != ans){
				path.push_back(cost[v]);
				v = par[0][v];
			}
			if(path.size() < k){
				printf("invalid request!\n");
			} else{
				sort(path.begin(), path.end(),greater<int>());
				printf("%d\n", path[k - 1]);
			}
		}
	}
	return 0;
}