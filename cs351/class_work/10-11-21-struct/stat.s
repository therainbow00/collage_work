extern printf, stat, perror

section .data
  usagemsg: db `Usage: stat <filename>\n`, 0
   staterr: db "stat", 0

    devfmt: db `device = %d\n`, 0
    inofmt: db `inode# = %d\n`, 0
   modefmt: db `mode   = %d\n`, 0
  nlinkfmt: db `nlink  = %d\n`, 0
    uidfmt: db `uid    = %d\n`, 0
    gidfmt: db `gid    = %d\n`, 0
   sizefmt: db `size   = %ld\n`, 0

section .bss
  st: resb 144


section .text

; argc == rdi, argv == rsi
global main
main:
  .st_dev  : equ 0 ; (8)
  .st_ino  : equ 8 ; (8)
  .st_mode : equ 24 ; (4)
  .st_nlink: equ 16 ; (8)
  .st_uid  : equ 28 ; (4)
  .st_gid  : equ 32 ; (4)
  .st_size : equ 48 ; (8)

	enter	16, 0

	cmp	rdi, 2
	jge	.continue

	mov	rax, 0
	mov	rdi, usagemsg
	call	printf

	leave
	mov	rax, 0
	ret

.continue:
	mov	rdi, QWORD [rsi + 8]
	mov	rsi, st
	call	stat
	cmp	rax, 0
	jge	.continue2

	mov	rdi, staterr
	call	perror
	leave
	mov	rax, 1
	ret

.continue2:

	mov	rax, 0
	mov	rdi, devfmt
	mov	rsi, QWORD [ st + .st_dev ]
	call	printf

	mov	rax, 0
	mov	rdi, inofmt
	mov	rsi, QWORD [ st + .st_ino ]
	call	printf

	mov	rax, 0
	mov	rdi, modefmt
	movsx	rsi, DWORD [ st + .st_mode ]
	call	printf

	mov	rax, 0
	mov	rdi, nlinkfmt
	mov	rsi, QWORD [ st + .st_nlink ]
	call	printf

	mov	rax, 0
	mov	rdi, uidfmt
	movsx	rsi, DWORD [ st + .st_uid ]
	call	printf

	mov	rax, 0
	mov	rdi, gidfmt
	movsx	rsi, DWORD [ st + .st_gid ]
	call	printf

	mov	rax, 0
	mov	rdi, sizefmt
	mov	rsi, QWORD [ st + .st_size ]
	call	printf

	leave
	mov	rax, 0
	ret
