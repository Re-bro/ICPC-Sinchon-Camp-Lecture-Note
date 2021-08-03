#include<iostream>
#include<cstring>
using namespace std;
int dp[11];
int sol(int x) {
	if (x == 1) return 1;
	else if (x == 2) return 2;
	else if (x == 3) return 4;
	int &ret = dp[x];
	if (ret != -1) return ret;
	ret = sol(x - 1) + sol(x - 2) + sol(x - 3);
	return ret;
}
int main(void) {
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int n; cin >> n;
		memset(dp, -1, sizeof(dp));
		cout << sol(n)<<'\n';
	}
}