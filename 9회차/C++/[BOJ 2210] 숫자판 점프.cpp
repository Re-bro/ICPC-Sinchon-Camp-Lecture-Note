#include<iostream>
using namespace std;

int A[5][5];
bool chk[1000000];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
void dfs(int x, int y, int k, int cnt) {
	if (cnt == 6) {
		chk[k] = true;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5) {
			dfs(nx, ny, k * 10 + A[nx][ny], cnt + 1);
		}
	}
}
int main(void) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) cin >> A[i][j];
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) dfs(i, j, A[i][j], 1);
	}
	int ans = 0;
	for (int i = 0; i < 1000000; i++) {
		if (chk[i]) ans++;
	}
	cout << ans;
}