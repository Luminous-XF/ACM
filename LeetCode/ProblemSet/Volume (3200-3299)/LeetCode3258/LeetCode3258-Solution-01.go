package LeetCode3258

func countKConstraintSubstrings(s string, k int) (ans int) {
	cnt0, cnt1, n := 0, 0, len(s)
	for i, j := 0, 0; i < n; i++ {
		if s[i] == '0' {
			cnt0++
		} else {
			cnt1++
		}

		for j <= i && cnt0 > k && cnt1 > k {
			if s[j] == '0' {
				cnt0--
			} else {
				cnt1--
			}
			j++
		}

		ans += i - j + 1
	}

	return
}
