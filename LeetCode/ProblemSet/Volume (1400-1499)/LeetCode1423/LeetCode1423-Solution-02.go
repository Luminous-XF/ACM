package LeetCode1423

func maxScore02(cardPoints []int, k int) (ans int) {
	n, sufSum := len(cardPoints), 0
	for i := n - 1; i >= n-k; i-- {
		sufSum += cardPoints[i]
	}

	ans, preSum := sufSum, 0
	for i, j := 0, n-k; i < k && j < n; i, j = i+1, j+1 {
		preSum += cardPoints[i]
		sufSum -= cardPoints[j]
		ans = max(ans, preSum+sufSum)
	}

	return
}
