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
const int maxn = 100005;
const int INF = 0x3f3f3f3f;
#define lson rt << 1, l, m
#define rson rt << 1 | 1, m + 1, r
struct Node{
	int val, minn, add;
	LL sum;
}seg[maxn << 2];
void push_up(int rt){
	seg[rt].minn = min(seg[rt << 1].minn, seg[rt << 1 | 1].minn);
	seg[rt].sum = seg[rt << 1].sum + seg[rt << 1 | 1].sum;
}
void push_down(int rt){
	if(seg[rt].add){
		seg[rt << 1].add += seg[rt].add;
		seg[rt << 1 | 1].add += seg[rt].add;
		seg[rt << 1].minn -= seg[rt].add;
		seg[rt << 1 | 1].minn -= seg[rt].add;
		seg[rt].add = 0;
	}
}
void build(int rt, int l, int r){
	seg[rt].add = seg[rt].sum = 0;
	if(l == r){
		scanf("%d", &seg[rt].val);
		seg[rt].minn = seg[rt].val;
		return ;
	}
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
	push_up(rt);
}
void updata(int L, int R, int rt, int l, int r){
	if(L <= l && R >= r && seg[rt].minn > 1){
		seg[rt].add++;
		seg[rt].minn--;
		return ;
	}
	if(l == r && seg[rt].minn == 1){
		seg[rt].sum++;
		seg[rt].minn = seg[rt].val;
		return ;
	}
	push_down(rt);
	int m = (l + r) >> 1;
	if(L <= m) updata(L, R, lson);
	if(R > m) updata(L, R, rson);
	push_up(rt);
}
LL query(int L, int R, int rt, int l, int r){
	if(L <= l && R >= r) return seg[rt].sum;
	int m = (l + r) >> 1;
	push_down(rt);
	LL ans = 0;
	if(L <= m) ans += query(L, R, lson);
	if(R > m) ans += query(L, R, rson);
	return ans;
}
int main(){
	int n, q;
	while(scanf("%d%d", &n, &q) != EOF){
		build(1, 1, n);
		while(q--){
			char s[10];
			scanf("%s", s);
			int a, b;
			scanf("%d%d", &a, &b);
			if(s[0] == 'a') updata(a, b, 1, 1, n);
			else printf("%lld\n", query(a, b, 1, 1, n));
		}
	}
	return 0;
}