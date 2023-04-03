;Complete o código assembly abaixo utilizando instruções de ponto flutuante para
;implementar o cálculo do volume de um cone (PI * altura * raio²/3)

SECTION .data

SECTION .text

global calcVol

calcVol:
    finit
    enter 0,0
    fld dword[ebp+8]    ;empilha raio
    fld dword[ebp+8]    ;empilha raio
    fmulp               ;raio*raio
    fldpi               ;empilha pi
    fmulp               ;pi*raio*raio
    fld dword[ebp+12]   ;empilha altura
    fmulp               ;altura*pi*raio*raio
    fld1                ;empilha 3 (1+1+1)
    fld1
    faddp
    fld1
    faddp
    fdivp               ;divide (altura*pi*raio*raio)/3
    fst dword[ebp+16]   ;armazena o resultado em volume
    leave
    ret
