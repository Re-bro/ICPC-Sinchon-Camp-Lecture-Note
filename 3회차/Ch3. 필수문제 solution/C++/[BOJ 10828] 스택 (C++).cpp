#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(void) {
	int n; cin >> n;
	stack<int> st;
	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		if (s == "push") {
			int x; cin >> x;
			st.push(x);
		}
		else if (s == "pop") {
			if (st.empty()) cout << -1 << '\n';
			else {
				cout << st.top() << '\n';
				st.pop();
			}
		}
		else if (s == "size") {
			cout << st.size() << '\n';
		}
		else if (s == "empty") {
			if (st.empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else {
			if (st.empty()) cout << -1 << '\n';
			else cout << st.top() << '\n';
		}
	}
}