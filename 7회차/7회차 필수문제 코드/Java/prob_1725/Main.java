package prob_1725;

import java.util.*;
public class Main {
	public static int A[] = new int[101010];
	public static int max(int a, int b) {
		return (a>b)?a:b;
	}
	public static int min(int a, int b) {
		return (a<b)?a:b;
	}
	public static int dnc(int l, int r) {
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
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		for (int i = 1; i <= n; i++) A[i] = in.nextInt();
		System.out.print(dnc(1, n));
	}

}
