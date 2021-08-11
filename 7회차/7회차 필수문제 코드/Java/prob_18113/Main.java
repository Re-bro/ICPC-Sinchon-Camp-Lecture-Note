package prob_18113;

import java.util.*;
import java.io.*;
public class Main {
	public static int L[] = new int[1010101];
	public static int n, k, m;
	public static int max(int a, int b) {
		return (a>b)?a:b;
	}
	public static boolean sol(int mid) {
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			cnt += L[i] / mid;
			if (cnt >= m) return true;
		}
		return false;
	}
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		//BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());k = Integer.parseInt(st.nextToken()); m = Integer.parseInt(st.nextToken());
		for (int i = 1; i <= n; i++) {
			L[i] = Integer.parseInt(br.readLine());;
			if (L[i] >= 2 * k) L[i] -= 2 * k;
			else L[i] = max(0, L[i] - k);
		}
		int s = 1;
		int e = 1000000000;
		int ans = -1;
		while (s <= e) {
			int mid = (s + e) / 2;
			if (sol(mid)) {
				ans = max(ans, mid);
				s = mid + 1;
			}
			else e = mid - 1;
		}
		System.out.print(ans);
	}

}
