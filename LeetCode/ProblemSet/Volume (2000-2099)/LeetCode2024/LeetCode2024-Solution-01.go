package LeetCode2024

func maxConsecutiveAnswers(answerKey string, k int) (ans int) {
	n, cntT, cntF := len(answerKey), 0, 0
	for i, j := 0, 0; i < n; i++ {
		if answerKey[i] == 'T' {
			cntT++
		} else {
			cntF++
		}

		for min(cntT, cntF) > k {
			if answerKey[j] == 'T' {
				cntT--
			} else {
				cntF--
			}
			j++
		}

		ans = max(ans, i-j+1)
	}

	return
}
