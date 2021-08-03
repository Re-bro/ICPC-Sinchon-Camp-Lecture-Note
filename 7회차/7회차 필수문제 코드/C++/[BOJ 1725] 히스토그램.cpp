#include<iostream>
#include<algorithm>
using namespace std;

int A[101010];
int dnc(int l, int r) {
	if (l == r) return A[l];
	if (l > r) return 0;
	int mid = (l + r) / 2;
	int res = max(dnc(l, mid - 1), dnc(mid + 1, r));
	int height = A[mid];
	res = max(res, A[mid]);
	int s = mid;
	int e = mid;
	while (s > l || e < r) {
		if ((s == l || (A[e + 1] >= A[s - 1])) && e < r) {
			e++;
			height = min(height, A[e]);
		}
		else {
			s--;
			height = min(height, A[s]);
		}
		res = max(res, height*(e - s + 1));
	}
	return res;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	cout << dnc(1, n);
}