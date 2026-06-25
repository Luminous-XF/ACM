package LeetCode904

func totalFruit(fruits []int) (ans int) {
	book := make(map[int]int)
	cnt, n := 0, len(fruits)
	for i, j := 0, 0; i < n; i++ {
		book[fruits[i]]++
		cnt++
		for len(book) > 2 {
			book[fruits[j]]--
			cnt--
			if book[fruits[j]] == 0 {
				delete(book, fruits[j])
			}
			j++
		}
		ans = max(ans, cnt)
	}
	return
}
