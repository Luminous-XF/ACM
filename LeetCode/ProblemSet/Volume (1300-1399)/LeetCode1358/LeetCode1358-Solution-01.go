package LeetCode1358

func numberOfSubstrings(s string) (ans int) {
	book := make(map[byte]int)
	n := len(s)
	for i, j := 0, 0; i < n; i++ {
		book[s[i]]++

		if book['a'] == 0 || book['b'] == 0 || book['c'] == 0 {
			continue
		}

		for book[s[j]] > 1 {
			book[s[j]]--
			j++
		}

		ans += j + 1
	}

	return
}
