package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()
	var n, m int
	fmt.Fscanln(reader, &n, &m)
	set := make(map[string]bool)
	for i := 0; i < n; i++ {
		var str string
		fmt.Fscanln(reader, &str)
		set[str] = true
	}
	cnt := 0
	for i := 0; i < m; i++ {
		var str string
		fmt.Fscanln(reader, &str)
		if _, exists := set[str]; exists {
			cnt++
		}
	}
	fmt.Fprintln(writer, cnt)
}
