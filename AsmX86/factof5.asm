

.model small
.stack 100h   


.data
   
   as dw 12,13,14
                          
.code
    main proc  
                   
        mov ax,@data
        mov ds,ax             
       
        xor bx,bx
        xor ax,ax
        xor cx,cx
        
        lea si,as  
        
        mov cx,1
        mov ax,1
        
        fact:
            
            
            cmp cx,5
            jg leave_with_result
            mul cx 
            inc cx
        jmp fact
            
            
        
        
        mov ax,cx
        
        
        
        
        
        
        
        leave_with_result:
        
        call outdec
        
        
        
        mov ah,4ch
        int 21h
       
        
        
            

    main endp
    include output.asm
    include input.asm
end main
