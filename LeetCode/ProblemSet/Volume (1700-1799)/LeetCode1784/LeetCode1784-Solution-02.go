package LeetCode1784

import "strings"

func checkOnesSegment02(s string) bool {
	return !strings.Contains(s, "01")
}
