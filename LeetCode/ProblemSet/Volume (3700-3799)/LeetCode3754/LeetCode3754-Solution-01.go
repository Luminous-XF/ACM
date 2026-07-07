package leetcode3754

func sumAndMultiply(n int) int64 {
	if n == 0 {
		return 0
	}	

	x, sum, k := int64(0), int64(0), int64(1)
	for n > 0 {
		v := int64(n % 10)
		n /= 10

		if (v == 0) {
			continue
		}

		sum += v
		x += v * k
		k *= 10
	}

	return x * sum
}