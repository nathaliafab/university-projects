;interrupção é um evento que faz o processador interromper a execução de um programa
;em seguida, o processador salva o estado atual do programa e executa um programa de tratamento de interrupção (ISR)
;quando o processador termina de executar o programa de ISR, ele retorna ao programa que estava sendo executado

;o processador pode ser configurado para gerar interrupções de hardware ou software (INT)
;INT é um comando que faz o processador interromper a execução de um programa
;tipos de eventos: divisão por zero, acesso indevido da memória, leitura do teclado, IRQs, etc

;o endereço de cada ISR (CS:IP) é armazenado em uma região de memória conhecida como IVT (Interrupt Vector Table)
;IVT é uma tabela de 256 entradas, cada entrada contém um endereço de 16 bits (CS:IP) de um programa de tratamento de interrupção
;CS: 2 bytes, IP: 2 bytes, total: 4 bytes
;1024 bytes/4 bytes = 256 entradas (0 a 255)

;Exemplo: onde está o INT 21h?
;21h * 4 bytes = 84h
;0h (segmento) + 84h (offset) = 84h -> 0h:84h

;Esquema do processamento de interrupções:
;1.     O processador detecta um evento de interrupção
;2.     O processador salva o estado atual do programa (CS:IP) na pilha
;3.     O processador salva o valor da flag IF na pilha
;3.5.   O processador salva o valor da flag TF na pilha
;4.     O processador desabilita as interrupções (IF = 0)
;4.5.   O processador desabilita a geração de interrupções (TF = 0)
;5.     O processador busca o endereço de tratamento de interrupção (CS:IP) na IVT
;6.     O processador salta para o endereço de tratamento de interrupção (CS:IP)
;7.     O processador executa o programa de tratamento de interrupção
;8.     O processador retorna para o programa que estava sendo executado
;9.     O processador restaura o valor da flag IF
;9.5.   O processador restaura o valor da flag TF
;10.    O processador restaura o estado atual do programa (CS:IP) da pilha

;Implementando uma interrupção:
;Supondo que a ISR da interrupção 50h está no endereço 25650h na memória, como configurar a posição da IVT?
;1.     Determinar valores de CS e IP (CS será deslocado 4 bits para a esquerda e somado com IP) que resultem no endereço 25650h
;2.     Determinar um valor válido para CS (por exemplo: 2562h)
;3.     Deslocar CS 4 bits para a esquerda (CS << 4 = 25620h)
;4.     Determinar um valor válido para IP (30h)
;5.     Verificar CS + IP (25620h + 30h = 25650h)
;6.     Calcular o endereço da IVT (50h * 4 = 140h)
;7.     Configurar a IVT (0h:140h = 25620h:30h)

;Exemplo: configurando a IVT para a interrupção 50h
;;push    ds                  ;salva o valor de DS na pilha
;;mov     ax, 0               ;zera AX
;;mov     ds, ax              ;zera DS
;;mov     di, 0140h           ;offset da interrupção 50h na IVT
;;mov     word[di], 30h       ;salvando o valor de IP
;;mov     word[di+2], 2562h   ;salvando o valor de CS
;;pop     ds                  ;restaura o valor de DS
;ds:di = 0h:140h = 2562h:30h = endereço da interrupção 50h na IVT
;cs:ip = 2562h:30h = endereço da ISR da interrupção 50h

;Exemplo: configurando a IVT para a interrupção 50h (forma simplificada)
;;mov     word[0140h], 30h    ;salvando o valor de IP
;;mov     word[0142h], 2562h  ;salvando o valor de CS
;ds:di = 0h:140h = 2562h:30h = endereço da interrupção 50h na IVT
;cs:ip = 2562h:30h = endereço da ISR da interrupção 50h

;Padrão de implementação de uma ISR:	
;1.     Empilhar os registradores que serão usados
;2.     Escrever o código da ISR
;3.     Desempilhar os registradores que foram usados
;4.     Retornar para o programa que estava sendo executado (iret)

;------------------------------------------------------------------------------------------------------------------------------

ORG 0x7C00		        ;bios
BITS 16			        ;código de 16 bits

	jmp start

hello: db "Hello world!", 0x0D, 0x0A, 0
msg: db "Escreva algo: ", 0
fim: db "Fim do programa", 0x0D, 0x0A, 0

start:
	mov ax, hello     ;carrega o endereço de hello em ax
    push ax           ;empilha ax
    call print_str

    mov ax, msg       ;carrega o endereço de msg em ax
    push ax           ;empilha ax
    call print_str
    call get_keyboard_input

end:
    mov ax, fim       ;carrega o endereço de fim em ax
    push ax           ;empilha ax
    call print_str
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
        ret

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
