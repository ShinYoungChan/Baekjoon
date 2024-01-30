package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

type coordinate struct {
	x     int
	y     int
	check bool
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	var test int
	fmt.Fscanln(reader, &test)
	for i := 0; i < test; i++ {
		var sx, sy, ex, ey, n int
		fmt.Fscanln(reader, &n)
		fmt.Fscanln(reader, &sx, &sy)
		var coor []coordinate
		for j := 0; j < n; j++ {
			var x1, y1 int
			fmt.Fscanln(reader, &x1, &y1)
			coor = append(coor, coordinate{x: x1, y: y1, check: false})
		}
		fmt.Fscanln(reader, &ex, &ey)
		coor = append(coor, coordinate{x: ex, y: ey, check: false})
		q := []coordinate{{x: sx, y: sy, check: true}}
		happy := false
		for len(q) != 0 {
			curr := q[0]
			q = q[1:]
			if curr.x == ex && curr.y == ey {
				happy = true
				break
			}
			for i := 0; i < len(coor); i++ {
				if (math.Abs(float64(coor[i].x-curr.x))+math.Abs(float64(coor[i].y-curr.y)) <= float64(1000)) && coor[i].check == false {
					coor[i].check = true
					q = append(q, coor[i])
				}
			}
		}
		if happy {
			fmt.Println("happy")
		} else {
			fmt.Println("sad")
		}
	}
}
