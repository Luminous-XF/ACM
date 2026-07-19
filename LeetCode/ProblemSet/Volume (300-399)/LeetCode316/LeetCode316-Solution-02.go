package leetcode316

func removeDuplicateLetters_02(s string) string {
	cnt := make(map[rune]int)
	for _, c := range s {
		cnt[c]++
	}

	book := make(map[rune]struct{})
	ans := make([]rune, 0)
	for _, c := range s {
		cnt[c]--
		if _, exist := book[c]; exist {
			continue
		}

		for len(ans) > 0 && c < ans[len(ans)-1] && cnt[ans[len(ans)-1]] > 0 {
			delete(book, ans[len(ans)-1])
			ans = ans[:len(ans)-1]
		}

		ans = append(ans, c)
		book[c] = struct{}{}
	}

	return string(ans)
}
