;#include <stdio.h>
;
;int main(void)
;{
;  int i = 1, c = 0;
;
;  while (i <= 99) {
;    c++;
;    if (c < 5) {
;      printf("%d\t", i);
;    } else {
;      printf("%d\n", i);
;      c = 0;
;    }
;
;    i += 2;
;  }
;  return 0;
;}
extern printnum, puts, exit

section .data
 nl: db `\n`, 0
tab: db `\t`, 0

section .bss

section .text

global _start
_start:
        mov r10, 1
        mov r11, 0
.while:
        cmp r10, 99
        jg .exit
        inc r11
        cmp r11, 5
        jl .if
        mov rax, r10
        mov rbx, 10
        call printnum
        mov rsi, nl
        call puts
        mov r11, 0
        add r10, 2
        jmp .while
.if:
    mov rax, r10
    mov rbx, 10
    call printnum
    mov rsi, tab
    call puts
    add r10, 2
    jmp .while
.exit:
        mov rdi, 0
        call exit
