package prob_19640;

import java.io.*;
import java.util.*;

public class Main {
	public static class person{
		int num, line, d, h;
		public person (int num, int line, int d, int h){
			this.num = num;
			this.line = line;
			this.d = d;
			this.h = h;
		}
	}
	public static class cmp implements Comparator<person>{
		public int compare(person p1, person p2) {
			if (p1.d == p2.d) {
				if (p1.h == p2.h) {
					return p1.line - p2.line;
				}
				return p2.h - p1.h;
			}
			return p2.d - p1.d;
		}
	}
	
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		ArrayList<person> v[];
		v = new ArrayList[101010];
		for(int i = 0; i < 101010; i++)v[i] = new ArrayList<>();
		int idx[] = new int[101010];
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());
		for (int i = 0; i < n; i++) {
			StringTokenizer st1 = new StringTokenizer(br.readLine());
			int d = Integer.parseInt(st1.nextToken()), h = Integer.parseInt(st1.nextToken()); 
			v[i%m].add(new person( i, i%m, d, h ));
		}
		PriorityQueue<person> pq = new PriorityQueue<>(new cmp());
		for (int i = 0; i < m; i++) {
			if (v[i].isEmpty()) continue;
			pq.add(v[i].get(idx[i]));
			idx[i]++;
		}
		int ans = 0;
		while (!pq.isEmpty()) {
			int num = pq.peek().num;
			int line = pq.peek().line;
			int d = pq.peek().d;
			int h = pq.peek().h;
			pq.remove();
			if (num == k) {
				break;
			}
			ans++;
			if (idx[line] < v[line].size()) {
				pq.add(v[line].get(idx[line]));
				idx[line]++;
			}
		}
		System.out.print(ans);
	}

}
