#include<iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int T; 
	cin >> T;
	for (int i = 1; i <= T; i++) {
		int a, b;
		cin >> a >> b;
		cout << a + b << '\n';
	}
}