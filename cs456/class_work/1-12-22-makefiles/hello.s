
extern printf

SECTION .data
  hello: db `Hello, %d world!\n`, 0

SECTION .text

global main
main:
	enter 16, 0

        mov	rax, 0
        mov	rdi, hello
        mov	esi, 42
	call	printf		; printf("Hello, %d world!\n", 42);

	leave
	mov	rax, 0		; return 0;
	ret
