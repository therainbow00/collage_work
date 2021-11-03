;#include <stdio.h>
;
;int main(void)
;{
;  for(int r = 0; r < 10; r++) {
;    for(int c = 0; c <= r; c++) {
;      putchar('*');
;    }
;    putchar('\n');
;  }
;  return 0;
;}
extern putc, exit

section .data
  nl: db `\n`, 0
star: db `*`, 0

section .bss

section .text

global _start
_start:
        mov r11, 0
        jmp .for
.for:
        cmp r11, 10
        jge .exit
        mov r12, 0
        jmp .for2
.for2:
        cmp r12, r11
        jg .else
        mov al, [star]
        call putc
        inc r12
        jmp .for2
.else:
        mov al, [nl]
        call putc
        inc r11
        jmp .for
.exit:
        mov rdi, 0
        call exit
