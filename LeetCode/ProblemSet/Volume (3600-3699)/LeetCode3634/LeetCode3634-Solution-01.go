package LeetCode3634

import "sort"

func minRemoval(nums []int, k int) (ans int) {
	sort.Ints(nums)

	length, n := 0, len(nums)
	for i, j := 0, 0; i < n; i++ {
		for nums[j]*k < nums[i] {
			j++
		}
		length = max(length, i-j+1)
	}

	ans = n - length

	return
}
