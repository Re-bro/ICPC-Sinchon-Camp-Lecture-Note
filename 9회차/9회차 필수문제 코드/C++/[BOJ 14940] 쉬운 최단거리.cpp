#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int A[1010][1010];
int dis[1010][1010];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	int sx, sy;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> A[i][j];
			if (A[i][j] == 2) {
				sx = i;
				sy = j;
			}
		}
	}
	memset(dis, -1, sizeof(dis));
	queue<pair<int, int>> q;
	q.push({ sx, sy });
	dis[sx][sy] = 0;
	while (!q.empty()) {
		auto[x, y] = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (A[nx][ny] == 1 && dis[nx][ny] == -1) {
					dis[nx][ny] = dis[x][y] + 1;
					q.push({ nx, ny });
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (A[i][j] == 0) cout << 0 << ' ';
			else cout << dis[i][j] << ' ';
		}
		cout << '\n';
	}
}