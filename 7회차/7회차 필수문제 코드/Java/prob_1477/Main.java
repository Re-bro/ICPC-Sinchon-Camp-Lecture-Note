package prob_1477;

import java.util.*;
public class Main {
	public static int n, m, l;
	public static int a[] = new int[101];
	public static boolean sol(int mid) {
		int cnt = 0;
		for (int i = 1; i <= n + 1; i++) {
			cnt += (a[i] - a[i - 1] - 1) / mid;
		}
		if (cnt <= m) return true;
		else return false;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner in = new Scanner(System.in);
		n = in.nextInt();
		m = in.nextInt();
		l = in.nextInt();
		for (int i = 1; i <= n; i++) a[i] = in.nextInt();
		Arrays.sort(a, 1, 1+n);
		a[n + 1] = l;
		int s = 1; 
		int e = 1000;
		int ans = 10000;
		while (s <= e) {
			int mid = (s + e) / 2;
			if (sol(mid)) {
				e = mid - 1;
				ans = (ans <mid)?ans:mid;
			}
			else s = mid + 1;
		}
		System.out.print(ans);
	}

}
