#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, r;
vector<pair<int, int>> adj[202020];
int ans1 = 0;
int ans2 = 0;
void dfs(int u, int p, int a, int b) { //p : 이전 정점, a : 기둥, b : 가지
	//a가 음수면 현재 가지. 0이상이면 기둥
	if (u != r && adj[u].size() == 1) {
		if (a == -1) ans2 = max(ans2, b); 
		else ans1 = a; 
		return;
	}
	if (a >= 0) {
		if (adj[u].size() > 2 || (adj[u].size() >= 2 && u == r)) {
			ans1 = a;
			for (auto[v, k] : adj[u]) {
				if (v == p) continue;
				dfs(v, u, -1, k);
			}
		}
		else {
			for (auto[v, k] : adj[u]) {
				if (v == p) continue;
				dfs(v, u, a + k, b);
			}
		}
	}
	else {
		for (auto[v, k] : adj[u]) {
			if (v == p) continue;
			dfs(v, u, a, b + k);
		}
	}
	
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> r;
	for (int i = 1; i < n; i++) {
		int a, b, d; cin >> a >> b >> d;
		adj[a].push_back({ b, d });
		adj[b].push_back({ a, d });
	}
	dfs(r, r, 0, 0);
	cout << ans1 << ' ' << ans2;
}