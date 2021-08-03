#include<iostream>
#include<algorithm>
using namespace std;

int A[101010];
int n, m;
const int MAX = 1000000000;
bool sol(int mid) {
	int cnt = 1;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (A[i] > mid) return false;
		if (sum + A[i] <= mid) {
			sum += A[i];
		}
		else {
			cnt++;
			sum = A[i];
		}
	}
	if (cnt <= m) return true;
	else return false;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> A[i];
	int s = 1;
	int e = MAX;
	int ans = MAX;
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