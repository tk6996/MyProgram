section .text
    global _main
    extern _printf
    %macro  printf 2
        push %2
        push %1
        call _printf
        pop ebx
        pop ebx
    %endmacro
    _main :
        printf fmt , dword[num]
        ret
section .data
    fmt db "%d" , 0
    num dd 50
