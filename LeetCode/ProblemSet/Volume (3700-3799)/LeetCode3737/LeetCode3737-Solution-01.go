package leetcode3737

func countMajoritySubarrays(nums []int, target int) int {
	n, ans := len(nums), 0
	for i := 0; i < n; i++ {
		cnt := 0
		for j := i; j < n; j++ {
			if nums[j] == target {
				cnt++
			} else {
				cnt-- 
			}

			if cnt > 0 {
				ans++
			}
		}
	}

	return ans
}