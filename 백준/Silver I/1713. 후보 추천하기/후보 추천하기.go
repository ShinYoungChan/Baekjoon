package main

import (
	"fmt"
	"sort"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	pCnt := [101]int{}
	var candi []int
	for i := 0; i < m; i++ {
		var vote int
		fmt.Scan(&vote)
		// 이미 투표한 후보인지
		flag := false
		for j := 0; j < len(candi); j++ {
			if candi[j] == vote {
				flag = true
				break
			}
		}
		if flag {
			pCnt[vote]++
		} else {
			// 사진 등록이 바로 가능한 경우
			if len(candi) < n {
				candi = append(candi, vote)
			} else {
				// 횟수가 가장 적은 후보 색출
				cnt, idx := 1001, -1
				for j := 0; j < len(candi); j++ {
					if pCnt[candi[j]] < cnt {
						cnt, idx = pCnt[candi[j]], j
					}
				}
				// 후보제거 후 새로운 후보 등록
				pCnt[candi[idx]] = 0
				candi = append(candi[:idx], candi[idx+1:]...)
				candi = append(candi, vote)
			}
			pCnt[vote]++
		}
	}
	sort.Slice(candi, func(i, j int) bool {
		return candi[i] < candi[j]
	})
	for i := 0; i < len(candi); i++ {
		fmt.Printf("%d ", candi[i])
	}
}
