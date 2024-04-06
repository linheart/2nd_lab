package main

import (
	"fmt"
)

func initVal() int {
	var val int
	_, err := fmt.Scanf("%d", &val)
	if err != nil || val <= 0 {
		panic("Invalid input")
	}
	return val
}

func cmp(arr []int, v int) {
	maxVal := 0
	for _, val := range arr {
		if val > maxVal {
			maxVal = val
		}
	}
	if v < maxVal {
		panic("The volume of the watering can is not enough to water the flower")
	}
}

func countingSteps(arr []int, v int) int {
	count := 0
	tmp := v

	for i, val := range arr {
		if tmp < val {
			tmp = v
			count += i * 2
		}
		count++
		tmp -= val
	}

	return count
}

func main() {
	n := initVal()

	arr := make([]int, n)
	for i := 0; i < n; i++ {
		arr[i] = initVal()
	}

	v := initVal()

	cmp(arr, v)

	fmt.Println(countingSteps(arr, v))
}
