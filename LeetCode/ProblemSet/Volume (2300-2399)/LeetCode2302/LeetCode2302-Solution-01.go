package LeetCode2302

func countSubarrays(nums []int, k int64) (ans int64) {
	sum, n := int64(0), len(nums)
	for i, j := 0, 0; i < n; i++ {
		sum += int64(nums[i])
		for j <= i && sum*int64(i-j+1) >= k {
			sum -= int64(nums[j])
			j++
		}
		ans += int64(i - j + 1)
	}
	return
}
