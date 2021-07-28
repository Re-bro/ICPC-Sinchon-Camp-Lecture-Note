package Prob_2304;

import java.util.*;

class elem{
    int first, second;
    elem (int first, int second){
        this.first = first;
        this.second = second;
    }
}

public class Main{

    public static void main(String[] args) {
        
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();

        Stack<elem> s = new Stack();
        ArrayList <elem> a = new ArrayList<elem>();

        for(int i=0; i<n;i++){
            a.add(new elem(in.nextInt(), in.nextInt()));
        }

        Collections.sort(a, new Comparator<elem>() {
        	public int compare(elem e1, elem e2) {
        		if(e1.first!=e2.first)return e1.first-e2.first;
        		return e1.second-e2.second;
        	}
        });
        
        for(int i=0; i<n;i++){
            while(s.size() >=2){
                int l = s.peek().first;
                int h = s.peek().second;
                s.pop();
                if(s.peek().second >= h && a.get(i).second >= h) continue;
                else {
                    s.push(new elem(l, h));
                    break;
                }
            }
            s.push(a.get(i));
        }
        int ans = 0;
        int prv_l = s.peek().first;
        int prv_h = s.peek().second;
        ans += prv_h;
        s.pop();
        while(!s.empty()){
            int l = s.peek().first;
            int h = s.peek().second;
            ans += Math.min(prv_h, h) * (prv_l - (l+1));
            ans += h;
            prv_h = h;
            prv_l = l;
            s.pop();
        }
        System.out.println(ans);
    } 
}
    
