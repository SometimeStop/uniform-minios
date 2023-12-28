extern main
extern exit
bits 32

[section .data]
db 0x90

[section .text]

global _start

_start:
	push 	eax
	push	ecx
	call	main
	push 	eax 
	call 	exit
