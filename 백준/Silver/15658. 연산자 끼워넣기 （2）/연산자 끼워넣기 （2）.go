package main

import "fmt"

var max = -1000000001
var min = 1000000001
var v []int
var op [4]int

func dfs(num, cnt int) {
	if cnt == len(v) {
		if max < num {
			max = num
		}
		if min > num {
			min = num
		}
		return
	}
	for i := 0; i < 4; i++ {
		if op[i] > 0 {
			op[i]--
			if i == 0 {
				dfs(num+v[cnt], cnt+1)
			} else if i == 1 {
				dfs(num-v[cnt], cnt+1)
			} else if i == 2 {
				dfs(num*v[cnt], cnt+1)
			} else {
				dfs(num/v[cnt], cnt+1)
			}
			op[i]++
		}
	}
}

func main() {
	var n int
	fmt.Scanln(&n)
	for i := 0; i < n; i++ {
		var a int
		fmt.Scan(&a)
		v = append(v, a)
	}
	for i := 0; i < 4; i++ {
		fmt.Scan(&op[i])
	}
	dfs(v[0], 1)
	fmt.Printf("%d\n%d\n", max, min)
}
