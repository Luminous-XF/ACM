package LeetCode2090

func getAverages(nums []int, k int) []int {
	n := len(nums)

	ans := make([]int, n)
	for i := range ans {
		ans[i] = -1
	}

	sum, length := int64(0), k*2+1
	for i, num := range nums {
		sum += int64(num)

		j := i - length + 1
		if j < 0 {
			continue
		}

		ans[i-k] = int(sum) / length

		sum -= int64(nums[j])
	}

	return ans
}
