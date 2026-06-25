package LeetCode209

import "math"

func minSubArrayLen(target int, nums []int) (ans int) {
	n, sum, ans := len(nums), 0, math.MaxInt
	for i, j := 0, 0; i < n; i++ {
		sum += nums[i]
		for sum-nums[j] >= target {
			sum -= nums[j]
			j++
		}

		if sum >= target {
			ans = min(ans, i-j+1)
		}
	}

	if ans == math.MaxInt {
		ans = 0
	}

	return
}
