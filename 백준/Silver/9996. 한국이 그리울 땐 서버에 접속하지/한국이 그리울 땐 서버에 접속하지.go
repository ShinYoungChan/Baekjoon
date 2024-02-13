package main

import (
	"fmt"
	"strings"
)

func main() {
	var n int
	fmt.Scanln(&n)
	str := make([]string, n)
	var p string
	fmt.Scanln(&p)
	ps := strings.Split(p, "*")
	for i := 0; i < n; i++ {
		fmt.Scanln(&str[i])
	}
	for _, s := range str {
		flag := true
		if len(ps[0])+len(ps[1]) > len(s) {
			fmt.Println("NE")
			continue
		}
		for i := 0; i < len(ps[0]); i++ {
			if ps[0][i] != s[i] {
				flag = false
				break
			}
		}
		for i := 0; i < len(ps[1]); i++ {
			if ps[1][i] != s[len(s)-len(ps[1]):][i] {
				flag = false
				break
			}
		}
		if flag {
			fmt.Println("DA")
		} else {
			fmt.Println("NE")
		}
	}
}
