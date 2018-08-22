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
const int maxn = 100005;
const int INF = 0x3f3f3f3f;
struct Edge{
	int to, next, cost, id;
}edge[2 * maxn];
int cnt;
int n, q, s;
int head[maxn];
int id[maxn];//各顶点在DFS序中首次出现的下标
int vs[2 * maxn];//DFS的顺序
int depth[2 * maxn];//节点的深度
int dp[2 * maxn][32];//RMQ ST表
int bit[2 * maxn];//树状数组
int es[2 * maxn];//边的下标，(i*2 +(叶子方向：0，根方向：1))
int val[maxn];//边的权值
inline void add_edge(int u, int v, int w, int id){
	edge[cnt].cost = w;
	edge[cnt].id = id;
	edge[cnt].to = v;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}
inline int lowbit(int x){
	return x & -x;
}
inline int sum(int i){
	int s = 0;
	while(i > 0){
		s += bit[i];
		i -= lowbit(i);
	}
	return s;
}
inline void add(int i, int x){
	while(i <= 2 * n - 1){
		bit[i] += x;
		i += lowbit(i);
	}
}
void dfs(int v, int p, int d, int &k){
	id[v] = k;
	vs[k] = v;
	depth[k++] = d;
	for(int i = head[v]; ~i; i = edge[i].next){
		Edge &e = edge[i];
		if(e.to != p){
			add(k, e.cost);
			es[e.id * 2] = k;
			dfs(e.to , v, d + 1, k);
			vs[k] = v;
			depth[k++] = d;
			add(k, -e.cost);
			es[e.id * 2 + 1] = k;
		}
	}
}
//返回深度小的点的下标
inline int depth_min(int x, int y){
	return depth[x] < depth[y] ? x : y;
}
void rmq_init(int num){
	for(int i = 1; i <= num; i++) dp[i][0] = i;
	int k = log((num + 1) * 1.0)/log(2.0);
	for(int j = 1; j <= k; j++){
		for(int i = 1; i + (1 << j) - 1 <= num; i++){
			dp[i][j] = depth_min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
		}
	}
}
inline int rmq_query(int l, int r){
	int k = log((r - l + 1) * 1.0)/log(2.0);
	return depth_min(dp[l][k], dp[r - (1 << k) + 1][k]);
}
void init(){
	int k = 0;
	dfs(1, -1, 0, k);
	rmq_init(k);
}
inline int lca(int u, int v){
	if(id[u] > id[v]) swap(u, v);
	return vs[rmq_query(id[u], id[v])];
}
int main() {
	ms(head, -1);
	scanf("%d%d%d", &n, &q, &s);
	for(int i = 1; i < n ; i++){
		int a, b;
		scanf("%d%d%d", &a, &b, &val[i]);
		add_edge(a, b, val[i], i);
		add_edge(b, a, val[i], i);
	}
	init();
	for(int i = 0; i < q; i++){
		int op, v;
		scanf("%d", &op);
		if(op == 0){
			scanf("%d", &v);
			int p = lca(s, v);
			printf("%d\n",sum(id[v]) + sum(id[s]) - 2 * sum(id[p]));
			s = v;
		}else{
			int w;
			scanf("%d%d", &v, &w);
			add(es[v * 2], w - val[v]);
			add(es[v * 2 + 1], val[v] - w);
			val[v] = w;
		}
	}
	return 0;
}