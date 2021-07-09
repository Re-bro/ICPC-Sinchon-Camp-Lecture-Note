#include<iostream>
#include<vector>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	/*
		vector의 반복자, erase 함수 이용한 풀이
	*/
	int n, k; cin >> n >> k;
	vector<int> v, ans;
	for (int i = 1; i <= n; i++) v.push_back(i);
	int x = 0;
	while (!v.empty()) {
		x = (x + k - 1) % v.size();
		ans.push_back(*(v.begin() + x));
		v.erase(v.begin() + x);
	}
	cout << '<';
	for (int i = 0; i < (int)ans.size() - 1; i++) {
		cout << ans[i] << ", ";
	}
	cout << ans.back() << '>';
}