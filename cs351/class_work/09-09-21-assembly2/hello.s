%define SYS_read	0

%define SYS_write	1
%define SYS_open	2
%define SYS_close	3
%define SYS_stat	4
%define SYS_exit	60

%define STDIN_FILENO	0
%define STDOUT_FILENO	1
%define STDERR_FILENO	2

; To assemble: nasm -felf64 hello.s
;     To link: ld -o hello hello.o

SECTION .data
  hello: db `Hello, world!\n`, 0

SECTION .text

global _start
_start:
	; write(STDOUT_FILENO, "Hello, world!\n", 14);
	mov	rax, SYS_write
	mov	rdi, STDOUT_FILENO
	mov	rsi, hello
	mov	rdx, 14
	syscall

	; exit(0);
	mov	rax, SYS_exit
	mov	rdi, 0
	syscall
