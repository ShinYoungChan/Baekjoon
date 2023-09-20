import java.util.*;

class Solution {
    public int solution(int[] order) {
        int answer = 0;
        Stack<Integer> stack = new Stack<>();
        int cnt = 0;
        for(int i=0;i<order.length;i++){
            if(i+1!=order[cnt]){
                stack.push(i+1);
            }
            else{
                answer++;
                cnt++;
                while(!stack.empty()&&stack.peek()==order[cnt]){
                    answer++;
                    cnt++;
                    stack.pop();
                }
            }
        }
        return answer;
    }
}