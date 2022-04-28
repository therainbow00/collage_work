/*
 * compile with gcc -c func.c
 * disassemble with objdump -M intel -d func.o
 */
int foo(int a)
{
  return a*97;
}

/*
func.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <foo>:
   0:   55                      push   rbp
   1:   48 89 e5                mov    rbp,rsp
   4:   89 7d fc                mov    DWORD PTR [rbp-0x4],edi
   7:   8b 45 fc                mov    eax,DWORD PTR [rbp-0x4]
   a:   6b c0 61                imul   eax,eax,0x61
   d:   5d                      pop    rbp
   e:   c3                      ret
*/
