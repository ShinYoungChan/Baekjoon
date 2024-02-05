package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	var n int
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanln(reader, &n)
	str := make([]string, n)
	for i := 0; i < n; i++ {
		fmt.Fscanln(reader, &str[i])
	}
	sort.Slice(str, func(i, j int) bool {
		if len(str[i]) == len(str[j]) {
			return str[i] < str[j]
		}
		return len(str[i]) < len(str[j])
	})
	fmt.Println(str[0])
	for i := 1; i < len(str); i++ {
		if str[i-1] == str[i] {
			continue
		}
		fmt.Println(str[i])
	}
}
