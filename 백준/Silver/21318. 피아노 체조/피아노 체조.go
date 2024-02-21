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
	var n, q int
	fmt.Fscan(reader, &n)
	music, sum := make([]int, n), make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &music[i])
	}

	for i := 1; i < n; i++ {
		if music[i-1] > music[i] {
			sum[i] = sum[i-1] + 1
		} else {
			sum[i] = sum[i-1]
		}
	}

	fmt.Fscan(reader, &q)

	for i := 0; i < q; i++ {
		var x, y int
		fmt.Fscan(reader, &x, &y)
		if x == y {
			fmt.Fprintln(writer, 0)
		} else {
			fmt.Fprintln(writer, sum[y-1]-sum[x-1])
		}
	}

}
