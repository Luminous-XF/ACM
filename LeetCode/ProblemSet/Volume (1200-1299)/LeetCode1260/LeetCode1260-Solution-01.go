package leetcode1260

func shiftGrid(grid [][]int, k int) [][]int {
	n, m := len(grid), len(grid[0])

	ans := make([][]int, n)
	for i := range ans {
		ans[i] = make([]int, m)
	}

	total := n * m
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			id := (i*m + j + k) % total
			ans[id/m][id%m] = grid[i][j]
		}
	}

	return ans
}
