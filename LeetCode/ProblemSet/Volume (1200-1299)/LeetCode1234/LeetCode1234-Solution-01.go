package LeetCode1234

func balancedString(s string) (ans int) {
	n, ans, k := len(s), len(s), len(s)/4

	book := make(map[byte]int)
	for _, c := range []byte(s) {
		book[c]++
	}

	if book['Q'] == k && book['W'] == k && book['E'] == k && book['R'] == k {
		return 0
	}

	for i, j := 0, 0; i < n; i++ {
		book[s[i]]--

		if book['Q'] > k || book['W'] > k || book['E'] > k || book['R'] > k {
			continue
		}

		for book[s[j]] < k {
			book[s[j]]++
			j++
		}

		ans = min(ans, i-j+1)
	}

	return
}
