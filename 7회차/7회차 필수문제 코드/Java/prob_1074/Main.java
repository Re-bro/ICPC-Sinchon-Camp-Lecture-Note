package prob_1074;

import java.util.*;
public class Main {

	public static int n, r, c;
	public static int sol(int x, int y, int size) {
		if (size == 1) return 0;
		int ret = 0;
		int s = size / 2;
		if (x + s > r && y + s > c) return ret += sol(x, y, s);
		ret += s * s;
		if (x + s > r && y + s <= c) return ret += sol(x, y + s, s);
		ret += s * s;
		if (x + s <= r && y + s > c) return ret += sol(x + s, y, s);
		ret += s * s;
		return ret += sol(x + s, y + s, s);
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		n = in.nextInt(); r = in.nextInt(); c = in.nextInt();
		int size = 1;
		for (int i = 1; i <= n; i++) size *= 2;
		System.out.print(sol(0, 0, size));
	}

}
