/*
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
typedef long long LL;
#define ms(a, s) memset(a, s, sizeof(a))
const int maxn = 40005;
const int INF = 0x3f3f3f3f;
int n, m;
int parent[35][maxn];
int depth[maxn];
int dis[maxn];
struct edge{
    int to, c;
};
vector<edge> G[maxn];
void dfs(int v, int p, int d, int cost){
    parent[0][v] = p;
    depth[v] = d;
    dis[v] = cost;
    for(int i = 0; i < G[v].size(); i++){
        if(G[v][i].to != p) dfs(G[v][i].to, v, d + 1, cost + G[v][i].c);
    }
}
int root;
void init(){
    dfs(root, -1, 0, 0);
    for(int k = 0; k < 20; k++){
        for(int v = 1; v <= n; v++){
            if(parent[k][v] < 0) parent[k + 1][v] = -1;
            else parent[k + 1][v] = parent[k][parent[k][v]];
        }
    }
}
int lca(int u, int v){
    if(depth[u] > depth[v]) swap(u, v);
    for(int k = 0; k < 20; k++){
        if((depth[v] - depth[u]) >> k & 1){
            v = parent[k][v];
        }
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
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        int u, v, c;
        scanf("%d%d%d%*c%*c", &u, &v, &c);
        G[u].push_back((edge){v, c});
        G[v].push_back((edge){u, c});
    }
    root = 1;
    init();
    int k; 
    scanf("%d", &k);
    while(k--){
        int u, v;
        scanf("%d%d", &u, &v);
        printf("%d\n",dis[u] + dis[v] - 2 * dis[lca(u, v)]);
    }
    return 0;
}
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
typedef long long LL;
#define ms(a, s) memset(a, s, sizeof(a))
const int maxn = 40005;
const int INF = 0x3f3f3f3f;
int n,m;
struct edge{
    int to, cost;
};
struct query{
    int p, id;
};
vector<edge> G[maxn];
vector<query> Q[maxn>>2];
int par[maxn];
int dis[maxn];
bool vis[maxn], root[maxn];
int ans[maxn];
int find(int x){
    return x == par[x] ? x : par[x] = find(par[x]);
}
void unite(int x, int y){
    x = find(x), y = find(y);
    if(x != y) par[y] = x;
}
void dfs(int u){
    vis[u] = true;
    for(int i = 0; i < G[u].size(); i++){
        edge &e = G[u][i];
        if(vis[e.to]) continue;
        dis[e.to] = dis[u] + e.cost;
        dfs(e.to);
        unite(u, e.to);
    }
    for(int i = 0; i < Q[u].size(); i++){
        query &q = Q[u][i];
        if(!vis[q.p]) continue;
        int lca = find(q.p);
        ans[q.id] = dis[u] + dis[v] - 2 * dis[lca];
    }
}
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i <= n; i++){
        par[i] = i;
    }
    for(int i = 0; i < m; i++){
        int u, v, c;
        scanf("%d%d%d%*c",&u, &v, &c);
        G[u].push_back((edge) {v, c});
        G[v].push_back((edge) {u, c});
    }
    int k;
    scanf("%d", &k);
    for(int i = 0; i < k; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        Q[u].push_back((query) {v, i});
        Q[v].push_back((query) {u, i});
    }
    for(int i = 0; i < k; i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}