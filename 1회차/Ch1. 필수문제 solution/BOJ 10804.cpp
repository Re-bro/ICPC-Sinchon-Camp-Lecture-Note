#include<iostream>
#include<algorithm>
using namespace std;

int arr[21];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	for (int i = 1; i <= 20; i++) arr[i] = i;
	for (int i = 1; i <= 10; i++) {
		int a, b; 
		cin >> a >> b;
		reverse(arr + a, arr + b + 1);
	}
	for (int i = 1; i <= 20; i++) {
		cout << arr[i] << ' ';
	}
}