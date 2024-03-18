import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

public class Main {
    public static class Pair implements Comparable<Pair>{
        int x,y;
        Pair(int x, int y){
            this.x=x; this.y=y;
        }
        @Override
        public int compareTo(Pair o) {
            if(this.x==o.x) return this.y - o.y;
            return this.x - o.x;
        }
    }
    public static void main(String[] args) throws Exception {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(bf.readLine());
        int n = Integer.parseInt(st.nextToken());
        Pair []arr = new Pair[n];
        for(int i=0;i<n;i++){
            st = new StringTokenizer(bf.readLine());
            arr[i] = new Pair(Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()));
        }
        Arrays.sort(arr); 
        int s = arr[0].x, e = arr[0].y;
        int sum = Math.abs(e-s);
        for(int i=1;i<n;i++){
            // 시작 지점이 현재 선을 그은 범위에 포함되면
            if(arr[i].x>=s&&arr[i].x<=e){
                // 끝나는 지점이 그은 범위 안에 포함되면
                if(arr[i].y<=e) continue;
                // 끝나는 지점이 현재 범위를 벗어나면
                else{
                    sum+=Math.abs(arr[i].y-e);
                    e=arr[i].y;
                }
            }
            // 시작 지점이 현재 선을 그은 범위에 포함되지 않으면
            else{
                sum+=Math.abs(arr[i].y-arr[i].x);
                s = arr[i].x; e=arr[i].y;
            }
        }
        bw.write(sum+"\n");
        bw.close();
    }
}
