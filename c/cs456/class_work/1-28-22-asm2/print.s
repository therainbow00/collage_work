extern printf

SECTION .data
  fmtstr: db `%d, %d, %d, %d, %d, %d, %d, %d, %d\n`, 0

SECTION .text

global main
main:
	enter 16, 0

;   printf("%d, %d, %d, %d, %d, %d, %d, %d, %d\n",
;           1, 2, 3, 4, 5, 6, 7, 8, 9);
;   printf (rdi, rsi, rdx, rcx, r8, r9, push 9, push 8, push 7, push 6)
	mov	rax, 0
	mov	rdi, fmtstr
	mov	esi, 1
	mov	edx, 2
	mov	ecx, 3
	mov	r8d, 4
	mov	r9d, 5
	; Final values pushed in "reverse" from right to left:
	push	9
	push	8
	push	7
	push	6
	call	printf

	mov	edi, 0
	leave
	ret
