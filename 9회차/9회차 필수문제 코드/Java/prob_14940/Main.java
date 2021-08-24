package prob_14940;

import java.util.*;
import java.io.*;

public class Main {

	static public class Pair{
		int first, second;
	}
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int A[][] = new int[1010][1010];
		int dis[][] = new int[1010][1010];
		int dx[] = { 0, 1, 0, -1 };
		int dy[] = { 1, 0, -1, 0 };
		int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
		int sx=0, sy=0;
		for (int i = 0; i < n; i++) {
			StringTokenizer st2 = new StringTokenizer(br.readLine());
			for (int j = 0; j < m; j++) {
				A[i][j] = Integer.parseInt(st2.nextToken());
				if (A[i][j] == 2) {
					sx = i;
					sy = j;
				}
			}
		}
		for(int a[]:dis)Arrays.fill(a, -1);
		Queue<Pair> q = new LinkedList<Pair>();
		Pair s = new Pair();
		s.first = sx; s.second = sy;
		q.add(s);
		dis[sx][sy] = 0;
		while (!q.isEmpty()) {
			Pair tmp = new Pair();
			tmp = q.peek(); q.remove();
			int x = tmp.first, y = tmp.second;
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
					if (A[nx][ny] == 1 && dis[nx][ny] == -1) {
						dis[nx][ny] = dis[x][y] + 1;
						Pair put = new Pair();
						put.first = nx; put.second = ny;
						q.add(put);
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (A[i][j] == 0) bw.write(0+" ");
				else bw.write(dis[i][j]+" "); 
			}
			bw.write("\n");
		}
		bw.flush();
	}

}
