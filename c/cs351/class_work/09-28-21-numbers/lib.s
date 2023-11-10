%define SYS_read	0
%define SYS_write	1
%define SYS_open	2
%define SYS_close	3
%define SYS_stat	4
%define SYS_exit	60
%define SYS_getrandom	318

%define STDIN_FILENO	0
%define STDOUT_FILENO	1
%define STDERR_FILENO	2

; Flags for use with getrandom:
%define GRND_NONBLOCK	0x01
%define GRND_RANDOM	0x02
%define GRND_INSECURE	0x04


; To compile: nasm -felf64 lib.s


section .bss
    ; char _cbuf[1];
    _cbuf: resb 1

section .text

; rax = strlen(rsi)
global strlen
strlen:
      mov	rax, 0
.loop:
      cmp	BYTE [rsi+rax], 0
      je	.done
      inc	rax
      jmp	.loop
.done:
      ret

; strcpy(rdi, rsi) - copy string from rsi to rdi
global strcpy
strcpy:
	push	rax
	push	rcx

	call	strlen
	mov	rcx, rax

	cld
.copy:
	movsb
	loop	.copy

	pop	rcx
	pop	rax
	ret

; rax = strchr(rsi, cl);
; return address of character in cl if found in rsi, or NULL (0) if not found
global strchr
strchr:
	push	rsi
	mov	rax, 0

	dec	rsi

.loop:
	inc	rsi
	cmp	BYTE [rsi], 0
	je	.done

	cmp	BYTE [rsi], cl
	jne	.loop

	mov	rax, rsi
.done:
	pop	rsi
	ret

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
	push	rcx
	push	rsi
	push	rdi
	push	r8
	push	r9
	push	r10
	push	r11

	call	strlen
	mov	rdx, rax
	mov	rax, SYS_write
	mov	rdi, STDOUT_FILENO
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

; Read a character from STDIN_FILENO, returning it in al, -1 on EOF
global getc
getc:
	push	rdx
	push	rcx
	push	rsi
	push	rdi
	push	r8
	push	r9
	push	r10
	push	r11

	mov	rax, SYS_read
	mov	rdi, STDIN_FILENO
	mov	rsi, _cbuf
	mov	rdx, 1
	syscall

	cmp	rax, 1
	jne	.error

	mov	al, BYTE [_cbuf]
	jmp	.leave

.error:
	mov	rax, -1

.leave:
	pop	r11
	pop	r10
	pop	r9
	pop	r8
	pop	rdi
	pop	rsi
	pop	rcx
	pop	rdx
	ret

; Get a random value between 0-255 from the kernel:
global rand
rand:
	push	rdx
	push	rcx
	push	rsi
	push	rdi
	push	r8
	push	r9
	push	r10
	push	r11

	mov	rax, SYS_getrandom
	mov	rdi, _cbuf
	mov	rsi, 1
	mov	rdx, GRND_NONBLOCK
	syscall

	cmp	rax, 1
	jne	.error

	mov	al, BYTE [_cbuf]
	jmp	.leave

.error:
	mov	rax, -1

.leave:
	pop	r11
	pop	r10
	pop	r9
	pop	r8
	pop	rdi
	pop	rsi
	pop	rcx
	pop	rdx
	ret
; Call exit, with the exit status in rdi
global exit
exit:
	mov	rax, SYS_exit
	syscall
