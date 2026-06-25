package LeetCode1695

func maximumUniqueSubarray(nums []int) (ans int) {
	set := make(map[int]bool)
	sum, n := 0, len(nums)
	for i, j := 0, 0; i < n; i++ {
		for set[nums[i]] {
			sum -= nums[j]
			set[nums[j]] = false
			j++
		}
		sum += nums[i]
		set[nums[i]] = true
		ans = max(ans, sum)
	}
	return
}
