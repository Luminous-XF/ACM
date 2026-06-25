package LeetCode1888

func minFlips(s string) (ans int) {
	n := len(s)

	first0, first1 := 0, 0
	for i, c := range s {
		if (i & 1) == 0 {
			if c == '0' {
				first1++
			} else {
				first0++
			}
		} else {
			if c == '0' {
				first0++
			} else {
				first1++
			}
		}
	}

	ans = min(first0, first1)
	second0, second1 := 0, 0
	for i, c := range s {
		if (i & 1) == 0 {
			if c == '0' {
				first1--
				second1++
			} else {
				first0--
				second0++
			}

			if ((n - i - 1) & 1) == 0 {
				ans = min(ans, first0+second1)
				ans = min(ans, first1+second0)
			} else {
				ans = min(ans, first0+second0)
				ans = min(ans, first1+second1)
			}
		} else {
			if c == '0' {
				first0--
				second0++
			} else {
				first1--
				second1++
			}

			if ((n - i - 1) & 1) == 0 {
				ans = min(ans, first0+second0)
				ans = min(ans, first1+second1)
			} else {
				ans = min(ans, first0+second1)
				ans = min(ans, first1+second0)
			}
		}
	}

	return
}
