package leetcode3336

import (
	"slices"
)


const (
	MOD = 1_000_000_007
)

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a % b)
}

func dfs(i, j, k int, dp [][][]int, nums []int) int {
	if i < 0 {
		if j == k {
			return 1
		}
		return 0
	}

	res := &dp[i][j][k]
	if *res == -1 {
		*res = (dfs(i - 1, j, k, dp, nums) + 
				dfs(i - 1, gcd(j, nums[i]), k, dp, nums) + 
				dfs(i - 1, j, gcd(k, nums[i]), dp, nums)) % MOD
	}

	return *res
}

func subsequencePairCount(nums []int) int {
	n, m := len(nums), slices.Max(nums)

	dp := make([][][]int, n)
	for i := range dp {
		dp[i] = make([][]int, m + 1)
		for j := range dp[i] {
			dp[i][j] = make([]int, m + 1)
			for k := range dp[i][j] {
				dp[i][j][k] = -1
			}
		}
	}

	return (dfs(n - 1, 0, 0, dp, nums) - 1 + MOD) % MOD
}