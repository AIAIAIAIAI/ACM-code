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
const int maxn = 1005;
const int INF = 0x3f3f3f3f;
int sum[maxn][maxn];
int dp[maxn][maxn];
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int x;
				scanf("%d", &x);
				sum[i][j] = sum[i][j - 1] + x;
			}
		}
		ms(dp, 0);
		int ans = -INF;
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				int tmp = 0;
				for (int k = 1; k <= n; k++) {
					tmp += sum[k][j] - sum[k][i - 1];
					dp[i][j] = max(dp[i][j], tmp);
					if (tmp < 0) tmp = 0;
					ans = max(ans, dp[i][j]);
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}