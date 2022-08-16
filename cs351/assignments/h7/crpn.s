	.file	"crpn.c"
	.text
	.comm	input,8,8
	.globl	pos
	.bss
	.align 4
	.type	pos, @object
	.size	pos, 4
pos:
	.zero	4
	.comm	numstack,4096,32
	.globl	nsp
	.align 4
	.type	nsp, @object
	.size	nsp, 4
nsp:
	.zero	4
	.text
	.globl	get
	.type	get, @function
get:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	input(%rip), %rdx
	movl	pos(%rip), %eax
	cltq
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L2
	movl	$-1, %eax
	jmp	.L3
.L2:
	movq	input(%rip), %rcx
	movl	pos(%rip), %eax
	leal	1(%rax), %edx
	movl	%edx, pos(%rip)
	cltq
	addq	%rcx, %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
.L3:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	get, .-get
	.globl	unget
	.type	unget, @function
unget:
.LFB7:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	pos(%rip), %eax
	testl	%eax, %eax
	je	.L6
	movq	input(%rip), %rdx
	movl	pos(%rip), %eax
	cltq
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	je	.L6
	movl	pos(%rip), %eax
	subl	$1, %eax
	movl	%eax, pos(%rip)
.L6:
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	unget, .-unget
	.globl	next
	.type	next, @function
next:
.LFB8:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movq	input(%rip), %rdx
	movl	pos(%rip), %eax
	cltq
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	cmpl	%eax, -4(%rbp)
	jne	.L8
	movl	pos(%rip), %eax
	addl	$1, %eax
	movl	%eax, pos(%rip)
	movl	$1, %eax
	jmp	.L9
.L8:
	movl	$0, %eax
.L9:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	next, .-next
	.globl	lex
	.type	lex, @function
lex:
.LFB9:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -40(%rbp)
.L11:
	call	get
	movl	%eax, -24(%rbp)
	call	__ctype_b_loc@PLT
	movq	(%rax), %rax
	movl	-24(%rbp), %edx
	movslq	%edx, %rdx
	addq	%rdx, %rdx
	addq	%rdx, %rax
	movzwl	(%rax), %eax
	movzwl	%ax, %eax
	andl	$8192, %eax
	testl	%eax, %eax
	jne	.L11
	movl	-24(%rbp), %eax
	addl	$1, %eax
	cmpl	$48, %eax
	ja	.L12
	movl	%eax, %eax
	leaq	0(,%rax,4), %rdx
	leaq	.L14(%rip), %rax
	movl	(%rdx,%rax), %eax
	cltq
	leaq	.L14(%rip), %rdx
	addq	%rdx, %rax
	notrack jmp	*%rax
	.section	.rodata
	.align 4
	.align 4
.L14:
	.long	.L20-.L14
	.long	.L12-.L14
	.long	.L12-.L14
	.long	.L12-.L14
	.long	.L12-.L14
	.long	.L12-.L14
	.long	.L12-.L14
	.long	.L12-.L14
	.long	.L12-.L14
	.long	.L12-.L14
	.long	.L12-.L14
	.long	.L12-.L14
	.long	.L12-.L14
	.long	.L12-.L14
	.long	.L12-.L14
	.long	.L12-.L14
	.long	.L12-.L14
	.long	.L12-.L14
	.long	.L12-.L14
	.long	.L12-.L14
	.long	.L12-.L14
	.long	.L12-.L14
	.long	.L12-.L14
	.long	.L12-.L14
	.long	.L12-.L14
	.long	.L12-.L14
	.long	.L12-.L14
	.long	.L12-.L14
	.long	.L12-.L14
	.long	.L12-.L14
	.long	.L12-.L14
	.long	.L12-.L14
	.long	.L12-.L14
	.long	.L12-.L14
	.long	.L12-.L14
	.long	.L12-.L14
	.long	.L12-.L14
	.long	.L12-.L14
	.long	.L12-.L14
	.long	.L12-.L14
	.long	.L12-.L14
	.long	.L19-.L14
	.long	.L18-.L14
	.long	.L17-.L14
	.long	.L16-.L14
	.long	.L12-.L14
	.long	.L15-.L14
	.long	.L12-.L14
	.long	.L13-.L14
	.text
.L20:
	movl	$8, %eax
	jmp	.L21
.L16:
	movl	$1, %eax
	jmp	.L21
.L15:
	movl	$2, %eax
	jmp	.L21
.L13:
	movl	$4, %eax
	jmp	.L21
.L19:
	movl	$6, %eax
	jmp	.L21
.L18:
	movl	$7, %eax
	jmp	.L21
.L17:
	movl	$42, %edi
	call	next
	testl	%eax, %eax
	je	.L22
	movl	$5, %eax
	jmp	.L21
.L22:
	movl	$3, %eax
	jmp	.L21
.L12:
	call	__ctype_b_loc@PLT
	movq	(%rax), %rax
	movl	-24(%rbp), %edx
	movslq	%edx, %rdx
	addq	%rdx, %rdx
	addq	%rdx, %rax
	movzwl	(%rax), %eax
	movzwl	%ax, %eax
	andl	$2048, %eax
	testl	%eax, %eax
	je	.L23
	movl	$0, -20(%rbp)
.L24:
	movl	-20(%rbp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	movl	%eax, -20(%rbp)
	movl	-24(%rbp), %eax
	subl	$48, %eax
	addl	%eax, -20(%rbp)
	call	__ctype_b_loc@PLT
	movq	(%rax), %rbx
	call	get
	movl	%eax, -24(%rbp)
	movl	-24(%rbp), %eax
	cltq
	addq	%rax, %rax
	addq	%rbx, %rax
	movzwl	(%rax), %eax
	movzwl	%ax, %eax
	andl	$2048, %eax
	testl	%eax, %eax
	jne	.L24
	call	unget
	movq	-40(%rbp), %rax
	movl	-20(%rbp), %edx
	movl	%edx, (%rax)
	movl	$0, %eax
	jmp	.L21
.L23:
	movl	$9, %eax
.L21:
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	lex, .-lex
	.globl	push
	.type	push, @function
push:
.LFB10:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	nsp(%rip), %eax
	leal	1(%rax), %edx
	movl	%edx, nsp(%rip)
	cltq
	leaq	0(,%rax,4), %rcx
	leaq	numstack(%rip), %rdx
	movl	-4(%rbp), %eax
	movl	%eax, (%rcx,%rdx)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	push, .-push
	.section	.rodata
.LC0:
	.string	"Stack underflow."
	.text
	.globl	pop
	.type	pop, @function
pop:
.LFB11:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	nsp(%rip), %eax
	testl	%eax, %eax
	jne	.L27
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
	movl	$1, %edi
	call	exit@PLT
.L27:
	movl	nsp(%rip), %eax
	subl	$1, %eax
	movl	%eax, nsp(%rip)
	movl	nsp(%rip), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	numstack(%rip), %rax
	movl	(%rdx,%rax), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	pop, .-pop
	.section	.rodata
.LC1:
	.string	"Usage: <expression-string>"
.LC2:
	.string	"%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB12:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movl	%edi, -36(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	cmpl	$1, -36(%rbp)
	jg	.L30
	leaq	.LC1(%rip), %rdi
	call	puts@PLT
	movl	$0, %eax
	jmp	.L41
.L30:
	movq	-48(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, input(%rip)
	nop
	jmp	.L33
.L40:
	cmpl	$4, -20(%rbp)
	ja	.L33
	movl	-20(%rbp), %eax
	leaq	0(,%rax,4), %rdx
	leaq	.L35(%rip), %rax
	movl	(%rdx,%rax), %eax
	cltq
	leaq	.L35(%rip), %rdx
	addq	%rdx, %rax
	notrack jmp	*%rax
	.section	.rodata
	.align 4
	.align 4
.L35:
	.long	.L39-.L35
	.long	.L38-.L35
	.long	.L37-.L35
	.long	.L36-.L35
	.long	.L34-.L35
	.text
.L39:
	movl	-24(%rbp), %eax
	movl	%eax, %edi
	call	push
	jmp	.L33
.L38:
	call	pop
	movl	%eax, -16(%rbp)
	call	pop
	movl	%eax, -12(%rbp)
	movl	-12(%rbp), %edx
	movl	-16(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, %edi
	call	push
	jmp	.L33
.L37:
	call	pop
	movl	%eax, -16(%rbp)
	call	pop
	movl	%eax, -12(%rbp)
	movl	-12(%rbp), %eax
	subl	-16(%rbp), %eax
	movl	%eax, %edi
	call	push
	jmp	.L33
.L36:
	call	pop
	movl	%eax, -16(%rbp)
	call	pop
	movl	%eax, -12(%rbp)
	movl	-12(%rbp), %eax
	imull	-16(%rbp), %eax
	movl	%eax, %edi
	call	push
	jmp	.L33
.L34:
	call	pop
	movl	%eax, -16(%rbp)
	call	pop
	movl	%eax, -12(%rbp)
	movl	-12(%rbp), %eax
	cltd
	idivl	-16(%rbp)
	movl	%eax, %edi
	call	push
	nop
.L33:
	leaq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	lex
	movl	%eax, -20(%rbp)
	cmpl	$8, -20(%rbp)
	jne	.L40
	call	pop
	movl	%eax, %esi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
.L41:
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L42
	call	__stack_chk_fail@PLT
.L42:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE12:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
