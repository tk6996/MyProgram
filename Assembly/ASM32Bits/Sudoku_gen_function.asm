section .text
    global _printBoard
    global _checkRow
    global _checkCollum
    global _checkBox
    extern _printf
    %define SIZE 9
    %define SRSIZE 3
    _printBoard:
        push ebp
        mov ebp , esp
        mov dword [__row] , 0
        rowl:
            mov dword [__collum] , 0
            coll:
                mov eax , SIZE
                mul byte [__row]
                movzx ebx , byte [__collum]
                add bl , al
                add ebx , dword[ebp + 8]
                movzx ecx , byte[ebx]
                push ecx
                push fmt
                call _printf
                add esp , 8
                inc byte [__collum]
                cmp byte [__collum] , SIZE
                jl coll
            push nl
            call _printf
            add esp , 4 
            inc byte [__row]
            cmp byte [__row] , SIZE
            jl rowl
        pop ebp
        ret
    _checkRow: ;bool checkRow(uint8_t board[SIZE][SIZE], uint8_t row, uint8_t num)
        push ebp
        mov ebp , esp
        mov ecx , SIZE
        mov edi , dword [ebp + 8]
        mov eax, SIZE
        mul byte[ebp + 12]
        add edi , eax
        mov al , byte[ebp + 16]
        cld
        repne scasb
        jz __find
        mov eax , 0
        pop ebp
        ret
    _checkCollum: ;bool checkCollum(uint8_t board[SIZE][SIZE], uint8_t col, uint8_t num)
        push ebp
        mov ebp , esp
        mov ecx , SIZE
        mov edx , dword [ebp + 8]
        add dl, byte [ebp + 12]
        mov bl , byte[ebp + 16]
        _checkCollum_loop:
            cmp byte[edx] , bl
            je __find 
            add edx , SIZE
            loop _checkCollum_loop
        mov eax , 0
        pop ebp
        ret
    _checkBox: ;checkBox(uint8_t board[SIZE][SIZE], uint8_t startRow, uint8_t startCol, uint8_t num)
        push ebp
        mov ebp , esp
        mov esi , dword [ebp + 8]
        movzx ebx , byte [ebp + 12]
        mov eax , SIZE
        mul ebx
        add esi , eax
        movzx ebx , byte [ebp + 16]
        mov dl , byte[ebp + 20]
        add esi ,ebx
        mov ebx , 0
        _checkBox_row:
            mov ecx , 0
            _checkBox_col:
                cmp byte[esi] , dl
                je __find                
                inc esi
                inc ecx
                cmp ecx , SRSIZE
                jl _checkBox_col
            add esi , SIZE
            sub esi , SRSIZE
            inc ebx
            cmp ebx ,SRSIZE
            jl _checkBox_row
        mov eax , 0
        pop ebp
        ret
    __find:
        mov eax , 1
        pop ebp
        ret
section .bss
     __row resb 1
    __collum resb 1
section .data
    fmt db "%d " , 0
    nl db 10 , 0