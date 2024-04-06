package main

import (
	"fmt"
	"math"
)

func err(exc string) {
	panic(exc)
}

func initVal() int {
	var val int
	_, err := fmt.Scanf("%d", &val)
	if err != nil || val <= 0 {
		panic("Invalid input") 
	}
	return val
}

func funcCalc(S, N, M int) int {
	if S*M > (S - S/7)*N {
		return -1
	}
	return int(math.Ceil(float64(S*M) / float64(N)))
}

func main() {
	S := initVal()
	N := initVal()
	M := initVal()

	fmt.Println(funcCalc(S, N, M))
}
