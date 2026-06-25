package LeetCode2875

import "math"

func minSizeSubarray(nums []int, target int) (ans int) {
	n, total := len(nums), 0
	for _, num := range nums {
		total += num
	}

	ans = target / total * n
	target %= total

	minLen, sum := math.MaxInt, 0
	for i, j := 0, 0; i < n*2; i++ {
		sum += nums[i%n]

		for sum > target {
			sum -= nums[j%n]
			j++
		}

		if sum == target {
			minLen = min(minLen, i-j+1)
		}
	}

	if minLen == math.MaxInt {
		return -1
	}

	ans += minLen

	return
}
