extern printf

section .data
a: dd 1
b: dd 2
format: db `a + b = %d\n`, 0
section .text
;int main(void)
;{
;    int a = 1, b = 2;
;    printf("a + b = %d\n", a + b);
;}
global main
main:
        ;push rbp
        ;mov rsp, rbp
        mov r9d, dword[a]
        add r9d, dword[b]
        mov rdi, format
        mov rsi, r9
        mov eax, 0
        call printf
        leave
        mov rax, 0
        ret
