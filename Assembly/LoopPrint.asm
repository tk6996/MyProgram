section .data
    fmtIn db "%d" , 0
    fmtOut db "%d" , 10 , 0
    msg db "Enter Number for Loop Print : " , 0
    number dd 0
section .bss
    dest resd 0
section .text
    global _main
    extern _printf
    extern _scanf
    _main:
        push msg
        call _printf
        add esp , 4
        push dest
        push fmtIn
        call _scanf
        add esp , 8
        mov ecx , dword[dest]
    l1:
        inc dword[number]
        push ecx
        push dword[number]
        push fmtOut
        call _printf
        add esp , 8
        pop ecx
        loop l1
    ret