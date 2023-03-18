section .data
vetor dd 5,10,2
SIZE dd 3
Msg db "min = %d",0x0a,0x00

section .text
extern min, printf
global main

main:
	push dword [SIZE]
	push dword vetor
	call min
	add esp,8
	push eax
	push dword Msg
	call printf
	add esp,8
	mov eax,1
	mov ebx,0
	int 0x80
