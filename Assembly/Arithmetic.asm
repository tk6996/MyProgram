 
    global _main
    extern _printf
    
    section .text
_main:
    inc dword[count]
    push dword[count]
    push formatInt
    call _printf
    add esp , 8
    mov ebx , dword[count]
    dec ebx
    push ebx
    push formatInt
    call _printf
    add esp , 8
    ret
section .data
    count dd 0
    formatInt db "%d" 