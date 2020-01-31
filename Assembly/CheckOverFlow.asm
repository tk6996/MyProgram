section .data
    fmt db "%d" , 0
    msg1 db "Please Enter Number One : " , 0
    msg2 db "Please Enter Number Two : " , 0
    msg3 db "Output Add : " , 0
    msg4 db "Overflow " , 0
    newline db  10 , 0
section .bss
    num1 resb 1
    num2 resb 1
section .text
    global _main
    extern _printf
    extern _scanf
    _main:
        push msg1
        call _printf
        push num1
        push fmt
        call _scanf
        push msg2
        call _printf
        push num2
        push fmt
        call _scanf
        push msg3
        call _printf
        mov eax , 0
        mov al , byte[num1]
        add al , byte[num2]
        JC carry
        mov ebx , eax
        push ebx
        push fmt
        call _printf
        ret
    carry:
        mov ebx , eax
        push ebx
        push fmt
        call _printf
        push newline
        call _printf
        push msg4
        call _printf