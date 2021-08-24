#include<iostream>
#include<queue>
using namespace std;

vector<pair<int, int>> adj[5050];
int dis1[5050], dis2[5050];
void dijkstra(int dis[5050], int S) {
	dis[S] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, S });
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
	int v, e, p; cin >> v >> e >> p;
	for (int i = 0; i < e; i++) {
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}
	fill(dis1, dis1 + 5050, (int)1e9);
	fill(dis2, dis2 + 5050, (int)1e9);
	dijkstra(dis1, 1);
	dijkstra(dis2, p);
	if (dis1[v] == dis1[p] + dis2[v]) cout << "SAVE HIM";
	else cout << "GOOD BYE";
}