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
const int maxn = 10005;
const int INF = 0x3f3f3f3f;
struct Node {
	int t, x, y;
	friend bool operator < (const Node &A, const Node &B) {
		return A.t < B.t;
	}
};
Node a[maxn];
int dp[maxn];
int main() {
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF) {
		if (n == 0 && m == 0) break;
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d", &a[i].t, &a[i].x, &a[i].y);
		}
		ms(dp, 0);
		sort(a, a + m);
		int ans = 0;
		for (int i = 0; i < m; i++) {
			dp[i] = 1;
			for (int j = 0; j < i; j++) {
				if(a[i].t - a[j].t >= abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y)) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			ans = max(ans, dp[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}