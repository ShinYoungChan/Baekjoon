package main

import (
	"container/list"
	"fmt"
)

func check(str string) bool {
	strList := list.New()
	for i := 0; i < len(str); i++ {
		if str[i] == '(' {
			strList.PushBack(str[i])
		} else {
			if strList.Len() == 0 {
				return false
			}
			strList.Remove(strList.Back())
		}
	}
	if strList.Len() > 0 {
		return false
	}
	return true
}

func main() {
	var n int
	fmt.Scanln(&n)
	str := make([]string, n)
	for i := 0; i < n; i++ {
		fmt.Scanln(&str[i])
	}
	for i := 0; i < n; i++ {
		if check(str[i]) {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}
