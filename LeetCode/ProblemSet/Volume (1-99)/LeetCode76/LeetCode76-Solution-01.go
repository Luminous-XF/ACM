package LeetCode76

import "math"

func minWindow(s string, t string) string {
	bookT := make(map[byte]int)
	for _, ch := range []byte(t) {
		bookT[ch]++
	}

	book := make(map[byte]int)
	minLen, idx, n := math.MaxInt, -1, len(s)
	for i, j := 0, 0; i < n; i++ {
		book[s[i]]++
		for j < i && book[s[j]] > bookT[s[j]] {
			book[s[j]]--
			j++
		}

		ok := true
		for ch, cnt := range bookT {
			if book[ch] < cnt {
				ok = false
				break
			}
		}

		length := i - j + 1
		if ok && length < minLen {
			minLen = length
			idx = j
		}
	}

	if minLen == math.MaxInt {
		return ""
	}

	return s[idx : idx+minLen]
}
