extern printnum, putc, exit

; nasm -felf64 nums.s
; ld -o nums nums.o lib.o

section .bss
  num: resq 1

section .text

global _start
_start:
	mov	QWORD[num], 1

.loop:
	cmp	QWORD[num], 100
	jg	.done

	mov	rax, QWORD[num]
	mov	rbx, 10
	mov	r9, 0
	call	printnum

	mov	al, `\n`
	call	putc

	inc	QWORD[num]
	jmp	.loop

.done:
	mov	rdi, 0
	call	exit
