package LeetCode2841

func maxSum(nums []int, m int, k int) (ans int64) {
	book := make(map[int]int)
	sum := int64(0)
	for i, num := range nums {
		sum += int64(num)
		book[num]++

		j := i - k + 1
		if j < 0 {
			continue
		}

		if len(book) >= m {
			ans = max(ans, sum)
		}

		sum -= int64(nums[j])
		book[nums[j]]--
		if book[nums[j]] == 0 {
			delete(book, nums[j])
		}
	}

	return
}
