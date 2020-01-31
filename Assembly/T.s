
.section .data
msg : 
    .ascii "Hello world!\n"
.section .text
    globl  _main
    extern  _printf
_main:
    pushl msg
    call _printf
    addl $4 , %esp
    ret