#include<iostream>
using namespace std;
int dp[11];
int main(void) {
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= 10; i++) dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int n; cin >> n;
		cout << dp[n]<<'\n';
	}
}