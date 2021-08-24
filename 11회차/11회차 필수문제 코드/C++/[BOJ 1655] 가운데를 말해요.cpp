#include<iostream>
#include<queue>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	priority_queue<int> S;
	priority_queue<int, vector<int>, greater<int>> L;
	while (n--) {
		int k; cin >> k;
		if (S.empty() || S.top() >= k) S.push(k);
		else L.push(k);
		while (S.size() < L.size()) {
			S.push(L.top());
			L.pop();
		}
		while (S.size() > L.size() + 1) {
			L.push(S.top());
			S.pop();
		}
		cout << S.top() << '\n';
	}
}