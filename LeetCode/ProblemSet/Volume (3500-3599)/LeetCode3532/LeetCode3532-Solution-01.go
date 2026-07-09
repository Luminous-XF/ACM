package leetcode3532

func pathExistenceQueries(n int, nums []int, maxDiff int, queries [][]int) []bool {
	pre := make([]int, n)
	pre[0] = 0
	for i := 1; i < n; i++ {
		if nums[i] - nums[i - 1] <= maxDiff {
			pre[i] = pre[i - 1] + 1
		} else {
			pre[i] = pre[i - 1]
		}
	}

	ans := make([]bool, len(queries))
	for i, query := range queries {
		u, v := query[0], query[1]
		ans[i] = pre[v] - pre[u] == v - u
	}

	return ans
}