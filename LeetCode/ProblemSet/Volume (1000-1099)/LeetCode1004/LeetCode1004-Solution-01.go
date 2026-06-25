package LeetCode1004

func longestOnes(nums []int, k int) (ans int) {
	n := len(nums)
	cnt := make([]int, 2)
	for i, j := 0, 0; i < n; i++ {
		cnt[nums[i]]++
		for cnt[0] > k {
			cnt[nums[j]]--
			j++
		}
		ans = max(ans, i-j+1)
	}
	return
}
