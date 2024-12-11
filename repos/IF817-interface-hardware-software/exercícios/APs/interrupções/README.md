# Interrupções

**Interrupção é um evento que faz o processador interromper a execução de um programa.** Uma vez que uma interrupção é chamada, o processador salva o estado atual do programa e executa um programa de tratamento de interrupção (ISR). Quando o processador termina de executar o programa de ISR, ele retorna ao programa que estava sendo executado.

O processador pode ser configurado para gerar interrupções de hardware ou software (`INT`). Alguns exemplos de eventos que podem gerar uma interrupção são: divisão por zero, acesso indevido da memória, leitura do teclado, IRQs, etc.

O endereço de cada ISR (`CS:IP`) é armazenado em uma região de memória conhecida como IVT (Interrupt Vector Table). IVT é uma tabela de 256 entradas, cada entrada contém um endereço de 16 bits (`CS:IP`) de um programa de tratamento de interrupção. Cada endereço de ISR ocupa 4 bytes (`CS: 2 bytes, IP: 2 bytes`).

### Exemplo: onde está o INT 21h?
```
21h * 4 bytes = 84h
0h (segmento) + 84h (offset) = 84h -> 0h:84h
```

## Esquema do processamento de interrupções

1. O processador detecta um evento de interrupção.
2. O processador salva o estado atual do programa (`CS:IP`) na pilha.
3. O processador salva o valor da flag IF na pilha.
4. O processador salva o valor da flag TF na pilha.
5. O processador desabilita as interrupções (`IF = 0`).
6. O processador desabilita a geração de interrupções (`TF = 0`).
7. O processador busca o endereço de tratamento de interrupção (`CS:IP`) na IVT.
8. O processador salta para o endereço de tratamento de interrupção (`CS:IP`).
9. O processador executa o programa de tratamento de interrupção.
10. O processador retorna para o programa que estava sendo executado.
11. O processador restaura o valor da flag IF.
9.5. O processador restaura o valor da flag TF.
12. O processador restaura o estado atual do programa (`CS:IP`) da pilha.

## Implementando uma interrupção

Supondo que a ISR da interrupção 50h está no endereço 25650h na memória, como configurar a posição da IVT?

1. Determinar valores de CS e IP (`CS` será deslocado 4 bits para a esquerda e somado com `IP`) que resultem no endereço `25650h`.
2. Determinar um valor válido para CS (por exemplo: `2562h`).
3. Deslocar CS 4 bits para a esquerda (`CS << 4 = 25620h`).
4. Determinar um valor válido para IP (`30h`).
5. Verificar CS + IP (`25620h + 30h = 25650h`).
6. Calcular o endereço da IVT (`50h * 4 = 140h`).
7. Configurar a IVT (`0h:140h = 25620h:30h`).

### Exemplo: configurando a IVT para a interrupção 50h
```asm
push    ds                  ;salva o valor de DS na pilha
mov     ax, 0               ;zera AX
mov     ds, ax              ;zera DS
mov     di, 0140h           ;offset da interrupção 50h na IVT
mov     word[di], 30h       ;salvando o valor de IP
mov     word[di+2], 2562h   ;salvando o valor de CS
pop     ds                  ;restaura o valor de DS
```

Ou, de forma análoga:
```asm
mov     word[0140h], 30h    ;salvando o valor de IP
mov     word[0142h], 2562h  ;salvando o valor de CS
```
Onde `ds:di = 0h:140h = 2562h:30h` é o endereço da interrupção `50h` na IVT, e `cs:ip = 2562h:30h` é o endereço da ISR da interrupção `50h`.

## Padrão de implementação de uma ISR

1. Empilhar os registradores que serão usados
2. Escrever o código da ISR
3. Desempilhar os registradores que foram usados
4. Retornar para o programa que estava sendo executado (iret)
