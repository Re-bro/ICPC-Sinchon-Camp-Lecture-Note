package prob_18115;

import java.io.*;
import java.util.*;
public class Main {

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		int n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		int a[] = new int[1010101];
		for(int i=1;i<=n;i++)a[i] = Integer.parseInt(st.nextToken());
		Deque<Integer> dq = new ArrayDeque();
		for (int i = 1; i <= n; i++) {
			if (a[n + 1 - i] == 1) {
				dq.addFirst(i);
			}
			else if (a[n + 1 - i] == 2) {
				int tmp = dq.peekFirst(); dq.removeFirst();
				dq.addFirst(i);
				dq.addFirst(tmp);
			}
			else {
				dq.addLast(i);
			}
		}
		while (!dq.isEmpty()) {
			bw.write(dq.peekFirst()+" ");
			dq.removeFirst();
		}
		bw.flush();
	}
	
}
