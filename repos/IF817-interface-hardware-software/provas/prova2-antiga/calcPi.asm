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
        push n
        push read_n
        call scanf
        add esp, 8

    print_n_value:
        push dword [n]
        push print_n
        call printf
        add esp, 8
        
    ; Guarda valor no endereço de n
    mov eax, [n]
    mov ecx, [ebp + 12]
    mov [ecx], eax

    ; Colocando em ecx o valor de n
    mov ecx, [n]

    ; Caso ecx = 0 (lembrando que ecx = n nesse trecho), pulamos para o final do código
    cmp ecx, 0  
    je .end

    ; 2k + 1
    .two_k_plus1:
        fild dword[n]       ;empilha o valor de k
        fild dword[n]       ;empilha o valor de k
        faddp               ;soma k + k, desempilha o k (st0) e põe o resultado no outro k (st1) => st1 vira st0
        fld1                ;empilha o valor de 1
        faddp               ;soma 1 + (k + k), desempilha o 1 e põe o resultado no (k + k) => st1 vira st0    
        
        mov eax, [n]
        fld1                ;1 em st0, 2k + 1 em st1

    ; (-1)^k
    .pow:
        fchs                ;troca o sinal de -1 -> 1 ou 1 -> -1
        dec eax             ;k começa igual a n, e vai até 0
        cmp eax, 0
        je .division
        jmp .pow   

    .division:
        fdiv st1            ;((-1)^k)/(2k + 1) em st0, 2k + 1 em st0
        fstp st1            ;((-1)^k)/(2k + 1) em st0
        fld qword[pi]       ;sum em st0, ((-1)^k)/(2k + 1) em st1
        faddp st1, st0      ;sum + ((-1)^k)/(2k + 1) em st0
        fstp qword[pi]      ;pilha zerada e valor da variável sum atualizado
        dec ecx
        cmp ecx, 0
        je .end
        mov [n], ecx        ;atualizando o valor de n
        jmp .two_k_plus1

    .end:
        fld1                        ;1 em st0
        fld qword[pi]               ;sum em st0, 1 em st1
        faddp st1, st0              ;sum + 1 em st0
        fst qword[pi]               ;valor da variável sum atualizado
        mov eax, dword[ebp + 8]     ;Passando o endereço do ponteiro 'pi' para eax
        fstp dword[eax]             ;Carregando o valor de st0 no ponteiro 'pi'

    leave
    ret
