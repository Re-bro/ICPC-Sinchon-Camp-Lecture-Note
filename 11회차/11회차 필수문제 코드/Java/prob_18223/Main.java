package prob_18223;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

public class Main {
	static public class Pair{
		int first, second;
		
		public Pair(int first, int second) {
			this.first = first;
			this.second = second;
		}
		
	}
	public static class Ascending implements Comparator<Pair>{
		public int compare(Pair p1, Pair p2) {
			if(p1.first>p2.first)return 1;
			return -1;
		}
	}
	
	static ArrayList<Pair> adj[];
	static int dis1[] = new int[5050], dis2[] = new int[5050];
	static void dijkstra(int dis[], int S) {
		dis[S] = 0;
		PriorityQueue<Pair> pq = new PriorityQueue<>(new Ascending());
		pq.add(new Pair( 0, S ));
		while (!pq.isEmpty()) {
			int d = pq.peek().first, u = pq.peek().second;
			pq.remove();
			if (-d > dis[u]) continue;
			for (int a=0; a<adj[u].size();a++) {
				int v = adj[u].get(a).first, c = adj[u].get(a).second;
				if (dis[v] > -d + c) {
					dis[v] = -d + c;
					pq.add(new Pair( -dis[v], v ));
				}
			}
		}
	}
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int v=Integer.parseInt(st.nextToken()), e = Integer.parseInt(st.nextToken()), p = Integer.parseInt(st.nextToken());
		adj = new ArrayList[5050];
		for(int i = 0; i < 5050; i++)adj[i] = new ArrayList<>();
		for (int i = 0; i < e; i++) {
			StringTokenizer st1 = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st1.nextToken()), b = Integer.parseInt(st1.nextToken()), c = Integer.parseInt(st1.nextToken());
			adj[a].add(new Pair( b, c ));
			adj[b].add(new Pair( a, c ));
		}
		Arrays.fill(dis1, (int)1e9);
		Arrays.fill(dis2, (int)1e9);
		dijkstra(dis1, 1);
		dijkstra(dis2, p);
		if (dis1[v] == dis1[p] + dis2[v]) bw.write("SAVE HIM");
		else bw.write("GOOD BYE");
		bw.flush();
	}

}
