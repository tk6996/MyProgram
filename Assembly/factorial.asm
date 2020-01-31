    global _factorial

    section .text
_factorial:
; - - - - - - - - - - - - - - - - - - - -> start of STACK FRAME
    push ebp        ; save for later
    mov  ebp, esp
    sub   esp, 4    ; create local variable "m"
; - - - - - - - - - - - - - - - - - - - -> (initial) end of STACK FRAME
    mov  eax, [ebp+8]
    cmp  eax, 2
    jbe   .basecase
.recurse
    dec  eax
    push eax
    call _factorial
    add  esp, 4     ; clean the stack
    mov  [ebp-4], eax   ; m = factorial(n-1)
    mov  eax, [ebp+8]   ; get n back
    mul  dword [ebp-4]  ; (edx,eax) <- n * m
    jmp  .done
.basecase
    xor  edx, edx       ; convert 32-bit "n" to 64-bit return value
    ;mov  eax, [ebp+8]  ; not necessary, because eax still holds "n"
.done
    add esp, 4          ; BETTER (more general):  mov esp, ebp
    pop  ebp
    ret                 ; return value is in (edx, eax)