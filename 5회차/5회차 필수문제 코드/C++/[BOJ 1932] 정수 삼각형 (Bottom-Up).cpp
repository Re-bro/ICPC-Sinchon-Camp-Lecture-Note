#include<iostream>
#include<algorithm>
using namespace std;
int A[501][501];
int dp[501][501];
int n;
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) cin >> A[i][j];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + A[i][j];
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dp[n][i]);
	}
	cout << ans;
}