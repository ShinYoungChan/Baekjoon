import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

public class Main {
    static int [][]team;
    static boolean []visit;
    static int ans = Integer.MAX_VALUE, n;

    public static void dfs(int idx, int cnt){
        if(idx>=n)return;
        if(cnt>n/2+1)return;
        int sum1 = 0, sum2 = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(visit[i]&&visit[j]){
                    sum1+=team[i][j];
                }
                else if(!visit[i]&&!visit[j]){
                    sum2+=team[i][j];
                }
            }
        }
        int diff = Math.abs(sum1-sum2);
        if(ans>diff) ans = diff;

        visit[idx]=true;
        dfs(idx+1,cnt+1);
        visit[idx]=false;
        dfs(idx+1,cnt);
    }
    public static void main(String[] args) throws Exception {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(bf.readLine());
        n = Integer.parseInt(st.nextToken());
        team = new int[n][n]; visit = new boolean[n];
        for(int i=0;i<n;i++){
            st = new StringTokenizer(bf.readLine());
            for(int j=0;j<n;j++){
                team[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        dfs(0,0);
        bw.write(ans+"\n");
        bw.close();
    }
}
