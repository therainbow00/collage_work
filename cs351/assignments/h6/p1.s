;#include <stdio.h>
;
;int main(void)
;{
;  for(int i=1; i < 30; i+=2) {
;    printf("%d\n", i);
;  }
;  return 0;
;}
extern printnum, puts, exit

section .data
nl: db `\n`, 0

section .bss

section .text

global _start
_start:
        mov r15, 1
.for:
        cmp r15, 30
        jge .exit
        mov rax, r15
        mov rbx, 10
        call printnum
        mov	rsi, nl
        call puts
        add r15, 2
        jmp .for

.exit:
        mov rdi, 0
        call exit
