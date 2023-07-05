package main

import (
	"bufio"
	"fmt"
	"os"
)

type coordinate struct {
	x int
	y int
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	var n, m int
	var q []coordinate
	fmt.Fscanln(reader, &n, &m)
	check := make([][]bool, n)
	arr := make([][]rune, n)
	for i := 0; i < n; i++ {
		check[i] = make([]bool, m)
		arr[i] = make([]rune, m)
	}
	for i := 0; i < n; i++ {
		var str string
		fmt.Fscanln(reader, &str)
		for j := 0; j < len(str); j++ {
			arr[i][j] = rune(str[j])
			if arr[i][j] == 'I' {
				q = append(q, coordinate{x: i, y: j})
			}
		}
	}
	count := 0
	dxdy := [4][2]int{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}
	for len(q) != 0 {
		curr := q[0]
		q = q[1:]
		for i := 0; i < 4; i++ {
			mx := curr.x + dxdy[i][0]
			my := curr.y + dxdy[i][1]
			if mx < 0 || mx > n-1 || my < 0 || my > m-1 {
				continue
			}
			if check[mx][my] == false && (arr[mx][my] == 'P' || arr[mx][my] == 'O') {
				if arr[mx][my] == 'P' {
					count++
				}
				q = append(q, coordinate{x: mx, y: my})
				check[mx][my] = true
			}
		}
	}
	if count != 0 {
		fmt.Println(count)
	} else {
		fmt.Println("TT")
	}

}
