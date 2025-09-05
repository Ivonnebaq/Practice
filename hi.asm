section .data   

    mensaje db "Hola mundo",0

    ;0 = me importe poner cuantos caracteres puedo

section .bss

    inversa resb 20

section .text

    global _start

_start:  

    mov rax, mensaje
    ;no poner [] solo sirve como puntero pra ver direccion de memoria

    mov rbx, 0

_countloop:
    inc rax
    inc rbx
    mov cl, [rax]
    cmp cl, 0
    jne _countloop
    ;me permite volver al inicio loop
    ;jne = jum not equal =  cuando no es cero salta
    ;analizar instruccciones aritmeticas

    mov r8, inversa
    mov rcx, rbx ;guardamos valor porque para imprimir neceito el numero de valores

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
    mov rax,60
    mov rdi,0
    syscall