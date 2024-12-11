- Em C, os parâmetros são inseridos na pilha da direita para a esquerda (right-pusher)

## Convenções de retorno de funções
Funções em C utilizam determinados registradores para retorno, portanto o código C sempre assume que as rotinas em assembly estão utilizando esses registradores também.

1. Valores de 8, 16 e 32 bits são devolvidos em **EAX**
2. Valores de 64 bits são devolvidos em **EDX:EAX**
3. Valores de 80 bits são devolvidos em **ST(0)** (pilha de ponto flutuante)
4. Endereços (ponteiros) são devolvidos em **EAX**

## Regras de escrita do código assembly
1. O código assembly chamado por C pode utilizar qualquer registrador, porém, deve colocar na pilha (preservar):
    - EBP (aponta pro stack frame)
    - EBX
    - ESI
    - EDI

2. O assembly deve utilizar para retorno os registradores de retorno padrão
3. É aconselhável começar a rotina com a instrução `enter` e terminar com a instrução `leave`, antes de retornar (ou usar instruções equivalentes)

## Como compilar e linkar os módulos
- Para toda rotina em um módulo externo, deve-se utilizar a diretiva `extern` para declarar a função.
- Para a rotina externa chamada, deve-se utilizar a diretiva `global` para declarar a função.

### Gerando o executável
1. Assemble:    `nasm -f elf filea.asm`
2. Link:        `gcc -m32 -o prog filea.o` ou `gcc -m32 -o prog filec.c filea.o`
3. Run:         `./prog`
