;#include <stdio.h>
;
;int rows = 11;
;int spaces = 10;
;int stars = 1;
;
;int main(void)
;{
;  while (rows > 0) {
;    for(int i=0; i < spaces; i++) putchar(' ');
;    for(int i=0; i < stars; i++) putchar('*');
;    putchar('\n');
;    spaces--;
;    stars += 2;
;    rows--;
;  }
;  return 0;
;}
extern putc, exit

section .data
   nl: db `\n`, 0
 star: db `*`, 0
space: db ` `, 0

;  rows: dd 11
;spaces: dd 10
; stars: dd 1

section .bss
;i: resd 1
section .text

global _start
_start:
        ;mov dword[i], 0
        mov r10, 11
        mov r11, 10
        mov r12, 1
        mov r13, 0
        mov r14, 0
.while:
        cmp r10, 0
        jle .exit
.for:
        cmp r13, r11
        jge .for2
        mov al, [space]
        call putc
        inc r13
        jmp .for
.for2:
        cmp r14, r12
        jge .else
        mov al, [star]
        call putc
        inc r14
        jmp .for2
.else:
        mov al, [nl]
        call putc
        dec r11
        add r12, 2
        dec r10
        mov r13, 0
        mov r14, 0
        jmp .while
.exit:
        mov rdi, 0
        call exit
