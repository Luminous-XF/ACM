package LeetCode1343

func numOfSubarrays(arr []int, k int, threshold int) (ans int) {
	sum, threshold := 0, threshold*k
	for i, v := range arr {
		sum += v

		j := i - k + 1
		if j < 0 {
			continue
		}

		if sum >= threshold {
			ans++
		}

		sum -= arr[j]
	}

	return
}
