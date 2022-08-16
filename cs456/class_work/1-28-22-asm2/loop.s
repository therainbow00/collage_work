; Compile with: nasm -felf64 loop.s
; Link with: gcc -o loop loop.o

extern printf

SECTION .data
  fmtstr: db `%d\n`, 0

SECTION .text

; Print the numbers 1 - 10:
; int main(void) {
;   int i = 0;
;   while (i <= 10) {
;     printf("%d\n", i);
;     i++;
;   }
;   return 0;
; }

global main
main:					; int main(void)
  .i: equ 4				; {
	enter 16, 0

	mov	DWORD[rbp - .i], 1	;   int i = 1;

.while:					;   while (i <= 10) {
	cmp	DWORD[rbp - .i], 10
	jg	.done

	mov	rax, 0
	mov	rdi, fmtstr
	mov	esi, DWORD[rbp - .i]
	call	printf			;     printf("%d\n", i);

	inc	DWORD[rbp - .i]		;     i++;
	jmp	.while			;   }

.done:
	mov	edi, 0			;   return 0;
	leave
	ret				; }
