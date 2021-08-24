package prob_1697;

import java.util.*;
import java.io.*;
public class Main {
	static ArrayList<Integer> adj[];
	static int dis[] = new int[101010];
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());
		adj = new ArrayList[101010];
		for(int i=0;i<101010;i++)adj[i] = new ArrayList<>();
		for (int i = 0; i <= 100000; i++) {
			if (i > 0) adj[i].add(i - 1);
			if (i < 100000) adj[i].add(i + 1);
			if (i * 2 <= 100000) adj[i].add(i * 2);
		}
		Queue<Integer> q = new LinkedList<Integer>();
		q.add(n);
		Arrays.fill(dis, -1);
		dis[n] = 0;
		while (!q.isEmpty()) {
			int u = q.peek(); q.remove();
			for (int a = 0; a < adj[u].size(); a++) {
				int v = adj[u].get(a);
				if (dis[v] == -1) {
					dis[v] = dis[u] + 1;
					q.add(v);
				}
			}
		}
		System.out.print(dis[k]);
	}

}
