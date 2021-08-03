#include<iostream>
#include<algorithm>
using namespace std;
int A[1010];
int dp[1010];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (A[j] < A[i]) dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) ans = max(ans, dp[i]);
	cout << ans;
}