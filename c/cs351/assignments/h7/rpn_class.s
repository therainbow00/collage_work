; Convert each function (one by one) from the C file to this file.  As
; you convert a C function, comment it out of the C code.
%define K	1024

%define TRUE	1
%define FALSE	0

%define T_NUMBER    0
%define T_PLUS      1
%define T_MINUS     2
%define T_MULT      3
%define T_DIV       4
%define T_EXP       5
%define T_OPAREN    6
%define T_CPAREN    7
%define T_EOE       8
%define T_UNKNOWN   9

extern printf, exit, isspace, isdigit

global pos, nsp, input, numstack

; int pos = 0;
; int nsp = 0;

section .data
    pos: dd 0
    nsp: dd 0

   fmt1: db `Stack underflow.\n`, 0

;char *input;
;int numstack[K];

section .bss
     input: resq 1
  numstack: resd K

section .text


global get
get:
	mov	rsi, QWORD[input]
	movsx	r15, DWORD[pos]
	movsx	eax, BYTE [rsi + r15]
	cmp	al, `\0`
	je	.rneg1

	inc	DWORD[pos]
	ret

.rneg1:
	mov	eax, -1
	ret



global unget
unget:
	movsx	r15, DWORD[pos]
	cmp	r15, 0
	je	.done

	mov	rsi, QWORD[input]
	movsx	eax, BYTE [rsi + r15]
	cmp	al, `\0`
	je	.done

	dec	DWORD[pos]
.done:
	ret


global next
next:
  .c: equ 4

	enter 16, 0
	mov	DWORD[rbp - .c], edi

	mov	rsi, QWORD[input]
	movsx	r15, DWORD[pos]
	movsx	eax, BYTE [rsi + r15]	; al = input[pos]

	cmp	eax, edi		; if (input[pos] == c)
	jne	.false
	inc	DWORD[pos]

	mov	eax, TRUE
	leave
	ret

.false:
	mov	rax, FALSE
	leave
	ret



global push
push:
	movsx	r15, DWORD [nsp]
	mov	DWORD [numstack + r15 * 4], edi
	inc	DWORD [nsp]
	ret


global pop
pop:
	cmp	DWORD[nsp], 0
	jne	.else

	mov	rax, 0
	mov	rdi, fmt1
	call	printf
	mov	edi, 1
	call	exit

.else:
	dec	DWORD[nsp]
	movsx	r15, DWORD [nsp]
	mov	eax, DWORD [numstack + r15 * 4]
	ret

global lex
lex:
      .c: equ 4
      .n: equ 8
  .value: equ 16

	enter 16, 0

	mov	QWORD[rbp - .value], rdi

.do:
	call	get
	mov	r15d, eax
	mov	edi, r15d
	call	isspace
	cmp	eax, 0
	jne	.do

; switch(r15d):
	cmp	r15d, -1
	jne	.plus

	mov	eax, T_EOE
	jmp	.done

.plus:
	cmp	r15b, '+'
	jne	.minus

	mov	eax, T_PLUS
	jmp	.done

.minus:
	cmp	r15b, '-'
	jne	.div

	mov	eax, T_MINUS
	jmp	.done

.div:
	cmp	r15b, '/'
	jne	.oparen

	mov	eax, T_DIV
	jmp	.done

.oparen:
	cmp	r15b, '('
	jne	.cparen

	mov	eax, T_OPAREN
	jmp	.done
.cparen:
	cmp	r15b, ')'
	jne	.star

	mov	eax, T_CPAREN
	jmp	.done
.star:
	cmp	r15b, '*'
	jne	.default

	mov	edi, '*'
	call	next
	cmp	eax, 0
	je	.mult

	mov	eax, T_EXP
	jmp	.done
.mult:
	mov	eax, T_MULT
	jmp	.done

.default:
	mov	edi, r15d
	call	isdigit
	cmp	eax, 0
	je	.unknown

	mov	DWORD [ rbp - .n ], 0
.numloop:
	mov	rbx, 10
	mov	eax, DWORD [ rbp - .n]
	imul	rbx
	sub	r15d, '0'
	add	eax, r15d
	mov	DWORD[rbp -.n], eax

	call	get
	mov	r15d, eax
	mov	edi, r15d
	call	isdigit
	cmp	eax, 0
	jne	.numloop

	call	unget

	mov	rdi, QWORD[rbp - .value]
	mov	r15d, DWORD[rbp - .n]
	mov	DWORD [rdi], r15d

	mov	eax, T_NUMBER
	jmp	.done

.unknown:
	mov	eax, T_UNKNOWN
.done:
	leave
	ret
