#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int A[101][101];
int psum[101][101];
int main(void) {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		for (int j = 1; j <= m; j++) {
			A[i][j] = s[j - 1] - '0';
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			psum[i][j] = psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1] + A[i][j];
		}
	}
	long long ans = 0;
	long long k1, k2, k3;
	// | | 형태
	for (int i = 1; i < m-1; i++) {
		k1 = psum[n][i];
		for (int j = i + 1; j < m; j++) {
			k2 = psum[n][j] - k1;
			k3 = psum[n][m] - psum[n][j];
			ans = max(ans, k1*k2*k3);
		}
	}
	// = 형태
	for (int i = 1; i < n - 1; i++) {
		k1 = psum[i][m];
		for (int j = i + 1; j < n; j++) {
			k2 = psum[j][m] - k1;
			k3 = psum[n][m] - psum[j][m];
			ans = max(ans, k1*k2*k3);
		}
	}
	// ㅏ 형태
	for (int i = 1; i < m; i++) {
		k1 = psum[n][i];
		for (int j = 1; j < n; j++) {
			k2 = psum[j][m] - psum[j][i];
			k3 = psum[n][m] - k1 - k2;
			ans = max(ans, k1*k2*k3);
		}
	}
	// ㅜ 형태
	for (int i = 1; i < n; i++) {
		k1 = psum[i][m];
		for (int j = 1; j < m; j++) {
			k2 = psum[n][j] - psum[i][j];
			k3 = psum[n][m] - k1 - k2;
			ans = max(ans, k1*k2*k3);
		}
	}
	// ㅓ 형태
	for (int i = 1; i < m; i++) {
		k1 = psum[n][m] - psum[n][i];
		for (int j = 1; j < n; j++) {
			k2 = psum[j][i];
			k3 = psum[n][i] - k2;
			ans = max(ans, k1*k2*k3);
		}
	}
	// ㅗ 형태 
	for (int i = 1; i < n; i++) {
		k1 = psum[n][m] - psum[i][m];
		for (int j = 1; j < m; j++) {
			k2 = psum[i][j];
			k3 = psum[i][m] - k2;
			ans = max(ans, k1*k2*k3);
		}
	}
	cout << ans;
}