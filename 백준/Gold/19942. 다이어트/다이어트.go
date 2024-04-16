package main

import (
	"bufio"
	"fmt"
	"os"
)

type Ingredient struct {
	protein      int //단백질
	fat          int //지방
	carbohydrate int //탄수화물
	vitamin      int //비타민
	price        int //가격
}

var n, p, f, c, v int
var arr []Ingredient
var ans []int
var max = 10000

func dfs(asd []int, idx, pi, fi, ci, vi, pSum int) {
	if pi >= p && fi >= f && ci >= c && vi >= v {
		if max > pSum {
			max = pSum
			ans = make([]int, len(asd))
			copy(ans, asd)
		} else if max == pSum {
			length := 0
			if len(ans) > len(asd) {
				length = len(asd)
			} else {
				length = len(asd)
			}
			flag := false
			for i := 0; i < length; i++ {
				if ans[i] > asd[i] {
					flag = true
					break
				}
			}
			if flag {
				ans = make([]int, len(asd))
				copy(ans, asd)
			}
		}
		return
	}
	if idx >= n {
		return
	}
	// 현재 인덱스를 고르지않을때
	dfs(asd, idx+1, pi, fi, ci, vi, pSum)
	asd = append(asd, idx+1)
	// 현재 인덱스를 고를때
	dfs(asd, idx+1, pi+arr[idx].protein, fi+arr[idx].fat, ci+arr[idx].carbohydrate, vi+arr[idx].vitamin, pSum+arr[idx].price)
	asd = asd[0 : len(asd)-1]
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()
	fmt.Fscanln(reader, &n)
	fmt.Fscanln(reader, &p, &f, &c, &v)
	for i := 0; i < n; i++ {
		var a, b, c, d, e int
		fmt.Fscanln(reader, &a, &b, &c, &d, &e)
		arr = append(arr, Ingredient{protein: a, fat: b, carbohydrate: c, vitamin: d, price: e})
	}
	var asd []int
	dfs(asd, 0, 0, 0, 0, 0, 0)
	if max == 10000 {
		fmt.Fprintln(writer, -1)
	} else {
		fmt.Fprintln(writer, max)
		for _, val := range ans {
			fmt.Fprintf(writer, "%d ", val)
		}
	}

}
