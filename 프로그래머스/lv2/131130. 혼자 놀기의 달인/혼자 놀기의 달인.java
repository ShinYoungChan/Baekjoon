import java.util.*;

class Solution {
    public int solution(int[] cards) {
        int answer = 0;
        boolean[] check = new boolean[cards.length];
        Arrays.fill(check,false);
        ArrayList<Integer> arr = new ArrayList<>();
        for(int i=0;i<cards.length;i++){
            if(check[i])continue;
            check[i]=true;
            int num = cards[i]-1;
            int cnt = 1;
            while(cards[num]!=cards[i]){
                check[num]=true;
                num = cards[num]-1;
                cnt++;
            }
            arr.add(cnt);
        }
        Collections.sort(arr);
        if(arr.size()>1)
            answer = arr.get(arr.size()-1)*arr.get(arr.size()-2);
        return answer;
    }
}