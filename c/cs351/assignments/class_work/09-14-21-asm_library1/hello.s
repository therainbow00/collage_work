extern puts, exit

section .data
  ; char hello[] = "Hello, world!\n";
  hello: db `Hello, world!\n`, 0

section .text

global _start
_start:
	mov	rsi, hello
	call	puts

	mov	rdi, 0
	call	exit
