package LeetCode2799

func countCompleteSubarrays(nums []int) (ans int) {
	set := make(map[int]struct{})
	for _, num := range nums {
		set[num] = struct{}{}
	}

	book := make(map[int]int)
	k, n := len(set), len(nums)
	for i, j := 0, 0; i < n; i++ {
		book[nums[i]]++

		if len(book) < k {
			continue
		}

		for len(book) > k || book[nums[j]] > 1 {
			book[nums[j]]--
			if book[nums[j]] == 0 {
				delete(book, nums[j])
			}
			j++
		}

		ans += j + 1
	}

	return
}
