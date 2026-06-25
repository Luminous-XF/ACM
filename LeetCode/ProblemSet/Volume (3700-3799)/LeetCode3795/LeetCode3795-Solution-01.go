package LeetCode3795

import "math"

func minLength(nums []int, k int) (ans int) {
	book := make(map[int]int)
	n, sum, ans := len(nums), 0, math.MaxInt
	for i, j := 0, 0; i < n; i++ {
		if book[nums[i]] == 0 {
			sum += nums[i]
		}
		book[nums[i]]++

		for sum-nums[j] >= k || book[nums[j]] > 1 {
			book[nums[j]]--
			if book[nums[j]] == 0 {
				sum -= nums[j]
			}
			j++
		}

		if sum >= k {
			ans = min(ans, i-j+1)
		}
	}

	if ans == math.MaxInt {
		ans = -1
	}

	return
}
