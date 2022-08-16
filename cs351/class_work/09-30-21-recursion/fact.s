; unsigned long fact(int num)
; {
;   if (num < 2) return 1;
;   return num * fact(num - 1);
; }

section .text


; parameter in rdi(edi), return value in rax
global fact
fact:
  .num: equ 4

	enter	4, 0

	mov	DWORD[rbp-.num], edi
	cmp	edi, 2
	jge	.compute

	mov	rax, 1
	leave
	ret

.compute:
	dec	edi
	call	fact
	movsx	rdi, DWORD[rbp-.num]
	imul	rax, rdi
	leave
	ret
