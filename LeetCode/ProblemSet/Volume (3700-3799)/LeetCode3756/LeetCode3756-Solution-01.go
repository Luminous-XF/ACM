package leetcode3756

const MOD = 1e9 + 7

func sumAndMultiply(s string, queries [][]int) []int {
	type Info struct {
		x int
		sum int
		cnt int
	}

    n, pre := len(s), make([]Info, len(s))
	pre[0] = Info{int(s[0] - '0'), int(s[0] - '0'), 0}
	if s[0] != '0' {
		pre[0].cnt = 1
	}

	for i := 1; i < n; i++ {
		digit := int(s[i] - '0')

		if digit == 0 {
			pre[i] = pre[i - 1]
			continue
		}

		pre[i].sum = pre[i - 1].sum + digit
		pre[i].cnt = pre[i - 1].cnt + 1
		pre[i].x = (pre[i - 1].x * 10 + digit) % MOD
	}

	pow10 := make([]int, n + 1)
	pow10[0] = 1
	for i := 1; i <= n; i++ {
		pow10[i] = pow10[i - 1] * 10 % MOD
	}

	ans := make([]int, len(queries))
	for i, query := range queries {
		l, r := query[0], query[1]

		if l == 0 {
			ans[i] = pre[r].x * pre[r].sum % MOD
			continue
		}

		sum := pre[r].sum - pre[l - 1].sum
		cnt := pre[r].cnt - pre[l - 1].cnt
		x := (pre[r].x - pre[l - 1].x * pow10[cnt] % MOD + MOD) % MOD
		ans[i] = x * sum % MOD
	}

	return ans
}