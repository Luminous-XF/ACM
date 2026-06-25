package LeetCode3325

func numberOfSubstrings(s string, k int) (ans int) {
	book := make(map[byte]int)
	cnt, n := 0, len(s)
	for i, j := 0, 0; i < n; i++ {
		book[s[i]]++
		if book[s[i]] == k {
			cnt++
		}

		if cnt == 0 {
			continue
		}

		for cnt > 1 || book[s[j]] != k {
			if book[s[j]] == k {
				cnt--
			}
			book[s[j]]--
			j++
		}

		ans += j + 1
	}

	return
}
