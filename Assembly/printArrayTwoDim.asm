section .text
    global _printArrayTwoDim
    extern _printf
    _printArrayTwoDim:
        push ebp
        mov ebp , esp
        mov dword [row] , 0
        rowl:
            mov dword [collum] , 0
            coll:
                mov eax , 32
                mul dword[row]
                mov ecx , eax
                mov eax , 4
                mul dword[collum]
                mov ebx , ebp
                add ebx , 8
                mov ebx , dword[ebx] 
                add ebx , eax
                add ebx , ecx
                push dword[ebx]
                push fmt
                call _printf
                add esp , 8
                inc dword [collum]
                cmp dword [collum] , 8
                jl coll
            push nl
            call _printf
            add esp , 4 
            inc dword [row]
            cmp dword [row] , 8
            jl rowl
        pop ebp
        ret
section .bss
    row resd 1
    collum resd 1
section .data
    fmt db "%d " , 0
    nl db "" , 10