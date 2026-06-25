package LeetCode1784

func checkOnesSegment01(s string) bool {
	n := len(s)

	i := -1
	for i+1 < n && s[i+1] == '1' {
		i++
	}

	j := n
	for j-1 >= 0 && s[j-1] == '0' {
		j--
	}

	return i+1 == j
}
