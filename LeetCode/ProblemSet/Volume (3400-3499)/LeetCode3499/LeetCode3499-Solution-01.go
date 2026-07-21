package leetcode3499

import "math"

func maxActiveSectionsAfterTrade(s string) int {
	pre, cnt, maxEx, total := math.MinInt, 0, 0, 0
	for i, c := range s {
		cnt++
		if i == len(s) - 1 || s[i] != s[i + 1] {
			if c == '1' {
				total += cnt
			} else {
				maxEx = max(maxEx, pre + cnt)
				pre = cnt
			}
			cnt = 0
		}
	}

	return total + maxEx
}