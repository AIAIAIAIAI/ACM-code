#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#include<set>
using namespace std;
typedef long long LL;
#define ms(a, s) memset(a, s, sizeof(a))
const int maxn = 100005;
const int INF = 0x3f3f3f3f;
int pre[maxn];
int ans[maxn];
int main() {
	int T;
	scanf("%d", &T);
	while(T--){
		int n, m;
		scanf("%d%d", &n, &m);
		set<int> st;
		for(int i = 1; i <= n; i++){
			st.insert(i);
			pre[i] = i;		
		}
		for(int i = 0; i < m; i++){
			int l, r;
			scanf("%d%d", &l, &r);
			pre[r] = min(pre[r], l);
		}
		for(int i = n - 1; i >= 1; i--){
			pre[i] = min(pre[i], pre[i + 1]);
		}
		int p = 1;
		for(int i = 1; i <= n; i++){
			while(p < pre[i]){
				st.insert(ans[p]);
				p++;
			}
			ans[i] = *st.begin();
			st.erase(ans[i]);
		}
		for(int i = 1; i < n; i++) printf("%d ",ans[i]);
		printf("%d\n",ans[n]);
	}
	return 0;
}