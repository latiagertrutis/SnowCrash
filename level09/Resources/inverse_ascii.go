package main

import (
	"fmt"
	"os"
)

func main() {
	if len(os.Args) != 2 {
		fmt.Printf("Give just one token")
		os.Exit(1)
	}

	for i, c := range []byte(os.Args[1]) {
		fmt.Printf("%c",int(c) + i)
	}
}
