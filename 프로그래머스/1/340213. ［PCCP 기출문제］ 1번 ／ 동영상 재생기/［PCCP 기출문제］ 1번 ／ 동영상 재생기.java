class Solution {
    public String solution(String video_len, String pos, String op_start, String op_end, String[] commands) {
        String answer = "";
        int vt = Integer.parseInt(video_len.substring(0,2))*60+Integer.parseInt(video_len.substring(3,5));
        int pt = Integer.parseInt(pos.substring(0,2))*60+Integer.parseInt(pos.substring(3,5));
        int ost = Integer.parseInt(op_start.substring(0,2))*60+Integer.parseInt(op_start.substring(3,5));
        int oet = Integer.parseInt(op_end.substring(0,2))*60+Integer.parseInt(op_end.substring(3,5));
        for(String c:commands){
            // 오프닝 건너뛰는지 체크
            if(pt>=ost&&pt<=oet){
                pt = oet;
            }
            if(c.equals("next")){
                pt+=10;
                if(pt >= vt) pt=vt;
            }
            else if(c.equals("prev")){
                pt-=10;
                if(pt<=0)pt=0;
            }
        }
        if(pt>=ost&&pt<=oet){
                pt = oet;
        }
        
        int hour = pt / 60;
        int minute = pt%60;
        if(hour<10){
            answer+="0"+Integer.toString(hour)+":";
        }
        else{
            answer+=Integer.toString(hour)+":";
        }
        if(minute<10){
            answer+="0"+Integer.toString(minute);
        }
        else{
            answer+=Integer.toString(minute);
        }
        return answer;
    }
}