;#include <stdio.h>
;
;int main(void)
;{
;  printf("    2 3 4 5 6 7\n");
;  printf("  -------------\n");
;  for(int i = 0; i < 16; i++) {
;    printf("%2X:", i);
;    for(int j = 2; j < 8; j++) {
;      int ch = (j<<4) + i;
;      if (ch == 127) printf(" DEL");
;      else printf(" %c", ch);
;    }
;    printf("\n");
;  }
;
;  return 0;
;}

; alphabet
extern exit, puts, putc, printnum

section .data
    nl: db `\n`, 0
  dash: db `-`, 0
 space: db ` `, 0
collen: db `:`, 0
   del: db `DEL`, 0

;row1: db `     2 3 4 5 6 7\n`, 0
;row2: db `   -------------\n`, 0
;del: db " DEL", 0

section .bss
;i: resd 1
;j: resd 1
;_ch: resb 1
section .text

global _start
_start:
        ;mov rsi, row1
        ;call puts
        ;mov rsi, row2
        ;call puts
        ;mov dword[i], 0

        mov r10, 2
        mov r11, 1
        mov r12, 1
        mov r13, 2
.spaces:
        cmp r11, 4
        jg .two_seven
        mov al, [space]
        call putc
        inc r11
        jmp .spaces
.two_seven:
            cmp r10, 7
            jg .new_line
            mov rax, r10
            mov rbx, 10
            call printnum
            mov al, [space]
            call putc
            inc r10
            jmp .two_seven
.new_line:
            mov al, [nl]
            call putc
            mov r11, 1
.spaces2:
            cmp r11, 2
            jg .dash
            mov al, [space]
            call putc
            inc r11
            jmp .spaces2
.dash:
        cmp r12, 13
        jg .reset
        mov al, [dash]
        call putc
        inc r12
        jmp .dash
.reset:
        mov r12, 0
        mov al, [nl]
        call putc
.for:
        cmp r12, 16
        jge .exit
        mov al, [space]
        call putc
        mov rax, r12
        mov rbx, 16
        call printnum
        mov al, [collen]
        call putc
.for2:
        cmp r13, 8
        jge .outside
        mov r14, r13
        shl r14, 4
        add r14, r12
        cmp r14, 127
        jne .else
        mov al, [space]
        call putc
        mov rsi, del
        call puts
        inc r13
        jmp .for2
.else:
        mov al, [space]
        call putc
        mov al, r14b
        call putc
        inc r13
        jmp .for2
.outside:
            mov al, [nl]
            call putc
            inc r12
            mov r13, 2
            jmp .for
.exit:
        mov rdi, 0
        call exit
