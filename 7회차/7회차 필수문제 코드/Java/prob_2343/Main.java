package prob_2343;

import java.util.*;
public class Main {
	public static int A[] = new int[101010];
	public static int n, m;
	public static int MAX = 1000000000;
	public static int min(int a, int b) {
		return (a<b)?a:b;
	}
	public static boolean sol(int mid) {
		int cnt = 1;
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			if (A[i] > mid) return false;
			if (sum + A[i] <= mid) {
				sum += A[i];
			}
			else {
				cnt++;
				sum = A[i];
			}
		}
		if (cnt <= m) return true;
		else return false;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		n = in.nextInt(); m = in.nextInt();
		for (int i = 1; i <= n; i++) A[i] = in.nextInt();
		int s = 1;
		int e = MAX;
		int ans = MAX;
		while (s <= e) {
			int mid = (s + e) / 2;
			if (sol(mid)) {
				e = mid - 1;
				ans = min(ans, mid);
			}
			else s = mid + 1;
		}
		System.out.print(ans);
	}

}
