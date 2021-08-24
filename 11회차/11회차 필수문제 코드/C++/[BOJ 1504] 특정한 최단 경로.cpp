#include<iostream>
#include<queue>
using namespace std;

vector<pair<int, int>> adj[808];
int dis1[808], disv1[808], disv2[808];
void dijkstra(int dis[808], int S) {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, S });
	dis[S] = 0;
	while (!pq.empty()) {
		auto[d, u] = pq.top(); pq.pop();
		if (-d > dis[u]) continue;
		for (auto[v, c] : adj[u]) {
			if (dis[v] > -d + c) {
				dis[v] = -d + c;
				pq.push({ -dis[v], v });
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, e; cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}
	fill(dis1, dis1 + n + 1, 1e8);
	fill(disv1, disv1 + n + 1, 1e8);
	fill(disv2, disv2 + n + 1, 1e8);
	int v1, v2; cin >> v1 >> v2;
	dijkstra(dis1, 1);
	dijkstra(disv1, v1);
	dijkstra(disv2, v2);
	int ans = min(dis1[v1] + disv1[v2] + disv2[n], dis1[v2] + disv2[v1] + disv1[n]);
	if (ans >= 1e8) cout << -1;
	else cout << ans;
}