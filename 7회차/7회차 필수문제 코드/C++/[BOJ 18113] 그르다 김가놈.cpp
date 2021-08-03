#include<iostream>
#include<algorithm>
using namespace std;
int L[1010101];
int n, k, m;
bool sol(int mid) {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		cnt += L[i] / mid;
		if (cnt >= m) return true;
	}
	return false;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> k >> m;
	for (int i = 1; i <= n; i++) {
		cin >> L[i];
		if (L[i] >= 2 * k) L[i] -= 2 * k;
		else L[i] = max(0, L[i] - k);
	}
	int s = 1;
	int e = 1000000000;
	int ans = -1;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (sol(mid)) {
			ans = max(ans, mid);
			s = mid + 1;
		}
		else e = mid - 1;
	}
	cout << ans;
}