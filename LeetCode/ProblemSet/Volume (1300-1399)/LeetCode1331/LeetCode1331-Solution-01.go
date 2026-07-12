package leetcode1331

import (
	"sort"
)

func arrayRankTransform(arr []int) []int {
	a := append([]int{}, arr...)
	sort.Ints(a)

	book := make(map[int]int)
	for _, v := range a {
		if _, exist := book[v]; !exist {
			book[v] = len(book) + 1
		}
	}

	ans := make([]int, len(arr))
	for i, v := range arr {
		ans[i] = book[v]
	}

	return ans
}