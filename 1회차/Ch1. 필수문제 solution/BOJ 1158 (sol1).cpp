#include<iostream>
#include<vector>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	/*
		vector의 push_back 이용한 풀이
	*/
	int n, k; cin >> n >> k;
	vector<int> v, ans;
	for (int i = 1; i <= n; i++) v.push_back(i);
	int x = 0;
	while (x < (int)v.size()) {
		if ((x % k) == k - 1) {
			ans.push_back(v[x]);
		}
		else {
			v.push_back(v[x]);
		}
		x++;
	}
	cout << '<';
	for (int i = 0; i < (int)ans.size() - 1; i++) {
		cout << ans[i] << ", ";
	}
	cout << ans.back() << '>';
}