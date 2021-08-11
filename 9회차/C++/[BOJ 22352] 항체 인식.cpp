#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int a[31][31], b[31][31];
int tmp[31][31], visited[31][31];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> b[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			memset(visited, 0, sizeof(visited));

			for (int ii = 1; ii <= n; ii++) {
				for (int jj = 1; jj <= m; jj++) {
					tmp[ii][jj] = a[ii][jj];
				}
			}
			queue<pair<int, int>> q;
			q.push({ i, j });
			tmp[i][j] = b[i][j];
			while (!q.empty()) {
				auto[x, y] = q.front(); q.pop();
				for (int s = 0; s < 4; s++) {
					int nx = x + dx[s];
					int ny = y + dy[s];
					if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && tmp[nx][ny] == a[i][j] && !visited[nx][ny]) {
						q.push({ nx, ny });
						visited[nx][ny] = 1;
						tmp[nx][ny] = b[i][j];
					}
				}
			}
			bool chk = true;
			for (int ii = 1; ii <= n; ii++) {
				for (int jj = 1; jj <= m; jj++) {
					if (tmp[ii][jj] != b[ii][jj]) chk = false;
				}
			}
			if (chk) {
				cout << "YES";
				return 0;
			}
		}
	}
	cout << "NO";
}