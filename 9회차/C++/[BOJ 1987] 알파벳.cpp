#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int R, C;
vector<string> v(20);
bool visited[26];
int ans = 0;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
void dfs(int x, int y, int cnt) {
	ans = max(ans, cnt);
	visited[v[x][y] - 'A'] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < R && ny >= 0 && ny < C && !visited[v[nx][ny] - 'A']) {
			dfs(nx, ny, cnt + 1);
		}
	}
	visited[v[x][y] - 'A'] = false;
}
int main(void) {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> v[i];
	}
	dfs(0, 0, 1);
	cout << ans;
}