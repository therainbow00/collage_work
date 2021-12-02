extern puts

section .data
  digits: db "0123456789ABCDEF", 0
  nl: db `\n`, 0

section .bss
  str: resb 128

section .text

;  char *digits = "0123456789ABCDEF";
;
;  char str[128];
;  int rdi = 127;
;  str[rdi--] = '\0';
;
;  int r8 = rax < 0;
;  if (r8) rax = -rax;
;
;  do {
;    str[rdi--] = digits[rax % rbx (rdx)];
;    rax = rax / rbx;
;  } while (rax > 0);
;  if (r8) str[rdi--] = '-';
;
;  rdi++;
;  puts(str+rdi);

; Prints a number in rax in base given rbx
; registers used:

global printnum
printnum:
	mov	rdi, 127
	mov	BYTE [str + rdi], 0
	dec	rdi

	mov	r8, 0
	cmp	rax, 0
	jge	.loop

	mov	r8, 1
	neg	rax

.loop:
	cqo
	div	rbx
	mov	cl, BYTE [digits + rdx]
	mov	BYTE [str + rdi], cl
	dec	rdi

	cmp	rax, 0
	jg	.loop

	cmp	r8, 0
	je	.output

	mov	BYTE [str + rdi], '-'
	dec	rdi

.output:
	inc	rdi
	lea	rsi, [str + rdi]
	call	puts

	mov	rsi, nl
	call	puts

	ret
