#include<iostream>
#include<algorithm>
using namespace std;
int n, m;
int A[1010][1010];
int dp[1010][1010];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) cin >> A[i][j];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = max({ dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j] }) + A[i][j];
		}
	}
	cout << dp[n][m];
}
