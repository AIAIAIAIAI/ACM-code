/**************
链接：https://www.nowcoder.com/acm/contest/35/D
来源：牛客网

wyf非常喜欢树。一棵有根数树上有N个节点，1号点是他的根，每条边都有一个距离，而wyf是个爱问奇怪问题的熊孩子，
他想知道对于某个点x,以x为根的子树上，所有与x距离大于等于k的点与x的距离之和。

输入描述:
第一行一个正整数N

接下来N-1描述这棵树，每行两个数第i行两个数p和D表示树上有一条p到i+1长度为D的边。(p<=i)

下面一行一个正整数Q表示wyf的询问次数。

接下来Q行每行两个正整数x和k。 (1<=N,Q<=2x105,1<=D,K<=106)

输出描述:
对于每次询问x,k输出以x为根的子树上，所有与x距离大于等于k的点与x的距离之和。(若不存在这样的点，则输出应为0)
输入：
3
1 2
1 3
2
1 3
1 2
输出：

3
5
**************/
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
const int maxn = 200005;
const int INF = 0x3f3f3f3f;
#define lson rt << 1, l, m
#define rson rt << 1 | 1, m + 1, r
struct Edge{
	int to, next, cost;
}edge[maxn << 1];
LL a[maxn << 1];//对应的线段的前缀和
LL d[maxn];
int in[maxn], out[maxn];
int head[maxn];
int cnt, dfs_clk;
void add(int u, int v, int cost){
	edge[cnt].to = v;
	edge[cnt].next = head[u];
	edge[cnt].cost = cost;
	head[u] = cnt++;
}
struct Node{
	LL sum, minn, maxx;
}seg[maxn << 2];
void dfs(int u, int par){
	in[u] = ++dfs_clk;
	for(int i = head[u]; ~i; i = edge[i].next){
		int v = edge[i].to;
		if(v == par) continue;
		d[v] = d[u] + edge[i].cost;
		dfs(v, u);
	}
	out[u] = dfs_clk;
}
void push_up(int rt){
	seg[rt].maxx = max(seg[rt << 1].maxx, seg[rt << 1 | 1].maxx);
	seg[rt].minn = min(seg[rt << 1].minn, seg[rt << 1 | 1].minn);
	seg[rt].sum = seg[rt << 1].sum + seg[rt << 1 | 1].sum;
}
void build(int rt, int l, int r){
	if(l == r){
		seg[rt].maxx = seg[rt].minn = seg[rt].sum = a[l];
		return ;
	}
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
	push_up(rt);
}
int x, k;
LL query(int L, int R, int rt, int l, int r){
	if(L <= l && R >= r){
		if(seg[rt].minn >= d[x] + k) return seg[rt].sum - (r - l + 1) * d[x];
		if(seg[rt].maxx < d[x] + k) return 0;
	}
	int m = (l + r) >> 1;
	LL ans = 0;
	if(L <= m) ans += query(L, R, lson);
	if(R > m) ans += query(L, R, rson);
	return ans; 
}
int main() {
	ms(head, -1);
	int n;
	scanf("%d", &n);
	for(int i = 2; i <= n; i++){
		int u, c;
		scanf("%d%d", &u, &c);
		add(u, i, c);
		add(i, u, c);
	}
	dfs(1, -1);
	for(int i = 1; i <= n; i++) a[in[i]] = d[i];
	build(1, 1, n);
	int q;
	scanf("%d", &q);
	while(q--){
		scanf("%d%d", &x, &k);
		printf("%lld\n", query(in[x], out[x], 1, 1, n));
	}
	return 0;
}