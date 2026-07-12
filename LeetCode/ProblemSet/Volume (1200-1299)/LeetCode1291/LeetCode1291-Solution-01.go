package leetcode1291

import (
	"sort"
)

func sequentialDigits(low int, high int) []int {
	ans := make([]int, 0)
	for i := 1; i < 10; i++ {
		res := 0
		for j := i; j < 10; j++ {
			res = res * 10 + j
			if low <= res && res <= high {
				ans = append(ans, res)
			}
		}
	}

	sort.Ints(ans)

	return ans
}