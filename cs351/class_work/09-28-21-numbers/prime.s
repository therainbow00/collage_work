extern printnum, exit

%define MAXNUM	1000
%define MAXSQ	32

section .text

; check
isprime:

	mov	r14, 3
.loop:
	; Don't try checking the number if the divisor is >= the number
	cmp	r14, r15
	jge	.prime

	mov	rax, r15
	cqo
	div	r14
	cmp	rdx, 0
	je	.notprime

	add	r14, 2
	cmp	r14, MAXSQ
	jl	.loop

.prime:
	mov	rax, 1
	ret

.notprime:
	mov	rax, 0
	ret

global _start
_start:
	mov	rax, 2
	mov	rbx, 10
	call	printnum

	mov	r15, 3

.loop:
	call	isprime
	cmp	rax, 1
	jne	.continue

	mov	rax, r15
	mov	rbx, 10
	call	printnum

.continue:
	add	r15, 2
	cmp	r15, MAXNUM
	jl	.loop

	mov	rdi, 0
	call	exit
