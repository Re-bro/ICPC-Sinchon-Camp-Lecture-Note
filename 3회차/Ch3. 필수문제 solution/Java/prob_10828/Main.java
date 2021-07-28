package prob_10828;

import java.util.*;
import java.io.*;
public class Main {

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		// Scanner 입력은 시간초과 발생
		int n = Integer.parseInt(br.readLine());
		Stack<Integer> st = new Stack();
		for (int i = 1; i <= n; i++) {
			String s = br.readLine();
			if (s.contains("push")) {
				String s_[] = s.split(" "); // push x에서 push는 s_[0], x는 s_[1]
				st.push(Integer.parseInt(s_[1]));
			}
			else if (s.contains("pop")) {
				System.out.println(st.isEmpty()?-1:st.pop());

			}
			else if (s.contains("size")) {
				System.out.println(st.size());
			}
			else if (s.contains("empty")) {
				System.out.println(st.isEmpty()?1:0);

			}
			else {
				System.out.println(st.isEmpty()?-1:st.peek());

			}
		}

	}

}
