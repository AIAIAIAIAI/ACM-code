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
const int maxn = 105;
const int INF = 0x3f3f3f3f;
int cost[maxn][maxn];
int level[maxn];
int d[maxn];
bool used[maxn];
int n;
void dijkstra(int s) {
	ms(d, INF);
	d[s] = 0;
	while (true) {
		int v = -1;
		for (int u = 0; u <= n; u++) {
			if (!used[u] && (v == -1 || d[u] < d[v])) v = u;
		}
		if (v == -1) break;
		used[v] = true;
		for (int u = 0; u <= n; u++) {
			if(!used[u])
				d[u] = min(d[u], d[v] + cost[v][u]);
		}
	}
}
int main() {
	int m;
	scanf("%d%d", &m, &n);
	ms(cost, INF);
	for (int i = 1; i <= n; i++) {
		int p, t;
		scanf("%d%d%d", &p, &level[i], &t);
		while (t--) {
			int id;
			scanf("%d", &id);
			scanf("%d", &cost[id][i]);
		}
		cost[0][i] = p;	
	}
	int ans = INF;
	for (int i = 1; i <= n; i++) {
		ms(used, 0);
		for (int j = 1; j <= n; j++) {
			if (level[j] < level[i] || level[j] - level[i] > m) {
				used[j] = true;
			}
		}
		dijkstra(0);
		ans = min(ans, d[1]);
	}
	printf("%d\n", ans);
	return 0;
}

