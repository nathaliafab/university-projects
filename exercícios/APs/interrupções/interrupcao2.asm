ORG 0x7C00		        ;bios
BITS 16			        ;código de 16 bits

	jmp start

msg: db "Escreva algo: ", 0

start:
    configurando_IVT:
        push ds
        xor ax, ax
        mov ds, ax

        mov di, 0x100   ;endereço da interrupção 40h (40h * 4 = 100h -> 64d * 4 = 256d)
        mov word[di], get_keyboard_input
        mov word[di+2], 0

        pop ds
        
    mov ax, msg       ;carrega o endereço de msg em ax
    push ax           ;empilha ax
    call print_str
    int 40h           ;chama a interrupção 40h (que eu configurei para ser a get_keyboard_input)

end:
    jmp $

get_keyboard_input:
    pusha              ;salva todos os registradores na pilha (salva o contexto)
    .loop:
        mov ah, 0x00    ;leitura do teclado
        int 0x16        ;chama a interrupção 16h (leitura do teclado)
                        ;o char digitado está em al
        cmp al, 0x0D
        je .done        ;se o char digitado for enter, sai do loop
        mov ah, 0x0E    ;imprime o char digitado
        int 0x10        ;chama a interrupção 10h (impressão na tela)
        jmp .loop

    .done:
        popa            ;restaura todos os registradores da pilha (restaura o contexto)
        iret            ;retorna da interrupção

print_str:
    push bp            ;salva o valor de bp na pilha
    mov bp, sp         ;move o valor de sp para bp
    ;; status da pilha:
    ;; bp+0 -> bp antigo (push bp empilhou o valor de bp)
    ;; bp+2 -> offset de retorno de print_str (call print_str empilhou o offset de retorno)
    ;; bp+4 -> endereço de hello (push ax empilhou o endereço de hello)
    mov ax, [bp+4]    ;move o endereço de hello para ax
    mov si, ax        ;move o endereço de hello para si
    .loop:
        lodsb
        or al, al
        jz .done
        mov ah, 0x0E
        int 0x10
        jmp .loop

    .done:
        pop bp         ;restaura o valor de bp
        ret 2          ;preciso desempilhar 2 bytes porque tem 1 parâmetro (2 bytes) na pilha (push ax)

boot_sig:
    times 510-($-$$) db 0
    dw 0xAA55
