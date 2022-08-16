extern printf

; Compile: nasm -felf64 print.s
;    Link: gcc -o print print.o

section .data
  fmt: db `a=%ld, b=%ld, c=%ld, e=%ld, f=%ld, g=%ld, h=%ld, i=%ld, j=%ld\n`, 0

section .text

; argc -> rdi, argv -> rsi
global main
main:
	enter 16, 0

	mov	rax, 0
	; rdi, rsi, rdx, rcx, r8, r9,
	mov	rdi, fmt
	mov	rsi, 0
	mov	rdx, 1
	mov	rcx, 2
	mov	r8, 3
	mov	r9, 4
	push	QWORD 8
	push	QWORD 7
	push	QWORD 6
	push	QWORD 5
	call	printf

	leave
	mov	rax, 0
	ret
