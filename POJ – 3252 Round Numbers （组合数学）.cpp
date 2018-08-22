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
int c[33][33];
void cal() {
    for (int i = 0; i <= 32; i++) {
        for (int j = 0; j <= i; j++) {
            if (i == j || j == 0) {
				c[i][j] = 1;                
            } else {
            	c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            }
        }
    }
}
int bit[33];
int solve(int n) {
	int len = 0;
	while (n != 0) {
		bit[++len] = n & 1;
		n >>= 1;
	}
	int ans = 0;
	for (int i = 1; i < len; i++) {
		//i为当前数的位数
		for (int j = (i + 1) / 2; j < i; j++) {
			//j是0的个数
			ans += c[i - 1][j];
		}
	}
	int zero = 0;
	for (int i = len - 1; i > 0; i--) {
		if(bit[i] == 1) {
			for (int j =(len + 1) / 2 - (zero + 1); j < i; j++) {
				//j为需要在后面添加的0的个数。
				ans += c[i - 1][j];
			}
		} else {
			zero++;
		}
	}
	return ans;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	cal();
	printf("%d\n", solve(m + 1) - solve(n));
	return 0;
}