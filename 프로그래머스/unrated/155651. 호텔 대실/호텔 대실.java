import java.util.Arrays;

class Solution {
    public int solution(String[][] book_time) {
        int answer = 0;
        int[] arr = new int[1450];
        Arrays.fill(arr,0);
        for(int i=0;i<book_time.length;i++){
            String[] startTime = book_time[i][0].split(":");
            String[] endTime = book_time[i][1].split(":");
            int sTime = Integer.parseInt(startTime[0])*60+Integer.parseInt(startTime[1]);
            int eTime = Integer.parseInt(endTime[0])*60+Integer.parseInt(endTime[1])+10;
            arr[sTime]++;
            arr[eTime]--;
        }
        for(int i=0;i<arr.length-1;i++){
            arr[i+1] += arr[i];
            if(answer<arr[i+1])
                answer = arr[i+1];
        }
        return answer;
    }
}