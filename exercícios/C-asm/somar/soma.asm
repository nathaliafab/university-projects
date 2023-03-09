SECTION .text
global soma
soma:
    enter 0,0
    mov eax, [ebp+8]
    add eax, [ebp+12]
    add eax, [ebp+16]
    leave
    ret