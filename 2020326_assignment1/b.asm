extern c
section .data
    printer db 'you are in function b', 10
    length equ $-printer
    helper db 'the ascii string is', 10
    ltwo equ $-helper
section .bss
    num resb 8
section .text
    global _b
_b:
    mov [num], rdi
    mov rax, 1
	mov rdi, 1
	mov rsi, printer
	mov rdx, length
	syscall
    mov rax, 1
    mov rdi, 1
    mov rsi, helper
    mov rdx, ltwo
    syscall
    mov rax, 1
    mov rdi, 1
    mov rsi, num
    mov rdx, 8
    syscall
    mov r9, $c
    mov [rbp+8], r9
    ret