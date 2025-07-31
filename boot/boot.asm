BITS 16
ORG 0x7C00
start:
    mov si, msg
.print:
    lodsb
    or al, al
    jz loadk
    mov ah, 0x0E
    int 0x10
    jmp .print
loadk:
    mov ax, 0x1000
    mov es, ax
    xor bx, bx
    mov ah, 0x02
    mov al, 8
    mov ch, 0
    mov cl, 2
    mov dh, 0
    mov dl, 0x80
    int 0x13
    jc halt
    jmp 0x1000:0x0000
halt:
    cli
    hlt
msg db 'aiOS Bootloader: Hello, world!',0
times 510-($-$$) db 0
dw 0xAA55
