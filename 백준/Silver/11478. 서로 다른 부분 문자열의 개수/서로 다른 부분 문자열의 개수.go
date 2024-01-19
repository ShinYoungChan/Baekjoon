package main

import "fmt"

func main() {
	var str string
	set := make(map[string]bool)
	fmt.Scanln(&str)
	for i := 0; i < len(str); i++ {
		for j := i + 1; j < len(str)+1; j++ {
			set[str[i:j]] = true
		}
	}
	fmt.Println(len(set))
}
