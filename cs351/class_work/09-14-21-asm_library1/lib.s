%define SYS_read	0
%define SYS_write	1
%define SYS_open	2
%define SYS_close	3
%define SYS_stat	4
%define SYS_exit	60

%define STDIN_FILENO	0
%define STDOUT_FILENO	1
%define STDERR_FILENO	2


; To compile: nasm -felf64 lib.s


section .bss
    ; char _cbuf[1];
    _cbuf: resb 1

section .text

; Print the 'character' that is stored in the 'al'
; rax == returns -1 (failed) or 1 (succeeded)

global putc
putc:
	push	rdx
	push	rcx
	push	rsi
	push	rdi
	push	r8
	push	r9
	push	r10
	push	r11

	; _cbuf[0] = al
	mov	BYTE [_cbuf], al

	; write(STDOUT_FILENO, _cbuf, 1)
	mov	rax, SYS_write
	mov	rdi, STDOUT_FILENO
	mov	rsi, _cbuf
	mov	rdx, 1
	syscall

	pop	r11
	pop	r10
	pop	r9
	pop	r8
	pop	rdi
	pop	rsi
	pop	rcx
	pop	rdx
	ret

; Print the "string" given by the address in rsi (puts(r15))
global puts
puts:
	push	rdx
	mov	rdx, 0

.loop:
	cmp	BYTE [rsi+rdx], 0
	je	.done

	mov	al, BYTE[rsi+rdx]
	call	putc

	inc	rdx
	jmp	.loop
.done:
	pop	rdx
	ret

; Call exit, with the exit status in rdi
global exit
exit:
	mov	rax, SYS_exit
	syscall
