package LeetCode713

func numSubarrayProductLessThanK(nums []int, k int) (ans int) {
	if k == 0 {
		return 0
	}

	res, n := 1, len(nums)
	for i, j := 0, 0; i < n; i++ {
		res *= nums[i]
		for j <= i && res >= k {
			res /= nums[j]
			j++
		}
		ans += i - j + 1
	}
	return
}
