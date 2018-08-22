#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;
typedef long long LL;
#define ms(a, s) memset(a, s, sizeof(a));
const int maxn = 505;
const int INF = 0x3f3f3f3f;
int dp[10005];
int w[maxn],v[maxn];
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int p, c;
        scanf("%d%d\n", &p, &c);
        c -= p;
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &v[i], &w[i]);
        }
        ms(dp, INF);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = w[i]; j <= c; j++) {
                dp[j] = min(dp[j], dp[j - w[i]] + v[i]);
            }
        }
        if (dp[c] == INF) {
            printf("This is impossible.\n");
        } else {
            printf("The minimum amount of money in the piggy-bank is %d.\n", dp[c]);
        }
    }
    return 0;
}
