#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#include<set>
#include<map>
using namespace std;
typedef long long LL;
#define ms(a, s) memset(a, s, sizeof(a))
const int maxn = 1000005;
const int INF = 0x3f3f3f3f;
int a[maxn];
int main() {
	int p;
	scanf("%d", &p);
	set<int> all;
	for(int i = 0; i < p; i++){
		scanf("%d", &a[i]);
		all.insert(a[i]);
	}
	int n = all.size();
	map<int, int> count;
	int ans = p;
	int s = 0, t = 0, num = 0;
	for(;;){
		while(t < p && num < n){
			if(count[a[t++]]++ == 0) num++;
		}
		if(num < n) break;
		ans = min(ans, t - s);
		if(--count[a[s++]] == 0) num--;
	}
	printf("%d\n", ans);
	return 0;
}