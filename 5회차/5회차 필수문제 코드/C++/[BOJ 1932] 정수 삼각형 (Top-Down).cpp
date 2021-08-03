#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int A[501][501];
int dp[501][501];
int n;
int sol(int a, int b) {
	if (a == n) return 0;
	int &ret = dp[a][b];
	if (ret != -1) return ret;
	ret = max(ret, sol(a + 1, b) + A[a + 1][b]);
	ret = max(ret, sol(a + 1, b + 1) + A[a + 1][b + 1]);
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) cin >> A[i][j];
	}
	memset(dp, -1, sizeof(dp));
	cout << sol(1, 1) + A[1][1];
}