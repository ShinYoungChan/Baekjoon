package main

import (
	"fmt"
	"math"
)

func check(num int) bool {
	if num <= 1 {
		return false
	}
	if num == 2 || num == 3 {
		return true
	}
	for i := 2; i <= int(math.Sqrt(float64(num))); i++ {
		if num%i == 0 {
			return false
		}
	}
	return true
}

func main() {
	var n int
	fmt.Scanln(&n)
	for i := 0; i < n; i++ {
		var num int
		fmt.Scanln(&num)
		for {
			if check(num) {
				fmt.Println(num)
				break
			} else {
				num++
			}
		}
	}
}
