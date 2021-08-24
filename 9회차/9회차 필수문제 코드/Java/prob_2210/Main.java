package prob_2210;

import java.util.*;
//import java.io.*;
public class Main {
	static int A[][] = new int[5][5];
	static boolean chk[] = new boolean[1000000];
	static int dx[] = { 0, 1, 0, -1 };
	static int dy[] = { 1, 0, -1, 0 };
	static public void dfs(int x, int y, int k, int cnt) {
		if (cnt == 6) {
			chk[k] = true;
			return;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5) {
				dfs(nx, ny, k * 10 + A[nx][ny], cnt + 1);
			}
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) A[i][j] = in.nextInt();
		}
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) dfs(i, j, A[i][j], 1);
		}
		int ans = 0;
		for (int i = 0; i < 1000000; i++) {
			if (chk[i]) ans++;
		}
		System.out.print(ans);
	}

}
