outdec proc
    push ax
    push bx
    push cx
    push dx
    
    or ax,ax
    jge endif
    
    push ax
    mov dl,'-'
    mov ah,2
    int 21h
    pop ax
    neg ax
    endif:
    xor cx,cx
    mov bx,10d
    rept:
    xor dx,dx
    div bx
    push dx
    inc cx
    
    or ax,ax
    jne rept
    
    mov ah,2
    
    print:
    pop dx
    or dl,30h
    int 21h
    loop print
    
    
    pop dx
    pop cx
    pop bx
    pop ax
    
    ret
    outdec endp
    