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
const int maxn = 305;
const int INF = 0x3f3f3f3f;
int cost[maxn][maxn];
typedef pair<int, int> P;
int d[maxn];
int n;
void dijkstra(int s){
    priority_queue<P, vector<P>, greater<P> > que;
    ms(d, INF);
    d[s] = 0;
    que.push(P(0, s));
    while(!que.empty()){
        P p = que.top();que.pop();
        int v = p.second;
        if(d[v] < p.first) continue;
        for(int i = 1; i <= n; i++){
            //if(i == 1 && v == 1) continue;
            //if( i == n && v == n) continue;
            if(d[i] > d[v] + cost[v][i]){
                d[i] = d[v] + cost[v][i];
                que.push(P(d[i], i));
            }
        }
    }
}
int main(){
    while(~scanf("%d", &n)){
        ms(cost, INF);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++) scanf("%d", &cost[i][j]);
        }
        dijkstra(1);
        int ans = d[n];
        int res1 = INF;
        for(int i = 2; i <= n; i++){
            res1 = min(res1, d[i] + cost[i][1]);
        }
        int res2 = INF;
        dijkstra(n);
        for(int i = 1; i < n; i++){
            res2 = min(res2, d[i] + cost[i][n]);
        }
        printf("%d\n", min(ans, res1 + res2));
    }
    return 0;
}
