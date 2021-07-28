#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

pair<int, int> a[1010];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	stack<pair<int, int>> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		while (s.size() >= 2) {
			int l = s.top().first;
			int h = s.top().second;
			s.pop();
			if (s.top().second >= h && a[i].second >= h) continue;
			else {
				s.push({ l, h });
				break;
			}
		}
		s.push(a[i]);
	}

	int ans = 0;
	int prv_l = s.top().first;
	int prv_h = s.top().second;
	ans += prv_h;
	s.pop();
	while (!s.empty()) {
		int l = s.top().first;
		int h = s.top().second;
		ans += min(prv_h, h) * (prv_l - (l + 1));
		ans += h;
		prv_h = h;
		prv_l = l;
		s.pop();
	}
	cout << ans;
}