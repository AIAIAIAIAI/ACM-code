#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#include<set>
#include<map>
#include<stack>
using namespace std;
typedef long long LL;
#define ms(a, s) memset(a, s, sizeof(a))
const int maxn = 1005;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> P;
int d[maxn];
int n, m;
struct Edge{
	int to, cost;
};
vector<Edge> G[maxn];
void dijkstra(int s){
	priority_queue<P, vector<P>, less<P> > que;
	ms(d, 0);
	d[s] = INF;
	que.push(P(INF, s));
	while(!que.empty()){
		P p = que.top();que.pop();
		int v = p.second;
		if(p.first < d[v]) continue;
		for(int i = 0; i < G[v].size(); i++){
			Edge &e = G[v][i];
			if(min(d[v], e.cost) > d[e.to]){
				d[e.to] = min(d[v], e.cost);
				que.push(P(d[e.to], e.to));
			}
		}
	}
}
int main() {
	int T;
	scanf("%d", &T);
	int cas = 0;
	while(T--){
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++) G[i].clear();
		for(int i = 0; i < m; i++){
			int u, v, cost;
			scanf("%d%d%d", &u, &v, &cost);
			G[u].push_back((Edge){v, cost});
			G[v].push_back((Edge){u, cost});
		}
		dijkstra(1);
		printf("Scenario #%d:\n", ++cas);
		printf("%d\n\n", d[n]);
	}	
	return 0;
}