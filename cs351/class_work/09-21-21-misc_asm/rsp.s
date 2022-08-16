%define SYS_write	1
%define SYS_exit	60
%define STDOUT_FILENO	1

; Print the value of the rsp register in binary to the screen:
; To compile: nasm -felf64 rsp.s
;    To link: ld -o rsp rsp.o

section .bss
      _cbuf: resb 1

section .text

; Prints the character in the al register
; Destroys registers: rax, rdi, rsi, rdx, r10, r8, r9, r11, rcx
putc:
	mov	BYTE [_cbuf], al
	mov	rax, SYS_write
	mov	rdi, STDOUT_FILENO
	mov	rsi, _cbuf
	mov	rdx, 1
	syscall
	ret


global _start
_start:
	mov	r12, 64
	mov	r13, rsp

.loop:
	cmp	r12, 0
	je	.finish

	shl	r13, 1
	jb	.one
	; print a 0
	mov	al, '0'
	call	putc
	jmp	.continue
.one:
	; print a 1
	mov	al, '1'
	call	putc

.continue:
	dec	r12
	jmp	.loop

.finish:
	; print a newline
	mov	al, `\n`
	call	putc

	; exit(0);
	mov	rax, SYS_exit
	mov	rdi, 0
	syscall
