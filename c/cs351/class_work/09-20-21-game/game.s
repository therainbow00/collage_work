extern rand, puts, getc, exit

section .data
      correct: db `That's right!\n`, 0
     lessthan: db `Too low.\n`, 0
  greaterthan: db `Too high.\n`, 0
       prompt: db `Input a digit: `, 0
      goodbye: db `Goodbye!\n`, 0

section .bss
    num: resb 1

section .text

picknum:
	call	rand
	mov	ah, 0
	mov	bl, 10
	div	bl		; al = (ax / bl), ah = (ax % bl)
	mov	BYTE [num], ah
	ret

global _start
_start:

	call	picknum

.loop:
	mov	rsi, prompt
	call	puts

	call	getc
	cmp	al, 'q'
	je	.done
	cmp	al, -1
	je	.done

	; is it a digit:
	; if (al >= '0' && al <= '9')
	cmp	al, '0'
	jl	.drain
	cmp	al, '9'
	jg	.drain

	sub	al, '0'		; al = al - '0';

	cmp	al, BYTE [num]
	je	.correct
	jl	.lessthan

	mov	rsi, greaterthan
	call	puts
	jmp	.drain

.lessthan:
	mov	rsi, lessthan
	call	puts
	jmp	.drain

.correct:
	mov	rsi, correct
	call	puts
	call	picknum


; drain input of all characters up to the newline
; do { al = getc(); } while (al != '\n');

.drain:
	call	getc
	cmp	al, `\n`
	jne	.drain
	jmp	.loop

.done:
	mov	rsi, goodbye
	call	puts
	mov	rdi, 0
	call	exit
