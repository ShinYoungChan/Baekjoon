package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var a, b float64
	var n int
	fmt.Fscanln(reader, &a, &b)
	fmt.Fscanln(reader, &n)
	var lst []float64
	lst = append(lst, math.Abs(a-b))
	for i := 0; i < n; i++ {
		var hz float64
		fmt.Fscanln(reader, &hz)
		lst = append(lst, math.Abs(b-hz)+1)
	}
	sort.Float64s(lst)
	fmt.Println(lst[0])
}
