; Convert each function (one by one) from the C file to this file.  As
; you convert a C function, comment it out of the C code.

extern isspace, isdigit, printf, exit
%define k   1024

section .data
     pos: dd 0
     nsp: dd 0
 stk_und: db `Stack underflow.\n`, 0
usagemsg: db `Usage: <expression-string>\n`, 0
     fmt: db `"%d\n`, 0

section .bss
   input: resq 1
   value: resq 1
       c: resd 1
       n: resd 1
numstack: resd k
     num: resd 1
       l: resd 1
       r: resd 1
     tok: resd 1

section .text


_pop:
        push rbp
        mov rbp, rsp
        cmp dword[nsp], 0
        jne .else

        mov rdi, stk_und
        call printf
        mov rdi, 1
        call exit
        ret
.else:
        mov r9d, dword[numstack]
        dec dword[nsp]
        mov eax, dword[r9d + nsp]
        ret


_push:
        push rbp
        mov rbp, rsp
        inc dword[nsp]
        mov r9, qword[rbp + 8]
        mov r10d, dword[nsp + r9d]
        mov r11d, dword[numstack + r10d * 4]
        mov rdi, r11
        leave
        ret


lex:
    mov qword[value], rdi
    mov eax, 0
    call get

    mov dword[c], eax
.do_while:
            mov edi, dword[c]
            call isspace

            mov dword[c], eax
            cmp dword[c], 1
            je .do_while

            cmp dword[c], -1
            je .case1

            cmp dword[c], `+`
            je .case2

            cmp dword[c], `-`
            je .case3

            cmp dword[c], `/`
            je .case4

            cmp dword[c], `(`
            je .case5

            cmp dword[c], `)`
            je .case6

            cmp dword[c], `*`
            je .case7

            jmp .default
.case1:
        mov eax, 8
        ret
.case2:
        mov eax, 2
        ret
.case3:
        mov eax, 1
        ret
.case4:
        mov eax, 4
        ret
.case5:
        mov eax, 6
        ret
.case6:
        mov eax, 7
        ret
.case7:
        mov rdi, `*`
        call next

        cmp eax, 1
        jne .else
        mov rax, 5
        ret
.else:
        mov rax, 3
        ret
.default:
        mov edi, dword[c]
        call isdigit

        mov dword[c], eax
        cmp dword[c], 1
        je .if
        mov eax, 9
        ret
.if:
    mov dword[n], 0
.do_while2:
            mov r8d, dword[n]
            mov r13, 10
            imul r8, r13
            mov r9, `0`
            mov r10d, dword[c]
            sub r10d, r9d
            add r8, r10
            call get

            mov dword[c], eax
            mov edi, dword[c]
            call isdigit

            cmp eax, 1
            je .do_while2

            call unget

            mov r11, qword[value]
            mov r12d, dword[n]
            mov r11, r12
            mov eax, 0
            ret


next:
        push rbp
        mov rbp, rsp
        mov r15, rdi
        mov r9, qword[rbp + 8]
        mov r10, qword[input + r9 * 8]
        mov r12d, dword[pos + r10 * 8]
        cmp r12, r15
        jne .done
        inc dword[pos]
        mov rax, 1
        leave
        ret
.done:
        mov rax, 0
        leave
        ret


unget:
        push rbp
        cmp dword[pos], 0
        je .check2
        leave
        ret
.check2:
        push rbp
        mov rbp, rsp
        mov r9, qword[rbp + 8]
        mov r10, qword[input + r9 * 8]
        mov r12d, dword[pos + r10 * 8]
        cmp r12d, 0
        jne .done
.done:
        dec dword[pos]
        leave
        ret


get:
    push rbp
    mov rbp, rsp
    mov r9, qword[rbp + 8]
    mov r10, qword[input + r9 * 8]
    mov r12d, dword[pos + r10d * 4]
    cmp r12d, `\0`
    jne .else
    mov rax, -1
    leave
    ret
.else:
        inc dword[pos]
        mov r12d, dword[pos + r10d * 8]
        mov rax, qword[r12]
        leave
        ret


main:
    cmp rsp, 2
    jl .if

    mov r9, qword[rsp + 8]
    mov r10, qword[r9 + (1 * 8)]
    mov qword[input], r10

.while:
        mov edi, dword[num]
        call lex
        mov r15d, dword[tok]
        mov r15d, eax
        cmp r15d, 8
        je .done

        cmp r15d, 0
        je .case1

        cmp r15d, 1
        je .case2

        cmp r15d, 2
        je .case3

        cmp r15d, 3
        je .case4

        cmp r15d, 4
        je .case5
.case5:
        mov eax, 0
        call _pop

        mov r11, 0
        mov r12, 0

        mov r11d, dword[r]
        mov r12d, dword[l]
        mov r11d, eax
        mov r12d, eax
        idiv r11
        mov rdi, r11
        call _push
        jmp .while
.case4:
        mov eax, 0
        call _pop

        mov r11, 0
        mov r12, 0

        mov r11d, dword[r]
        mov r12d, dword[l]
        mov r11d, eax
        mov r12d, eax
        imul r11, r12
        mov rdi, r11
        call _push
        jmp .while
.case3:
        mov eax, 0
        call _pop

        mov r11, 0
        mov r12, 0

        mov r11d, dword[r]
        mov r12d, dword[l]
        mov r11d, eax
        mov r12d, eax
        sub r11, r12
        mov rdi, r11
        call _push
        jmp .while
.case2:
        mov eax, 0
        call _pop

        mov r11, 0
        mov r12, 0

        mov dword[r], eax
        mov dword[l], eax
        mov r11d, dword[r]
        mov r12d, dword[l]
        add r11, r12
        mov rdi, r11
        call _push
        jmp .while
.case1:
        mov edi, dword[num]
        call _push
        jmp .while
.done:
    mov rax, 0
    mov rdi, fmt
    mov rsi, _pop
    call printf

    mov rax, 0
    ret
.if:
    mov rdi, usagemsg
    mov rax, 0
    call printf
    mov rax, 0
    ret
