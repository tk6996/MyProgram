; ----------------------------------------------------------------------------
; helloworld.asm
;
; This is a Win32 console program that writes "Hello, World" on one line and
; then exits.  It needs to be linked with a C library.
; ----------------------------------------------------------------------------

    global  _bar
    extern _printf
    section .text
_bar:
    push ebp
    mov  ebp, esp
    mov eax , esp
    add eax , 8
    push dword[eax]
    push fmtI
    call _printf
    add esp , 8
    pop ebp
    mov eax , 789
    ret
    section .data
    fmtI db "%d" ,10, 0