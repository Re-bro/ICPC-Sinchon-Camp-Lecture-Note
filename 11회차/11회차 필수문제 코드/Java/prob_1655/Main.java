package prob_1655;

import java.util.*;
import java.io.*;
public class Main {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb=new StringBuilder();
		
		String s=br.readLine();
		
		int N=Integer.parseInt(s);
		
		PriorityQueue<Integer> pq1=new PriorityQueue<Integer>();//啊款单~弥措
		PriorityQueue<Integer> pq2=new PriorityQueue<Integer>(Collections.reverseOrder());//弥家~啊款单
		
		s=br.readLine();
		
		int temp=Integer.parseInt(s);
		sb.append(s+"\n");
		
		int temp1,temp2;
		if(N>=2) {
			s=br.readLine();
			temp1=Integer.parseInt(s);
			if(temp>temp1) {
				sb.append(s+"\n");
				pq2.add(temp1);
				pq1.add(temp);
			}
			else {
				sb.append(Integer.toString(temp)+"\n");
				pq1.add(temp1);
				pq2.add(temp);
			}
			
			for(int i=2;i<N;i++) {
				s=br.readLine();
				temp=Integer.parseInt(s);
				temp1=pq1.remove();
				temp2=pq2.remove();
				
				if(i%2==1) {
					if(temp<=temp2) {
						sb.append(Integer.toString(temp2)+"\n");
						pq2.add(temp);
						pq2.add(temp2);
						pq1.add(temp1);
					}	
					else if(temp1<=temp) {
						sb.append(Integer.toString(temp1)+"\n");
						pq2.add(temp1);
						pq2.add(temp2);
						pq1.add(temp);
					}
					else {
						sb.append(s+"\n");
						pq2.add(temp);
						pq2.add(temp2);
						pq1.add(temp1);
					}
				}
				else {
					if(temp<=temp2) {
						sb.append(Integer.toString(temp2)+"\n");
						pq2.add(temp);
						pq1.add(temp1);
						pq1.add(temp2);
					}
					else if(temp1<=temp) {
						sb.append(Integer.toString(temp1)+"\n");
						pq2.add(temp2);
						pq1.add(temp);
						pq1.add(temp1);
					}
					else {
						sb.append(s+"\n");
						pq2.add(temp2);
						pq1.add(temp);
						pq1.add(temp1);
					}
				}
			}
		}
		
		bw.write(sb.toString());
		bw.flush();
		bw.close();
		br.close();
		
	}

}
