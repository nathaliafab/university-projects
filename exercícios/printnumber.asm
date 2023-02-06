ORG 0x7C00		        ;bios
BITS 16			        ;código de 16 bits

start:
	xor ax, ax	        ;zera o reg ax
	mov ax, 255
    call print_number

end:
    jmp $               ;halt

print_number:
    mov bx, 10          ;dividendo
    mov cx, 0           ;contador

    .loop1:
        mov dx, 0       ;zera o reg dx (por segurança)
        div bx          ;divide o ax pelo bx, guarda o quociente em ax e o resto em dx
        add dx, 48      ;converte o resto para char
        push dx         ;empilha o resto
        inc cx          ;incrementa o contador
        cmp ax, 0       ;compara o quociente com 0 para saber quando acabou a divisão
        jne .loop1      ;se não acabou, volta para o começo

    .loop2:
        pop ax          ;desempilha o resto
        mov ah, 0x0E    ;int 10h, função 0Eh
        int 0x10        ;chama o serviço de interrupção 10h
        loop .loop2     ;decrementa o contador e volta para o começo se não for 0
    
    .done:
        ret

boot_sig:
    times 510-($-$$) db 0
    dw 0xAA55