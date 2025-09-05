section .data

    

section .text

    global _start

_start:

    mov ax, 2000
    mov bx, 4000
    mul bx

end:
    mov rax,60
    mov rdi,0
    syscall

; considerar el tamaño del dw o dq etc, con  respecto a rax, eax y ax (considera bits)

