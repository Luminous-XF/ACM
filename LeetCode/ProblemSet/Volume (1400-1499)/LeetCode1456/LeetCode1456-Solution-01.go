package LeetCode1456

func maxVowels(s string, k int) (ans int) {
	set := map[byte]bool{
		'a': true,
		'e': true,
		'i': true,
		'o': true,
		'u': true,
	}

	cnt := 0
	for i, c := range s {
		if set[byte(c)] {
			cnt++
		}

		j := i - k + 1
		if j < 0 {
			continue
		}

		ans = max(ans, cnt)

		if set[s[j]] {
			cnt--
		}
	}

	return
}
