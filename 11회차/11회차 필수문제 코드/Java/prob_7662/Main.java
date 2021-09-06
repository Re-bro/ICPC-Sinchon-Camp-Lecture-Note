package prob_7662;

import java.util.*;
public class Main {
	
	public static class Pair{
		Long first;
		int second;
		
		public Pair(Long first, int second){
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

	public static class Descending implements Comparator<Pair>{
		public int compare(Pair p1, Pair p2) {
			if(p1.first<p2.first)return 1;
			return -1;
		}
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		boolean chk[] = new boolean[1010101];
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		while (T-->0) {
			PriorityQueue<Pair> max_pq = new PriorityQueue<>(new Descending());
			PriorityQueue<Pair> min_pq = new PriorityQueue<>(new Ascending());
			int k = in.nextInt();
			Arrays.fill(chk, false);
			for(int i =0; i<k; i++){
				String c = in.next(); Long x = in.nextLong();
				if (c.equals("D")) {
					if (max_pq.isEmpty()) continue;
					if (x == 1) {
						chk[max_pq.peek().second] = true;
						max_pq.remove();
					}
					else {
						chk[min_pq.peek().second] = true;
						min_pq.remove();
					}
				}
				else {
					max_pq.add(new Pair( x, i ));
					min_pq.add(new Pair( x, i ));
				}
				while (!max_pq.isEmpty() && chk[max_pq.peek().second]) max_pq.remove();
				while (!min_pq.isEmpty() && chk[min_pq.peek().second]) min_pq.remove();
			}
			if (max_pq.isEmpty()) System.out.println("EMPTY");
			else {
				System.out.println(max_pq.peek().first+" "+min_pq.peek().first);
			}
		}
	}

}
