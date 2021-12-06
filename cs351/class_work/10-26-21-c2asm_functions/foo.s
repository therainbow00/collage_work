extern printf

section .data
  foofmt: db `%s -> %d\n`, 0
 mainfmt: db `foo = %d\n`, 0
   hello: db `Hello, world!`, 0

section .text

; int foo(int a, int b, char *str)
; {
;   printf("%s -> %d\n", str, a+b);
;   return a+b;
; }

; a:edi (int), b:esi (int), str:rdx (char *)
global foo
foo:
  .abstore: equ 4
	enter 16, 0

	add	edi, esi	; a = a+b;
	mov	DWORD[rbp-.abstore], edi

	;  printf("%s -> %d\n", str, a+b);
	mov	rax, 0
	mov	rdi, foofmt
	mov	rsi, rdx
	mov	edx, DWORD[rbp - .abstore]
	call	printf

	mov	eax, DWORD[rbp - .abstore]
	leave
	ret

; int main(void)
; {
;   printf("foo = %d\n", foo(1, 5, "Hello, world!"));
;
;   return 0;
; }

global main
main:
	enter 16, 0

	mov	edi, 1
	mov	esi, 5
	mov	rdx, hello
	call	foo

	mov	rdi, mainfmt
	mov	esi, eax
	mov	rax, 0
	call	printf

	mov	eax, 0
	leave
	ret
