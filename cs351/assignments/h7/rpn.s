; Convert each function (one by one) from the C file to this file.  As
; you convert a C function, comment it out of the C code.

%define k   1024
%define { TRUE=1, FALSE=0 } bool;
%define {
    T_NUMBER, T_PLUS, T_MINUS, T_MULT, T_DIV, T_EXP, T_OPAREN, T_CPAREN, T_EOE,
    T_UNKNOWN
    } token_t;

section .data
pos: dd 0
nsp: dd 0

section .bss
   input: resq 1
   value: resq 1
       c: resd 1
       n: resd 1
numstack: resb k

section .text
;char *input;
;int pos = 0;
;int numstack[K];
;int nsp = 0;
;int get(void)

;{
;  if (input[pos] == '\0') return -1;
;  return input[pos++];
;}
;void unget(void)
;{
;  if (pos && input[pos] != '\0') pos--;
;}
;bool next(int c)
;{
;  if (input[pos] == c) {
;    pos++;
;    return TRUE;
;  }
;  return FALSE;
;}
;token_t lex(int *value)
;{
;  int c, n;
;
;  // Skip over any white-space:
;  do {
;    c = get();
;  } while(isspace(c));
;
;  switch(c) {
;    case -1: return T_EOE;
;    case '+': return T_PLUS;
;    case '-': return T_MINUS;
;    case '/': return T_DIV;
;    case '(': return T_OPAREN;
;    case ')': return T_CPAREN;
;    case '*':
;      if (next('*')) return T_EXP;
;      return T_MULT;
;    default:
;      if (isdigit(c)) {
;	n = 0;
;	do {
;	  n *= 10;
;	  n += (c-'0');
;	} while (isdigit(c = get()));
;	unget();
;	*value = n;
;	return T_NUMBER;
;      }
;      return T_UNKNOWN;
;  }

;  // NOT REACHED
;  return T_UNKNOWN;
;}
lex:
    mov qword[value], rsi
    mov eax, 0
    call get

    mov dword[c], eax
.do_while:
            mov rsi, dword[c]
            call isspace

            mov dword[c], eax
            cmp dword[c], 1
            je .do_while

next:
        mov r10, qword[rbp + 8]
        mov r11, qword[r10 * input]
        mov r12d, dword[r11d * pos]
        cmp r12d, rdi
        jne .done
        inc dword[pos]
        mov rax, 1
        ret
.done:
        mov rax, 0
        ret
unget:
        cmp dword[pos], 0
        je .check2
        ret
.check2:
        mov r10, qword[rbp + 8]
        mov r11, qword[r10 * input]
        mov r12d, dword[r11d * pos]
        cmp r12d, 0
        jne .done
.done:
        dec dword[pos]
        ret
get:
    mov r10, [rbp + 8]
    mov r11, qword[r10 * input]
    mov r12d, dword[r11d * pos]
    cmp r12d, `\0`
    jne .else
    mov rax, -1
    ret
.else:
        inc dword[pos]
        mov r12d, dword[r11d * pos]
        mov rax, r12d
        ret
global main
main:
