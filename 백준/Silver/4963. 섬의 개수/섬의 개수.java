import java.util.*;

public class Main {
    static int[][] map;
    static boolean[][] visit;
    static int[][] dxdy = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    
    public static class Pair{
        int x,y;
        Pair(int x, int y){
            this.x=x; this.y=y;
        }
    }

    public static boolean bfs(int x,int y,int n, int m){
        if(map[x][y]==0 || visit[x][y]) return false;
        int ans = 1;
        Queue<Pair> q = new LinkedList<>();
        visit[x][y] = true;
        q.add(new Pair(x,y));
        while(!q.isEmpty()){
            Pair p = q.poll();
            for(int i=0;i<8;i++){
                int nx = p.x + dxdy[i][0];
                int ny = p.y + dxdy[i][1];
                if(nx<0||nx>n-1||ny<0||ny>m-1||visit[nx][ny]||map[nx][ny]==0)continue;
                q.add(new Pair(nx, ny));
                visit[nx][ny]=true;
            }
        }
        return true;
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        while(true){
            int n, m, ans = 0;
            m = sc.nextInt();
            n = sc.nextInt();
            if( n == 0 && m == 0) break;
            map = new int[n][m]; visit = new boolean[n][m];
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    map[i][j] = sc.nextInt();
                    visit[i][j]=false;
                }
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(bfs(i,j,n,m)){
                        ans++;
                    }
                }
            }
            System.out.println(ans);
        }
    }
}
