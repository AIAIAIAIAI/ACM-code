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
const int maxn = 1e5 + 5;
const int INF = 0x3f3f3f3f;
int head[maxn];
bool vis[maxn << 2];
int cnt;
struct Edge{
	int to, next, color;
}edge[maxn << 2];
struct Node{
	int u, step;
};
int n, m;
queue<Node> que;
void add_edge(int u, int v, int c){
	edge[cnt].to = v;
	edge[cnt].color = c;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}
void init(){
	ms(head, -1);
	ms(vis, 0);
	cnt = 0;
}
void dfs(int u, int c, int d){
	que.push((Node){u, d});
	for(int i = head[u]; ~i; i = edge[i].next){
		if(vis[i] || edge[i].color != c) continue;
		vis[i] = vis[i ^ 1] = true;
		dfs(edge[i].to, c, d);
	}
}
int bfs(int u){
	while(!que.empty()) que.pop();
	que.push((Node){u, 0});
	while(!que.empty()){
		Node now = que.front();que.pop();
		if(now.u == n) return now.step;
		for(int i = head[now.u]; ~i; i = edge[i].next){
			if(vis[i]) continue;
			vis[i] = vis[i ^ 1] = true;
			dfs(edge[i].to, edge[i].color, now.step + 1);
		}
	}
	return -1;
}
int main() {
	while(scanf("%d%d", &n, &m) != EOF){
		init();
		for(int i = 0; i < m; i++){
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			add_edge(u, v, c);
			add_edge(v, u, c);
		}
		printf("%d\n", bfs(1));
	}
	return 0;
}