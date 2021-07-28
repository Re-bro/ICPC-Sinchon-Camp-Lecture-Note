package prob_2504;

import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String s = in.nextLine();
		Stack <Integer> st = new Stack();
		for(int i=0;i< s.length();i++) {
			if(s.charAt(i) == '(')st.push(-1);
			else if(s.charAt(i)=='[')st.push(-2);
			else {
				if(st.empty() || (st.peek()>0 && st.size()==1)) {
					System.out.print(0);
					System.exit(0);
				}
				int now = 1;
				if(st.peek()>0) {
					now = st.peek();
					st.pop();
				}
				if(s.charAt(i)==')' && st.peek()==-1) {
					st.pop();
					st.push(now*2);
				}
				else if(s.charAt(i)==']' && st.peek()==-2) {
					st.pop();
					st.push(now*3);
				}
				else {
					System.out.print(0);
					System.exit(0);
				}
				if(st.size() >=2) {
					int tmp = st.peek();st.pop();
					if(st.peek()>0 && tmp>0) {
						tmp +=st.peek();
						st.pop();
					}
					st.push(tmp);
				}
			}
		}
		if(st.size()==1 && st.peek()>0)System.out.print(st.peek());
		else System.out.print(0);
	}

}
