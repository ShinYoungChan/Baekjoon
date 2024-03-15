import java.util.*;

public class Main {
    static int [][]map, copymap, dxdy;
    static boolean []check;
    static int n,m,k;
    static int ans = Integer.MAX_VALUE;

    public static void rotate(int sx, int sy, int ex, int ey){
        int r1 = sx, c1 = sy, r2 = ex, c2 = ey;
        while(sx!=ex){
            for(int i=sy;i<ey;i++){
                copymap[sx][i+1] = map[sx][i];
                copymap[ex][i] = map[ex][i+1];
            }
            for(int i=sx;i<ex;i++){
                copymap[i+1][ey] = map[i][ey];
                copymap[i][sy] = map[i+1][sy];
            }
            sx++; sy++; ex--; ey--;
        }
        copymap[sx][sy]=map[sx][sy];
        for(int i=r1;i<=r2;i++){
            for(int j=c1;j<=c2;j++){
                map[i][j]=copymap[i][j];
            }
        }
    }

    public static void backrotate(int sx, int sy, int ex, int ey){
        int r1 = sx, c1 = sy, r2 = ex, c2 = ey;
        while(sx!=ex){
            for(int i=ey;i>sy;i--){
                copymap[sx][i-1] = map[sx][i];
                copymap[ex][i] = map[ex][i-1];
            }
            for(int i=ex;i>sx;i--){
                copymap[i-1][ey] = map[i][ey];
                copymap[i][sy] = map[i-1][sy];
            }
            sx++; sy++; ex--; ey--;
        }
        copymap[sx][sy]=map[sx][sy];
        for(int i=r1;i<=r2;i++){
            for(int j=c1;j<=c2;j++){
                map[i][j]=copymap[i][j];
            }
        }
    }

    public static void dfs(int depth){
        if(depth == k){
            for(int i=0;i<n;i++){
                int sum = 0;
                for(int j=0;j<m;j++){
                    sum+=map[i][j];
                }
                if(ans>sum)ans = sum;
            }
            return;
        }
        for(int i=0;i<k;i++){
            if(!check[i]){
                check[i]=true;
                rotate(dxdy[i][0], dxdy[i][1], dxdy[i][2], dxdy[i][3]);
                dfs(depth+1);
                backrotate(dxdy[i][0], dxdy[i][1], dxdy[i][2], dxdy[i][3]);
                check[i]=false;
            }
        }
    }
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt(); m = sc.nextInt(); k = sc.nextInt();
        map = new int[n][m]; copymap = new int[n][m];
        dxdy = new int[k][4]; check = new boolean[k];

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                map[i][j] = sc.nextInt();
            }
        }
        for(int i=0;i<k;i++){
            int r,c,s;
            r = sc.nextInt(); c = sc.nextInt(); s = sc.nextInt();
            dxdy[i][0]=r-s-1; dxdy[i][1]=c-s-1; dxdy[i][2]=r+s-1; dxdy[i][3]=c+s-1;
        }

        for(int i=0;i<k;i++){
            check[i]=true;
            rotate(dxdy[i][0], dxdy[i][1], dxdy[i][2], dxdy[i][3]);
            dfs(1);
            backrotate(dxdy[i][0], dxdy[i][1], dxdy[i][2], dxdy[i][3]);
            check[i]=false;
        }
        System.out.println(ans);
    }
}
