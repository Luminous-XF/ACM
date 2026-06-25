// TODO: MLE

package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n int
	fmt.Fscan(in, &n)

	ans, cnt := 0, 0
	for i := 0; i < n; i++ {
		var v int
		fmt.Fscan(in, &v)

		if cnt == 0 {
			ans = v
		}

		if v == ans {
			cnt++
		} else {
			cnt--
		}
	}

	fmt.Fprintf(out, "%d\n", ans)
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	solve(in, out)
}
