class Solution {
    public boolean check(int x, int y, int m, String[][] park){
        for(int i=x;i<x+m;i++){
            for(int j=y;j<y+m;j++){
                if(!park[i][j].equals("-1")){
                    return false;
                }
            }
        }
        return true;
    }
    public int solution(int[] mats, String[][] park) {
        int answer = -1;
        for(int m:mats){
            for(int i=0;i<=park.length-m;i++){
                for(int j=0;j<=park[i].length-m;j++){
                    if(check(i,j,m,park)){
                        if(answer<m)answer=m;
                    }
                }
            }
        }
        return answer;
    }
}