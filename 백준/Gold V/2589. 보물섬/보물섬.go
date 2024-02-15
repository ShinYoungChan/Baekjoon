package main

import (
	"fmt"
)

type coor struct {
	x   int
	y   int
	cnt int
}

var n, m int
var land []string
var dxdy [4][2]int = [4][2]int{{-1, 0}, {0, -1}, {1, 0}, {0, 1}}

func bfs(i, j int) int {
	visit := [50][50]bool{}
	q := []coor{}
	visit[i][j] = true
	q = append(q, coor{i, j, 0})
	ans := 0
	for len(q) > 0 {
		x, y, cnt := q[0].x, q[0].y, q[0].cnt
		q = q[1:]
		if ans < cnt {
			ans = cnt
		}
		for k := 0; k < 4; k++ {
			nx := x + dxdy[k][0]
			ny := y + dxdy[k][1]
			if nx < 0 || nx > n-1 || ny < 0 || ny > m-1 || visit[nx][ny] || land[nx][ny] == 'W' {
				continue
			}
			visit[nx][ny] = true
			q = append(q, coor{nx, ny, cnt + 1})
		}
	}
	return ans
}

func main() {
	fmt.Scanln(&n, &m)

	for i := 0; i < n; i++ {
		var str string
		fmt.Scanln(&str)
		land = append(land, str)
	}
	ans := 0
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if land[i][j] == 'L' {
				cnt := bfs(i, j)
				if ans < cnt {
					ans = cnt
				}
			}
		}
	}
	fmt.Println(ans)
}
