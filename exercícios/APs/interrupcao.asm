;programa em assembly modo real que recebe uma string do teclado e guarda em uma região de memória
;depois executa interrupção 40h que recebe um parâmetro da pilha (offset da string) e imprime na tela
;tal interrupção deverá ser implementada e configurada na IVT

ORG 0x7C00		        ;bios
BITS 16			        ;código de 16 bits

    jmp start

start:


end:
    jmp $               ;halt

boot_sig:
    times 510-($-$$) db 0
    dw 0xAA55
