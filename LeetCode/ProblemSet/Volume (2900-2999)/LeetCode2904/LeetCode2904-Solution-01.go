package LeetCode2904

func shortestBeautifulSubstring(s string, k int) (ans string) {
	n, cnt := len(s), 0
	for i, j := 0, 0; i < n; i++ {
		if s[i] == '1' {
			cnt++
		}

		if cnt < k {
			continue
		}

		for cnt > k || s[j] == '0' {
			if s[j] == '1' {
				cnt--
			}
			j++
		}

		length := i - j + 1
		if len(ans) == 0 || length < len(ans) {
			ans = s[j : i+1]
		} else if length == len(ans) {
			ans = min(ans, s[j:i+1])
		}
	}

	return
}
