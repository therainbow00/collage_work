%define K	1024

%define	TRUE	1
%define FALSE	0

%define T_NUMBER   0
%define T_PLUS     1
%define T_MINUS    2
%define T_MULT     3
%define T_DIV      4
%define T_EXP      5
%define T_OPAREN   6
%define T_CPAREN   7
%define T_EOE      8
%define T_UNKNOWN  9

extern isspace, isdigit, printf, exit

global input, pos, numstack, nsp

section .bss
   input: resq 1
     pos: resd 1
numstack: resd K
     nsp: resd 1

section .data
  stackunderflow: db `Stack underflow.\n`, 0
  usage: db `Usage: <expression-string>\n`, 0
  fmt: db `%d\n`, 0

section .text

;int get(void)
;{
;  if (input[pos] == '\0') return -1;
;  return input[pos++];
;}

global get
get:
	enter	16,0

	movsx	rdi, DWORD [pos]
	mov	rsi, QWORD [input]
	movsx	eax, BYTE [rsi + rdi];	eax = input[pos];
	cmp	al, `\0`
	jne	.false
	mov	eax, -1
	jmp	.exit
.false:
	inc	DWORD [pos]
.exit:
	leave
	ret


;void unget(void)
;{
;  if (pos && input[pos] != '\0') pos--;
;}
global unget
unget:
	enter	16,0

	movsx	rdi, DWORD [pos]
	cmp	edi, 0
	je	.exit
	mov	rsi, QWORD [input]
	movsx	eax, BYTE [rsi + rdi];	eax = input[pos];
	cmp	al, `\0`
	je	.exit

	dec	DWORD [pos]

.exit:
	leave
	ret


;bool next(int c)
;{
;  if (input[pos] == c) {
;    pos++;
;    return TRUE;
;  }
;  return FALSE;
;}


global next
next:
  .c: equ 4
	enter 16,0

	mov	DWORD[rbp - .c], edi

	mov	rsi, QWORD[input]
	movsx	rbx, DWORD[pos]
	cmp	BYTE [rsi + rbx], dil
	jne	.false
	inc	DWORD[pos]
	mov	eax, TRUE
	leave
	ret
.false:
	mov	eax, FALSE
	leave
	ret

;token_t lex(int *value)
; {
;   int c, n;
;
;   // Skip over any white-space:
;   do {
;     c = get();
;   } while(isspace(c));
;   switch(c) {
;     case -1: return T_EOE;
;     case '+': return T_PLUS;
;     case '-': return T_MINUS;
;     case '/': return T_DIV;
;     case '(': return T_OPAREN;
;     case ')': return T_CPAREN;
;     case '*':
;       if (next('*')) return T_EXP;
;       return T_MULT;
;     default:
;       if (isdigit(c)) {
; 	n = 0;
; 	do {
; 	  n *= 10;
; 	  n += (c-'0');
; 	} while (isdigit(c = get()));
; 	unget();
; 	*value = n;
; 	return T_NUMBER;
;       }
;       return T_UNKNOWN;
;  }
;
;  // NOT REACHED
;  return T_UNKNOWN;
;}


global lex
lex:
 .value: equ 8
 .c: equ 12
 .n: equ 16
	enter 16, 0

	mov	QWORD[rbp - .value], rdi

.doloop:
	  call	get
	  mov	DWORD[rbp - .c], eax
	  mov	edi, DWORD[rbp - .c]
	  call	isspace
	  cmp	eax, 0
        jne .doloop

        mov	eax, DWORD[rbp - .c]
	cmp	eax, -1
	jne	.plus
	; case -1:
	mov	eax, T_EOE
	jmp	.leave

.plus:
	cmp	al, '+'
	jne	.minus
	mov	eax, T_PLUS
	jmp	.leave

.minus:
	cmp	al, '-'
	jne	.div
	mov	eax, T_MINUS
	jmp	.leave

.div:
	cmp	al, '/'
	jne	.oparen
	mov	eax, T_DIV
	jmp	.leave
.oparen:
	cmp	al, '('
	jne	.cparen
	mov	eax, T_OPAREN
	jmp	.leave
.cparen:
	cmp	al, ')'
	jne	.mult
	mov	eax, T_CPAREN
	jmp	.leave
.mult:
	cmp	al, '*'
	jne	.default

	mov	edi, eax
	call	next
	cmp	eax, 0
	je	.ismult

	mov	eax, T_EXP
	jmp	.leave

.ismult:
	mov	eax, T_MULT
	jmp	.leave

.default:
	mov	edi, eax
	call	isdigit
	cmp	eax, 0
	je	.unknown

	mov	DWORD[rbp -.n], 0

        .do2:
	  mov	ebx, DWORD[rbp - .n]
	  imul	ebx, ebx, 10
	  mov	eax, DWORD[rbp - .c]
	  sub	eax, '0'
	  add	ebx, eax
	  mov	DWORD[rbp - .n], ebx

	  call	get
	  mov	DWORD[rbp - .c], eax
	  mov	edi, eax
	  call	isdigit
	  cmp	eax, 0
	jne .do2

	call	unget

	mov	rdi, QWORD[rbp - .value]
	mov	ebx, DWORD[rbp - .n]
	mov	DWORD[rdi], ebx

	mov	eax, T_NUMBER
	jmp	.leave

.unknown:
	mov	eax, T_UNKNOWN

.leave:
	leave
	ret

;void push(int v)
;{
;  numstack[nsp++] = v;
;}

global push
push:
	mov	esi, DWORD [nsp]
	mov	DWORD[numstack + esi*4], edi
	inc	DWORD[nsp]
	ret

;// (2pts)
;int pop(void)
;{
;  if (nsp == 0) {
;    printf("Stack underflow.\n");
;    exit(1);
;  }
;  return numstack[--nsp];
;}

global pop
pop:
	enter	16, 0
	cmp	DWORD[nsp], 0
	jne	.dopop

	mov	rax, 0
	mov	rdi, stackunderflow
	call	printf
	mov	rdi, 1
	call	exit
.dopop:
	dec	DWORD[nsp]
	mov	esi, DWORD[nsp]
	mov	eax, DWORD[numstack + esi*4]
	leave
	ret

;int main(int argc, char *argv[])
;{
;  if (argc < 2) {
;    printf("Usage: <expression-string>\n");
;    return 0;
;  }
;  input = argv[1];
;  int num, l, r;
;  token_t tok;
;  pos = 0;
;  nsp = 0;
;
;  // lea  rdi, [rbp - .num]
;  // call lex
;  while ((tok = lex(&num)) != T_EOE) {
;  printf("%d\n", pop());
;
;  return 0;
;}
;    switch(tok) {
;      case T_NUMBER:
;	push(num);
;	break;
;      case T_EXP:
;	r = pop();
;	l = pop();
;	int v = 1;
;	for(int i=0; i < l; i++)
;	  v = v * r;
;	push(v);
;	break;
;      case T_PLUS:
;	r = pop();
;	l = pop();
;	push(l+r);
;	break;
;      case T_MINUS:
;	r = pop();
;	l = pop();
;	push(l-r);
;	break;
;      case T_MULT:
;	r = pop();
;	l = pop();
;	push(l*r);
;	break;
;      case T_DIV:
;	r = pop();
;	l = pop();
;	push(l/r);
;	break;
;    }
;  }

global main
main:
  .num: equ 4
    .l: equ 8
    .r: equ 12
  .tok: equ 16
    .v: equ 20

	enter	32, 0

	cmp	rdi, 2
	jge	.start

	mov	rax, 0
	mov	rdi, usage
	call	printf
	mov	eax, 0
	leave
	ret

.start:
	mov	rdi, QWORD[rsi + 8]
	mov	QWORD[input], rdi

	mov	DWORD[pos], 0
	mov	DWORD[nsp], 0

.while:
	lea	rdi, [rbp - .num]
	call	lex
	mov	DWORD[rbp - .tok], eax
	cmp	eax, T_EOE
	je	.finish

	cmp	eax, T_NUMBER
	jne	.exp
	mov	edi, DWORD[rbp - .num]
	call	push
	jmp	.while

.exp:
	cmp	eax, T_EXP
	jne	.plus
	call	pop
	mov	DWORD[rbp - .r], eax
	call	pop
	mov	DWORD[rbp - .l], eax

	mov	eax, 1
	mov	edi, DWORD[rbp - .r]
.exploop:
	cmp	DWORD[rbp - .l], 0
	je	.expdone

	imul	eax, edi
	dec	DWORD[rbp - .l]
	jmp	.exploop
.expdone:
	mov	edi, eax
	call	push
	jmp	.while

.plus:
	cmp	eax, T_PLUS
	jne	.minus
	call	pop
	mov	DWORD[rbp - .r], eax
	call	pop
	mov	DWORD[rbp - .l], eax

	mov	ebx, DWORD[rbp - .r]
	add	eax, ebx
	mov	edi, eax
	call	push
	jmp	.while

.minus:
	cmp	eax, T_MINUS
	jne	.mult
	call	pop
	mov	DWORD[rbp - .r], eax
	call	pop
	mov	DWORD[rbp - .l], eax

	mov	ebx, DWORD[rbp - .r]
	sub	eax, ebx
	mov	edi, eax
	call	push
	jmp	.while

.mult:
	cmp	eax, T_MULT
	jne	.div
	call	pop
	mov	DWORD[rbp - .r], eax
	call	pop
	mov	DWORD[rbp - .l], eax

	mov	ebx, DWORD[rbp - .r]
	imul	eax, ebx
	mov	edi, eax
	call	push
	jmp	.while

.div:
	cmp	eax, T_MINUS
	jne	.while
	call	pop
	mov	DWORD[rbp - .r], eax
	call	pop
	mov	DWORD[rbp - .l], eax

	mov	ebx, DWORD[rbp - .r]
	cdq
	idiv	ebx
	mov	edi, eax
	call	push
	jmp	.while

.finish:
	call	pop
	mov	esi, eax
	mov	rax, 0
	mov	rdi, fmt
	call	printf

	mov	eax, 0
	leave
	ret
