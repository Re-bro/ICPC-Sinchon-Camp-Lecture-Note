#include<iostream>
#include<queue>
using namespace std;

bool chk[1010101];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		priority_queue<pair<int, int>> max_pq;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_pq;
		int k; cin >> k;
		fill(chk, chk + k, false);
		for(int i =0; i<k; i++){
			char c; int x; cin >> c >> x;
			if (c == 'D') {
				if (max_pq.empty()) continue;
				if (x == 1) {
					chk[max_pq.top().second] = true;
					max_pq.pop();
				}
				else {
					chk[min_pq.top().second] = true;
					min_pq.pop();
				}
			}
			else {
				max_pq.push({ x, i });
				min_pq.push({ x, i });
			}
			while (!max_pq.empty() && chk[max_pq.top().second]) max_pq.pop();
			while (!min_pq.empty() && chk[min_pq.top().second]) min_pq.pop();
		}
		if (max_pq.empty()) cout << "EMPTY\n";
		else {
			cout << max_pq.top().first << ' ' << min_pq.top().first << '\n';
		}
	}
}