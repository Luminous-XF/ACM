package LeetCode3090

func maximumLengthSubstring(s string) (ans int) {
	book := make(map[byte]int)
	n := len(s)
	for i, j := 0, 0; i < n; i++ {
		for book[s[i]] >= 2 {
			book[s[j]]--
			j++
		}

		book[s[i]]++

		ans = max(ans, i-j+1)
	}

	return
}
