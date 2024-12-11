ORG 0x7C00		        ;bios
BITS 16			        ;código de 16 bits

	jmp start

msg: db "Hello world!", 0x0D, 0x0A, 0   ;0x0D > move o cursor p/ início
                                        ;0x0A > fim da string
                                        ;semelhante ao \n do C

start:
	xor ax, ax	        ;zera o reg ax
	mov ds, ax	        ;zera data segment
	mov es, ax	        ;zera extra segment
	mov ss, ax	        ;zera stack segment

    mov si, msg         ;um ponteiro para "H" em msg
    ;lodsb               ;carrega si em al, dps disso o si aponta pra "e"
    ;mov ah, 0x0E
    ;int 0x10            ;printa o "H"

    ;mov al, byte[si]    ;carrega o byte que si aponta em al
    ;int 0x10            ;printa o "e"
    call print_str

end:
    jmp $               ;halt

print_str:
    .loop:
        lodsb
        or al, al       ;se for 0, ZF=1
        jz .done        ;se ZF=1, vai pra .done
        mov ah, 0x0E
        int 0x10
        jmp .loop       ;o "." é como uma label interna

    .done:
        ret             ;retorna

boot_sig:
    times 510-($-$$) db 0
    dw 0xAA55