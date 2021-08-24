package prob_1987;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
public class Main {

	static public int max(int a, int b) {
		return (a>b)?a:b;
	}
	static int R, C;
	static Vector<String> v = new Vector<String>(21);
	static boolean visited[] = new boolean[26];
	static int ans = 0;
	static int dx[] = { 0, 1, 0, -1 };
	static int dy[] = { 1, 0, -1, 0 };
	static public void dfs(int x, int y, int cnt) {
		ans = max(ans, cnt);
		String A = "A";
		int A_int = (int)A.toCharArray()[0];
		//System.out.println(R + C);
		visited[(int)v.elementAt(x).toCharArray()[y] - A_int] = true;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < R && ny >= 0 && ny < C && !visited[(int)v.elementAt(nx).toCharArray()[ny] - A_int]) {
				dfs(nx, ny, cnt + 1);
			}
		}
		visited[(int)v.elementAt(x).toCharArray()[y] - A_int] = false;
	}
	public static void main (String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		R = Integer.parseInt(st.nextToken()); C = Integer.parseInt(st.nextToken());
		for (int i = 0; i < R; i++) {
			String s = br.readLine();
			v.add(s);
		}
		dfs(0, 0, 1);
		System.out.print(ans);
	}

}
