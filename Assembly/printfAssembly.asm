
    global  _main
    extern  _printf
    extern  _scanf
    extern _puts

    section .text
_main:
    push msg1
    push len1
    push format
    call _printf
    add esp , 12
    push msg2
    push len2
    push format
    call _printf
    add esp , 12
    push msg3
    push len3
    push format
    call _printf
    add esp , 12
    push msg3
    add esp , 12
    ret
section .data
    msg1 db "Hello, programmers!",0xA,0xD
    len1 equ $ - msg1
    msg2 db "Welcome to the world of,",0xA,0xD
    len2 equ $ - msg2
    msg3 db "Window assembly programming! ",0xA,0xD
    len3 equ $ - msg3
    format db "%.*s"