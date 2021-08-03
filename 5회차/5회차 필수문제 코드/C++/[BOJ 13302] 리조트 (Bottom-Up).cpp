#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
int n, m;
bool closed[101];
int dp[101][101];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int k; cin >> k;
		closed[k] = true;
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) dp[i][j] = 100000000;
	}
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (closed[i]) dp[i][j] = min(dp[i][j], dp[i - 1][j]);
			dp[i][j] = min(dp[i][j], dp[i - 1][j] + 10000);
			if (i >= 3 && j >= 1) dp[i][j] = min(dp[i][j], dp[i - 3][j - 1] + 25000);
			if (i >= 5 && j >= 2) dp[i][j] = min(dp[i][j], dp[i - 5][j - 2] + 37000);
			if (j + 3 <= n) dp[i][j] = min(dp[i][j], dp[i - 1][j + 3]);
		}
	}
	int ans = 100000000;
	for (int i = 0; i <= n; i++) ans = min(ans, dp[n][i]);
	cout << ans;
}