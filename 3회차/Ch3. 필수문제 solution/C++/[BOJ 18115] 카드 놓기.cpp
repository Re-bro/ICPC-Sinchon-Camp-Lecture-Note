#include<iostream>
#include<deque>
using namespace std;

int a[1010101];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	deque<int> dq;
	for (int i = 1; i <= n; i++) {
		if (a[n + 1 - i] == 1) {
			dq.push_front(i);
		}
		else if (a[n + 1 - i] == 2) {
			int tmp = dq.front(); dq.pop_front();
			dq.push_front(i);
			dq.push_front(tmp);
		}
		else {
			dq.push_back(i);
		}
	}
	while (!dq.empty()) {
		cout << dq.front()<<' '; 
		dq.pop_front();
	}
}