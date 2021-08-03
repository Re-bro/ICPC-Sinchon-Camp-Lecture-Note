#include<iostream>
#include<algorithm>
using namespace std;

int n, m, l; 
int a[101];
bool sol(int mid) {
	int cnt = 0;
	for (int i = 1; i <= n + 1; i++) {
		cnt += (a[i] - a[i - 1] - 1) / mid;
	}
	if (cnt <= m) return true;
	else return false;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m >> l;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	a[n + 1] = l;
	int s = 1; 
	int e = 1000;
	int ans = 10000;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (sol(mid)) {
			e = mid - 1;
			ans = min(ans, mid);
		}
		else s = mid + 1;
	}
	cout << ans;
}