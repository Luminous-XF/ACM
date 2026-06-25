package LeetCode643

func findMaxAverage(nums []int, k int) (ans float64) {
	ans, sum := -1e4+10, float64(0)
	for i, num := range nums {
		sum += float64(num)

		j := i - k + 1
		if j < 0 {
			continue
		}

		avg := sum / float64(k)
		ans = max(ans, avg)

		sum -= float64(nums[j])
	}

	return
}
