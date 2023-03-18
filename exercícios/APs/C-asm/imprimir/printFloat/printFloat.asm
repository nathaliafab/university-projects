; printFloat.asm usa "C" printf em um float
;
; Assemble:     nasm -f elf printFloat.asm
; Link:         gcc -m32 -o printFloat printFloat.o
; Run:          ./printFloat

extern printf                   ; a funcao C
extern scanf
SECTION .data                   

msg     db      "soma = %.20f",0x0a,0x00
msg2    db      "%f %f",0x00

x       dd      1.5
y       dd     2.0
z       dq      0
temp    dq      0
       
SECTION .text                  

global  main                    
main:                                  
       
	push y
	push x
	push dword msg2
	call scanf
	add esp,12
	
        fld     dword [x]              
        fld     dword [y]
        faddp 
        fstp    qword [z]               ; armazena soma em z
	
      	push dword [z+4]
      	push dword [z]  
        push    msg               ; endereco do formato string
        call    printf                  ; 
        add     esp, 12                 ; pop na pilha 3*4 bytes

        mov     eax, 1                  ; exit code, 0=normal
        mov     ebx, 0
        int     0x80                    ;
