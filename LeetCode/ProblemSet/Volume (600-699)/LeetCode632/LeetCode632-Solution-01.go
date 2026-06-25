package LeetCode632

import (
	"sort"
)

type Pair struct {
	value int
	id    int
}

func smallestRange(nums [][]int) []int {
	v := make([]Pair, 0)
	for i, arr := range nums {
		for _, x := range arr {
			v = append(v, Pair{x, i})
		}
	}

	sort.Slice(v, func(i, j int) bool {
		if v[i].value != v[j].value {
			return v[i].value < v[j].value
		}
		return v[i].id < v[j].id
	})

	n := len(v)
	k, ansL, ansR := len(nums), v[0].value, v[n-1].value
	book := make(map[int]int)
	for i, j := 0, 0; i < n; i++ {
		book[v[i].id]++
		for book[v[j].id] > 1 {
			book[v[j].id]--
			j++
		}
		if len(book) == k && v[i].value-v[j].value < ansR-ansL {
			ansL = v[j].value
			ansR = v[i].value
		}
	}

	return []int{ansL, ansR}
}
