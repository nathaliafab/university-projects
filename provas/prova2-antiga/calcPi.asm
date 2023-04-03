;Objetivo: função que calcula pi através de série de Sangamagrama-Leibniz.
;Sangamagrama-Leibniz: somatório de k=0 até n de [(-1)^k / (2k + 1)]

SECTION .data
    read_n    db      "%d",0x00
    print_n   db      "n = %d", 0x0a, 0x00
    pi db 0.0
    n db 0

SECTION .text
    global calcularPI
    extern scanf, printf

calcularPI:
    finit
    enter 0,0
    
    read_n_value:
        mov eax, [ebp+12]
        push eax
        push dword read_n
        call scanf
        add esp, 8

    print_n_value:
        mov eax, [ebp+12]   ;carrega o endereço de n em eax
        push dword [eax]    ;empilha o valor de n
        push print_n        ;empilha a string de formato para printf
        call printf         ;imprime o valor de n
        add esp, 8          ;remove os argumentos da pilha

    ;-----------------------------------SEGFAULT EM ALGUM LUGAR:
    mov eax, [ebp+12]
    mov [n], eax       ;guarda o valor de n na variável local n
    mov eax, [ebp+8]   ;carrega o endereço de pi em eax
    
    fldz                ;empilha o valor de k (inicialmente 0)
    fldz                ;empilha o valor de 0
    fld1                ;empilha o valor de 1
    fsubp               ;subtrai 1 de 0, desempilha o st1 e empilha o resultado
    fldz                ;empilha o valor de 0
    fld1                ;empilha o valor de 1
    fsubp               ;subtrai 1 de 0, desempilha o st1 e empilha o resultado
    ;status da pilha:
        ;st0 = -1
        ;st1 = -1
        ;st2 = k

    make_sum:
        xor ecx, ecx            ;aqui será o nosso contador
        minus1_pow_k:
            fmul st1            ;multiplica st0 por st1 e guarda o resultado em st0
            fild dword[ecx]     ;empilha o contador
            fcomp st3           ;compara com o k e desempilha o contador
            je two_k_plus1
            inc ecx
            jmp minus1_pow_k
            ;status da pilha:
                ;st0 = (-1)^k
                ;st1 = -1
                ;st2 = k
        two_k_plus1:
            fild dword[ecx]     ;empilha o valor de k
            fild dword[ecx]     ;empilha o valor de k
            faddp               ;soma k + k, desempilha o k (st0) e põe o resultado no outro k (st1) => st1 vira st0
            fld1                ;empilha o valor de 1
            faddp               ;soma 1 + (k + k), desempilha o 1 e põe o resultado no (k + k) => st1 vira st0
            jmp division
            ;status da pilha:
                ;st0 = 2*k + 1
                ;st1 = (-1)^k
                ;st2 = -1
                ;st3 = k
        division:
            fdivp st1, st0      ;divide st1 por st0, desempilha e empilha o resultado
            fld dword[pi]       ;empilha o valor de pi atual
            faddp               ;soma parcial + pi, desempilha o pi e põe o resultado no st1 => st1 vira st0
            fstp dword[pi]      ;guarda o resultado em pi e desempilha
            jmp organize_stack
            ;status da pilha:
                ;st0 = -1
                ;st1 = k
        organize_stack:
            fild dword[n]       ;empilha o n
            fcomp st2           ;compara k com n e desempilha o n
            je end
            fldz                ;empilha o valor de 0
            fld1                ;empilha o valor de 1
            fsubp               ;subtrai 1 de 0, desempilha o st1 e empilha o resultado
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
            jmp make_sum
            ;status da pilha:
                ;st0 = -1
                ;st1 = -1
                ;st2 = k + 1
        end:
            fld dword[pi]       ;empilha o resultado
            fstp dword[eax]     ;desempilha, armazenando em eax (que aponta pra pi)
    leave
    ret
