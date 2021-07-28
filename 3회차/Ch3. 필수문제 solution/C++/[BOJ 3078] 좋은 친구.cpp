#include<iostream>
#include<string>
#include<queue>
using namespace std;

int cnt[21];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, k; cin >> n >> k;
	queue<int> q;
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		if (q.size() > k) {
			cnt[q.front()]--;
			q.pop();
		}
		ans += cnt[s.size()];
		cnt[s.size()]++;
		q.push(s.size());
	}
	cout << ans;
}