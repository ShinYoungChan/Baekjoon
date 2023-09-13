import java.util.*;

class Solution {
    public int solution(int x, int y, int n) {
        int[] answer = new int[1000001];
        Arrays.fill(answer,0);
        Queue<Integer> q = new LinkedList<>();
        q.add(x);
        answer[x] = 1;
        while(!q.isEmpty()){
            int curr = q.peek();
            q.poll();
            int next = curr + n;
            if(next <= 1000000 && answer[next]==0){
                q.add(next);
                answer[next] = answer[curr] + 1;
            }
            next = curr * 2;
            if(next <= 1000000 && answer[next]==0){
                q.add(next);
                answer[next] = answer[curr] + 1;
            }
            next = curr * 3;
            if(next <= 1000000 && answer[next]==0){
                q.add(next);
                answer[next] = answer[curr] + 1;
            }
        }
        return answer[y]-1;
    }
}