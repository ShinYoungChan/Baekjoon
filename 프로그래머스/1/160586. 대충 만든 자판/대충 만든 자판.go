import (
    // "fmt"
    "strings"
)

func solution(keymap []string, targets []string) []int {
    var answer []int
    for _, target := range targets{
        sum := 0
        for _, t := range target{
            idx := 101
            for _,key :=range keymap{
                aaa := strings.IndexRune(key,t)
                if aaa != -1 && aaa<idx{
                    idx=aaa
                }
            }
            if idx==101{
                sum = -1; break
            }
            sum+=idx+1
        }
        answer = append(answer,sum)
    }
    return answer
}