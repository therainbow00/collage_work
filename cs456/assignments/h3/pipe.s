extern printf, perror, wait

SECTION .bss


SECTION .data
 exit: db `Exit status of the child = %d\n`, 0
_wait: db `wait`, 0

SECTION .text

;void waitforchild(void)
;{
;    int status;
;
;  if (wait(&status) < 0) {
;    perror("wait");
;  }
;  printf("Exit status of the child = %d\n", WEXITSTATUS(status));
;}
global waitforchild
waitforchild:
        .status: equ 4

            enter 16, 0

            mov rax, 0
            mov edi, dword [rbp - .status]
            call $wait

            cmp eax, 0
            jl .error

.continue:
            mov rax, 0
            mov rdi, exit
            ;mov r8d, dword [rbp - .status]
            mov rsi, (((dword [rbp - .status]) & 0xff00) >> 8)
            call printf
            leave
            ret
.error:
        mov rax, 0
        mov rdi, _wait
        call perror
        jmp .continue
