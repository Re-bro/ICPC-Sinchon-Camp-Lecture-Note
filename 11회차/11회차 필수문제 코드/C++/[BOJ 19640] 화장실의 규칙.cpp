#include<iostream>
#include<queue>
using namespace std;

struct person {
	int num, line, d, h;
};
struct cmp {
	bool operator()(person p1, person p2) {
		if (p1.d == p2.d) {
			if (p1.h == p2.h) {
				return p1.line > p2.line;
			}
			return p1.h < p2.h;
		}
		return p1.d < p2.d;
	}
};
vector<person> v[101010];
int idx[101010];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, m, k; cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		int d, h; cin >> d >> h;
		v[i%m].push_back({ i, i%m, d, h });
	}
	priority_queue<person, vector<person>, cmp> pq;
	for (int i = 0; i < m; i++) {
		if (v[i].empty()) continue;
		pq.push(v[i][idx[i]]);
		idx[i]++;
	}
	int ans = 0;
	while (!pq.empty()) {
		auto[num, line, d, h] = pq.top(); pq.pop();
		if (num == k) {
			break;
		}
		ans++;
		if (idx[line] < v[line].size()) {
			pq.push(v[line][idx[line]]);
			idx[line]++;
		}
	}
	cout << ans;
}