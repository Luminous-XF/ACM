package LeetCode2962

import "slices"

func countSubarrays(nums []int, k int) (ans int64) {
	n, cnt, maxNum := len(nums), 0, slices.Max(nums)
	for i, j := 0, 0; i < n; i++ {
		if nums[i] == maxNum {
			cnt++
		}

		if cnt < k {
			continue
		}

		for nums[j] != maxNum || cnt > k {
			if nums[j] == maxNum {
				cnt--
			}
			j++
		}

		ans += int64(j + 1)
	}

	return
}
