#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#include<set>
#include<map>
using namespace std;
typedef long long LL;
#define ms(a, s) memset(a, s, sizeof(a))
const int maxn = 100005;
const int INF = 0x3f3f3f3f;
struct Edge{
	int to, next;
}edge[maxn << 2];
int head[maxn], dfn[maxn], low[maxn];
int par[maxn];
int bridge[maxn];
int cnt, index;
int ans;
int n, m;
void add_edge(int u, int v){
	edge[cnt].to = v;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}
void tarjan(int u,int p){
	dfn[u] = low[u] = ++index;
	for(int i = head[u]; ~i; i = edge[i].next){
		int v = edge[i].to;
		if(i == (p ^ 1)) continue;
		if(!dfn[v]){
			par[v] = u;
			tarjan(v, i);
			low[u] = min(low[u], low[v]);
			if(low[v] > dfn[u]){
				ans++;
				bridge[v] = true;
			}
		}else{
			low[u] = min(low[u], dfn[v]);
		}
	}
}
int lca(int u, int v){
	if(dfn[u] > dfn[v]) swap(u, v);
	while(dfn[v] > dfn[u]){
		if(bridge[v]){
			ans--;
			bridge[v] = false;
		}
		v = par[v];
	}
	while(u != v){
		if(bridge[u]){
			ans--;
			bridge[u] = false;
		}
		u = par[u];
	}
	return ans;
}
void init(int n){
	ms(head, -1);
	ms(dfn, 0);
	ms(bridge, 0);
	cnt = ans = index = 0;
}
int main() {
	int cas = 0;
	while(scanf("%d%d", &n, &m) != EOF){
		if(!n && !m) break;
		init(n);
		for(int i = 0; i < m; i++){
			int u, v;
			scanf("%d%d", &u, &v);
			add_edge(u, v);
			add_edge(v, u);
		}
		for(int i = 1; i <= n; i++){
			if(!dfn[i]) tarjan(i, -1);
		}
		printf("Case %d:\n", ++cas);
		int q;
		scanf("%d", &q);
		while(q--){
			int u, v;
			scanf("%d%d", &u, &v);
			printf("%d\n", lca(u, v));
		}
		puts("");
	}
	return 0;
}