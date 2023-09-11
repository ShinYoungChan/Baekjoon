import java.util.*;
import javafx.util.Pair;

class Solution {
    boolean[][] check = new boolean[100][100];
    int[][] dxdy = {{-1,0},{0,-1},{1,0},{0,1}};
    public int bfs(int i,int j, String[] maps){
        Queue<Pair<Integer,Integer>> q = new LinkedList<>();
        check[i][j]=true;
        q.add(new Pair<>(i,j));
        int sum = maps[i].charAt(j)-'0';
        while(!q.isEmpty()){
            int x = q.peek().getKey();
            int y = q.peek().getValue();
            q.poll();
            for(int k=0;k<4;k++){
                int mx = x + dxdy[k][0];
                int my = y + dxdy[k][1];
                if(mx<0||mx>maps.length-1||my<0||my>maps[x].length()-1)continue;
                if(maps[mx].charAt(my)=='X'||check[mx][my])continue;
                check[mx][my]=true;
                q.add(new Pair<>(mx,my));
                sum += maps[mx].charAt(my)-'0';
            }
        }
        return sum;
    }
    public int[] solution(String[] maps) {
        ArrayList<Integer> arr = new ArrayList<>();
        for(int i=0;i<maps.length;i++){
            for(int j=0;j<maps[i].length();j++){
                if(!check[i][j]&&maps[i].charAt(j)!='X'){
                    int sum = bfs(i,j,maps);
                    arr.add(sum);
                }
            }
        }
        if(arr.size()==0)
            arr.add(-1);
        int[] answer =new int[arr.size()];
        for(int i=0;i<arr.size();i++){
            answer[i] = arr.get(i);
        }
        Arrays.sort(answer);
        return answer;
    }
}