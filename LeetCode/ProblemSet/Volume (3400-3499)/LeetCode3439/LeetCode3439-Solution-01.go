package LeetCode3439

func maxFreeTime(eventTime int, k int, startTime []int, endTime []int) (ans int) {
	n := len(startTime)

	freeTime := getLeftFreeTime(0, startTime, endTime)
	ans = freeTime
	for i := 0; i < n; i++ {
		freeTime += getRightFreeTime(i, n, eventTime, startTime, endTime)

		ans = max(ans, freeTime)

		j := i - k + 1
		if j >= 0 {
			freeTime -= getLeftFreeTime(j, startTime, endTime)
		}
	}

	return
}

func getLeftFreeTime(i int, startTime []int, endTime []int) int {
	if i == 0 {
		return startTime[i] - 0
	}
	return startTime[i] - endTime[i-1]
}

func getRightFreeTime(i, n, eventTime int, startTime []int, endTime []int) int {
	if i == n-1 {
		return eventTime - endTime[i]
	}
	return startTime[i+1] - endTime[i]
}
