;programa em assembly modo real que conta a quantidade de vogais numa string declarada na memória e printa essa informação na tela.

ORG 0x7C00		        ;bios
BITS 16			        ;código de 16 bits

    jmp start

str: db "Biscoito ou bolacha? NAO IMPORTA", 0x0D, 0x0A, 0x00    ;string a ser analisada
msg_print1: db "A string tem ", 0x00                ;string que será printada na tela
msg_print2: db " vogais.", 0x0D, 0x0A, 0x00         ;string que será printada na tela

start:
	xor ax, ax	        ;zera os registradores
    xor bx, bx
    xor cx, cx

    mov si, msg_print1  ;ponteiro para a string 1 que será printada na tela
    call print_str      ;chama a rotina que printa a string na tela
    xor ax, ax          ;limpa o registrador ax

    call conta_vogal    ;chama a rotina que conta as vogais
    call print_number   ;chama a rotina que printa o número na tela
    
    mov si, msg_print2  ;ponteiro para a string 2 que será printada na tela
    call print_str

end:
    jmp $               ;halt

conta_vogal:
    mov si, str         ;ponteiro para a string a ser analisada

    .loop:
        lodsb           ;carrega o caractere atual para al e incrementa o ponteiro

        mov bx, 65      ;A
        cmp ax, bx      ;compara o caractere atual com A
        je .conta_um    ;se for igual, pula para a rotina que incrementa o contador
        add bx, 32      ;aumenta o valor de A em 32 para comparar com a minúscula
        cmp ax, bx      ;compara o caractere atual com a
        je .conta_um    ;se for igual, pula para a rotina que incrementa o contador

        mov bx, 69      ;E
        cmp ax, bx
        je .conta_um
        add bx, 32
        cmp ax, bx
        je .conta_um

        mov bx, 73      ;I
        cmp ax, bx
        je .conta_um
        add bx, 32
        cmp ax, bx
        je .conta_um

        mov bx, 79      ;O
        cmp ax, bx
        je .conta_um
        add bx, 32
        cmp ax, bx
        je .conta_um

        mov bx, 85      ;U
        cmp ax, bx
        je .conta_um
        add bx, 32
        cmp ax, bx
        je .conta_um

        jmp .checkend   ;se não for nenhuma das vogais, pula para a rotina que verifica se acabou a string
    
    .conta_um:
        inc cx          ;incrementa o contador
        jmp .checkend   ;pula para a rotina que verifica se acabou a string

    .checkend:
        or al, al       ;se for 0, aciona a flag ZF
        jz .done        ;se ZF=1, vai pra .done
        jmp .loop       ;senão, volta para o .loop
    
    .done:
        mov ax, cx      ;guarda o contador em ax
        ret

print_str:
    .loop:
        lodsb
        or al, al
        jz .done
        mov ah, 0x0E    ;int 10h, função 0Eh
        int 0x10        ;chama o serviço de interrupção 10h
        jmp .loop

    .done:
        ret

print_number:
    mov bx, 10          ;divisor
    mov cx, 0           ;novo contador
                        ;note que o dividendo está em ax, que foi guardado pela rotina anterior

    .loop1:
        mov dx, 0       ;zera o reg dx (por segurança)
        div bx          ;divide o ax pelo bx, guarda o quociente em ax e o resto em dx
        add dx, 48      ;converte o resto para char
        push dx         ;empilha o resto
        inc cx          ;incrementa o contador
        cmp ax, 0       ;compara o quociente com 0 para saber quando acabou a divisão
        jne .loop1      ;se não acabou, volta para o .loop1

    .loop2:
        pop ax          ;desempilha o resto
        mov ah, 0x0E
        int 0x10
        loop .loop2     ;decrementa o contador e volta para o começo se não for 0
    
    .done:
        ret

boot_sig:
    times 510-($-$$) db 0
    dw 0xAA55