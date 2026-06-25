package LeetCode1423

func maxScore01(cardPoints []int, k int) (ans int) {
	total := 0
	for _, v := range cardPoints {
		total += v
	}

	n := len(cardPoints)
	if k == n {
		return total
	}

	length, sum, minSum := n-k, 0, total
	for i, v := range cardPoints {
		sum += v

		j := i - length + 1
		if j < 0 {
			continue
		}

		minSum = min(minSum, sum)

		sum -= cardPoints[j]
	}

	ans = total - minSum

	return
}
