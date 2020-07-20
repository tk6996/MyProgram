; ----------------------------------------------------------------------------------------
; Writes "Hola, mundo" to the console using a C library. Runs on Linux.
;
;     nasm -felf64 hola.asm && gcc hola.o && ./a.out
; ----------------------------------------------------------------------------------------

          global    main
          bits 64
          extern    printf

          section   .text
main:                                       ; This is called by the C library startup code
          mov       rcx, fmt
          mov       rdx, 5            ; First integer (or pointer) argument in rdi
          call      printf                    ; puts(message)
          ret                               ; Return from main back into C library wrapper
fmt : 
    db "%d" , 0