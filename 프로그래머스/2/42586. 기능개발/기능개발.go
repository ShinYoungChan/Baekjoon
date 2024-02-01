import "math"

func solution(progresses []int, speeds []int) []int {
    var list, succ, ans []int
    for i:=0;i<len(progresses);i++{
        list = append(list, int(math.Ceil(float64(100-progresses[i])/float64(speeds[i]))))
    }
    succ = append(succ, list[0])
    list = list[1:]
    for i:=0; i<len(list);i++{
        if succ[0] >= list[i]{
            succ = append(succ,list[i])
        }else{
            ans = append(ans, len(succ))
            succ = nil
            succ = append(succ, list[i])
        }
    }
    ans = append(ans, len(succ))
    return ans
}