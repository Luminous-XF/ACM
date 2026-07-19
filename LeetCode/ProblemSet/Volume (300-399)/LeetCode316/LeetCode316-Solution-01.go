package leetcode316

import "sort"

func removeDuplicateLetters_01(s string) string {
	book := make([][]int, 26)
	for i := range book {
		book[i] = make([]int, 0)
	}

	for i, c := range s {
		j := int(c - 'a')
		book[j] = append(book[j], i)
	}

	length := 0
	for _, v := range book {
		if len(v) > 0 {
			length++
		}
	}

	pre, ans := -1, make([]byte, length)
	for i := 0; i < length; i++ {
		for j := 0; j < 26; j++ {
			if len(book[j]) == 0 {
				continue
			}

			ok := true
			idx := book[j][sort.Search(len(book[j]), func(idx int) bool {
				return book[j][idx] > pre
			})]

			for k := 0; k < 26; k++ {
				if len(book[k]) == 0 || j == k {
					continue
				}

				if book[k][len(book[k])-1] < idx {
					ok = false
					break
				}
			}

			if ok {
				pre = idx
				ans[i] = byte('a' + j)
				book[j] = nil
				break
			}
		}
	}

	return string(ans)
}
