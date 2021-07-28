package prob_20923;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
public class Main {

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		//Scanner in = new Scanner(System.in);
		int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
		Deque<Integer> D = new ArrayDeque(), S = new ArrayDeque();
		Queue<Integer> dq1 = new LinkedList(), dq2 = new LinkedList();
		//D = dodo, S = suyeon, dq1 = dodo ground, dq2 = suyeon ground
		for (int i = 1; i <= n; i++) {
			StringTokenizer st2 = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st2.nextToken()), b = Integer.parseInt(st2.nextToken());
			D.addFirst(a);
			S.addFirst(b);
		}
		boolean turn = true; //true = dodo, false = suyeon 
		int k1 = 0, k2 = 0;
		for (int i = 1; i <= m; i++) {
			if (turn) {
				k1 = D.peekFirst(); D.removeFirst();
				dq1.add(k1);
			}
			else {
				k2 = S.peekFirst(); S.removeFirst();
				dq2.add(k2);
			}
			if (D.isEmpty()) {
				System.out.print("su");
				System.exit(0);
			}
			if (S.isEmpty()) {
				System.out.print("do");
				System.exit(0);
			}
			if (k1 == 5 || k2 == 5) {
				while (!dq2.isEmpty()) {
					D.addLast(dq2.peek()); 
					dq2.remove();
				}
				while (!dq1.isEmpty()) {
					D.addLast(dq1.peek());
					dq1.remove();
				}
				k1 = k2 = 0;
			}
			else if (k1 + k2 == 5 && k1 != 0 && k2 != 0) {
				while (!dq1.isEmpty()) {
					S.addLast(dq1.peek());
					dq1.remove();
				}
				while (!dq2.isEmpty()) {
					S.addLast(dq2.peek());
					dq2.remove();
				}
				k1 = k2 = 0;
			}
			turn = !turn;
		}
		if (D.size() < S.size()) System.out.print("su");
		else if (D.size() > S.size()) System.out.print("do");
		else System.out.print("dosu");

	}

}
