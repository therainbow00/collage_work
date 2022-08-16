extern printf
section .data
    hello: db 'Hello, %d world!', 0

section .text

global main
main:
        enter 16, 0

        mov rax, 0
        mov rdi, hello
        call printf
