package LeetCode2379

func minimumRecolors(blocks string, k int) (ans int) {

	cnt, maxCnt := 0, 0
	for i, c := range blocks {
		if c == 'B' {
			cnt++
		}

		j := i - k + 1
		if j < 0 {
			continue
		}

		maxCnt = max(maxCnt, cnt)

		if blocks[j] == 'B' {
			cnt--
		}
	}

	ans = k - maxCnt

	return
}
