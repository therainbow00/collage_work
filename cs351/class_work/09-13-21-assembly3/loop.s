; To compile:
; nasm -felf64 loop.s
; gcc -o loop loop.o

extern printf, exit

section .data
    fmt: db `%d\n`, 0

section .bss
      i: resd	1

section .text

global main
main:
	enter	16,0
	mov	DWORD [i], 0		; i = 0;

.while:					; while (i < 10) {
	cmp	DWORD [i], 10
	jge	.wend

	mov	rax, 0
	mov	rdi, fmt
	movsx	rsi, DWORD [i]
	call	printf			;   printf("%d\n", i);

	inc	DWORD [i]		;   i++;
	jmp	.while			; }

.wend:
	leave
	mov	rax, 0
	ret				; return 0;
