package LeetCode2958

func maxSubarrayLength(nums []int, k int) (ans int) {
	book := make(map[int]int)
	n := len(nums)
	for i, j := 0, 0; i < n; i++ {
		book[nums[i]]++
		for book[nums[i]] > k {
			book[nums[j]]--
			j++
		}
		ans = max(ans, i-j+1)
	}
	return
}
