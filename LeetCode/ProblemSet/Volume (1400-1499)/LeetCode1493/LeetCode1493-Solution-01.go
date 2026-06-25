package LeetCode1493

func longestSubarray(nums []int) (ans int) {
	cnt1, cnt2, n := 0, 0, len(nums)
	for i, j := 0, 0; i < n; i++ {
		if nums[i] == 1 {
			cnt1++
		} else {
			cnt2++
			for cnt2 > 1 {
				if nums[j] == 1 {
					cnt1--
				} else {
					cnt2--
				}
				j++
			}
		}

		if cnt2 == 0 {
			ans = max(ans, cnt1-1)
		} else {
			ans = max(ans, cnt1)
		}
	}

	return
}
