#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int dis[101010];
vector<int> adj[101010];
int main(void) {
	int n, k; cin >> n >> k;
	for (int i = 0; i <= 100000; i++) {
		if(i > 0) adj[i].push_back(i - 1);
		if (i < 100000) adj[i].push_back(i + 1);
		if (i * 2 <= 100000) adj[i].push_back(i * 2);
	}
	queue<int> q;
	q.push(n);
	memset(dis, -1, sizeof(dis));
	dis[n] = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int v : adj[u]) {
			if (dis[v] == -1) {
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}
	cout << dis[k];
}