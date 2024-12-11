;programa em assembly modo real que recebe uma string do teclado e guarda em uma região de memória
;depois executa interrupção 40h que recebe um parâmetro da pilha (offset da string) e imprime na tela
;tal interrupção deverá ser implementada e configurada na IVT

ORG 0x7C00		        ;bios
BITS 16			        ;código de 16 bits

    jmp start

placeholder times 30 db 0 ;reserva espaço para a string

start:
    xor ax, ax
    mov ds, ax
    mov es, ax
    mov ss, ax

    configurando_IVT:
        mov di, 0100H   ;endereço da interrupção 40h (40h * 4 = 100h)
        mov word[di], print_str
        mov word[di+2], 0

    mov di, placeholder
    call get_keyboard_input

    mov ax, placeholder ;move o offset da string para ax
    push ax             ;empilha o offset da string
    
    int 40h             ;chama a interrupção 40h (impressão na tela)
    jmp end

get_keyboard_input:
    .loop:
        mov ah, 0x00    ;leitura do teclado
        int 0x16        ;chama a interrupção 16h (leitura do teclado)
                        ;o char digitado está em al
        stosb           ;salva o char digitado na região de memória reservada
        cmp al, 0x0D
        je .done        ;se o char digitado for enter, sai do loop
        mov ah, 0x0E    ;impressão na tela
        int 0x10        ;chama a interrupção 10h (impressão na tela)
        jmp .loop

    .done:
        ret

print_str:
    push bp             ;salva o valor de bp na pilha
    mov bp, sp          ;move o valor de sp para bp
    mov si, [bp+8]      ;estão empilhados: bp, flags, cs, ip, e offset da string (0, 2, 4, 6, 8)
    .loop:
        lodsb           ;carrega o char da região de memória para al
        or al, al       ;se o char for nulo, sai do loop
        jz .done
        mov ah, 0x0E    ;impressão na tela
        int 0x10
        jmp .loop

    .done:
        pop bp          ;restaura o valor de bp
        iret            ;retorna da interrupção

end:
    jmp $               ;halt

boot_sig:
    times 510-($-$$) db 0
    dw 0xAA55
