
;;show abs value[10,-10]


.model small
.stack 100h   


.data
   nam db 100 dup ('$')
   id db 0
   sd db 0
                         
.code
    main proc  
                   
        mov ax,@data
        mov ds,ax             
        XOR BX,BX
        
        call indec
        
        mov bx,ax           
        
        
        mov ah,2
        mov dl,10
        int 21h
      
        mov ax,bx
       
        ;; mov id ,1 in input.asm if negeive       
        cmp id,1
        je min
        
       
        
        call outdec
        jmp leave
        
        
        
        
        
        
        min:
        
        neg ax
        call outdec
        
        
        
        
        
        leave:
        mov ah,4ch
        int 21h
       
        
        
            

    main endp
    include output.asm
    include input.asm
end main
