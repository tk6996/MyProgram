    global _main
    extern _printf
    extern _scanf
section .data
    msg1 db "Enter a digit:" , 10 , 13 ,  0
    msg2 db "Please enter a second digit:" , 10 , 13  , 0
    msg3 db "The sum is:" , 10 , 13 , 0
    formatInt db "%d" , 0 
section .bss
    num1 resd 1
    num2 resd 1 
    res resd 1  
section .text
_main:
    push msg1
    call _printf
    add esp , 4
    push num1
    push formatInt
    call _scanf
    add esp , 8
    push msg2
    call _printf
    add esp , 4
    push num2
    push formatInt
    call _scanf
    add esp , 8
    mov eax , dword[num1]
    mov ebx , dword[num2]
    add eax , ebx
    mov dword[res] , eax
    push msg3
    call _printf
    add esp , 4
    push dword[res]
    push formatInt
    call _printf
    add esp , 8
    ret
