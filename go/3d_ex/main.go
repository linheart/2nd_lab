package main

import (
	"fmt"
)

func initVal() int {
	var val int
	_, err := fmt.Scanf("%d", &val)
	if err != nil {
		panic("Invalid input")
	}
	return val
}

func countingDup(n int) int {
	a := initVal()
	b := a
	count := 0

	for i := 1; i < n; i++ {
		a = initVal()
		if a == b {
			count++
		}
		b = a
	}

	return count
}

func main() {
	n := initVal()
	if n <= 0 {
		panic("Invalid input")
	}

	fmt.Println(countingDup(n))
}
