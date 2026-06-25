package LeetCode1208

import (
	"math"
)

func equalSubstring(s string, t string, maxCost int) (ans int) {
	cost, n := 0, len(s)
	for i, j := 0, 0; i < n; i++ {
		cost += int(math.Abs(float64(int(s[i]) - int(t[i]))))
		for cost > maxCost {
			cost -= int(math.Abs(float64(int(s[j]) - int(t[j]))))
			j++
		}

		ans = max(ans, i-j+1)
	}
	return
}
