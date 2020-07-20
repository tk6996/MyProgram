section .data
    fmt db "%d" , 0
    fmtOut db "%d ", 0
    array times 10 dd 0
    index dd 0
section .text
    global _main
    extern _printf
    extern _scanf
    _main:
    l0:
        mov esi , array
        mov edi , dword[index]
        lea eax , [esi + 4 * edi]
        push eax
        push fmt
        call _scanf
        inc dword[index]
        cmp dword[index] , 10
        jl l0
    mov dword[index] , 0
    l1:
        mov esi , array
        mov edi , dword[index]
        push dword[esi + 4 * edi]
        push fmtOut
        call _printf
        inc dword[index]
        cmp dword[index] , 10
        jl l1
    mov eax , 0
    ret
; C Code
; #include <stdio.h>
; char fmt[] = "%d";
; char fmtOut[] = "%d ";
; unsigned long array[10] = {0};
; unsigned long index = 0;
; int main()
; {
;     do
;     {
;         scanf(fmt,array + index);
;         index++;
;     }while(index < 10);
;     index = 0;
;     do
;     {
;         printf(fmtOut,*(array + index));
;         index++;
;     }while(index < 10);
;     return 0;
; }