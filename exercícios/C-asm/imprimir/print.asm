extern imprimir
SECTION .data
    var dq 3.5

SECTION .text
    global main

main:
    push dword [var+4]  ; push the high part of the double
    push dword [var]    ; push the low part of the double
    call imprimir       ; call the function
    add esp, 8          ; clean the stack