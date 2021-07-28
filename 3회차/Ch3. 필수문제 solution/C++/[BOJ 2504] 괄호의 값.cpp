#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	string s; cin >> s;
	stack<int> st;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') st.push(-1);
		else if (s[i] == '[') st.push(-2);
		else {
			if (st.empty() || (st.top() > 0 && st.size() == 1)) {
				cout << 0; return 0;
			}
			int now = 1;
			if (st.top() > 0) {
				now = st.top(); st.pop();
			}
			if (s[i] == ')' && st.top() == -1) {
				st.pop();
				st.push(now * 2);
			}
			else if (s[i] == ']' && st.top() == -2) {
				st.pop();
				st.push(now * 3);
			}
			else {
				cout << 0; return 0;
			}
			if (st.size() >= 2) {
				int tmp = st.top(); st.pop();
				if (st.top() > 0 && tmp > 0) {
					tmp += st.top();
					st.pop();
				}
				st.push(tmp);
			}
		}
	}
	if (st.size() == 1 && st.top() > 0) cout << st.top();
	else cout << 0;
}