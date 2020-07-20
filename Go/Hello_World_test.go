package main

import (
	"testing"
)

func Test_printNum(t *testing.T) {
	type args struct {
		n int
	}
	tests := []struct {
		name string
		args args
	}{
		{name: "TC-1", args: args{n: 1}},
		{name: "TC-2", args: args{n: 2}},
		{name: "TC-3", args: args{n: 3}},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			printNum(tt.args.n)
		})
	}
}
func Benchmark_swap_work(b *testing.B) {
	for i := 0; i < b.N; i++ {
		swap_word("Hello", "World")
	}
}
func Test_swap_word(t *testing.T) {
	type args struct {
		a string
		b string
	}
	tests := []struct {
		name  string
		args  args
		want  string
		want1 string
	}{
		{"TC-0", args{"Hello", "World"}, "World", "Hello"},
		{"TC-1", args{"Hello", "Hello"}, "Hello", "Hello"},
		{"TC-2", args{"", "Hello"}, "Hello", ""},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got, got1 := swap_word(tt.args.a, tt.args.b)
			if got != tt.want {
				t.Errorf("swap_word() got = %v, want %v", got, tt.want)
			}
			if got1 != tt.want1 {
				t.Errorf("swap_word() got1 = %v, want %v", got1, tt.want1)
			}
		})
	}
}
