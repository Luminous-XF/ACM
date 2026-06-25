package LeetCode2730

func longestSemiRepetitiveSubstring(s string) (ans int) {
	cnt, ans, n := 0, 1, len(s)
	for i, j := 1, 0; i < n; i++ {
		if s[i] == s[i-1] {
			cnt++
		}

		for cnt > 0 {
			if s[j] == s[j+1] {
				cnt--
			}
			j++
		}

		ans = max(ans, i-j+1)
	}

	return
}
