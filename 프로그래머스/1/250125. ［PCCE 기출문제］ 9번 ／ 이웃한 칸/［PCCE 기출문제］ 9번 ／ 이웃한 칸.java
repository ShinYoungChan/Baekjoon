class Solution {
    static int[][] dxdy = {{-1,0},{0,1},{1,0},{0,-1}};
    public int solution(String[][] board, int h, int w) {
        int answer = 0;
        int n = board.length;
        for(int i=0;i<4;i++){
            int nx = h+dxdy[i][0];
            int ny = w+dxdy[i][1];
            if(nx<0||nx>n-1||ny<0||ny>n-1)continue;
            if(board[h][w].equals(board[nx][ny])){
                answer++;
            }
        }
        return answer;
    }
}