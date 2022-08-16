%define SYS_write	1
%define SYS_exit	60
%define STDOUT_FILENO	1

section .data
    nl: db `\n`, 0


section .text
; length of string pointed to by rsi returned in rdx
strlen:
	mov	rdx, 0
.loop:
	cmp	BYTE [rsi+rdx], 0
	je	.done
	inc	rdx
	jmp	.loop
.done:
	ret


; 	     ....
;         [  argv[1] ]
;         [  argv[0] ]
; rsp ->  [   argc   ]
;
;   argc = [rsp]
;   argv[0] = [rsp+8]
;   argv[1] = [rsp+16]
;
global _start
_start:
	mov	r15, QWORD [rsp]	; r15 = argc
	lea	r14, [rsp + 8]		; r14 = argv
	mov	r12, 0

.loop:
	cmp	r12, r15
	jge	.done

	;     write(STDOUT_FILENO, argv[r12], my_strlen(argv[r12]));
	mov	rax, SYS_write
	mov	rdi, STDOUT_FILENO
	mov	rsi, QWORD [r14 + r12*8]
	call	strlen
	syscall

	; write(STDOUT_FILENO, "\n", 1);
	mov	rax, SYS_write
	mov	rdi, STDOUT_FILENO
	mov	rsi, nl
	mov	rdx, 1
	syscall

	inc	r12
	jmp	.loop

.done:
	; exit(0);
	mov	rax, SYS_exit
	mov	rdi, 0
	syscall
