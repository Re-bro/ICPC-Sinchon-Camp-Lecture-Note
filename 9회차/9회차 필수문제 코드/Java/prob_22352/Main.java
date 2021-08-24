package prob_22352;

import java.util.*;

public class Main {

	public static class Pair{
		int first, second;
		public Pair(int first, int second) {
			this.first = first;
			this.second = second;
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int a[][] = new int[31][31], b[][] = new int[31][31];
		int tmp[][] = new int[31][31], visited[][] = new int[31][31];
		int dx[] = { 0, 1, 0, -1 };
		int dy[] = { 1, 0, -1, 0 };
		
		int n = in.nextInt(), m = in.nextInt();
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				a[i][j] = in.nextInt();
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				b[i][j] = in.nextInt();
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				for(int k=0;k<31;k++)
				Arrays.fill(visited[k], 0);

				for (int ii = 1; ii <= n; ii++) {
					for (int jj = 1; jj <= m; jj++) {
						tmp[ii][jj] = a[ii][jj];
					}
				}
				Queue<Pair> q = new LinkedList();
				q.add(new Pair( i, j ));
				tmp[i][j] = b[i][j];
				while (!q.isEmpty()) {
					int x =q.peek().first, y = q.peek().second;
					q.remove();
					for (int s = 0; s < 4; s++) {
						int nx = x + dx[s];
						int ny = y + dy[s];
						if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && tmp[nx][ny] == a[i][j] && visited[nx][ny]==0) {
							q.add(new Pair (nx, ny));
							visited[nx][ny] = 1;
							tmp[nx][ny] = b[i][j];
						}
					}
				}
				boolean chk = true;
				for (int ii = 1; ii <= n; ii++) {
					for (int jj = 1; jj <= m; jj++) {
						if (tmp[ii][jj] != b[ii][jj]) chk = false;
					}
				}
				if (chk) {
					System.out.print("YES");
					System.exit(0);
				}
			}
		}
		System.out.print("NO");

	}

}
