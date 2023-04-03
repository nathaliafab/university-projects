;Objetivo: função que calcula pi através de série de Sangamagrama-Leibniz.
;Sangamagrama-Leibniz: somatório de k=0 até n de [(-1)^k / (2k + 1)]

SECTION .data
    read_n    db      "%d",0x00
    print_n   db      "n = %d", 0x0a, 0x00

SECTION .text
    global calcularPI
    extern scanf, printf

calcularPI:
    enter 8,0
    
    read_n_value:
        mov eax, [ebp+12]
        push eax
        push dword read_n
        call scanf
        add esp, 8

    print_n_value:
        mov eax, [ebp+12] ; carrega o endereço de n em eax
        push dword [eax] ; empilha o valor de n
        push print_n ; empilha a string de formato para printf
        call printf ; imprime o valor de n
        add esp, 8 ; remove os argumentos da pilha

    ;Segmentation Fault em algum lugar aqui p/ baixo
    xor eax,eax         ;aqui será o nosso k
    mov dword[ebp+8], 0 ;inicializa pi com 0
    finit               ;inicializa a pilha de ponto flutuante
    fldz                ;empilha o valor de k (inicialmente 0)
    fldz                ;empilha o valor de 0
    fld1                ;empilha o valor de 1
    fsubp               ;subtrai 1 de 0, desempilha o st1 e empilha o resultado no st0
    fldz                ;empilha o valor de 0
    fld1                ;empilha o valor de 1
    fsubp               ;subtrai 1 de 0, desempilha o st1 e empilha o resultado no st0
    ;status da pilha:
        ;st0 = -1
        ;st1 = -1
        ;st2 = k

    iterate:
        xor ecx,ecx         ;aqui será o nosso contador
        pt1:
            fmul st1        ;multiplica st0 por st1 e guarda o resultado no st0
            cmp ecx, eax
            je pt2
            inc ecx
            jmp pt1
            ;status da pilha:
                ;st0 = (-1)^k
                ;st1 = -1
                ;st2 = k
        pt2:
            fild dword[eax]  ;empilha o valor de k
            fild dword[eax]  ;empilha o valor de k
            faddp           ;soma k + k, desempilha o st0 e põe o resultado no st1 => st1 vira st0
            fld1            ;empilha o valor de 1
            faddp           ;soma 1 + k + k, desempilha o st0 e põe o resultado no st1 => st1 vira st0
            jmp pt3
            ;status da pilha:
                ;st0 = 2*k + 1
                ;st1 = (-1)^k
                ;st2 = -1
                ;st3 = k
        pt3:
            fdivp st1, st0          ;divide st1 por st0, desempilha e empilha o resultado no st0
            fld dword[ebp+8]         ;empilha o valor de pi atual
            faddp                 ;soma parcial + pi, desempilha o st0 e põe o resultado no st1 => st1 vira st0
            fstp dword[ebp+8]        ;guarda o resultado em pi e desempilha
            jmp pt4
            ;status da pilha:
                ;st0 = -1
                ;st1 = k
        pt4:
            cmp eax, dword[ebp+12]  ;compara k com n
            je end
            fldz                ;empilha o valor de 0
            fld1                ;empilha o valor de 1
            fsubp               ;subtrai 1 de 0, desempilha o st1 e empilha o resultado no st0
            ;status da pilha:
                ;st0 = -1
                ;st1 = -1
                ;st2 = k
            fxch st2            ;troca o topo com o st2 (k)
            fld1                ;empilha o valor de 1
            ;status da pilha:
                ;st0 = 1
                ;st1 = k
                ;st2 = -1
                ;st3 = -1
            faddp               ;soma k + 1, desempilha o st0 e põe o resultado no st1 => st1 vira st0
            fxch st2            ;desfaz a troca anterior
            inc eax             ;incrementa k
            jmp iterate
            ;status da pilha:
                ;st0 = -1
                ;st1 = -1
                ;st2 = k + 1
        end:
    leave
    ret
