%include "lib.h"
; Do not %include "lib.s", use make to build your program
extern putchar, puts, exit


section .data



section .bss
  r: resd 1
 fd: resd 1
num: resb 1


section .text

printbinary:
            mov r8d, rdi
            mov r9w, 7
            jmp .for
    .for:
        cmp r9w, 0
        jle ret
        mov rax, bittest
        mov rdi, [num]
        mov rsi, r9w
        call bittest
        cmp rax, 1
        jne .putchar
        mov rax, putchar
        mov rdi, `#`
        call putchar
        dec r9w
        jmp .for
    .putchar:
            mov rax, putchar
            mov rdi, ` `
            call putchar

bittest:
        mov r10d, rdi
        mov r11d, rsi
        shl r11d, 1
        test r10d, r11d
        ret

global _start
_start:
        cmp 2, [rsp]
        jl .if
        mov rax, fd
        mov rdi, [rsp + 16]
        mov rsi, O_RDONLY
        cmp rax, 0
        jl .if2
        cmp rax, 1
        je .while
.while:
        mov rax, r
        mov rdi, fd
        mov rsi, [num]
        mov rdx, BYTE [num]
        cmp rax, 1
        jne .done
        mov rax, printbinary
        mov rdi, num
        call printbinary
        mov rax, putchar
        mov rdi, `\n`
        call putchar
        jmp .while
.if2:
    mov rdi, `Unable to open file for reading.\n`
    call puts
    mov rdi, 1
    call exit
.if:
    mov rdi, `Usage: h5 <file>\n`
    call puts
    mov rdi, 1
    call exit
.done:
        mov rax, SYS_close
        mov rdi, fd
        call close
        mov rax, exit
        mov rdi, 0
        call exit
