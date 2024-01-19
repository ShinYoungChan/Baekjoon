import "strings"

func solution(friends []string, gifts []string) int {
    total, count := make(map[string]int), make(map[string]int)
    friend, ans := make([]string, len(friends)), make([]int, len(friends))
    for i:=0; i<len(friends); i++{
        friend[i] = friends[i]
    }
    for i:=0; i<len(gifts); i++{
        gift := strings.Split(gifts[i]," ")
        total[gift[0]]++; total[gift[1]]--; count[gifts[i]]++
    }
    for i:=0; i<len(friend) - 1; i++ {
        for j:=i+1; j<len(friend); j++ {
            first := friend[i] + " " +friend[j]
            second := friend[j] + " " +friend[i]
            // 준게 많으면
            if count[first] > count[second] {
                ans[i]++
            } else if count[first] < count[second] {    // 준게 적으면
                ans[j]++
            } else {    // 주고 받은게 같으면
                // 선물지수가 크면
                if total[friend[i]] > total[friend[j]] {
                    ans[i]++
                } else if total[friend[i]] < total[friend[j]] {
                    ans[j]++
                }
            }
        }
    }
    maxVal := 0
    for i:=0; i<len(ans); i++ {
        if maxVal < ans[i] {
            maxVal = ans[i]
        }
    }
    return maxVal
}