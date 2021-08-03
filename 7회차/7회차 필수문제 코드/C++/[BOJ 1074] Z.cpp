#include<iostream>
using namespace std;
int n, r, c;
int sol(int x, int y, int size) {
	if (size == 1) return 0;
	int ret = 0;
	int s = size / 2;
	if (x + s > r && y + s > c) return ret += sol(x, y, s);
	ret += s * s;
	if (x + s > r && y + s <= c) return ret += sol(x, y + s, s);
	ret += s * s;
	if (x + s <= r && y + s > c) return ret += sol(x + s, y, s);
	ret += s * s;
	return ret += sol(x + s, y + s, s);
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> r >> c;
	int size = 1;
	for (int i = 1; i <= n; i++) size *= 2;
	cout << sol(0, 0, size);
}