#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n, m;
int A[1010][1010];
int dp[1010][1010];
int sol(int x, int y) {
	if (x == n && y == m) return A[x][y];
	if (x > n || y > m) return 0;
	int &ret = dp[x][y];
	if (ret != -1) return ret;
	ret = max({ sol(x + 1, y), sol(x, y + 1), sol(x + 1, y + 1) });
	ret += A[x][y];
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) cin >> A[i][j];
	}
	memset(dp, -1, sizeof(dp));
	cout << sol(1, 1);
}