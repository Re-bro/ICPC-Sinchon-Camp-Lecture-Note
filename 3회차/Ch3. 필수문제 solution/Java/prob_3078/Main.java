package prob_3078;

import java.util.*;
import java.io.*;
public class Main {
	private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static void main(String[] args) throws IOException{
		StringTokenizer st = new StringTokenizer(br.readLine());
		// Scanner로 입력받으면 메모리 초과 발생
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		int cnt[] = new int[21];
		Queue<Integer> q = new LinkedList();
		long ans = 0;
		for (int i = 1; i <= n; i++) {
			int s_length = br.readLine().trim().length();
			if (q.size() > k) {
				cnt[q.peek()]--;
				q.remove();
			}
			ans += cnt[s_length];
			cnt[s_length]++;
			q.add(s_length);
		}
		System.out.println(ans);

	}

}
