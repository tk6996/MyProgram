package main

import (
	"fmt"
	"strings"
)

func add(a, b int) int {
	return a + b
}

func swap_word(a, b string) (string, string) {
	return b, a
}

func printNum(n int) {
	for i := 1; i <= n; i++ {
		fmt.Println(i)
	}
}

func main() {
	// var a, b string = "Hello", "World"
	// c, d := swap_word(a, b)
	// fmt.Print(c, " ", d)
	// if x, y := 1, 2; x < y {
	// 	printNum(10)
	// }
	fmt.Println(len(strings.Split("Hello A World", " ")))

}
