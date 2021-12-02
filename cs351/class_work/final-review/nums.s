extern scanf, printf

SECTION .data
    sfmt: db "%d", 0
    pfmt: db `%d: %d\n`, 0

SECTION .bss
    nums: resd	1000

SECTION .text

global main
main:
  .value: equ 4
    .idx: equ 8

	enter	16,0

	mov	DWORD[rbp - .idx], 0	; idx = 0;

.while:
	mov	rdi, sfmt
	lea	rsi, [rbp - .value]
	call	scanf

	cmp	eax, 1
	jne	.stoploop			; while (scanf("%d", &value) == 1) {

	mov	esi, DWORD[rbp - .value]
	mov	edi, DWORD[rbp - .idx]
	mov	DWORD[nums + edi*4], esi	;   nums[idx] = value;

	inc	DWORD[rbp - .idx];		;   idx++;

	jmp	.while				; }

.stoploop:

	mov	r15d, 0

.printloop:
	cmp	r15d, DWORD[rbp - .idx]
	je	.printdone

	mov	rax, 0
	mov	rdi, pfmt
	mov	esi, r15d
	mov	edx, DWORD[nums + r15 * 4]
	call	printf				; printf("%d: %d\n", r15, nums[r15]);

	inc	r15d
	jmp	.printloop

.printdone:

	mov	rax, 0
	leave
	ret
