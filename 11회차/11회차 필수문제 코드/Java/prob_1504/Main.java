package prob_1504;

import java.util.*;
public class Main {
	public static class Pair implements Comparable<Pair>{
		int first, second;
		public Pair(int first, int second) {
			this.first = first;
			this.second = second;
		}

		public int compareTo(Pair p) {
			return second - p.second;
		}
	}
	public static int min(int a, int b) {
		return (a<b)?a:b;
	}
	static ArrayList<Pair> adj[];
	static int dis1[] = new int[808], disv1[] = new int[808], disv2[] = new int[808];
	static void dijkstra(int dis[], int S) {
		PriorityQueue<Pair> pq = new PriorityQueue<Pair>();
		pq.add(new Pair(0, S));
		dis[S] = 0;
		while (!pq.isEmpty()) {
			int d = pq.peek().first, u = pq.peek().second;
			pq.remove();
			if (-d > dis[u]) continue;
			for (int a=0; a<adj[u].size();a++) {
				int v = adj[u].get(a).first,c = adj[u].get(a).second;
				if (dis[v] > -d + c) {
					dis[v] = -d + c;
					pq.add(new Pair(-dis[v], v ));
				}
			}
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(), e = in.nextInt();
		adj = new ArrayList[n+1];
		for(int i = 0; i < n + 1; i++)adj[i] = new ArrayList<>();
		for (int i = 0; i < e; i++) {
			int a = in.nextInt(), b = in.nextInt(), c = in.nextInt();
			adj[a].add(new Pair(b, c));
			adj[b].add(new Pair(a, c));
		}
		Arrays.fill(dis1, (int) 1e8);
		Arrays.fill(disv1, (int)1e8);
		Arrays.fill(disv2, (int)1e8);
		int v1 = in.nextInt(), v2 = in.nextInt();
		dijkstra(dis1, 1);
		dijkstra(disv1, v1);
		dijkstra(disv2, v2);
		int ans = min(dis1[v1] + disv1[v2] + disv2[n], dis1[v2] + disv2[v1] + disv1[n]);
		if (ans >= 1e8) System.out.print(-1);
		else System.out.print(ans);
	}

}
