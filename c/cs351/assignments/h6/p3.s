;#include <stdio.h>
;
;int main(void)
;{
;  for(int r = 0; r < 10; r++) {
;    for(int c = 0; c < 10; c++) {
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
        inc r11
        mov r12, 0
        jmp .for2
.for2:
        cmp r12, 10
        jge .else
        inc r12
        mov al, [star]
        call putc
        jmp .for2
.else:
        mov al, [nl]
        call putc
        jmp .for
.exit:
        mov rdi, 0
        call exit
