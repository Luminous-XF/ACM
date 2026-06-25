package LeetCode3

func lengthOfLongestSubstring(s string) (ans int) {
	set := make(map[byte]bool)
	n := len(s)
	for i, j := 0, 0; i < n; i++ {
		for set[s[i]] {
			set[s[j]] = false
			j++
		}

		set[s[i]] = true

		ans = max(ans, i-j+1)
	}

	return
}
