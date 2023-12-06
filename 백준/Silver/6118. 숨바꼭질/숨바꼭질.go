package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

type result struct {
	current  int
	distance int
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	var n, m int
	fmt.Fscanln(reader, &n, &m)
	adj := make([][]int, n+1)
	for i := 1; i <= n; i++ {
		adj[i] = make([]int, 0)
	}
	for i := 0; i < m; i++ {
		var n1, n2 int
		fmt.Fscanln(reader, &n1, &n2)
		adj[n1] = append(adj[n1], n2)
		adj[n2] = append(adj[n2], n1)
	}
	check := make([]bool, n+1)
	q := []result{{current: 1, distance: 0}}
	maxDist := 0
	var lst []int
	check[1] = true
	for len(q) != 0 {
		curr := q[0].current
		dist := q[0].distance
		q = q[1:]
		if maxDist == dist {
			lst = append(lst, curr)
		} else if maxDist < dist {
			//lst = []int{}
			lst = make([]int, 0)
			lst = append(lst, curr)
			maxDist = dist
		}
		for _, next := range adj[curr] {
			if !check[next] {
				q = append(q, result{current: next, distance: dist + 1})
				check[next] = true
			}
		}
	}
	sort.Ints(lst)
	fmt.Println(lst[0], maxDist, len(lst))
}
