;Programa em C que chama uma rotina feita em assembly para calcular o volume de um cone usando a FPU,
;tal rotina deve retornar o resultado para o programa principal em C e esse programa deve printar a resposta.
;Atenção, considere que todos os parâmetros da rotina são em float assim como seu retorno

;1. como calcula volume de um cone?
;pi * raio * raio * altura / 3
;primeiro empilho os valores de raio e altura
;depois multiplico raio * raio
;depois multiplico pi * raio * raio
;depois multiplico pi * raio * raio * altura
;depois divido por 3
;depois retorno o resultado

SECTION .data
    tres dd 3.0

SECTION .text
    global calc_volume_cone

calc_volume_cone:
    enter 8,0           ;prepara stack frame (8 bytes para variáveis locais, no caso, raio e altura)
    finit               ;inicializa a FPU
    fldpi               ;empilha o valor de pi
    fld dword[ebp+8]    ;empilha o valor de raio
    fmul st0, st0       ;multiplica o valor de raio por ele mesmo e empilha o resultado
    fmulp               ;desempilha o resultado de raio * raio e multiplica por pi
    fld dword[ebp+12]   ;empilha o valor de altura
    fmulp               ;desempilha o resultado de pi * raio * raio e multiplica por altura
    fld dword[tres]     ;empilha o valor de 3
    fdivp               ;desempilha o resultado de pi * raio * raio * altura e divide por 3
    leave               ;desfaz o stack frame
    ret