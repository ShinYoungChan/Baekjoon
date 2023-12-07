package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

var ans []string
var sign []string
var k int

func dfs(num string, depth int) {
	if depth == k {
		ans = append(ans, num)
		return
	}
	div, _ := strconv.Atoi(num)
	div = div % 10
	for i := 0; i < 10; i++ {
		if sign[depth] == ">" && div > i {
			if !strings.Contains(num, strconv.Itoa(i)) {
				dfs(num+strconv.Itoa(i), depth+1)
			}
		}
		if sign[depth] == "<" && div < i {
			if !strings.Contains(num, strconv.Itoa(i)) {
				dfs(num+strconv.Itoa(i), depth+1)
			}
		}
	}
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanln(reader, &k)
	sign = make([]string, k)
	for i := 0; i < k; i++ {
		fmt.Fscan(reader, &sign[i])
	}
	for i := 0; i < 10; i++ {
		dfs(strconv.Itoa(i), 0)
	}
	sort.Strings(ans)
	fmt.Printf("%s\n%s\n", ans[len(ans)-1], ans[0])
}
