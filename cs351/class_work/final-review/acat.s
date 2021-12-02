%define EOF	-1
%define NULL	0

extern fgetc, fputc, fopen, fclose, perror, stdin, stdout

SECTION .data
  readonly: db "r", 0
   openerr: db "fopen", 0

SECTION .text

; void cat(FILE *fp)
; {
;   int ch;
;
;   while ((ch = fgetc(fp)) != EOF) {
;     fputc(ch, stdout);
;   }
; }

cat:
  .ch: equ 4
  .fp: equ 12

	enter 16, 0
	mov	QWORD[rbp - .fp], rdi

.while:
	mov	rdi, QWORD[rbp - .fp]
	call	fgetc
	mov	DWORD[rbp - .ch], eax
	cmp	eax, EOF
	je	.done

	mov	edi, DWORD[rbp - .ch]
	mov	rsi, QWORD [ stdout ]
	call	fputc

	jmp 	.while
.done:
	leave
	ret


; int main(int argc, char *argv[])
; {
;   if (argc < 2) cat(stdin);
;   else {
;     FILE *fp;
;     for(int i=1; i < argc; i++) {
;       fp = fopen(argv[i], "r");
;       if (fp == NULL) {
; 	perror("fopen");
; 	continue;
;       }
;       cat(fp);
;       fclose(fp);
;     }
;   }
;   return 0;
; }

global main
main:
    .argc: equ 4
    .argv: equ 12
    .i:    equ 16
    .fp:   equ 24

	enter	32, 0
	mov	r15, 0
	mov	DWORD[rbp - .argc], edi
	mov	QWORD[rbp - .argv], rsi

	cmp	DWORD[rbp - .argc], 2
	jge	.argvloop

	mov	rdi, QWORD [ stdin ]
	call	cat
	jmp	.exit

.argvloop:

	mov	DWORD[rbp - .i], 1
.forloop:
	mov	r15d, DWORD[rbp - .i]
	cmp	r15d, DWORD[rbp - .argc]
	jge	.exit

	mov	rsi, QWORD [ rbp - .argv]
	mov	rdi, QWORD [ rsi + r15 * 8 ]
	mov	rsi, readonly
	call	fopen
	mov	QWORD [ rbp - .fp], rax
	cmp	rax, NULL
	jne	.catit
	mov	rdi, openerr
	call	perror
	jmp	.continue

.catit:
	mov	rdi, QWORD [ rbp - .fp]
	call	cat
	mov	rdi, QWORD [ rbp - .fp]
	call	fclose

.continue:
	inc	DWORD[rbp - .i]
	jmp	.forloop

.exit:
	leave
	mov	eax, 0
	ret
