import java.util.*;

class Pair{
    int x,y;
    Pair(int x,int y){
        this.x=x;
        this.y=y;
    }
    public int getX(){
        return this.x;
    }
    public int getY(){
        return this.y;
    }
}

class Solution {
    static int[][] map;
    static int[][] dxdy = {{-1,0},{0,-1},{1,0},{0,1}};
    static int n,m,lx,ly,ex,ey;
    public void bfs(int i,int j, String[] maps){
        Queue<Pair> q = new LinkedList<>();
        map[i][j]=1;
        q.add(new Pair(i,j));
        while(!q.isEmpty()){
            int x = q.peek().getX();
            int y = q.peek().getY();
            q.poll();
            for(int k=0;k<4;k++){
                int mx = x+dxdy[k][0];
                int my = y+dxdy[k][1];
                if(mx<0||mx>n-1||my<0||my>m-1)continue;
                if(maps[mx].charAt(my)=='X')continue;
                if(map[mx][my]!=0) continue;
                q.add(new Pair(mx,my));
                map[mx][my] = map[x][y] + 1;
            }
        }
    }
    public int solution(String[] maps) {
        map = new int[maps.length][maps[0].length()];
        int x=0;int y = 0;
        n = maps.length;
        m = maps[0].length();
        for(int i=0;i<maps.length;i++){
            for(int j=0;j<maps[i].length();j++){
                if(maps[i].charAt(j)=='S'){
                    x=i;y=j;
                }
                if(maps[i].charAt(j)=='L'){
                    lx=i;ly=j;
                }
                if(maps[i].charAt(j)=='E'){
                    ex=i;ey=j;
                }
            }
        }
        bfs(x,y,maps);
        int lever = map[lx][ly];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(maps[i].charAt(j)=='L')continue;
                map[i][j]=0;
            }
        }
        if(map[lx][ly]!=0){
            bfs(lx,ly,maps);
        }
        return map[ex][ey] == 0 ? -1 : map[ex][ey]+lever-2;
    }
}