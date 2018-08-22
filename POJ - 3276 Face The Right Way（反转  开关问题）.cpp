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
const int maxn = 5005;
const int INF = 0x3f3f3f3f;
int dir[maxn];
int f[maxn];//区间[i, i+k]进行了反转为1，否则为0
int n;
int cal(int k){
	memset(f, 0, sizeof(f));
	int res = 0;
	int sum = 0;
	for(int i = 0; i + k < n; i++){
		if((dir[i] + sum) % 2 != 0){
			res++;
			f[i] = 1;
		}
		sum += f[i];
		if(i - k>= 0){
			sum -= f[i - k];
		}
	}
	for(int i = n - k; i < n; i++){
		if((dir[i] + sum) % 2 != 0){
			return -1;
		}
		if(i - k >= 0){
			sum -= f[i - k];
		}
	}
	return res;
}
int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		char ch;
		cin >> ch;
		if(ch == 'B') dir[i] = 1;
	}
	int len = 0, ans = n;
	for(int k = 0; k < n; k++){
		int m = cal(k);
		if(m >= 0 && ans > m){
			ans = m;
			len = k + 1;
		}
	}
	cout << len << ' ' << ans << endl;
	return 0;
}