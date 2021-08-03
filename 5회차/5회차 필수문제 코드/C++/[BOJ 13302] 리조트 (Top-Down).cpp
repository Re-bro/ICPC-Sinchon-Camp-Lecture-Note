#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
int n, m;
bool closed[101];
int dp[101][101];
int sol(int day, int coupon) {
	if (day >= n + 1) return 0;
	int &ret = dp[day][coupon];
	if (ret != -1) return ret;
	ret = 100000000;
	if (closed[day]) ret = min(ret, sol(day + 1, coupon));
	if (coupon >= 3) ret = min(ret, sol(day + 1, coupon - 3));
	ret = min(ret, sol(day + 1, coupon) + 10000);
	ret = min(ret, sol(day + 3, coupon + 1) + 25000);
	ret = min(ret, sol(day + 5, coupon + 2) + 37000);
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int k; cin >> k;
		closed[k] = true;
	}
	memset(dp, -1, sizeof(dp));
	cout << sol(1, 0);
}