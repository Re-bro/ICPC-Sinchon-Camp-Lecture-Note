#include<iostream>
using namespace std;

int cube[21];
bool chk = true;
int dnc(int l, int w, int h) {
	if (l == 0 || w == 0 || h == 0) return 0;
	for (int i = 20; i >= 0; i--) {
		if (cube[i] > 0) {
			int s = (1 << i); //cube size
			if (l >= s && w >= s && h >= s) {
				cube[i]--;
				return dnc(l, w, h - s) + dnc(l - s, s, s) + dnc(l, w - s, s) + 1;
			}
		}
	}
	chk = false;
	return 0;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int l, w, h; cin >> l >> w >> h;
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b; cin >> a >> b;
		cube[a] = b;
	}
	int res = dnc(l, w, h);
	if (chk) cout << res;
	else cout << -1;
}