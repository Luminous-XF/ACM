package LeetCode2779

import "sort"

func maximumBeauty(nums []int, k int) (ans int) {
	sort.Ints(nums)
	n := len(nums)
	for i, j := 0, 0; i < n; i++ {
		for nums[j]+k < nums[i]-k {
			j++
		}
		ans = max(ans, i-j+1)
	}
	return
}
