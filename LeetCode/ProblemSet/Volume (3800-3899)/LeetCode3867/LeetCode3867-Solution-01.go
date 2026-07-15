package leetcode3867

import (
	"sort"
)

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func gcdSum(nums []int) int64 {
	n, maxNum := len(nums), 0
	for i := 0; i < n; i++ {
		maxNum = max(maxNum, nums[i])
		nums[i] = gcd(nums[i], maxNum)
	}

	sort.Ints(nums)

	i, j, sum := 0, n - 1, 0
	for i < j {
		sum += gcd(nums[i], nums[j])
		i++
		j--
	}
	
	return int64(sum)
}