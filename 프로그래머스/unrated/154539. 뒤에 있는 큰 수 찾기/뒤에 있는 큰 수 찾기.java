import java.util.Stack;
import java.util.Arrays;

class Solution {
    public int[] solution(int[] numbers) {
        int[] answer = new int[numbers.length];
        Stack<Integer> s = new Stack<>();
        Arrays.fill(answer,-1);
        s.push(0);
        for(int i=1;i<numbers.length;i++){
            while(numbers[s.peek()]<numbers[i]){
                answer[s.peek()] = numbers[i];
                s.pop();
                if(s.size()==0)break;
            }
            s.push(i);
        }
        return answer;
    }
}