extern putc, exit

section .data
    _c: db 'a'

section .text

global _start
_start:
	mov	al, BYTE [_c]
	call	putc

	inc	BYTE [_c]

	cmp	BYTE [_c], 'z'
	jle	_start

	mov	al, `\n`
	call	putc

	mov	rdi, 0
	call	exit
