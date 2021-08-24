package prob_20924;

import java.util.*;
import java.io.*;
public class Main {
	static public class Pair{
		int first, second;
		public Pair(int first, int second) {
			this.first = first;
			this.second = second;
		}
	}
	
	static int n, r;
	
	static ArrayList<Pair>[] adj;
	static int ans1 = 0;
	static int ans2 = 0;
	static public void dfs(int u, int p, int a, int b) { //p : 이전 정점, a : 기둥, b : 가지
		//a가 음수면 현재 가지. 0이상이면 기둥
		if (u != r && adj[u].size() == 1) {
			if (a == -1) ans2 = (ans2>b)?ans2:b; 
			else ans1 = a; 
			return;
		}
		if (a >= 0) {
			if (adj[u].size() > 2 || (adj[u].size() >= 2 && u == r)) {
				ans1 = a;
				for (int j=0 ; j<adj[u].size();++j) {
					Pair P = adj[u].get(j);
					int v = P.first, k = P.second;
					if (v == p) continue;
					dfs(v, u, -1, k);
				}
			}
			else {
				for (int j=0 ; j < adj[u].size();++j) {
					Pair P = adj[u].get(j);
					int v = P.first, k = P.second;
					if (v == p) continue;
					dfs(v, u, a + k, b);
				}
			}
		}
		else {
			for (int j=0 ; j<adj[u].size();++j) {
				Pair P = adj[u].get(j);
				int v = P.first, k = P.second;
				if (v == p) continue;
				dfs(v, u, a, b + k);
			}
		}
		
	}
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken()); r = Integer.parseInt(st.nextToken());
		
		adj = new ArrayList[n+1];
		for(int i=1;i<=n;i++)adj[i] = new ArrayList<>();
		for (int i = 1; i < n; i++) {
			StringTokenizer st1 = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st1.nextToken()), b = Integer.parseInt(st1.nextToken()), d = Integer.parseInt(st1.nextToken());
			adj[a].add(new Pair( b, d ));
			adj[b].add(new Pair( a, d ));
		}
		dfs(r, r, 0, 0);
		bw.write(ans1+" "+ans2);
		bw.flush();
	}

}
