%define SYS_read	0
%define SYS_write	1
%define SYS_open	2
%define SYS_close	3
%define SYS_exit	60

%define STDIN_FILENO	0
%define STDOUT_FILENO	1
%define STDERR_FILENO	2

%define O_RDONLY	0

%define K	1024

section .bss
      buf: resb K

section .data
  erropen: db "Error opening file ", 0
       nl: db `\n`, 0

section .text

; rdx = strlen(rsi)
strlen:
	mov	rdx, 0
.loop:
	cmp	BYTE [rsi + rdx], 0
	je	.done
	inc	rdx
	jmp	.loop
.done:
	ret

; Print string in rsi
puts:
	mov	rax, SYS_write
	mov	rdi, STDERR_FILENO
	call	strlen
	syscall
	ret

cat:
	mov	rax, SYS_read
	mov	rdi, r15
	mov	rsi, buf
	mov	rdx, K
	syscall
	cmp	rax, 0
	jle	.done

	mov	rdx, rax
	mov	rax, SYS_write
	mov	rdi, STDOUT_FILENO
	mov	rsi, buf
	syscall
	jmp	cat

.done:
	ret


global _start
_start:
	cmp	QWORD [rsp], 2
	jge	.else

	mov	r15, STDIN_FILENO
	call	cat
	jmp	.done

.else:
	lea	r14, [rsp + 8]		; r14 = argv
	mov	r12, 1

.loop:
	cmp	r12, QWORD[rsp]
	jge	.done

	; r15 = open(argv[r12], O_RDONLY);
	mov	rax, SYS_open
	mov	rdi, QWORD [r14 + r12*8]
	mov	rsi, O_RDONLY
	syscall
	cmp	rax, 0
	jge	.noerror

	mov	rsi, erropen
	call	puts
	mov	rsi, QWORD [r14 + r12*8]
	call	puts
	mov	rsi, nl
	call	puts
	jmp	.continue


.noerror:
	; cat(r15)
	mov	r15, rax
	call	cat

	; close(r15);
	mov	rax, SYS_close
	mov	rdi, r15
	syscall

.continue:
	inc	r12
	jmp	.loop

.done:
	mov	rax, SYS_exit
	mov	rdi, 0
	syscall
