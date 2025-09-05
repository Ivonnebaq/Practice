section .data   

    mensaje db "Hola mundo", 0

section .bss

    inversa resb 20

section .text

    global _start

_start:  

    mov rax, mensaje

    mov rbx, 0

_countloop:
    inc rax
    inc rbx
    mov cl, [rax]
    cmp cl, 0
    jne _countloop

    mov r8, inversa
    mov rcx, rbx 

inv: 
    dec rax
    mov r9b, [rax]
    mov [r8], r9b
    inc r8
    dec rbx
    jne inv

escritura:
	mov rax, 1
	mov rdi, 1
	mov rsi, inversa
	mov rdx, rcx
	syscall

end:
    mov rax, 60
    mov rdi, 0
    syscall