    global _main
    extern _printf
    extern _scanf
section .data
    msg1 db "Enter a digit:" ,  0
    msg2 db "Please enter a second digit:" , 0
    msg3 db "The product is:" , 0
    formatInt db "%d" , 0 
section .bss
    num1 resd 1
    num2 resd 1 
    pro resq 1
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
    mov edx , dword[num2]
    mul edx
    mov [pro] , eax
    mov [pro+4] , edx
    push dword[pro]
    push formatInt
    call _printf
    add esp , 8
    ret