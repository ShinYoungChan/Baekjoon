package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scanln(&n)
	for i := 0; i < n; i++ {
		var str1, str2 string
		fmt.Scanln(&str1, &str2)
		fmt.Print("Distances: ")
		for j := 0; j < len(str1); j++ {
			num := str2[j] - str1[j]
			if str1[j] > str2[j] {
				num += 26
			}
			fmt.Printf("%d ", num)
		}
		fmt.Println()
	}
}
