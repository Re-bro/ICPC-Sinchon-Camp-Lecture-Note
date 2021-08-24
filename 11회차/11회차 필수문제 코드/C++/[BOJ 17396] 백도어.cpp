#include<iostream>
#include<queue>
using namespace std;
int a[101010];
vector<pair<int, int>> adj[101010];
long long dis[101010];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) {
		int u, v, c; cin >> u >> v >> c;
		if ((a[u] == 0 && a[v] == 0) || u == n - 1 || v == n - 1) {
			adj[u].push_back({ v, c });
			adj[v].push_back({ u, c });
		}
	}
	fill(dis, dis + n, 1e18);
	priority_queue<pair<long long, int>> pq;
	pq.push({ 0, 0 });
	dis[0] = 0;
	while (!pq.empty()) {
		auto[d, u] = pq.top(); pq.pop();
		if (-d > dis[u]) continue;
		for (auto[v, c] : adj[u]) {
			if (dis[v] > -d + c) {
				dis[v] = -d + c;
				if (v != n - 1) pq.push({ -dis[v], v });
			}
		}
	}
	if (dis[n - 1] == 1e18) cout << -1;
	else cout << dis[n - 1];
}