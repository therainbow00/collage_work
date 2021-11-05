extern atoi, printf

; To compile: nasm -felf64 print.s
;    To link: gcc -o print print.o

section .data
  usagemsg: db `Usage: print <name> <number>\n`, 0
  fmt1: db `Name: %s (%d)\n`, 0


section .text

; argc -> rdi
; argv -> rsi
global main:
main:
	.argv:  equ 0
	.num:	equ 8
	enter	16, 0
	mov	QWORD[rbp-.argv], rsi

	cmp	rdi, 3
	jge	.printit

	mov	rax, 0
	mov	rdi, usagemsg
	call	printf

	leave
	mov	rax, 0
	ret

.printit:
	;   int num = atoi(argv[2]);
	mov	rax, 0
	mov	rsi, QWORD[rbp-.argv]
	mov	rdi, QWORD[rsi+2*8]
	call	atoi
	mov	DWORD[rbp-.num], eax


	;  printf("Name: %s (%d)\n", argv[1], num);
	mov	rax, 0
	mov	rdi, fmt1
	mov	rsi, QWORD[rbp-.argv]	; rsi = argv
	mov	rsi, QWORD[rsi + 1*8]	; rsi = rsi[1]
	mov	edx, DWORD[rbp-.num]
	call	printf

	leave
	mov	rax, 0
	ret
