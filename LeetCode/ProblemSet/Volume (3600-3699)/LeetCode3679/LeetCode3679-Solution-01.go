package LeetCode3679

func minArrivalsToDiscard(arrivals []int, w int, m int) (ans int) {
	n := len(arrivals)
	vis := make([]bool, n)
	book := make(map[int]int)

	for i, v := range arrivals {
		if book[v] < m {
			book[v]++
		} else {
			ans++
			vis[i] = true
		}

		j := i - w + 1
		if j >= 0 && !vis[j] {
			book[arrivals[j]]--
		}
	}

	return
}
