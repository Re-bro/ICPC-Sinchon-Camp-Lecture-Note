package prob_1493;

import java.util.*;
public class Main {
	static public int cube[] = new int[21];
	public static boolean chk = true;
	static int dnc(int l, int w, int h) {
		if (l == 0 || w == 0 || h == 0) return 0;
		for (int i = 20; i >= 0; i--) {
			if (cube[i] > 0) {
				int s = (1 << i); //cube size
				if (l >= s && w >= s && h >= s) {
					cube[i]--;
					return dnc(l, w, h - s) + dnc(l - s, s, s) + dnc(l, w - s, s) + 1;
				}
			}
		}
		chk = false;
		return 0;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int l = in.nextInt(), w = in.nextInt(), h = in.nextInt();
		int n = in.nextInt();
		for (int i = 1; i <= n; i++) {
			int a = in.nextInt(), b = in.nextInt();
			cube[a] = b;
		}
		int res = dnc(l, w, h);
		if (chk) System.out.print(res);
		else System.out.print(-1);
	}

}
