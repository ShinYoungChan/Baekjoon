package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var n int
	fmt.Fscanln(reader, &n)
	book := make(map[string]int)
	for i := 0; i < n; i++ {
		var str string
		fmt.Fscanln(reader, &str)
		book[str] += 1
	}
	sortedKey := make([]string, 0)
	for key := range book {
		sortedKey = append(sortedKey, key)
	}
	max := 0
	var best string
	sort.Strings(sortedKey)
	for _, key := range sortedKey {
		if max < book[key] {
			max = book[key]
			best = key
		}
	}
	fmt.Println(best)
}
