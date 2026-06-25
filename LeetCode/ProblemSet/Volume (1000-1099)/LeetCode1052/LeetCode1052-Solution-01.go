package LeetCode1052

func maxSatisfied(customers []int, grumpy []int, minutes int) (ans int) {
	ans1, ans2, sum := 0, 0, 0
	for i, v := range customers {
		if grumpy[i] == 0 {
			ans1 += v
		} else {
			sum += v
		}

		j := i - minutes + 1
		if j < 0 {
			continue
		}

		ans2 = max(ans2, sum)

		if grumpy[j] == 1 {
			sum -= customers[j]
		}
	}

	ans = ans1 + ans2

	return
}
