#include<iostream>
#include<vector>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	vector<int> v = { 1, 2, 3 };
	int M; cin >> M;
	for (int i = 1; i <= M; i++) {
		int X, Y; cin >> X >> Y;
		X--; Y--;
		swap(v[X], v[Y]);
	}
	for (int i = 0; i < 3; i++) {
		if (v[i] == 1) {
			cout << i + 1;
		}
	}
}