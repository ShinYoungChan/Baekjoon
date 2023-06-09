package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var str string
	fmt.Fscanln(reader, &str)
	loopstart := 0
	for k := 0; k < len(str); k++ {
		check := true
		for i, j := k, len(str)-1; i < len(str); i++ {
			if str[i] != str[j] {
				check = false
				break
			}
			j--
		}
		if check {
			loopstart = k
			break
		}
	}
	for i := loopstart - 1; i >= 0; i-- {
		str += string(str[i])
	}
	fmt.Println(len(str))
}
