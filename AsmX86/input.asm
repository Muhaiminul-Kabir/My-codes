indec proc
    push bx
    push cx
    push dx
    
    begin:
    xor bx,bx
    xor cx,cx
    
    mov ah,1
    int 21h
    
    cmp al,'-'
    je minus
    cmp al,'+'
    je plus
    jmp repeat
    
    minus:
	mov id,1
    mov cx,1
    
    plus:
    int 21h
    
    repeat:
    cmp al,'0'
    jnge notdig
    cmp al,'9'
    jnle notdig
    
    and ax,000fh
    push ax
    
    mov ax,10
    mul bx
    pop bx
    add bx,ax
    
    mov ah,1
    int 21h
    cmp al,0dh
    jne repeat
    
    mov ax,bx
    
    or cx,cx
    je exit
    
    
    neg ax
    exit:
    pop dx
    pop cx
    pop bx
    ret
    
    notdig:
    mov ah,2
    mov dl,0dh
    int 21h
    mov dl,0ah
    int 21h
    jmp begin
    indec endp
    