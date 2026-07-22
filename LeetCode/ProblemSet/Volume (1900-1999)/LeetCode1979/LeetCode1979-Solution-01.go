package leetcode1979

import "slices"

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func findGCD(nums []int) int {
	return gcd(slices.Min(nums), slices.Max(nums))
}