;Complete o código assembly abaixo utilizando instruções de ponto flutuante para
;implementar o cálculo do volume de um cone (PI * altura * raio²/3)

global calcVol
extern scanf

calcVol:
    finit
    enter 0,0

    mov eax, [ebp+8]    ;guarda o endereço de volume em eax
    fld dword[ebp+12]   ;empilha raio
    fld dword[ebp+12]   ;empilha raio
    fmulp               ;raio*raio
    fldpi               ;empilha pi
    fmulp               ;pi*raio*raio
    fld dword[ebp+16]   ;empilha altura
    fmulp               ;altura*pi*raio*raio
    fld1                ;empilha 3 (1+1+1)
    fld1
    faddp
    fld1
    faddp
    fdivp               ;divide (altura*pi*raio*raio)/3
    fstp dword[eax]     ;armazena o resultado em volume
    leave
    ret
